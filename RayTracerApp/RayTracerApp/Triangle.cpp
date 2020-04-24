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

Triangle::Triangle(Vector vertexa, Vector vertexb, Vector vertexc, std::shared_ptr<Material> mat)
{
	this->ShapeMaterial_ = mat;
	this->VertexA = vertexa;
	this->EdgeAB = vertexb - vertexa;
	this->EdgeAC = vertexc - vertexa;

	this->NormalA = this->EdgeAB.Cross(this->EdgeAC).NormalizeProduct();
	this->NormalAB = Vector();
	this->NormalAC = Vector();
}

Triangle::Triangle(Vector vertexa, Vector vertexb, Vector vertexc, Vector normala, Vector normalb, Vector normalc, std::shared_ptr<Material> mat)
{
	this->ShapeMaterial_ = mat;
	this->VertexA = vertexa;
	this->EdgeAB = vertexb - vertexa;
	this->EdgeAC = vertexc - vertexa;

	this->NormalA = normala;
	this->NormalAB = normalb - normala;
	this->NormalAC = normalc - normala;
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
bool Triangle::HitTest(Ray ray, float& distance, Vector& normal)
{
	Vector pVec = ray.Direction().Cross(this->EdgeAC);
	float determinant = pVec.Dot(this->EdgeAB);

	if (determinant < Epsilon)
	{
		return false;
	}

	float invDet = 1 / determinant;

	Vector aVec = ray.Origin() - this->VertexA;
	Vector bVec = aVec.Cross(this->EdgeAB);

	float u = aVec.Dot(pVec) * invDet;
	float v = ray.Direction().Dot(bVec) * invDet;

	if (u < 0 || v < 0 || u + v > 1)
	{
		return false;
	}

	normal = this->NormalA + this->NormalAB * u + this->NormalAC * v;
	distance = this->EdgeAC.Dot(bVec) * invDet;

	return true;
}
