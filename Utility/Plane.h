#pragma once
/************************************************************************/
/* Plane 
/* -----
/* A simple 3d plane 
/************************************************************************/
#include <glm/glm.hpp>


class Plane
{
private:
	glm::vec3 _point;  
	glm::vec3 _normal;

public:
	Plane(const glm::vec3& point
		, const glm::vec3& normal);
	Plane(const glm::vec3& p0
		, const glm::vec3& p1
		, const glm::vec3& p2);
	Plane(const Plane& other);

	const float distance() const;	// from origin
	const glm::vec3& point() const;
	const glm::vec3& normal() const;

	bool isPointOn   (const glm::vec3& point);
	bool isPointAbove(const glm::vec3& point);
	bool isPointBelow(const glm::vec3& point);

/*
	bool isSphereOn   (const glm::vec3& center, const float radius);
	bool isSphereAbove(const glm::vec3& center, const float radius);
	bool isSphereBelow(const glm::vec3& center, const float radius);
*/
};


inline Plane::Plane(const glm::vec3& point
				  , const glm::vec3& normal)
	: _point(point)
	, _normal(glm::normalize(normal))
{ }

inline Plane::Plane(const glm::vec3& p0
				  , const glm::vec3& p1
				  , const glm::vec3& p2)
	: _point(p0)
	, _normal(glm::normalize(glm::cross(p2 - p0, p1 - p0)))
{ }

inline const float Plane::distance()    const { return glm::dot(_normal, _point); }
inline const glm::vec3& Plane::point()  const { return _point; }
inline const glm::vec3& Plane::normal() const { return _normal; }

inline bool Plane::isPointOn(const glm::vec3& point)
{
	return (glm::dot(_normal, point - _point) == 0.f);
}

inline bool Plane::isPointAbove(const glm::vec3& point)
{
	return (glm::dot(_normal, point - _point) > 0.f);
}

inline bool Plane::isPointBelow(const glm::vec3& point)
{
	return (glm::dot(_normal, point - _point) < 0.f);
}

/*
bool Plane::isSphereOn(const glm::vec3& center, const float radius)
{
	throw std::runtime_error("Plane::isSphereOn() is not yet implemented");
	return false;
}

bool Plane::isSphereAbove(const glm::vec3& center, const float radius)
{
	throw std::runtime_error("Plane::isSphereAbove() is not yet implemented");
	return false;
}

bool Plane::isSphereBelow(const glm::vec3& center, const float radius)
{
	throw std::runtime_error("Plane::isSphereBelow() is not yet implemented");
	return false;
}
*/
