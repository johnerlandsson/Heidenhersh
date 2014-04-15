/*
 * HershChar.h
 *
 *  Created on: Apr 14, 2014
 *      Author: john
 */

#ifndef HERSHCHAR_H_
#define HERSHCHAR_H_

#include <vector>
#include <string>
#include "Point.h"
#include <initializer_list>

namespace heidenhersh
{

class HershChar
{
	public:

		HershChar( const char c, const std::initializer_list<Point> p );
		char c();
		const bool isZTop( double pos ) const;
		const double width() const;
		const std::vector<std::string> toHeidenhain( const double scale, const bool mirror, const int feed,
													 const int rapid, double &x_offset ); //Linear
		const std::vector<std::string> toHeidenhain( const double scale, const bool mirror, const int feed,
													 const int rapid, const int n_cuts, const double workp_z_pos,
													 double &x_offset ); //Linear n cuts

	private:
		const std::vector<std::string> toHeidenhain( const double scale, const bool mirror, const int feed,
													 const int rapid );
		void multiple_cuts( const int n_cuts, const double workp_z_pos );
		void split_yz_groove( const Point yz_center, const double workp_z_pos );

		std::vector<Point> p_;
		char c_;
		double max_z_pos;
		double min_z_pos;
		double width_;
};

} /* namespace heidenhersh */

#endif /* HERSHCHAR_H_ */
