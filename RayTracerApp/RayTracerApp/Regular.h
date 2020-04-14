#pragma once
#include "pch.h"
#include "SampleGenerator.h"

//! Regular class which is a class to create regular samples
class Regular :public SampleGenerator
{
	std::vector<Vector2> Sample(int count);
};

