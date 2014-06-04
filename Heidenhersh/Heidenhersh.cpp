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

		//cout << prevC.width() << ' ' << co.width() << ' ' << spacing << ' ' << (prevC.width() / 2) + (co.width() / 2) + spacing << endl;

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
					  	  	  const double zoffs, const double seg_len, const double gradius,
					  	  	  const double wradius )
{
	vector<double> ret;
	int lno{ 0 };
	int pgmno{ 1 };
	double a { 0.0f };

	cout << lno << " BEGIN PGM " << pgmno << " MM" << endl;
	HershChar prevC;
	for( auto i = line.begin(); i != line.end(); i++ )
	{
		//Create temporary character for scaling
		HershChar tco{ map.character( *i ) };
		tco.scale( scale );

		HershChar co = HershChar::yzGroove( tco, zoffs, gradius, wradius, n_cuts, seg_len );

		//Don't scale again
		for( const auto l : co.toHeidenhain( 1.0f, mirror, feed, rapid ) )
			cout << ++lno << ' ' << l << endl;

		string mfun = i == (line.end() - 1) ? "M2" : "M";
		cout << ++lno << ' ' << "STOP " << mfun << endl;

		if( i != line.begin() )
			a += dist2angle( dia, ((prevC.width() / 2) * scale) + ((co.width() / 2) * scale) + spacing );
		prevC = co;
		ret.push_back( a );

		if( lno >= 900 )
		{
			cout << ++lno << " END PGM " << pgmno << " MM" << endl << endl;
			lno = 0;
			pgmno++;
			cout << lno << " BEGIN PGM " << pgmno << " MM" << endl;
		}

	}
	cout << ++lno << " END PGM " << pgmno << " MM" << endl;

	return ret;
}


int main()
try
{
//	string line{ "amokabel - H00S-D 25 - IEC 61138/60165" };
//	string line{ "AMO H07V2-K S" };
	string line{ "I" };

	CharacterMap m{ 0.2, -0.3 };

//	vector<double> angles = wheel( line, m, 60.0f, 3.2f, true, 30, 1000, 1.0f, 2, 0.0f );
	cout << ";Program. String: " << line << endl;
//	vector<double> angles = wheel( line, m, 60.0f, 2.8f, true, 30, 2000, 1.3f, 2, 0.0f );

	vector<double> angles = grooved_wheel( line,	//Input test
										   m, 		//Character map
										   60, 		//Wheel dia
										   3.0f, 	//Scale
										   true,	//Mirror
										   30, 		//Feed
										   6000, 	//Rapid feed
										   1.7f, 	//Spacing
										   1,		//Number of cuts
										   1.5f,	//YZ center offset
										   0.25f,	//Max segment length
										   4.7f,	//Groove radius
										   5.0f );	//Groove work radius

//	vector<double> angles = grooved_wheel( line,	//Input test
//										   m, 		//Character map
//										   60, 		//Wheel dia
//										   3.2, 	//Scale
//										   true,	//Mirror
//										   30, 		//Feed
//										   6000, 	//Rapid feed
//										   1.7f, 	//Spacing
//										   3,		//Number of cuts
//										   1.5f,	//YZ center offset
//										   0.25f,	//Max segment length
//										   4.7f,	//Groove radius
//										   5.0f );	//Groove work radius

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
