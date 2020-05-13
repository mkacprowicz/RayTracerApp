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
/**
* The part of the light beam that is not reflected passes through the boundary plane and propagates further into the new center. 
* The resulting ray is defined as a refracted ray.
* The phenomenon of light passing through the surface separating two different media is called refraction. 
* Refraction consists in changing the direction of wave propagation associated with changing its speed. 
* Consequently, this causes a change in wavelength at a constant frequency. The fact that the light can propagate in a given medium indicates its transparency.
* The law of physics describing the change in the direction of the light beam when passing through the border between two transparent 
* centers with different refractive indexes is called Snell's law. This law says that the incident and refracted radius and the perpendicular incident (normal)
* lie in one plane, and the angles meet the condition:
* \f[ 
*  \frac{\sin \theta_{1}}{\sin \theta_{2}} = \frac{n_2}{n_1}
* \f]
* It should be noted that Snell's law describes the geometrical relationships that occur between the directions of rays in a complete manner only for homogeneous media.
* In the case of the anisotropic surfaces mentioned above, the light ray may separate into two rays.
* As in the case of a mirror reflection, in order to reproduce the phenomenon of refraction, a new radius must be taken from the point of intersection.
* The direction of this radius will of course depend on the angle of incidence relative to the normal vector of the surface at the intersection 
* and the refractive indexes of both centers. To calculate the secondary ray directional vector, we can use the basic trigonometric identities and the Snell's law presented:
* \f[
* \lambda_{s} \sin \theta = \lambda_{t} \sin \phi \\
* \sin^{2} \phi + cos^{2} \phi = 1 \\
* \cos^{2} \phi = 1 - \frac{\lambda^{2}_{s} (1 - \cos^{2} \theta)}{\lambda^{2}_{t}} \\
* t = b \sin \phi - n \cos \phi \\
* d = b \sin \theta - n \cos \theta \\
* b = \frac{d + n \cos \theta}{\sin \theta} \\
* t = \frac{\sin \phi (d+n \cos \theta)}{\sin \theta} - n \cos \phi = \frac{\lambda_{s} (d+n \cos \theta)}{\lambda_{t}} - n \cos \phi = \frac{\lambda_{s} (d-n(d \cdot n))}{\lambda_t} - n \sqrt{1 - \frac{\lambda_{s}^{2}(1 - (d \cdot n)^{2})}{\lambda^{2}_{t}}}
* \f]
* As a result of refraction, surrounding objects immediately behind the bending medium of light rays are distorted.
* @param tracer - Raytracer object
* @param hit - info about hit of a ray
* @returns Color object
*/
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