#include "Camera.h"

Camera::Camera()
{
	this->Origin_ = Vector(0.0f, 0.0f, 0.0f);
	this->LowerLeftCorner_ = Vector(-1.0f, -1.0f, -1.0f);
	this->Horizontal_ = Vector(2.0f, 0.0f, 0.0f);
	this->Vertical_ = Vector(0.0f, 2.0f, 0.0f);
}