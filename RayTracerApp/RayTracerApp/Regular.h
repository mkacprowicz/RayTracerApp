#pragma once
#include "pch.h"
#include "SampleGenerator.h"

class Regular :public SampleGenerator
{
	std::vector<Vector2> Sample(int count);
};

