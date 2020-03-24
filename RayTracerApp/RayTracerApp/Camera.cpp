#include "Camera.h"

Camera::Camera()
{
	this->Position_ = Vector(0.0f, 0.0f, 0.0f);
	this->Target_ = Vector(0.0f, 0.0f, 1.0f);
	this->NearPlane_ = 1;
	this->FarPlane_ = 1000;
	this->Up_ = Vector(0.0f, 1.0f, 0.0f);
}

Camera::Camera(Vector position, Vector target)
{
	this->Position_ = position;
	this->Target_ = target;
	this->NearPlane_ = 1;
	this->FarPlane_ = 1000;
	this->Up_ = Vector(0.0f, 1.0f, 0.0f);
}
