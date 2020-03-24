#pragma once
#include "Camera.h"
class PerspectiveCamera :
	public Camera
{
public :
	Ray GetRay(float u, float v);
	void Render();
};