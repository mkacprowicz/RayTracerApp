#include "Reflective.h"

#include "ImageRT.h"

Reflective::Reflective(Color materialColor, float diffuse, float specular, float exponent, float reflectivity)
{
	this->Direct_ = std::make_shared<Phong>(materialColor, diffuse, specular, exponent);
	this->Reflectivity_ = reflectivity;
	this->ReflectionColor_ = materialColor;
}

Color Reflective::Shade(std::shared_ptr<ImageRT> tracer, std::shared_ptr<HitInfo> hit)
{
	Vector toCameraDirection = -hit->HitRay().Direction();

	Color radiance = this->Direct_->Shade(tracer, hit);
	Vector reflectionDirection = toCameraDirection.ReflectProduct(toCameraDirection, hit->Normal());
	Ray reflectedRay(hit->HitPoint(), reflectionDirection);

	Color temp = tracer->ShadeRay(hit->CurrentWorld(), reflectedRay, hit->Depth()) * this->ReflectionColor_ * this->Reflectivity_;
	radiance = radiance + temp;

	return radiance;
}
