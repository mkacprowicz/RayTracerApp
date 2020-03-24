#pragma once

#include "pch.h"
#include "Vector.h"

class Camera
{
public:
	Camera();
	Camera(Vector position, Vector target);

	Vector Position() const { return Position_; }
	void Position(Vector position) { Position_ = position; }
	Vector Target() const { return Target_; }
	void Target(Vector target) { Target_ = target; }
	Vector Up() const { return Up_; }
	void Up(Vector up) { Up_ = up; }
	float NearPlane() const { return NearPlane_; }
	void NearPlane(float nearPlane) { NearPlane_ = nearPlane; }
	float FarPlane() const { return FarPlane_; }
	void FarPlane(float farPlane) { FarPlane_ = farPlane; }
	float FOV() const { return FOV_; }
	void FOV(float fov) { FOV_ = fov; }

private:
	Vector Position_;
	Vector Target_;
	Vector Up_;
	float NearPlane_;
	float FarPlane_;
	float FOV_;
};

