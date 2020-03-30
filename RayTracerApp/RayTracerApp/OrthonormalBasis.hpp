#pragma once
#include "Vector.h"
class OrthonormalBasis
{
private:
	Vector u;
	Vector v;
	Vector w;

public:
	OrthonormalBasis(Vector eye, Vector lookAt, Vector up);
	Vector operator*(Vector v);

};

