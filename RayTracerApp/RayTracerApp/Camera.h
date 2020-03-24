#pragma once

#include "pch.h"
#include "Vector.h"
#include "Ray.h"

class Camera
{
public:
	Camera();

	virtual Ray GetRay(float u, float v) = 0;

	virtual void Render() = 0;

	Vector Origin() const { return Origin_; }
	void Origin(Vector position) { Origin_ = position; }

protected:
	Vector Origin_;
	Vector LowerLeftCorner_;
	Vector Horizontal_;
	Vector Vertical_;
};

