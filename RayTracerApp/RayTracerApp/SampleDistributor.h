#pragma once
#include "pch.h"
#include "Vector.h"

class SampleDistributor
{
public:
	virtual Vector2 MapSample(Vector2 sample) = 0;
};

