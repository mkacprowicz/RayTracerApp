#pragma once
#include "Camera.h"
class OrtoCamera :
	public Camera
{
public:
	Ray GetRay(float u, float v);
	void Render();
};

