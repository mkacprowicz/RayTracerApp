#include "Camera.h"

Camera::Camera()
{
	this->Origin_ = Vector(0.0f, 0.0f, 0.0f);
	this->LowerLeftCorner_ = Vector(-1.0f, -1.0f, -1.0f);
	this->Horizontal_ = Vector(2.0f, 0.0f, 0.0f);
	this->Vertical_ = Vector(0.0f, 2.0f, 0.0f);
}

Camera::Camera(Vector position, Vector target)
{
	/*this->Origin_ = position;
	this->Target_ = target;
	this->NearPlane_ = 1;
	this->FarPlane_ = 1000;
	this->Up_ = Vector(0.0f, 1.0f, 0.0f);*/
}

Ray Camera::GetRay(float u, float v)
{
	return Ray(this->Origin_, this->LowerLeftCorner_ + u * this->Horizontal_ + v * this->Vertical_ - this->Origin_);
}
