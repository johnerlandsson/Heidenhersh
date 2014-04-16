/*
 * Point.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: john
 */

#include "Point.h"
#include <stdexcept>
#include <sstream>

namespace heidenhersh
{

Point::Point()
{
}

Point::Point( const Point &other )
{
	if( other.x_ )
		x_ = std::unique_ptr<double>{ new double{ *other.x_ } };
	if( other.y_ )
		y_ = std::unique_ptr<double>{ new double{ *other.y_ } };
	if( other.z_ )
		z_ = std::unique_ptr<double>{ new double{ *other.z_ } };
}

Point::Point( const double x, const double y, const double z ) : x_{ new double{ x } },
																 y_{ new double{ y } },
																 z_{ new double{ z } }
{
}

Point::Point( const double z ) : x_{ nullptr }, y_{ nullptr }, z_{ new double{ z } }
{
}

const double Point::x() const
{
	if( x_ == nullptr )
		throw std::out_of_range( "Point::x. nullptr from getter." );

	return *x_;
}

const double Point::y() const
{
	if( y_ == nullptr )
		throw std::out_of_range( "Point::y. nullptr from getter." );

	return *y_;
}

const double Point::z() const
{
	if( z_ == nullptr )
		throw std::out_of_range( "Point::z. nullptr from getter." );

	return *z_;
}

void Point::setX( const double x )
{
	if( x_ == nullptr )
		throw std::out_of_range( "Point::setX. X is nullptr." );

	*x_ = x;
}

void Point::setY( const double y )
{
	if( y_ == nullptr )
		throw std::out_of_range( "Point::setY. Y is nullptr." );

	*y_ = y;
}

void Point::setZ( const double z )
{
	if( z_ == nullptr )
		throw std::out_of_range( "Point::setZ. Z is nullptr." );

	*z_ = z;
}

const std::string Point::toString() const
{
	std::stringstream ret;
	ret << std::showpos;

	if( x_ )
		ret << "X " << *x_ << ' ';
	if( y_ )
		ret << "Y " << *y_ << ' ';
	if( z_ )
		ret << "Z " << *z_ << ' ';

	return ret.str();
}

bool Point::operator==( const Point &other )
{
	if( (x_ && !other.x_) || (!x_ && other.x_) )
		return false;
	if( x_ && other.x_ )
		if( *x_ != *other.x_ )
			return false;

	if( (y_ && !other.y_) || (!y_ && other.y_) )
		return false;
	if( y_ && other.y_ )
		if( *y_ != *other.y_ )
			return false;

	if( (z_ && !other.z_) || (!z_ && other.z_) )
		return false;
	if( z_ && other.z_ )
		if( *z_ != *other.z_ )
			return false;

	return true;
}

bool Point::operator!=( const Point &other )
{
	return !(*this == other);
}

Point &Point::operator=( const Point &other )
{
	if( x_ )
		x_.release();
	if( y_ )
		y_.release();
	if( z_ )
		z_.release();

	if( other.x_ )
		x_ = std::unique_ptr<double>{ new double{ *other.x_ } };
	if( other.y_ )
		y_ = std::unique_ptr<double>{ new double{ *other.y_ } };
	if( other.z_ )
		z_ = std::unique_ptr<double>{ new double{ *other.z_ } };

	return *this;
}

Point::operator bool() const
{
	if( !x_ && !y_ && !z_ )
		return false;

	return true;
}

const Point::xy_points_t Point::normalizeXY( const Point &other )
{
	return normalizeXY( *this, other );
}

const Point::xy_points_t Point::normalizeXY( const Point &a, const Point &b )
{
	if( !a.x_ && !b.x_ )
		throw std::runtime_error( "Point::normalize: No X value in points." );
	if( !a.y_ && !b.y_ )
		throw std::runtime_error( "Point::normalize: No Y value in points." );

	xy_points_t ret;
	if( a.x_ )
		ret.ax = *a.x_;
	else
		ret.ax = *b.x_;
	if( a.y_ )
		ret.ay = *a.y_;
	else
		ret.ay = *b.y_;
	if( b.x_ )
		ret.bx = *b.x_;
	else
		ret.bx = *a.x_;
	if( b.y_ )
		ret.by = *b.y_;
	else
		ret.by = *a.y_;

	return ret;
}

const bool Point::hasX() const
{
	return x_ != nullptr;
}

const bool Point::hasY() const
{
	return y_ != nullptr;
}

const bool Point::hasZ() const
{
	return z_ != nullptr;
}

} /* namespace heidenhersh */

