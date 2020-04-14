#include "Triangle.h"

Triangle::Triangle()
{
	this->A_ = Vector::Zero();
	this->B_ = Vector::Zero();
	this->C_ = Vector::Zero();
}
/**
* Constructor that creates triangle with 3 vertices
* @param a - first vertex
* @param b - second vertex
* @param c - third vertex
* @return Triangle object
*/
Triangle::Triangle(Vector a, Vector b, Vector c)
{
	this->A_ = a;
	this->B_ = b;
	this->C_ = c;
}

/**
* Triangle intersection is based on three steps:
* 1. finding vectors from the intersection to each of the vertices, i.e. \f$PA\f$ \f$PB\f$  \f$PC\f$
* 2. checking if the angle between the \f$PA-PB, PB-PC, PC-PA\f$ vectors is smaller than \f$\pi\f$
* 3. if all angles are smaller then point P lies inside the triangle
* We determine angle between individual pairs of vectors vector from the vector product containing 
* the sine of the angle and instead of comparing it with the angle \f$\pi\f$ we check its scalar product from the normal triangle.
* A triangle normal vector is nothing more than a vector product of two non-parallel vectors from the plane. 
* By using the points from the triangle, using them clockwise, the normal vector will have the following form:
* \f[
* n = (b - a) \times (c - a)
* \f]
*/
bool Triangle::Intersection(Ray ray, float& t0, float& t1)
{
	Vector e1 = this->B_ - this->A_;
	Vector e2 = this->C_ - this->A_;
	Vector dir = ray.Direction();
	Vector ori = ray.Origin();
	Vector pVect = dir.Cross(e2);
	float det = e1.Dot(pVect);
	float invDet = 1 / det;

	if (det < 0.0000001f)
	{
		return false;
	}

	Vector tVect = ori - this->A_;
	float u = tVect.Dot(pVect) * invDet;

	if (u < 0.0f || u > 1)
	{
		return false;
	}
	
	Vector qVect = tVect.Cross(e1);

	float v = dir.Dot(qVect) * invDet;

	if (v < 0 || u + v > 1)
	{
		return false;
	}

	t0 = e2.Dot(qVect) * invDet;

	return true;
}

bool Triangle::HitTest(Ray ray, float& distance, Vector& normal)
{
	return false;
}
