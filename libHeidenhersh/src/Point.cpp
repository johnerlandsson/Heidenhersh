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

//Point::Point( const Point &other ) : x_{ new double{ *other.x_ } },
//									 y_{ new double{ *other.y_ } },
//									 z_{ new double{ *other.z_ } }
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

} /* namespace heidenhersh */

