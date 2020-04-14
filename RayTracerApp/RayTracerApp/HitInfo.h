#pragma once
#include "pch.h"
#include "GeometricShape.h"

class World;


//! Hitinfo class that represents infomation after hit ray in objects.
class HitInfo
{
public:
	HitInfo();

	std::shared_ptr<GeometricShape> HitObject() const { return HitObject_; }
	void HitObject(std::shared_ptr<GeometricShape> h) { HitObject_ = h; }
	std::shared_ptr<World> CurrentWorld() const { return CurrentWorld_; }
	void CurrentWorld(std::shared_ptr<World> w) { CurrentWorld_ = w; }
	Vector Normal() const { return Normal_; }
	void Normal(Vector n) { Normal_ = n; }
	Vector HitPoint() const { return HitPoint_; }
	void HitPoint(Vector h) { HitPoint_ = h; }
	Ray HitRay() const { return HitRay_; }
	void HitRay(Ray r) { HitRay_ = r; }
	int Depth() const { return Depth_; }
	void Depth(int d) { Depth_ = d; }

private:
	std::shared_ptr<GeometricShape> HitObject_;
	std::shared_ptr<World> CurrentWorld_;
	Vector Normal_;
	Vector HitPoint_;
	Ray HitRay_;
	int Depth_;
};

