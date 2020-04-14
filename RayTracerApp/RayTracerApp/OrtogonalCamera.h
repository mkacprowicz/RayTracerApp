#pragma once
#include "Camera.h"

//! OrtogonalCamera is a class which is a representation of a ortogonal camera
class OrtogonalCamera :
	public Camera
{
public :

	OrtogonalCamera();
	OrtogonalCamera(Vector eye, float angle, Vector2 size);

	Ray GetRay(Vector2 uv);

	Vector EyePosition() const { return EyePosition_; }
	void EyePosition(Vector e) { EyePosition_ = e; }
	float Angle() const { return Angle_; }
	void Angle(float a) { Angle_ = a; }
	Vector2 CameraSize() const { return CameraSize_; }
	void CameraSize(Vector2 s) { CameraSize_ = s; }

private:
	Vector EyePosition_;
	float Angle_;
	Vector2 CameraSize_;
};