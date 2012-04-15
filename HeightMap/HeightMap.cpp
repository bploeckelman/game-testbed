/************************************************************************/
/* HeightMap 
/* ---------
/* A basic height map 
/************************************************************************/
#include "HeightMap.h"
#include "../Utility/Matrix2d.h"
#include "../Core/Common.h"

#include <SFML/Graphics.hpp>

#include <glm/gtc/random.hpp>

#include <vector>
#include <cmath>

using std::vector;


HeightMap::HeightMap(const unsigned int width, const unsigned int height)
	: heights(height, width)
{
	randomize();
}

void HeightMap::render()
{
	const float groundScale = 20.f;
	const float heightScale = 30.f;
	for(unsigned int row = 0; row < (heights.rows() - 1); ++row)
	{
		glBegin(GL_TRIANGLE_STRIP);
		for(unsigned int col = 0; col < (heights.cols() - 1); ++col)
		{
			const float r = static_cast<float>(row) / static_cast<float>(heights.rows());
			const float g = static_cast<float>(col) / static_cast<float>(heights.cols());
			const float b = static_cast<float>(row) / static_cast<float>(col);
			glColor3f(r,g,b);
			glVertex3d(groundScale * col
					 , heightScale * heights(row,col)
					 , groundScale * row);
			glVertex3d(groundScale * col
					 , heightScale * heights(row+1,col)
					 , groundScale * (row + 1));
			glVertex3d(groundScale * (col + 1)
					 , heightScale * heights(row,col+1)
					 , groundScale * row);
			glVertex3d(groundScale * (col + 1)
					 , heightScale * heights(row+1,col+1)
					 , groundScale * (row + 1));
		}
		glEnd();
	}
}

void HeightMap::randomize()
{
	for(unsigned int row = 0; row < heights.rows(); ++row)
	for(unsigned int col = 0; col < heights.cols(); ++col)
	{
		heights(row,col) = glm::gaussRand(1.0, 0.4);
	}
}
