#include "Triangle.h"

Triangle::Triangle()
{
	this->A_ = Vector::Zero();
	this->B_ = Vector::Zero();
	this->C_ = Vector::Zero();
}

Triangle::Triangle(Vector a, Vector b, Vector c)
{
	this->A_ = a;
	this->B_ = b;
	this->C_ = c;
}

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
