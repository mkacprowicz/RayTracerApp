#include "PointLight.h"

//PointLight::PointLight()
//{
//	this->Position_ = Vector(0, 0, 0);
//	this->LightColor_ = Color(0, 0, 0);
//}
//
//PointLight::PointLight(Vector pos, Color rgb)
//{
//	this->Position_ = pos;
//	this->LightColor_ = rgb;
//}

PointLight::PointLight(Vector position, Color color)
{
	this->Center_ = position;
	this->LightColor_ = color;
	this->LightSampler_ = nullptr;
	this->Radius_ = 0;
}

PointLight::PointLight(Vector center, Color color, std::shared_ptr<Sampler> sampler, double radius)
{
	this->Center_ = center;
	this->LightColor_ = color;
	this->LightSampler_ = sampler;
	this->Radius_ = radius;
}

Vector PointLight::Sample()
{
	if (this->Radius_ == 0)
	{
		return this->Center_;
	}

	Vector2 sample = this->LightSampler_->Single();

	Vector result = this->Center_;
	Vector temp = RemapSampleToUnitSphere(sample) * this->Radius_;

	result = result + temp;

	return result;
}

Vector PointLight::RemapSampleToUnitSphere(Vector2 sample)
{
	float z = 2 * sample.X() - 1;
	float t = 2 * M_PI * sample.Y();
	float r = std::sqrtf(1 - z * z);

	return Vector(r * std::cosf(t), r * std::sinf(t), z);
}