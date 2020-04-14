#pragma once
#include "pch.h"
#include "SampleDistributor.h"
class SquareDistributor :
	public SampleDistributor
{
	Vector2 MapSample(Vector2 sample);
};

