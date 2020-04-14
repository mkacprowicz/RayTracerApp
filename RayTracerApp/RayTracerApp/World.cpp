#include "World.h"

World::World()
{
	Objects_.clear();
	Lights_.clear();
	BackgroundColor_(0, 0, 0);
}

World::World(Color background)
{
	Objects_.clear();
	BackgroundColor_ = background;
}

void World::AddObject(std::shared_ptr<GeometricShape> object)
{
	this->Objects_.push_back(object);
}

void World::AddLight(std::shared_ptr<PointLight> light)
{
	this->Lights_.push_back(light);
}

std::shared_ptr<HitInfo> World::TraceRay(Ray ray)
{
	std::shared_ptr<HitInfo> result = std::make_shared<HitInfo>();
	Vector normal;

	float minimalDistance = Huge;
	float lastDistance = 0;

	for (auto obj : this->Objects_)
	{
		if (obj->HitTest(ray, lastDistance, normal) && lastDistance < minimalDistance)
		{
			minimalDistance = lastDistance;
			result->HitObject(obj);
			result->Normal(normal);
		}
	}

	if (result->HitObject() != nullptr)
	{
		result->HitPoint(ray.Origin() + ray.Direction() * minimalDistance);
		result->HitRay(ray);
		result->CurrentWorld(shared_from_this());
	}

	return result;
}

bool World::AnyObstacleBetween(Vector pointA, Vector pointB)
{
	Vector vectorAB = pointB - pointA;
	float distAB = vectorAB.Lenght();
	float currDistance = Huge;

	Ray ray(pointA, vectorAB);

	Vector ignored;

	for (auto obj : this->Objects_)
	{
		if (obj->HitTest(ray, currDistance, ignored) && currDistance < distAB)
		{
			return true;
		}
	}

	return false;
}
