#include "Sphere.h"

/**
* Default constructor. Creates a sphere object that has center in \f$ (0,0,0) \f$ and radius equal to \f$ 1 \f$
* @return Sphere object
*/
Sphere::Sphere()
{
	this->Center_ = Vector::Zero();
	this->Radius_ = 1.0f;
	this->ShapeMaterial_ = nullptr;
}

/**
* Basic constructor. Creates a sphere object that has center in \f$ (0,0,0) \f$ and radius equal to \f$ r \f$
* @param r - radius of a sphere
* @return Sphere object
*/
Sphere::Sphere(float r)
{
	this->Center_ = Vector::Zero();
	this->Radius_ = r;
	this->ShapeMaterial_ = nullptr;
}

/**
* Basic constructor. Creates a sphere object that has center in \f$ v \f$ and radius equal to \f$ 1 \f$
* @param v - center of a sphere
* @return Sphere object
*/
Sphere::Sphere(Vector v)
{
	this->Center_ = v;
	this->Radius_ = 1.0f;
	this->ShapeMaterial_ = nullptr;
}

/**
* Basic constructor. Creates a sphere object that has center in \f$ v \f$ and radius equal to \f$ r \f$
* @param r - radius of a sphere
* @param v - center of a sphere
* @return Sphere object
*/
Sphere::Sphere(Vector v, float r)
{
	this->Center_ = v;
	this->Radius_ = r;
	this->ShapeMaterial_ = nullptr;
}

/**
* Basic constructor. Creates a sphere object that has center in \f$ v \f$ and radius equal to \f$ r \f$
* @param r - radius of a sphere
* @param v - center of a sphere
* @param mat - material of a sphere
* @return Sphere object
*/
Sphere::Sphere(Vector v, float r, std::shared_ptr<Material> mat)
{
	this->Center_ = v;
	this->Radius_ = r;
	this->ShapeMaterial_ = mat;
}

/**
* Function that checks whether or not Sphere intersects with a Ray. There are three possible cases that can occur:
*	- Ray doesn't hit a Sphere
*	- Ray hits a Sphere in one point
*	- Ray hits a Sphere in two points
* To examine which case is valid we have to determine an equation:
* \f[
* ||A + Bt -c||^2 = r^2 <=> (A + Bt - c) \cdot (A + Bt - c) = r^2 \\
*	t^2(B \cdot B) + 2t(B \cdot (A - c)) + (A - c) \cdot (A - c) = r^2 \\
*	t^2(B \cdot B) + 2t(B \cdot (A - c)) + (A - c) \cdot (A - c) - r^2 = 0 \\
* \f]
* which is equal to quadratic equation:
* \f[
*	at^2 + bt + c = 0
* \f]
* where:
* \f[
*	a = B \cdot B = ||B||^2 \\
*	b = 2(B \cdot (A - c)) \\
*	c = (A - c) \cdot (A - c) - r^2 = ||A - c||^2 - r^2
* \f]
* what can be simplified:
* \f[
* t = \frac{-2(B \cdot (A - c)) \pm \sqrt{(2(B \cdot (A - c)))^2 - 4||B||^2 (||A - c||^2 - r^2)}}{2||B||} \\
* ||A||^2 = 1, so \\
* t = -(B * (A - c)) \pm \sqrt{(B \cdot (A - c))^2 - ||A - c||^2 + r^2)}
* \f]
*	- if the sqrt value \f$ (B \cdot (A - c))^2 - ||A - c||^2 + r^2) < 0\f$ equation cannot be solved, thus Ray is not intersecting with a Sphere
*	- if it's equal to \f$ 0 \f$ there is only one solution - the Ray intersects with a Sphere in one spot
*	- if it's more than zero the Ray intersects with the Spehere in two spots
* @param ray - radius of a sphere
* @param distance - length to hit point
* @return Bool - tells us whether it intersects or not
*/
bool Sphere::HitTest(Ray ray, float& distance, Vector& normal)
{
	float t;
	Vector vectorDistance = ray.Origin() - this->Center_;
	float a = ray.Direction().LenghtSquared();
	float b = (vectorDistance * 2).Dot(ray.Direction());
	float c = vectorDistance.LenghtSquared() - this->Radius_ * this->Radius_;
	float disc = b * b - 4 * a * c;

	if (disc < 0)
	{
		return false;
	}
	
	float discSq = std::sqrtf(disc);
	float denom = 2 * a;

	t = (-b - discSq) / denom;

	if (t < Epsilon)
	{
		t = (-b + discSq) / denom;
	}

	if (t < Epsilon)
	{
		return false;
	}

	Vector hitPoint = ray.Origin() + ray.Direction() * t;
	normal = (hitPoint - this->Center_).NormalizeProduct();
	distance = t;

	return true;
}

std::ostream& operator<<(std::ostream& os, const Sphere& sph)
{
	os << "Sphere(" << sph.Center_ << "," << std::to_string(sph.Radius_) << ")";
	return os;
}
