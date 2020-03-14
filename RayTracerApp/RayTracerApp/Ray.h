#pragma once
#include "pch.h"
#include "Vector.h"

class Ray
{
public:
	Ray();
	Ray(Vector o, Vector d);

	Vector Origin() const { return Origin_; }
	void Origin(Vector o) { Origin_ = o; }
	Vector Destination() const { return Destination_; }
	void Destination(Vector d) { Destination_ = d; }
	Vector Direction() const { return Direction_; }
	void Direction(Vector d) { Direction_ = d; }
	float Distance() const { return Distance_; }
	void Distance(float d) { Distance_ = d; }

private:
	Vector Origin_;
	Vector Destination_;
	Vector Direction_;
	float Distance_;
};

