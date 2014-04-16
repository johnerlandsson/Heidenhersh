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
	string line{ "ABCDEFGHIJKLMNOPQRSTUVXYZ" };

	CharacterMap m{ 0.2, -0.3 };

	int lno{ 0 };
	cout << lno << " BEGIN PGM 1 MM" << endl;
	for( auto i = line.begin(); i != line.end(); i++ )
	{
		HershChar co = HershChar::yzGroove( m.character( *i ), 5, 0.0f, 10.0f, 10.3f, 2, 0.5f );
		for( const auto l : co.toHeidenhain( 3.2f, false, 30, 6000 ) )
			cout << ++lno << ' ' << l << endl;
		string mfun = i == (line.end() - 1) ? "M2" : "M";
		cout << ++lno << ' ' << "STOP " << mfun << endl;
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
