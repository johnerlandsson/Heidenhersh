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

	private:
		std::unique_ptr<double> x_;
		std::unique_ptr<double> y_;
		std::unique_ptr<double> z_;
};

} /* namespace heidenhersh */

#endif /* POINT_H_ */
