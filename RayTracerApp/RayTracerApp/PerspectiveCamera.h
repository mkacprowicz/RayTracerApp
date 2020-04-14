#pragma once
#include "Camera.h"
#include "OrthonormalBasis.hpp"

//! PerspectiveCamera is a class which is a representation of a perspective camera
class PerspectiveCamera :
	public Camera
{
public:
	PerspectiveCamera() {};
	PerspectiveCamera(Vector origin, Vector lookAt, Vector up, float distance);
	Ray GetRay(Vector2 uv);
	Vector RayDirection(Vector2 v);

	OrthonormalBasis Onb() const { return Onb_; }
	void Onb(OrthonormalBasis o) { Onb_ = o; }
	Vector Origin() const { return Origin_; }
	void Origin(Vector o) { Origin_ = o; }
	float Distance() const { return Distance_; }
	void Distance(float d) { Distance_ = d; }

private:
	OrthonormalBasis Onb_;
	Vector Origin_;
	float Distance_;
};