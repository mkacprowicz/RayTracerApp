#pragma once

#include "pch.h"
#include "Material.h"

//! Phong class is a representation of the Phong model
class Phong : public Material
{
public:
	Phong();
	Phong(Color materialColor, float diffuseCoeff, float specular, float specularExponent);
	Phong(Color materialColor, float diffuseCoeff, float specular, float specularExponent, std::shared_ptr<Texture> texture);

	Color Shade(std::shared_ptr<ImageRT> tracer, std::shared_ptr<HitInfo> hit);
	float PhongFactor(Vector inDirection, Vector normal, Vector toCameraDirection);


	Color MaterialColor() const { return MaterialColor_; }
	void MaterialColor(Color c) { MaterialColor_ = c; }
	float DiffuseCoeff() const { return DiffuseCoeff_; }
	void DiffuseCoeff(float d) { DiffuseCoeff_ = d; }
	float Specular() const { return Specular_; }
	void Specular(float s) { Specular_ = s; }
	float SpecularExponent() const { return SpecularExponent_; }
	void SpecularExponent(float se) { SpecularExponent_ = se; }

private:
	Color MaterialColor_;
	float DiffuseCoeff_;
	float Specular_;
	float SpecularExponent_;
};

