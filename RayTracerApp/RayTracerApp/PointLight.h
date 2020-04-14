#pragma once

#include "pch.h"
#include "Vector.h"
#include "Color.h"


//! PointLight class which create point light in scene
class PointLight
{
public:
	PointLight();
	PointLight(Vector pos, Color rgb);

	Vector Position() const { return Position_; }
	void Position(Vector v) { Position_ = v; }
	Color LightColor() const { return LightColor_; }
	void LightColor(Color c) { LightColor_ = c; }

private:
	Vector Position_;
	Color LightColor_;
};

