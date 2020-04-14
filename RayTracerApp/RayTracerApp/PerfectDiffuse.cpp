#include "PerfectDiffuse.h"

PerfectDiffuse::PerfectDiffuse()
{
	this->MaterialColor_ = Color(0, 0, 0);
}

PerfectDiffuse::PerfectDiffuse(Color rgb)
{
	this->MaterialColor_ = rgb;
}

Color PerfectDiffuse::Shade(std::shared_ptr<ImageRT> tracer, std::shared_ptr<HitInfo> hit)
{
	Color totalColor(0, 0, 0);

	for (auto light : hit->CurrentWorld()->Lights())
	{
		Vector inDirection = (light->Position() - hit->HitPoint()).NormalizeProduct();
		float diffuseFactor = inDirection.Dot(hit->Normal());

		if (diffuseFactor < 0)
		{
			continue;
		}

		if (hit->CurrentWorld()->AnyObstacleBetween(hit->HitPoint(), light->Position()))
		{
			continue;
		}

		Color temp = light->LightColor() * this->MaterialColor_ * diffuseFactor;
		totalColor = totalColor + temp;
	}

	return totalColor;
}
