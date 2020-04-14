#pragma once

#include "pch.h"
#include "GeometricShape.h"
#include "Sphere.h"
#include "HitInfo.h"
#include "PointLight.h"

class World : public std::enable_shared_from_this<World>
{
public:
	World();
	World(Color background);

	void AddObject(std::shared_ptr<GeometricShape> object);
	void AddLight(std::shared_ptr<PointLight> light);
	std::shared_ptr<HitInfo> TraceRay(Ray ray);

	bool AnyObstacleBetween(Vector pointA, Vector pointB);

	Color BackgroundColor() const { return BackgroundColor_; }
	void BackgroundColor(Color c) { BackgroundColor_ = c; }

	std::vector<std::shared_ptr<PointLight>> Lights() const { return Lights_; }

private:
	std::vector<std::shared_ptr<GeometricShape>> Objects_;
	std::vector<std::shared_ptr<PointLight>> Lights_;
	Color BackgroundColor_;
};

