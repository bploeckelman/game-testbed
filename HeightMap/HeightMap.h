#pragma once
/************************************************************************/
/* HeightMap 
/* ---------
/* A basic height map 
/************************************************************************/
#include "../Utility/Matrix2d.h"

typedef Matrix2d<double> HeightMatrix;


class HeightMap
{
private:
	HeightMatrix heights;	

	void randomize();

public:
	HeightMap(const unsigned int width=100
			, const unsigned int height=100);

	void render();

};
