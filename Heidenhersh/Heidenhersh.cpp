//============================================================================
// Name        : Heidenhersh.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CharacterMap.h"

using namespace std;
using namespace heidenhersh;


const double z_safe{ 0.2f };
const double z_work{ -0.3f };

std::vector<HershChar> chars;

int main()
try
{
	string line{ "A" };

	CharacterMap m{ 0.2, -0.3 };

	double xoffs{ 0.0f };
	int lno{ 0 };
	cout << lno << " BEGIN PGM 1 MM" << endl;
	for( auto c : line )
	{
		for( auto l : m.character( c ).toHeidenhain( 1.0f, false, 30, 6000 ) )
			cout << ++lno << ' ' << l << endl;
	}
	cout << ++lno << " END PGM 1" << endl;

	return 0;
}
catch( const exception &e )
{
	cerr << "Exception caught: " << e.what() << endl;
	return 1;
}
catch( ... )
{
	cerr << "Unknown exception\n";
	return 1;
}
