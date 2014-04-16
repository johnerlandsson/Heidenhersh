/*
 * Point.h
 *
 *  Created on: Apr 14, 2014
 *      Author: john
 */

#ifndef POINT_H_
#define POINT_H_

#include <utility>
#include <memory>
#include <string>

namespace heidenhersh
{

class Point
{
	public:
		typedef struct { double ax; double ay; double bx; double by; } xy_points_t;
		Point();
		Point( const Point &other );
		Point( const double x, const double y, const double z );
		Point( const double z );
		const double x() const;
		const double y() const;
		const double z() const;
		void setX( const double x );
		void setY( const double y );
		void setZ( const double z );
		const std::string toString() const;
		bool operator==( const Point &other );
		bool operator!=( const Point &other );
		Point &operator=( const Point &other );
		operator bool() const;
		const xy_points_t normalizeXY( const Point &other );
		static const xy_points_t normalizeXY( const Point &a, const Point &b );
		const bool hasX() const;
		const bool hasY() const;
		const bool hasZ() const;

	private:
		std::unique_ptr<double> x_;
		std::unique_ptr<double> y_;
		std::unique_ptr<double> z_;
};

} /* namespace heidenhersh */

#endif /* POINT_H_ */
