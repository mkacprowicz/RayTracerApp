#include "Phong.h"

Phong::Phong()
{
	this->MaterialColor_ = Color(0, 0, 0);
	this->DiffuseCoeff_ = 0;
	this->Specular_ = 0;
	this->SpecularExponent_ = 0;
}

Phong::Phong(Color materialColor, float diffuseCoeff, float specular, float specularExponent)
{
	this->MaterialColor_ = materialColor;
	this->DiffuseCoeff_ = diffuseCoeff;
	this->Specular_ = specular;
	this->SpecularExponent_ = specularExponent;
}

Color Phong::Shade(std::shared_ptr<ImageRT> tracer, std::shared_ptr<HitInfo> hit)
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

		Color result = light->LightColor() * this->MaterialColor_ * diffuseFactor * this->DiffuseCoeff_;
		float phongFactor = PhongFactor(inDirection, hit->Normal(), -hit->HitRay().Direction());

		if (phongFactor != 0)
		{
			Color temp = this->MaterialColor_ * this->Specular_ * phongFactor;
			result = result + temp;
		}

		totalColor = totalColor + result;
	}

	return totalColor;
}

float Phong::PhongFactor(Vector inDirection, Vector normal, Vector toCameraDirection)
{
	Vector reflected = inDirection.ReflectProduct(inDirection, normal);
	float cosAngle = reflected.Dot(toCameraDirection);

	if (cosAngle <= 0)
	{
		return 0;
	}

	return std::powf(cosAngle, this->SpecularExponent_);
}
