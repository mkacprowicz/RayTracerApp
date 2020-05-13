#include "Transparent.h"

#include "ImageRT.h"

Transparent::Transparent(Color color, float diffuse, float specular, float exponent, float reflection, float refraction, float transmission)
{
	this->Direct_ = std::make_shared<Phong>(color, diffuse, specular, exponent);
	this->Transmission_ = transmission;
	this->BaseColor_ = color;
	this->Reflection_ = reflection;
	this->Refraction_ = refraction;
	this->Specular_ = specular;
}

Color Transparent::Shade(std::shared_ptr<ImageRT> tracer, std::shared_ptr<HitInfo> hit)
{
	Color finalColor = this->Direct_->Shade(tracer, hit);

	Vector toCameraDirection = (-1) * hit->HitRay().Direction();
	float cosIncidentAngle = hit->Normal().Dot(toCameraDirection);
	float eta = cosIncidentAngle > 0 ? this->Refraction_ : (1 / this->Refraction_);
	float refractionCoeff = FindRefractionCoeff(eta, cosIncidentAngle);

	Ray reflectedRay(hit->HitPoint(), toCameraDirection.Reflect(hit->Normal()));
	Color reflectionColor = this->BaseColor_ * this->Reflection_;

	if (IsTotalInternalReflection(refractionCoeff))
	{
		Color temp = tracer->ShadeRay(hit->CurrentWorld(), reflectedRay, hit->Depth());
		finalColor = finalColor + temp;
	}
	else
	{
		Ray transmittedRay = ComputeTransmissionDirection(hit->HitPoint(), toCameraDirection, hit->Normal(), eta, std::sqrtf(refractionCoeff), cosIncidentAngle);
		Color transmissionColor = ComputeTransmissionColor(eta, hit->Normal(), transmittedRay.Direction());

		Color temp = reflectionColor;// *tracer->ShadeRay(hit->CurrentWorld(), reflectedRay, hit->Depth());
		Color temp2 = tracer->ShadeRay(hit->CurrentWorld(), reflectedRay, hit->Depth());
		temp = temp * temp2;
		finalColor = finalColor + temp;

		temp = transmissionColor;// *tracer->ShadeRay(hit->CurrentWorld(), transmittedRay, hit->Depth());
		temp2 = tracer->ShadeRay(hit->CurrentWorld(), transmittedRay, hit->Depth());
		temp = temp * temp2;

		finalColor = finalColor + temp;
	}

	return finalColor;
}

bool Transparent::IsTotalInternalReflection(float refractionCoeff)
{
	return refractionCoeff < 0;
}

float Transparent::FindRefractionCoeff(float eta, float cosIncidentAngle)
{
	return 1 - (1 - cosIncidentAngle * cosIncidentAngle) / (eta * eta);
}

Ray Transparent::ComputeTransmissionDirection(Vector hitPoint, Vector toCameraDirection, Vector normal, float eta, float cosTransmittedAngle, float cosIncidentAngle)
{
	if (cosIncidentAngle < 0)
	{
		normal = (-1) * normal;
		cosIncidentAngle = (-1) * cosIncidentAngle;
	}

	Vector direction = ((-1) * toCameraDirection) / eta - normal * (cosTransmittedAngle - cosIncidentAngle / eta);

	return Ray(hitPoint, direction);
}

Color Transparent::ComputeTransmissionColor(float eta, Vector normal, Vector transmissionDirection)
{
	return ((Color(255,255,255) * this->Transmission_) / (eta * eta));
}