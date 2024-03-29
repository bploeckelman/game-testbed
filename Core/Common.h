#pragma once
/************************************************************************/
/* Common includes and helper functions
/************************************************************************/
#include "../Utility/Logger.h"

#include <vector>

class Camera;

typedef std::vector<Camera>          CameraVector;
typedef CameraVector::iterator       CameraVectorIter;
typedef CameraVector::const_iterator CameraVectorConstIter;


namespace constants
{
	const float one_third = 1.f / 3.f;
	const float e = 2.71828182845904523536f;
	const float pi = 3.1415926535897932384f;
	const float two_pi = 2.f * pi;
	const float four_pi = 4.f * pi;
	const float half_pi = 0.5f * pi;
	const float quarter_pi = 0.25f * pi;
	const float one_third_pi = one_third * pi;
	const float pi_over_180 = pi / 180.f;
};


inline float degToRad(const float deg) { return deg * constants::pi_over_180; }
inline float radToDeg(const float rad) { return rad / constants::pi_over_180; }
