#include "OrtogonalCamera.h"

/**
* Function that creates a Ray from a camera
* @param u - horizontal offset
* @param v - vertical offset
* @return Ray object
*/

OrtogonalCamera::OrtogonalCamera()
{
	this->EyePosition_ = Vector::Zero();
	this->Angle_ = 0;
	this->CameraSize_ = Vector2(1.0f, 1.0f);
}
OrtogonalCamera::OrtogonalCamera(Vector eye, float angle, Vector2 size)
{
	this->EyePosition_ = eye;
	this->Angle_ = angle;
	this->CameraSize_ = size;
}

Ray OrtogonalCamera::GetRay(Vector2 uv)
{
	Vector direction(std::sin(this->Angle_), 0, std::cos(this->Angle_));
	direction = direction.NormalizeProduct();

	Vector2 offsetFromCenter(uv.X() * this->CameraSize_.X(), uv.Y() * this->CameraSize_.Y());

	Vector position(this->EyePosition_.X() + offsetFromCenter.X() * std::cos(this->Angle_), this->EyePosition_.Y() + offsetFromCenter.Y(), this->EyePosition_.Z() + offsetFromCenter.X() * std::sin(this->Angle_));

	return Ray(position, direction);
}