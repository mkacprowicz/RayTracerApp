#pragma once

#include "pch.h"
#include "Ray.h"

class Material;

class GeometricShape
{
public:
	GeometricShape() {};

	virtual bool HitTest(Ray ray, float& distance, Vector& normal) = 0;

	std::shared_ptr<Material> ShapeMaterial() const { return ShapeMaterial_;  }
	void ShapeMaterial(std::shared_ptr<Material> m) { ShapeMaterial_ = m; }

protected:
	std::shared_ptr<Material> ShapeMaterial_;
};

