#pragma once
#include "pch.h"
#include "Material.h"
#include "Phong.h"

class Reflective : public Material
{
public:
	Reflective(Color materialColor, float diffuse, float specular, float exponent, float reflectivity);

	Color Shade(std::shared_ptr<ImageRT> tracer, std::shared_ptr<HitInfo> hit);

	Color ReflectionColor() const { return ReflectionColor_; }
	void ReflectionColor(Color c) { ReflectionColor_ = c; }
	float Reflectivity() const { return Reflectivity_; }
	void Reflectivity(float r) { Reflectivity_ = r; }

private:
	std::shared_ptr<Phong> Direct_;
	float Reflectivity_;
	Color ReflectionColor_;
};

