#pragma once

#include "pch.h"
#include "Vector.h"
#include "Color.h"
#include "Sampler.h"

//! PointLight class which create point light in scene
class PointLight
{
public:
	//PointLight();
	PointLight(Vector position, Color color);
	PointLight(Vector center, Color color, std::shared_ptr<Sampler> sampler, double radius);

	Vector Sample();
	Vector RemapSampleToUnitSphere(Vector2 sample);

	Vector Center() const { return Center_; }
	void Center(Vector v) { Center_ = v; }
	Color LightColor() const { return LightColor_; }
	void LightColor(Color c) { LightColor_ = c; }
	float Radius() const { return Radius_; }
	void Radius(float r) { Radius_ = r; }

private:
	Vector Center_;
	Color LightColor_;
	std::shared_ptr<Sampler> LightSampler_;
	float Radius_;
};

