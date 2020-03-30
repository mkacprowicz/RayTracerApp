#pragma once

#include "pch.h"
#include "Ray.h"
#include "Vector.h"

class Shape
{
public:
	Shape() {};

	virtual bool Intersection(Ray ray, float &t0, float &t1) = 0;

	Vector Position() const { return Position_; }
	void Position(Vector p) { Position_ = p; }

protected:
	Vector Position_;
};

