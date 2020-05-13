#pragma once
#include "pch.h"
#include "Material.h"
#include "Phong.h"

class Transparent : public Material
{
public:
	Transparent(Color color, float diffuse, float specular, float exponent, float reflection, float refraction, float transmission);

	Color Shade(std::shared_ptr<ImageRT> tracer, std::shared_ptr<HitInfo> hit);

	bool IsTotalInternalReflection(float refractionCoeff);
	float FindRefractionCoeff(float eta, float cosIncidentAngle);
	Ray ComputeTransmissionDirection(Vector hitPoint, Vector toCameraDirection, Vector normal, float eta, float cosTransmittedAngle, float cosIncidentAngle);
	Color ComputeTransmissionColor(float eta, Vector normal, Vector transmissionDirection);

	Color BaseColor() const { return BaseColor_; }
	void BaseColor(Color c) { BaseColor_ = c; }
	float Refraction() const { return Refraction_; }
	void Refraction(float r) { Refraction_ = r; }
	float Reflection() const { return Reflection_; }
	void Reflection(float r) { Reflection_ = r; }
	float Transmission() const { return Transmission_; }
	void Transmission(float r) { Transmission_ = r; }
	float Specular() const { return Specular_; }
	void Specular(float r) { Specular_ = r; }

private:
	std::shared_ptr<Phong> Direct_;
	float Refraction_;
	float Reflection_;
	float Transmission_;
	float Specular_;
	Color BaseColor_;
};

