#pragma once

#include "pch.h"
#include "Vector.h"
#include "Ray.h"

class Camera
{
public:
	Camera();
	Camera(Vector position, Vector target);

	Ray GetRay(float u, float v);

	Vector Origin() const { return Origin_; }
	void Origin(Vector position) { Origin_ = position; }
	//Vector Target() const { return Target_; }
	//void Target(Vector target) { Target_ = target; }
	//Vector Up() const { return Up_; }
	//void Up(Vector up) { Up_ = up; }
	//float NearPlane() const { return NearPlane_; }
	//void NearPlane(float nearPlane) { NearPlane_ = nearPlane; }
	//float FarPlane() const { return FarPlane_; }
	//void FarPlane(float farPlane) { FarPlane_ = farPlane; }
	//float FOV() const { return FOV_; }
	//void FOV(float fov) { FOV_ = fov; }

private:
	Vector Origin_;
	Vector LowerLeftCorner_;
	Vector Horizontal_;
	Vector Vertical_;
};

