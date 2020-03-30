#pragma once
#include "Camera.h"
#include "OrthonormalBasis.hpp"

//! Camera is a class which is a representation of a ortographic camera
class OrtoCamera :
	public Camera
{
public:
	OrtoCamera() {};
	OrtoCamera(Vector origin, Vector lookAt, Vector up, float distance);
	Ray GetRay(float u, float v);
	void Render();
	Vector RayDirection(float u, float v);

private:
	OrthonormalBasis onb_;
	float distance_;
};

