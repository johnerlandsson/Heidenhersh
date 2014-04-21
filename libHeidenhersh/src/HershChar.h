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

class CharacterMap;
class HershChar
{
	public:
		struct NoY {};
		HershChar();
		HershChar( const char c, const std::initializer_list<Point> p );
		char c() const;
		bool isZTop( double pos ) const;
		double width() const;
		const std::vector<std::string> toHeidenhain( const double scale, const bool mirror, const int feed,
													 const int rapid ) const;
		static const HershChar multipleCuts( HershChar const &from, const int n_cuts, const double workp_z_pos );
		static const HershChar yzGroove( HershChar const &from, const double z_offs, const double workp_z_pos,
										 const double groove_radius, const double work_radius, const int n_cuts,
										 const double z_res );

	protected:
		void addPoint( const Point p );

	private:
		friend class CharacterMap;
		static const HershChar splitYSegments( HershChar const &from, const double max_y_len );
		double firstY() const;
		static double segmentLength( const Point a, const Point b );
		std::vector<Point> p_;
		char c_;
		double max_z_pos;
		double min_z_pos;
		double width_;
};

} /* namespace heidenhersh */

#endif /* HERSHCHAR_H_ */
