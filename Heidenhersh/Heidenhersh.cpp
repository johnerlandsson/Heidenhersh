//============================================================================
// Name        : Heidenhersh.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "CharacterMap.h"
#include <cmath>

using namespace std;
using namespace heidenhersh;


const double z_safe{ 0.2f };
const double z_work{ -0.3f };

std::vector<HershChar> chars;

constexpr double dist2angle( const double dia, const double dist )
{
	return dist / ((dia * M_PI) / 360);
}

vector<double> wheel( const std::string &line, const CharacterMap &map, const double dia, const double scale,
					  const bool mirror, const int feed, const int rapid, const double spacing, const int n_cuts,
					  const int workp_z_pos )
{
	vector<double> ret;
	int lno{ 0 };
	double a { 0.0f };

	cout << lno << " BEGIN PGM 1 MM" << endl;
	HershChar prevC;
	for( auto i = line.begin(); i != line.end(); i++ )
	{
		HershChar co;
		if( n_cuts > 1 )
			co = HershChar::multipleCuts( map.character( *i ), n_cuts, workp_z_pos );
		else
			co = map.character( *i );

		for( const auto l : co.toHeidenhain( scale, mirror, feed, rapid ) )
			cout << ++lno << ' ' << l << endl;

		string mfun = i == (line.end() - 1) ? "M2" : "M";
		cout << ++lno << ' ' << "STOP " << mfun << endl;

		cout << prevC.width() << ' ' << co.width() << ' ' << spacing << ' ' << (prevC.width() / 2) + (co.width() / 2) + spacing << endl;

		if( i != line.begin() )
			a += dist2angle( dia, ((prevC.width() / 2) * scale) + ((co.width() / 2) * scale) + spacing );
		prevC = co;
		ret.push_back( a );
	}
	cout << ++lno << " END PGM 1 MM" << endl;

	return ret;
}

vector<double> grooved_wheel( const std::string &line, const CharacterMap &map, const double dia, const double scale,
					  	  	  const bool mirror, const int feed, const int rapid, const double spacing, const int n_cuts,
					  	  	  const int workp_z_pos, const double zoffs, const double seg_len, const double gradius,
					  	  	  const double wradius )
{
	vector<double> ret;
	int lno{ 0 };
	double a { 0.0f };

	cout << lno << " BEGIN PGM 1 MM" << endl;
	HershChar prevC;
	for( auto i = line.begin(); i != line.end(); i++ )
	{
		HershChar co;
		co = HershChar::yzGroove( map.character( *i ), zoffs, workp_z_pos, gradius, wradius, n_cuts, seg_len );

		for( const auto l : co.toHeidenhain( scale, mirror, feed, rapid ) )
			cout << ++lno << ' ' << l << endl;

		string mfun = i == (line.end() - 1) ? "M2" : "M";
		cout << ++lno << ' ' << "STOP " << mfun << endl;

		if( i != line.begin() )
			a += dist2angle( dia, ((prevC.width() / 2) * scale) + ((co.width() / 2) * scale) + spacing );
		prevC = co;
		ret.push_back( a );
	}
	cout << ++lno << " END PGM 1 MM" << endl;

	return ret;
}


int main()
try
{
	string line{ "amokabel H00S-D 50 - " };
//	string line{ "IEC 61138/60165" };
//	string line{ "EXQ 4G1" };
	CharacterMap m{ 0.2, -0.3 };

//	vector<double> angles = wheel( line, m, 60.0f, 3.2f, true, 30, 1000, 1.0f, 2, 0.0f );
	cout << ";Program. String: " << line << endl;
	vector<double> angles = grooved_wheel( line, m, 60, 3.2, true, 30, 6000, 0.5f, 2, 0.0f, 4.93f, 0.25f, 6.35, 6.65 );

	cout << endl << ";Angles." << endl;
	for( auto a : angles )
		cout << a << ';';
	cout << endl;

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
