#pragma once
#include "pch.h"
#include "Vector.h"

class SampleGenerator
{
public:
	virtual std::vector<Vector2> Sample(int count) = 0;
};

