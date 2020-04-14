#include "Sampler.h"

Sampler::Sampler(std::shared_ptr<SampleGenerator> sampler, std::shared_ptr <SampleDistributor> mapper, int sampleCt, int setCt)
{
	this->Sets_ = std::vector<std::vector<Vector2>>(setCt);
	this->SampleCount_ = sampleCt;

	this->RandomGenerator = std::mt19937_64(this->RandomDevice());

	this->SampleNdx_ = 0;
	this->SetNdx_ = 0;

	this->Sets_.clear();

	for (auto i = 0; i < setCt; i++)
	{
		auto samples = sampler->Sample(sampleCt);

		std::vector<Vector2> mappedSamples;

		for (auto obj : samples)
		{
			mappedSamples.push_back(mapper->MapSample(obj));
		}

		this->Sets_.push_back(mappedSamples);
	}

	int stopit = 5;
}

Vector2 Sampler::Single()
{
	Vector2 sample = this->Sets_[this->SetNdx_][this->SampleNdx_];

	this->SampleNdx_++;

	if (this->SampleNdx_ >= this->Sets_[this->SetNdx_].size())
	{
		this->SampleNdx_ = 0;

		int tempSize = this->Sets_.size();

		if (tempSize > 1)
		{
			tempSize -= 1;

			this->Random = std::uniform_int_distribution<int>(0, tempSize);

			this->SetNdx_ = Random(RandomGenerator);
		}
		else
		{
			this->SetNdx_ = 0;
		}	
	}

	return sample;
}
