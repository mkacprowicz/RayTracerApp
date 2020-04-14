#include "PointLight.h"

PointLight::PointLight()
{
	this->Position_ = Vector(0, 0, 0);
	this->LightColor_ = Color(0, 0, 0);
}

PointLight::PointLight(Vector pos, Color rgb)
{
	this->Position_ = pos;
	this->LightColor_ = rgb;
}
