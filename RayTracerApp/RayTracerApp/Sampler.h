#pragma once
#include "pch.h"
#include "Vector.h"
#include "SampleDistributor.h"
#include "SampleGenerator.h"

//! Sampler class which is a class to organising samples for antyaliasing
class Sampler
{
public:
	Sampler(std::shared_ptr<SampleGenerator> sampler, std::shared_ptr <SampleDistributor> mapper, int sampleCt, int setCt);

	Vector2 Single();

	int SampleNdx() const { return SampleNdx_; }
	void SampleNdx(int s) { SampleNdx_ = s; }
	int SetNdx() const { return SetNdx_; }
	void SetNdx(int s) { SetNdx_ = s; }
	int SampleCount() const { return SampleCount_; }
	void SampleCount(int s) { SampleCount_ = s; }

	int SetCount() const { return Sets_.size();  }

	std::random_device RandomDevice;
	std::mt19937_64 RandomGenerator;
	std::uniform_int_distribution<int> Random;

private:

	std::vector<std::vector<Vector2>> Sets_;
	int SampleNdx_;
	int SetNdx_;
	int SampleCount_;
};