#include "OrthonormalBasis.hpp"

OrthonormalBasis::OrthonormalBasis(Vector eye, Vector lookAt, Vector up)
{
	this->w = eye - lookAt;
	this->w.Normalize();
	this->u = up.Cross(w);
	this->u.Normalize();
	this->v = w.Cross(u);
}

Vector OrthonormalBasis::operator*(Vector v)
{
	return (this->u * v.X + this->v * v.Y + this->w * v.Z);
}
