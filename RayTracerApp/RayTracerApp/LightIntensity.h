#pragma once

#include "pch.h"

//! LightIntensity class that represents light intensiti for a color in RGB colorspace.
/**
* This class represents ambient light intensity in RGB colorspace. 
* It has no position, and it's the same for every object in a virtual scene. 
*/
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
	float A() const { return A_; }
	void A(float a) { A_ = a; }

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
	float A_;
};

