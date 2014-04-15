/*
 * CharacterMap.cpp
 *
 *  Created on: Apr 14, 2014
 *      Author: john
 */

#include "CharacterMap.h"

namespace heidenhersh
{
CharacterMap::CharacterMap( const double z_safe, const double z_work ) : zs{ z_safe }, zw{ z_work }
{
	data.push_back( make_A() );
}

const HershChar CharacterMap::character( char c ) const
{
	for( auto i : data )
		if( i.c() == c )
			return i;

	throw std::invalid_argument( "CharacterMap::character: No such character." );
	return HershChar( '\0', {} );
}

inline const HershChar CharacterMap::make_A()
{
	std::initializer_list<Point> pl{ { zs }, { -0.3633, -0.4773, zs }, { zw }, { 0.0000, 0.4773, zw }, { 0.3633, -0.4773, zw }, { zs }, { -0.2269, -0.1591, zs }, { zw }, { 0.2276, -0.1591, zw }, { zs } };
	return HershChar{ 'A', pl };
}

} /* namespace heidenhersh */
