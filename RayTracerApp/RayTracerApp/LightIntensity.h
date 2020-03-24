#pragma once

#include "pch.h"

class LightIntensity
{
public:
	LightIntensity(float r, float g, float b);
	LightIntensity(float r, float g);
	LightIntensity(float r);
	LightIntensity();

	void Add(float r, float g, float b);

	float R() const { return R_; }
	void R(float r) { R_ = r; }
	float G() const { return G_; }
	void G(float g) { G_ = g; }
	float B() const { return B_; }
	void B(float b) { B_ = b; }

	void operator()(float r, float g, float b) { R_ = r; G_ = g; B_ = b; }
	void operator()(float r, float g) { R_ = r; G_ = g; B_ = 0.0f; }
	void operator()(float r) { R_ = r; G_ = B_ = 0.0f; }
	void operator+=(LightIntensity& li);
	LightIntensity operator/(float num);
	LightIntensity operator+(LightIntensity& li);
	LightIntensity operator-(LightIntensity& li);	
	LightIntensity operator-=(LightIntensity& li);
	LightIntensity operator*=(LightIntensity& li);
	LightIntensity operator/=(LightIntensity& li);
	LightIntensity operator*(float num);
	LightIntensity operator*(LightIntensity &li);

	friend std::ostream& operator<<(std::ostream& str, LightIntensity &li);

protected:
	float R_; 
	float G_; 
	float B_;
};

