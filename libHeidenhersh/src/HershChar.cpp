/*
 * HershChar.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: john
 */

#include "HershChar.h"
#include <sstream>
#include <iomanip>
#include <limits>
#include <bitset>
#include <cmath>

//TODO debug include
#include <iostream>

namespace heidenhersh
{

HershChar::HershChar( const char c, const std::initializer_list<Point> p ) : p_{ p }, c_{ c }
{
	max_z_pos = std::numeric_limits<double>::min();
	min_z_pos = std::numeric_limits<double>::max();
	double min_x = std::numeric_limits<double>::max();
	double max_x = std::numeric_limits<double>::min();

	for( auto i : p_ )
	{
		//Determine highest/lowest Z pos
		try
		{
			double z = i.z();

			if( z > max_z_pos )
				max_z_pos = z;
			if( z < min_z_pos )
				min_z_pos = z;
		}
		catch( const std::out_of_range & ) { }
		//Determine width
		try
		{
			double x = i.x();
			if( x < min_x )
				min_x = x;
			if( x > max_x )
				max_x = x;
		}
		catch( const std::out_of_range & ) { }
	}

	width_ = max_x - min_x;
}


const char HershChar::c() const
{
	return c_;
}

const bool HershChar::isZTop( double pos ) const
{
	return pos == max_z_pos;
}

const double HershChar::width() const
{
	return width_;
}

const std::vector<std::string> HershChar::toHeidenhain(	const double scale, const bool mirror, const int feed,
														const int rapid, double& x_offset )
{
	x_offset += (width_ / 2);

	return toHeidenhain( scale, mirror, feed, rapid );
}

const std::vector<std::string> HershChar::toHeidenhain( const double scale, const bool mirror, const int feed, const int rapid ) const
{
	if( p_.size() == 0 )
		return std::vector<std::string>();

	std::vector<std::string> ret;

	for( auto l : p_ )
	{
		std::stringstream line;
		line << "L " << std::showpos << std::fixed << std::setprecision( 3 );

		int f = feed;

		try
		{
			double x{ l.x() };
			if( mirror )
				x *= -1.0f;
			line << 'X' << (x *= scale) << ' ';
		}
		catch( const std::out_of_range &e ) { }

		try
		{
			double y{ l.y() };
			if( mirror )
				y *= -1.0f;
			line << 'Y' << (y *= scale) << ' ';
		}
		catch( const std::out_of_range &e ) { }

		try
		{
			double z = l.z();

			if( isZTop( z ) )
				f = rapid;

			line << 'Z' << z << ' ';
		}
		catch( const std::out_of_range &e ) { }

		line << std::noshowpos << "R F" << f;

		ret.push_back( line.str() );
	}

	return ret;
}

const HershChar HershChar::multipleCuts( HershChar const &from, const int n_cuts, const double workp_z_pos )
{
	if( n_cuts == 1 )
		return HershChar( from );
	else if( n_cuts <= 1 )
		throw std::invalid_argument( "HershChar::multipleCuts: less than one cut." );

	double inc = workp_z_pos - from.min_z_pos / (double)n_cuts;
	if( inc < 0.0f )
		throw std::invalid_argument( "HershChar::multipleCuts: increment is less than zero." );

	HershChar ret{ from.c(), {} };
	ret.max_z_pos = from.max_z_pos;
	ret.min_z_pos = from.min_z_pos;
	ret.width_ = from.width_;

	if( from.p_.size() == 0 )
		return ret;

	Point prev, current;
	for( int i = n_cuts; i > 0; i-- )
	{
		for( const auto p : from.p_ )
		{
			current = p;
			try
			{
				double z = current.z();
				if( z == from.min_z_pos )
					current.setZ( z + (inc * (i - 1)) );
			}
			catch( const std::out_of_range & ) { }

			//Skip duplicate entries
			if( prev != current )
				ret.p_.push_back( current );
			prev = current;
		}
	}

	return ret;
}

const HershChar HershChar::yzGroove( HershChar const &from, const double z_offs, const double workp_z_pos,
									 const double groove_radius, const double work_radius, const int n_cuts,
									 const double z_res )
{
	HershChar split{ splitYSegments( from, z_res ) };
	HershChar ret{ split.c_, {} };
	ret.max_z_pos = split.max_z_pos;
	ret.min_z_pos = split.min_z_pos;
	ret.width_ = split.width_;

	if( from.p_.size() == 0 )
		return ret;

	double incR = (work_radius - groove_radius) / n_cuts;
	if( incR <= 0.0f )
		throw std::invalid_argument( "HershChar::yzGroove: Negative radius increment.\nCheck parameters: groove_radius, work_radius and n_cuts." );

	double currY = split.firstY();
	for( int i = 1; i <= n_cuts; i++ )
	{
		Point prevP;
		for( auto p : split.p_ )
		{
			if( (prevP) && p == prevP )
				continue;

			if( p.hasY() )
				currY = p.y();

			if( (p.hasZ()) && p.z() == split.min_z_pos )
			{
				double currR = groove_radius + (incR * i);
				Point nP = p;
				nP.setZ( z_offs - (currR - ( 1 - (cos( asin( currY / currR ) )))) );
				ret.p_.push_back( nP );
			}
			else
			{
				ret.p_.push_back( p );
			}
		}
	}

	return ret;
}

void HershChar::addPoint( const Point p )
{
	p_.push_back( p );
}

const HershChar HershChar::splitYSegments( HershChar const &from, const double max_y_len )
{
	if( max_y_len < 0.1f )
		throw std::invalid_argument( "HershChar::splitYSegments: Segment too short." );

	HershChar ret{ from.c(), {} };
	ret.max_z_pos = from.max_z_pos;
	ret.min_z_pos = from.min_z_pos;
	ret.width_ = from.width_;

	if( from.p_.size() == 0 )
		return ret;

	try
	{
		double prevY = from.firstY();
		Point prevP;
		for( const auto p : from.p_ )
		{
			try
			{
				if( prevP )
				{
					//Don't split segments with no Z coordinate or where Z is in top position
					try
					{
						if( p.z() == from.max_z_pos )
							throw std::out_of_range( "dummy" );
					}
					catch( const std::out_of_range &e )
					{
						ret.p_.push_back( p );
						prevP = p;
						continue;
					}

					double y_dist = prevY - p.y();
					if( y_dist < 0.0f )
						y_dist *= -1.0f;

					if( y_dist > 0.0f )
					{
						int n_seg = (int)ceil( y_dist / max_y_len );
						double seg_len = segmentLength( prevP, p ) / n_seg;
						if( seg_len == 0.0f )
							throw std::overflow_error( "HershChar::splitYSegments: About to divide by zero." );

						Point::xy_points_t xy = Point::normalizeXY( prevP, p );
						double incX = (xy.bx - xy.ax) / n_seg;
						double incY = (xy.by - xy.ay) / n_seg;

						double z = p.hasZ() ? p.z() : ret.max_z_pos;

						for( int i = 1; i <= n_seg; i++ )
							ret.p_.push_back( Point( xy.ax + (incX * i), xy.ay + (incY * i), z ) );
					}
					else
					{
						ret.p_.push_back( p );
					}

					prevY = p.y();
				}
				else
				{
					ret.p_.push_back( p );
				}

				prevP = p;
			}
			catch( const std::out_of_range & ) { ret.p_.push_back( p ); }
		}
	}
	catch( const NoY &e ) { return from; }

	return ret;
}

const double HershChar::firstY() const
{
	double ret;
	bool hasValue = false;

	for( auto p : p_ )
	{
		try { ret = p.y(); hasValue = true; }
		catch( const std::out_of_range & ) { }

		if( hasValue )
			return ret;
	}

	throw NoY{};

	return ret;
}

const double HershChar::segmentLength( const Point a, const Point b )
{
	Point::xy_points_t xy = Point::normalizeXY( a, b );

	return sqrt( (xy.ax - xy.bx) * (xy.ax - xy.bx) + (xy.ay - xy.by) * (xy.ay - xy.by) );
}

} /* namespace heidenhersh */

