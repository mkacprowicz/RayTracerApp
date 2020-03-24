#pragma once
#include "Camera.h"

//! Camera is a class which is a representation of a ortographic camera
class OrtoCamera :
	public Camera
{
public:
	Ray GetRay(float u, float v);
	void Render();
};

