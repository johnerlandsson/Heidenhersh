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
	data.push_back( make_B() );
	data.push_back( make_C() );
	data.push_back( make_D() );
	data.push_back( make_E() );
	data.push_back( make_F() );
	data.push_back( make_G() );
	data.push_back( make_H() );
	data.push_back( make_I() );
	data.push_back( make_J() );
	data.push_back( make_K() );
	data.push_back( make_L() );
	data.push_back( make_M() );
	data.push_back( make_N() );
	data.push_back( make_O() );
	data.push_back( make_P() );
	data.push_back( make_Q() );
	data.push_back( make_R() );
	data.push_back( make_S() );
	data.push_back( make_T() );
	data.push_back( make_U() );
	data.push_back( make_V() );
	data.push_back( make_X() );
	data.push_back( make_Y() );
	data.push_back( make_Z() );

	data.push_back( make_m() );
	data.push_back( make_x() );

	data.push_back( make_0() );
	data.push_back( make_1() );
	data.push_back( make_2() );
	data.push_back( make_3() );
	data.push_back( make_4() );
	data.push_back( make_5() );
	data.push_back( make_6() );
	data.push_back( make_7() );
	data.push_back( make_8() );
	data.push_back( make_9() );

	data.push_back( make_dash() );
	data.push_back( make_dot() );
	data.push_back( make_slash() );
	data.push_back( make_space() );
}

const HershChar CharacterMap::character( char c ) const
{
	for( auto i : data )
		if( i.c() == c )
			return i;

	std::string msg{ "CharacterMap::character: No such character \'" };
	msg.push_back( c );
	msg.append( "\'." );
	throw std::invalid_argument( msg );
	return HershChar( '\0', {} );
}

inline const HershChar CharacterMap::make_A()
{
	std::initializer_list<Point> pl{ { zs }, { -0.3633, -0.4773, zs }, { zw }, { 0.0000, 0.4773, zw }, { 0.3633, -0.4773, zw }, { zs }, { -0.2269, -0.1591, zs }, { zw }, { 0.2276, -0.1591, zw }, { zs } };
	return HershChar{ 'A', pl };
}

inline const HershChar CharacterMap::make_B()
{
	std::initializer_list<Point> pl{ { zs }, { -0.3183, 0.4773, zs }, { zw }, { -0.3183, -0.4773, zw }, { zs }, { -0.3183, 0.4773, zs }, { zw }, { 0.0908, 0.4773, zw }, { 0.2272, 0.4318, zw }, { 0.2726, 0.3864, zw }, { 0.3181, 0.2955, zw }, { 0.3181, 0.2046, zw }, { 0.2726, 0.1137, zw }, { 0.2272, 0.0682, zw }, { 0.0908, 0.0227, zw }, { zs }, { -0.3183, 0.0227, zs }, { zw }, { 0.0908, 0.0227, zw }, { 0.2272, -0.0227, zw }, { 0.2726, -0.0682, zw }, { 0.3181, -0.1591, zw }, { 0.3181, -0.2955, zw }, { 0.2726, -0.3863, zw }, { 0.2272, -0.4318, zw }, { 0.0908, -0.4773, zw }, { -0.3183, -0.4773, zw }, { zs } };
	return HershChar{ 'B', pl };
}

inline const HershChar CharacterMap::make_C()
{
	std::initializer_list<Point> pl{ { zs }, { 0.3415, 0.2500, zs }, { zw }, { 0.2961, 0.3409, zw }, { 0.2052, 0.4318, zw }, { 0.1143, 0.4773, zw }, { -0.0675, 0.4773, zw }, { -0.1585, 0.4318, zw }, { -0.2494, 0.3409, zw }, { -0.2948, 0.2500, zw }, { -0.3403, 0.1137, zw }, { -0.3403, -0.1136, zw }, { -0.2948, -0.2500, zw }, { -0.2494, -0.3409, zw }, { -0.1585, -0.4318, zw }, { -0.0675, -0.4773, zw }, { 0.1143, -0.4773, zw }, { 0.2052, -0.4318, zw }, { 0.2961, -0.3409, zw }, { 0.3415, -0.2500, zw }, { zs } };
	return HershChar{ 'C', pl };
}

inline const HershChar CharacterMap::make_D()
{
	std::initializer_list<Point> pl{ { zs }, { -0.3183, 0.4773, zs }, { zw }, { -0.3183, -0.4773, zw }, { zs }, { -0.3183, 0.4773, zs }, { zw }, { -0.0001, 0.4773, zw }, { 0.1363, 0.4318, zw }, { 0.2272, 0.3409, zw }, { 0.2726, 0.2500, zw }, { 0.3181, 0.1137, zw }, { 0.3181, -0.1136, zw }, { 0.2726, -0.2500, zw }, { 0.2272, -0.3409, zw }, { 0.1363, -0.4318, zw }, { -0.0001, -0.4773, zw }, { -0.3183, -0.4773, zw }, { zs } };
	return HershChar{ 'D', pl };
}

inline const HershChar CharacterMap::make_E()
{
	std::initializer_list<Point> pl{ { zs }, { -0.2953, 0.4773, zs }, { zw }, { -0.2953, -0.4773, zw }, { zs }, { -0.2953, 0.4773, zs }, { zw }, { 0.2956, 0.4773, zw }, { zs }, { -0.2953, 0.0227, zs }, { zw }, { 0.0684, 0.0227, zw }, { zs }, { -0.2953, -0.4773, zs }, { zw }, { 0.2956, -0.4773, zw }, { zs } };
	return HershChar{ 'E', pl };
}

inline const HershChar CharacterMap::make_F()
{
	std::initializer_list<Point> pl{ { zs }, { -0.2953, 0.4773, zs }, { zw }, { -0.2953, -0.4773, zw }, { zs }, { -0.2953, 0.4773, zs }, { zw }, { 0.2956, 0.4773, zw }, { zs }, { -0.2953, 0.0227, zs }, { zw }, { 0.0684, 0.0227, zw }, { zs } };
	return HershChar{ 'F', pl };
}

inline const HershChar CharacterMap::make_G()
{
	std::initializer_list<Point> pl{ { zs }, { 0.3415, 0.2500, zs }, { zw }, { 0.2961, 0.3409, zw }, { 0.2052, 0.4318, zw }, { 0.1143, 0.4773, zw }, { -0.0675, 0.4773, zw }, { -0.1585, 0.4318, zw }, { -0.2494, 0.3409, zw }, { -0.2948, 0.2500, zw }, { -0.3403, 0.1137, zw }, { -0.3403, -0.1136, zw }, { -0.2948, -0.2500, zw }, { -0.2494, -0.3409, zw }, { -0.1585, -0.4318, zw }, { -0.0675, -0.4773, zw }, { 0.1143, -0.4773, zw }, { 0.2052, -0.4318, zw }, { 0.2961, -0.3409, zw }, { 0.3415, -0.2500, zw }, { 0.3415, -0.1136, zw }, { zs }, { 0.1143, -0.1136, zs }, { zw }, { 0.3415, -0.1136, zw }, { zs } };
	return HershChar{ 'G', pl };
}

inline const HershChar CharacterMap::make_H()
{
	std::initializer_list<Point> pl{ { zs }, { -0.3183, 0.4773, zs }, { zw }, { -0.3183, -0.4773, zw }, { zs }, { 0.3181, 0.4773, zs }, { zw }, { 0.3181, -0.4773, zw }, { zs }, { -0.3183, 0.0227, zs }, { zw }, { 0.3181, 0.0227, zw }, { zs } };
	return HershChar{ 'H', pl };
}

inline const HershChar CharacterMap::make_I()
{
	std::initializer_list<Point> pl{ {zs}, { 0.0, 0.5, zs }, { zw }, { 0.0f, -0.5, zw }, { zs } };
	return HershChar{ 'I', pl };
}

inline const HershChar CharacterMap::make_J()
{
	std::initializer_list<Point> pl{ { zs }, { 0.2273, 0.4773, zs }, { zw }, { 0.2273, -0.2500, zw }, { 0.1818, -0.3863, zw }, { 0.1364, -0.4318, zw }, { 0.0455, -0.4773, zw }, { -0.0455, -0.4773, zw }, { -0.1364, -0.4318, zw }, { -0.1818, -0.3863, zw }, { -0.2273, -0.2500, zw }, { -0.2273, -0.1591, zw }, { zs } };
	return HershChar{ 'J', pl };
}

inline const HershChar CharacterMap::make_K()
{
	std::initializer_list<Point> pl{ { zs }, { -0.3183, 0.4773, zs }, { zw }, { -0.3183, -0.4773, zw }, { zs }, { 0.3181, 0.4773, zs }, { zw }, { -0.3183, -0.1591, zw }, { zs }, { -0.0910, 0.0682, zs }, { zw }, { 0.3181, -0.4773, zw }, { zs } };
	return HershChar{ 'K', pl };
}

inline const HershChar CharacterMap::make_L()
{
	std::initializer_list<Point> pl{ { zs }, { -0.2683, 0.4773, zs }, { zw }, { -0.2683, -0.4773, zw }, { zs }, { -0.2683, -0.4773, zs }, { zw }, { 0.2772, -0.4773, zw }, { zs } };
	return HershChar{ 'L', pl };
}

inline const HershChar CharacterMap::make_M()
{
	std::initializer_list<Point> pl{ { zs }, { -0.3633, -0.4773, zs }, { zw }, { -0.3633, 0.4773, zw }, { 0.0004, -0.4773, zw }, { 0.3640, 0.4773, zw }, { 0.3640, -0.4773, zw }, { zs } };
	return HershChar{ 'M', pl };
}

inline const HershChar CharacterMap::make_N()
{
	std::initializer_list<Point> pl{ { zs }, { -0.3183, 0.4773, zs }, { zw }, { -0.3183, -0.4773, zw }, { zs }, { -0.3183, 0.4773, zs }, { zw }, { 0.3181, -0.4773, zw }, { zs }, { 0.3181, 0.4773, zs }, { zw }, { 0.3181, -0.4773, zw }, { zs } };
	return HershChar{ 'N', pl };
}

inline const HershChar CharacterMap::make_O()
{
	std::initializer_list<Point> pl{ { zs }, { -0.0905, 0.4773, zs }, { zw }, { -0.1815, 0.4318, zw }, { -0.2724, 0.3409, zw }, { -0.3178, 0.2500, zw }, { -0.3633, 0.1137, zw }, { -0.3633, -0.1136, zw }, { -0.3178, -0.2500, zw }, { -0.2724, -0.3409, zw }, { -0.1815, -0.4318, zw }, { -0.0905, -0.4773, zw }, { 0.0913, -0.4773, zw }, { 0.1822, -0.4318, zw }, { 0.2731, -0.3409, zw }, { 0.3185, -0.2500, zw }, { 0.3640, -0.1136, zw }, { 0.3640, 0.1137, zw }, { 0.3185, 0.2500, zw }, { 0.2731, 0.3409, zw }, { 0.1822, 0.4318, zw }, { 0.0913, 0.4773, zw }, { -0.0905, 0.4773, zw }, { zs } };
	return HershChar{ 'O', pl };
}

inline const HershChar CharacterMap::make_P()
{
	std::initializer_list<Point> pl{ { zs }, { -0.3183, 0.4773, zs }, { zw }, { -0.3183, -0.4773, zw }, { zs }, { -0.3183, 0.4773, zs }, { zw }, { 0.0908, 0.4773, zw }, { 0.2272, 0.4318, zw }, { 0.2726, 0.3864, zw }, { 0.3181, 0.2955, zw }, { 0.3181, 0.1591, zw }, { 0.2726, 0.0682, zw }, { 0.2272, 0.0227, zw }, { 0.0908, -0.0227, zw }, { -0.3183, -0.0227, zw }, { zs } };
	return HershChar{ 'P', pl };
}

inline const HershChar CharacterMap::make_Q()
{
	std::initializer_list<Point> pl{ { zs }, { -0.0897, 0.4774, zs }, { zw }, { -0.1799, 0.4323, zw }, { -0.2702, 0.3421, zw }, { -0.3153, 0.2518, zw }, { -0.3604, 0.1164, zw }, { -0.3604, -0.1092, zw }, { -0.3153, -0.2445, zw }, { -0.2702, -0.3348, zw }, { -0.1799, -0.4251, zw }, { -0.0897, -0.4702, zw }, { 0.0908, -0.4702, zw }, { 0.1811, -0.4251, zw }, { 0.2713, -0.3348, zw }, { 0.3164, -0.2445, zw }, { 0.3616, -0.1092, zw }, { 0.3616, 0.1164, zw }, { 0.3164, 0.2518, zw }, { 0.2713, 0.3421, zw }, { 0.1811, 0.4323, zw }, { 0.0908, 0.4774, zw }, { -0.0897, 0.4774, zw }, { zs }, { 0.0457, -0.2897, zs }, { zw }, { 0.3164, -0.5604, zw }, { zs } };
	return HershChar{ 'Q', pl };
}

inline const HershChar CharacterMap::make_R()
{
	std::initializer_list<Point> pl{ { zs }, { -0.318273 , 0.477271, zs }, { zw }, { -0.318273 , -0.477274, zw }, { zs }, { -0.318273 , 0.477271, zs }, { zw }, { 0.090818 , 0.477271, zw }, { 0.227182 , 0.431816, zw }, { 0.272636 , 0.386362, zw }, { 0.318091 , 0.295453, zw }, { 0.318091 , 0.204544, zw }, { 0.272636 , 0.113635, zw }, { 0.227182 , 0.068180, zw }, { 0.090818 , 0.022726, zw }, { -0.318273 , 0.022726, zw }, { zs }, { -0.000091 , 0.022726, zs }, { zw }, { 0.318091 , -0.477274, zw }, { zs } };
	return HershChar{ 'R', pl };
}

inline const HershChar CharacterMap::make_S()
{
	std::initializer_list<Point> pl{ { zs }, { 0.3181, 0.3409, zs }, { zw }, { 0.2272, 0.4318, zw }, { 0.0908, 0.4773, zw }, { -0.0910, 0.4773, zw }, { -0.2274, 0.4318, zw }, { -0.3183, 0.3409, zw }, { -0.3183, 0.2500, zw }, { -0.2728, 0.1591, zw }, { -0.2274, 0.1137, zw }, { -0.1365, 0.0682, zw }, { 0.1363, -0.0227, zw }, { 0.2272, -0.0682, zw }, { 0.2726, -0.1136, zw }, { 0.3181, -0.2045, zw }, { 0.3181, -0.3409, zw }, { 0.2272, -0.4318, zw }, { 0.0908, -0.4773, zw }, { -0.0910, -0.4773, zw }, { -0.2274, -0.4318, zw }, { -0.3183, -0.3409, zw }, { zs } };
	return HershChar{ 'S', pl };
}

inline const HershChar CharacterMap::make_T()
{
	std::initializer_list<Point> pl{ { zs }, { -0.0001, 0.4773, zs }, { zw }, { -0.0001, -0.4773, zw }, { zs }, { -0.3183, 0.4773, zs }, { zw }, { 0.3181, 0.4773, zw }, { zs } };
	return HershChar{ 'T', pl };
}

inline const HershChar CharacterMap::make_U()
{
	std::initializer_list<Point> pl{ { zs }, { -0.3183, 0.4773, zs }, { zw }, { -0.3183, -0.2046, zw }, { -0.2728, -0.3409, zw }, { -0.1819, -0.4318, zw }, { -0.0455, -0.4773, zw }, { 0.0454, -0.4773, zw }, { 0.1817, -0.4318, zw }, { 0.2726, -0.3409, zw }, { 0.3181, -0.2046, zw }, { 0.3181, 0.4773, zw }, { zs } };
	return HershChar{ 'U', pl };
}

inline const HershChar CharacterMap::make_V()
{
	std::initializer_list<Point> pl{ { zs }, { -0.3633, 0.4773, zs }, { zw }, { 0.0004, -0.4773, zw }, { zs }, { 0.3640, 0.4773, zs }, { zw }, { 0.0004, -0.4773, zw }, { zs } };
	return HershChar{ 'V', pl };
}

inline const HershChar CharacterMap::make_W()
{
	std::initializer_list<Point> pl{ { zs }, { -0.3633, 0.4773, zs }, { zw }, { -0.3633, -0.4773, zw }, { 0.0004, 0.4773, zw }, { 0.3640, -0.4773, zw }, { 0.3640, 0.4773, zw }, { zs } };
	return HershChar{ 'W', pl };
}

inline const HershChar CharacterMap::make_X()
{
	std::initializer_list<Point> pl{ { zs }, { -0.3183, 0.4773, zs }, { zw }, { 0.3181, -0.4773, zw }, { zs }, { 0.3181, 0.4773, zs }, { zw }, { -0.3183, -0.4773, zw }, { zs } };
	return HershChar{ 'X', pl };
}

inline const HershChar CharacterMap::make_Y()
{
	std::initializer_list<Point> pl{ { zs }, { -0.3633, 0.4773, zs }, { zw }, { 0.0004, 0.0227, zw }, { 0.0004, -0.4773, zw }, { zs }, { 0.3640, 0.4773, zs }, { zw }, { 0.0004, 0.0227, zw }, { zs } };
	return HershChar{ 'Y', pl };
}

inline const HershChar CharacterMap::make_Z()
{
	std::initializer_list<Point> pl{ { zs }, { -0.318091 , 0.477271, zs }, { zw }, { 0.318091 , 0.477271, zw }, { -0.318091, -0.477271, zw }, { 0.318091, -0.477271, zw }, { zs } };
	return HershChar{ 'Z', pl };
}

inline const HershChar CharacterMap::make_m()
{
	std::initializer_list<Point> pl{ { zs }, { -0.477273, 0.159090, zs }, { zw }, { -0.477273, -0.477265, zw }, { zs }, { -0.477273, -0.022718, zs }, { zw }, { -0.340909, 0.113624, zw }, { -0.250000, 0.159090, zw }, { -0.113636, 0.159090, zw }, { -0.022727, 0.113624, zw }, { 0.022727, -0.022718, zw }, { 0.022727, -0.477265, zw }, { zs }, { 0.022727, -0.022718, zs }, { zw }, { 0.159091 , 0.113624, zw }, { 0.250000, 0.159090, zw }, { 0.386364, 0.159090, zw }, { 0.477273, 0.113624, zw }, { 0.522727, -0.022718, zw }, { 0.522727, -0.477265, zw }, { zs } };
	return HershChar{ 'm', pl };
}

inline const HershChar CharacterMap::make_x()
{
	std::initializer_list<Point> pl{ { zs }, { -0.249773 , 0.159090, zs }, { zw }, { 0.250227 , -0.477265, zw }, { zs }, { 0.250227, 0.159090, zs }, { zw }, { -0.249773, -0.477265, zw }, { zs } };
	return HershChar{ 'x', pl };
}

inline const HershChar CharacterMap::make_0()
{
	std::initializer_list<Point> pl{ { zs }, { -0.0455, 0.4773, zs }, { zw }, { -0.1819, 0.4318, zw }, { -0.2728, 0.2955, zw }, { -0.3183, 0.0682, zw }, { -0.3183, -0.0682, zw }, { -0.2728, -0.2954, zw }, { -0.1819, -0.4318, zw }, { -0.0455, -0.4773, zw }, { 0.0454, -0.4773, zw }, { 0.1817, -0.4318, zw }, { 0.2726, -0.2954, zw }, { 0.3181, -0.0682, zw }, { 0.3181, 0.0682, zw }, { 0.2726, 0.2955, zw }, { 0.1817, 0.4318, zw }, { 0.0454, 0.4773, zw }, { -0.0455, 0.4773, zw }, { zs } };
	return HershChar{ '0', pl };
}

inline const HershChar CharacterMap::make_1()
{
	std::initializer_list<Point> pl{ { zs }, { -0.1133, 0.2955, zs }, { zw }, { -0.0224,  0.3409, zw }, { 0.1140, 0.4773, zw }, { 0.1140, -0.4773, zw }, { zs } };
	return HershChar{ '1', pl };
}

inline const HershChar CharacterMap::make_2()
{
	std::initializer_list<Point> pl{ { zs }, { -0.2728, 0.2500, zs }, { zw }, { -0.2728, 0.2955, zw }, { -0.2274, 0.3864, zw }, { -0.1819, 0.4318, zw }, { -0.0910, 0.4773, zw }, { 0.0908, 0.4773, zw }, { 0.1817, 0.4318, zw }, { 0.2272, 0.3864, zw }, { 0.2726, 0.2955, zw }, { 0.2726, 0.2046, zw }, { 0.2272, 0.1137, zw }, { 0.1363, -0.0227, zw }, { -0.3183, -0.4773, zw }, { 0.3181, -0.4773, zw }, { zs } };
	return HershChar{ '2', pl };
}

inline const HershChar CharacterMap::make_3()
{
	std::initializer_list<Point> pl{ { zs }, { -0.2273, 0.4772, zs }, { zw }, { 0.2728, 0.4772, zw }, { -0.0000, 0.1136, zw }, { 0.1364, 0.1136, zw }, { 0.2273, 0.0681, zw }, { 0.2728, 0.0227, zw }, { 0.3183, -0.1137, zw }, { 0.3183, -0.2046, zw }, { 0.2728, -0.3409, zw }, { 0.1819, -0.4318, zw }, { 0.0455, -0.4773, zw }, { -0.0909, -0.4773, zw }, { -0.2273, -0.4318, zw }, { -0.2728, -0.3864, zw }, { -0.3183, -0.2955, zw }, { zs } };
	return HershChar{ '3', pl };
}

inline const HershChar CharacterMap::make_4()
{
	std::initializer_list<Point> pl{ { zs }, { 0.1143, 0.4773, zs }, { zw }, { -0.3403, -0.1591, zw }, { 0.3415, -0.1591, zw }, { zs }, { 0.1143, 0.4773, zs }, { zw }, { 0.1143, -0.4773, zw }, { zs } };
	return HershChar{ '4', pl };
}

inline const HershChar CharacterMap::make_5()
{
	std::initializer_list<Point> pl{ { zs }, { 0.2272, 0.4773, zs }, { zw }, { -0.2274, 0.4773, zw }, { -0.2728, 0.0682, zw }, { -0.2274, 0.1137, zw }, { -0.0910, 0.1591, zw }, { 0.0454, 0.1591, zw }, { 0.1817, 0.1137, zw }, { 0.2726, 0.0227, zw }, { 0.3181, -0.1136, zw }, { 0.3181, -0.2045, zw }, { 0.2726, -0.3409, zw }, { 0.1817, -0.4318, zw }, { 0.0454, -0.4773, zw }, { -0.0910, -0.4773, zw }, { -0.2274, -0.4318, zw }, { -0.2728, -0.3864, zw }, { -0.3183, -0.2954, zw }, { zs } };
	return HershChar{ '5', pl };
}

inline const HershChar CharacterMap::make_6()
{
	std::initializer_list<Point> pl{ { zs }, { 0.2502, 0.3409, zs }, { zw }, { 0.2047, 0.4318, zw }, { 0.0684, 0.4773, zw }, { -0.0225, 0.4773, zw }, { -0.1589, 0.4318, zw }, { -0.2498, 0.2955, zw }, { -0.2953, 0.0682, zw }, { -0.2953, -0.1591, zw }, { -0.2498, -0.3409, zw }, { -0.1589, -0.4318, zw }, { -0.0225, -0.4773, zw }, { 0.0229, -0.4773, zw }, { 0.1593, -0.4318, zw }, { 0.2502, -0.3409, zw }, { 0.2956, -0.2045, zw }, { 0.2956, -0.1591, zw }, { 0.2502, -0.0227, zw }, { 0.1593, 0.0682, zw }, { 0.0229, 0.1137, zw }, { -0.0225, 0.1137, zw }, { -0.1589, 0.0682, zw }, { -0.2498, -0.0227, zw }, { -0.2953, -0.1591, zw }, { zs } };
	return HershChar{ '6', pl };
}

inline const HershChar CharacterMap::make_7()
{
	std::initializer_list<Point> pl{ { zs }, { 0.3181, 0.4773, zs }, { zw }, { -0.1365, -0.4773, zw }, { zs }, { -0.3183, 0.4773, zs }, { zw }, { 0.3181, 0.4773, zw }, { zs } };
	return HershChar{ '7', pl };
}

inline const HershChar CharacterMap::make_8()
{
	std::initializer_list<Point> pl{ { zs }, { -0.0910, 0.4773, zs }, { zw }, { -0.2274, 0.4318, zw }, { -0.2728, 0.3409, zw }, { -0.2728, 0.2500, zw }, { -0.2274, 0.1591, zw }, { -0.1365, 0.1137, zw }, { 0.0454, 0.0682, zw }, { 0.1817, 0.0227, zw }, { 0.2726, -0.0682, zw }, { 0.3181, -0.1591, zw }, { 0.3181, -0.2954, zw }, { 0.2726, -0.3864, zw }, { 0.2272, -0.4318, zw }, { 0.0908, -0.4773, zw }, { -0.0910, -0.4773, zw }, { -0.2274, -0.4318, zw }, { -0.2728, -0.3864, zw }, { -0.3183, -0.2954, zw }, { -0.3183, -0.1591, zw }, { -0.2728, -0.0682, zw }, { -0.1819, 0.0227, zw }, { -0.0455, 0.0682, zw }, { 0.1363, 0.1137, zw }, { 0.2272, 0.1591, zw }, { 0.2726, 0.2500, zw }, { 0.2726, 0.3409, zw }, { 0.2272, 0.4318, zw }, { 0.0908, 0.4773, zw }, { -0.0910, 0.4773, zw }, { zs } };
	return HershChar{ '8', pl };
}

inline const HershChar CharacterMap::make_9()
{
	std::initializer_list<Point> pl{ { zs }, { 0.2956, 0.1591, zs }, { zw }, { 0.2502, 0.0227, zw }, { 0.1593, -0.0682, zw }, { 0.0229, -0.1136, zw }, { -0.0225, -0.1136, zw }, { -0.1589, -0.0682, zw }, { -0.2498, 0.0227, zw }, { -0.2953, 0.1591, zw }, { -0.2953, 0.2046, zw }, { -0.2498, 0.3409, zw }, { -0.1589, 0.4318, zw }, { -0.0225, 0.4773, zw }, { 0.0229, 0.4773, zw }, { 0.1593, 0.4318, zw }, { 0.2502, 0.3409, zw }, { 0.2956, 0.1591, zw }, { 0.2956, -0.0682, zw }, { 0.2502, -0.2954, zw }, { 0.1593, -0.4318, zw }, { 0.0229, -0.4773, zw }, { -0.0680, -0.4773, zw }, { -0.2044, -0.4318, zw }, { -0.2498, -0.3409, zw }, { zs } };
	return HershChar{ '9', pl };
}

inline const HershChar CharacterMap::make_dash()
{
	std::initializer_list<Point> pl{ { zs }, { -0.2, 0.0, zs }, { zw }, { 0.2, 0.0, zw }, { zs } };
	return HershChar{ '-', pl };
}

inline const HershChar CharacterMap::make_dot()
{
	std::initializer_list<Point> pl{ { zs }, { 0.0000, -0.5000, zs }, { zw }, { zs } };
	return HershChar{ '.', pl };
}

inline const HershChar CharacterMap::make_slash()
{
	std::initializer_list<Point> pl{ { zs }, { -0.4 , -0.5, zs }, { zw }, { 0.4 , 0.5, zw }, { zs } };
	return HershChar{ '/', pl };
}

inline const HershChar CharacterMap::make_space()
{
	HershChar ret{ ' ', {} };
	ret.width_ = 0.5f;
	ret.max_z_pos = zs;
	ret.min_z_pos = zw;

	return ret;
}

} /* namespace heidenhersh */
