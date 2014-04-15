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


char HershChar::c()
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

const std::vector<std::string> HershChar::toHeidenhain( const double scale, const bool mirror, const int feed,
														const int rapid, const int n_cuts, const double workp_z_pos,
														double& x_offset )
{
	x_offset += (width_ / 2);
	multiple_cuts( n_cuts, workp_z_pos );

	return toHeidenhain( scale, mirror, feed, rapid );
}

const std::vector<std::string> HershChar::toHeidenhain( const double scale, const bool mirror, const int feed, const int rapid )
{
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

void HershChar::multiple_cuts( const int n_cuts, const double workp_z_pos )
{
	if( n_cuts == 1 )
		return;
	else if( n_cuts <= 1 )
		throw std::invalid_argument( "HershChar::multiple_cuts: less than one cut." );

	double inc = workp_z_pos - min_z_pos / (double)n_cuts;
	if( inc < 0.0f )
		throw std::invalid_argument( "HershChar::multiple_cuts: increment is less than zero." );

	std::vector<Point> tmp_p = p_;
	p_.clear();
	for( int i = 0; i < n_cuts - 1; i++ )
	{
		for( const auto p : tmp_p )
		{
			Point current = p;
			try
			{
				double z = current.z();
				if( z == min_z_pos )
					current.setZ( z - ((z / (double)n_cuts) * (n_cuts - i)) );
			}
			catch( const std::out_of_range & ) { }

			p_.push_back( current );
		}
	}

}

void HershChar::split_yz_groove( const Point yz_center, const double workp_z_pos )
{
}

} /* namespace heidenhersh */

