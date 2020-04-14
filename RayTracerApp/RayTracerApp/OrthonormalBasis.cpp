#include "OrthonormalBasis.hpp"


/**
* We use orthonormal bases (ONB) in raytracing wherever we need a local coordinate system. The ONB can be constructed
* from any two vectors \f$a\f$ and \f$b\f$ (they need not be mutually perpendicular or normalized).
* The first step is to create a vector \f$w\f$ - it is a normalized vector parallel to \f$a\f$.
* Then the vector \f$u\f$ is calculated as the normalized vector product \f$b \times w\f$.
* Ultimately v is equal \f$w \times u\f$ thus creating a clockwise coordinate system:
* \f[
* w = \frac{a}{||a||} \\
* u = \frac{(b \times w)}{||b \times w||} \\
* v = w \times u
* \f]
*/
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
	return (this->u * v.X() + this->v * v.Y() + this->w * v.Z());
}
