#include "PerfectDiffuse.h"

PerfectDiffuse::PerfectDiffuse()
{
	this->MaterialColor_ = Color(0, 0, 0);
}

PerfectDiffuse::PerfectDiffuse(Color rgb)
{
	this->MaterialColor_ = rgb;
}

PerfectDiffuse::PerfectDiffuse(Color rgb, std::shared_ptr<Texture> texture)
{
	this->MaterialColor_ = rgb;
	this->MaterialTexture = texture;
}

Color PerfectDiffuse::Shade(std::shared_ptr<ImageRT> tracer, std::shared_ptr<HitInfo> hit)
{
	Color totalColor(0, 0, 0);

	for (auto light : hit->CurrentWorld()->Lights())
	{
		Vector lightPos = light->Sample();
		Vector inDirection = (lightPos - hit->HitPoint()).NormalizeProduct();
		float diffuseFactor = inDirection.Dot(hit->Normal());

		if (diffuseFactor < 0)
		{
			continue;
		}

		if (hit->CurrentWorld()->AnyObstacleBetween(hit->HitPoint(), lightPos))
		{
			continue;
		}

		Color temp = light->LightColor() * this->MaterialColor_ * diffuseFactor;
		totalColor = totalColor + temp;

		if (IsTextured())
		{
			Color temp = this->MaterialTexture->GetTexelColor(this->UV);
			totalColor = temp;
		}
	}

	return totalColor;
}
