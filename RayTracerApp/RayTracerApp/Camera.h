#pragma once

#include "pch.h"
#include "Vector.h"
#include "Ray.h"

//! Camera is a pure abstract class which is a representation of a virtual camera
class Camera
{
public:
	virtual Ray GetRay(Vector2 uv) = 0;
};

