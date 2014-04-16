/*
 * CharacterMap.h
 *
 *  Created on: Apr 14, 2014
 *      Author: john
 */

#ifndef CHARACTERMAP_H_
#define CHARACTERMAP_H_

#include <vector>
#include "HershChar.h"

namespace heidenhersh
{

class CharacterMap
{
	public:
		CharacterMap( const double z_safe, const double z_work );
		const HershChar character( char c ) const;

	private:
		std::vector<HershChar> data;
		double zs;
		double zw;

		const inline HershChar make_A();
		const inline HershChar make_B();
		const inline HershChar make_C();
		const inline HershChar make_D();
		const inline HershChar make_E();
		const inline HershChar make_F();
		const inline HershChar make_G();
		const inline HershChar make_H();
		const inline HershChar make_I();
		const inline HershChar make_J();
		const inline HershChar make_K();
		const inline HershChar make_L();
		const inline HershChar make_M();
		const inline HershChar make_N();
		const inline HershChar make_O();
		const inline HershChar make_P();
		const inline HershChar make_Q();
		const inline HershChar make_R();
		const inline HershChar make_S();
		const inline HershChar make_T();
		const inline HershChar make_U();
		const inline HershChar make_V();
		const inline HershChar make_W();
		const inline HershChar make_X();
		const inline HershChar make_Y();
		const inline HershChar make_Z();

		const inline HershChar make_0();
		const inline HershChar make_1();
		const inline HershChar make_2();
		const inline HershChar make_3();
		const inline HershChar make_4();
		const inline HershChar make_5();
		const inline HershChar make_6();
		const inline HershChar make_7();
		const inline HershChar make_8();
		const inline HershChar make_9();

		const inline HershChar make_dash();
		const inline HershChar make_dot();
		const inline HershChar make_slash();
		const inline HershChar make_space();
};

} /* namespace heidenhersh */

#endif /* CHARACTERMAP_H_ */
