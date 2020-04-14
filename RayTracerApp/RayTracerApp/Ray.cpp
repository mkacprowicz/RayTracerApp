#include "Ray.h"

/**
* Default constructor. Creates a ray object that has it's parameters set to  \f$ (0, 0, 0) \f$ .
* @return Zero Ray object
*/
Ray::Ray()
{
	this->Origin_ = Vector::Zero();
	this->Direction_ = Vector::Zero();
	this->Distance_ = 0.0f;
}

/**
* Basic constructor. Creates a ray object that has fixed parameters.
* @param origin - origin (A parameter) of a ray function
* @param direction - direction (B parameter) of a ray function
* @returns Ray object
*/
Ray::Ray(Vector origin, Vector direction)
{
	this->Origin_ = origin;
	this->Direction_ = direction.NormalizeProduct();
	this->Distance_ = 0.0f;
}

/**
* Basic constructor. Creates a ray object that has fixed parameters.
* @param origin - origin (A parameter) of a ray function
* @param dist - distance (t parameter) of a ray function
* @returns Ray object
*/
Ray::Ray(Vector origin, float dis)
{
	this->Origin_ = origin;
	this->Distance_ = dis;
}

/**
* Basic constructor. Creates a ray object that has fixed parameters.
* @param origin - origin (A parameter) of a ray function
* @param direction - direction (B parameter) of a ray function
* @param dist - distance (t parameter) of a ray function
* @returns Ray object
*/
Ray::Ray(Vector origin, Vector direction, float dis)
{
	this->Origin_ = origin;
	this->Direction_ = direction.NormalizeProduct();
	this->Distance_ = dis;
}

/**
* Overlaoded << operator for debug purposes.
* Example:
* @code
* Ray ray();
* std::cout << ray;
* @endcode
* Output:
* @code
* "Ray(0,0,0)"
* @endcode
*/
std::ostream& operator<<(std::ostream& os, const Ray& ray)
{
	os << "Ray(" << ray.Origin_ << "," << ray.Direction_ << "," << std::to_string(ray.Distance_) << ")";
	return os;
}
