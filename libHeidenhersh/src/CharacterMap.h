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
};

} /* namespace heidenhersh */

#endif /* CHARACTERMAP_H_ */
