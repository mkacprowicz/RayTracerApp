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

/**
* Phong model can be represented as given formula:
* \f[
* I_{out} = I_{in}(k_d (L \cdot N ) k_s (R \cdot V)^{n} )
* \f]
* where \f$L\f$ is the vector towards the light source, \f$V\f$ towards the observer, 
* \f$N\f$ is normal to the surface and \f$R\f$ is the reflection direction. \f$k_d\f$ and \f$k_s\f$ respectively, 
* reflection coefficients and diffuse reflection coefficient, \f$n\f$ reflection flare.
* As we are currently considering only direct lighting, we will save the Phong lighting model as:
* \f[
* L_{o} = L_{i}(k_d (L \cdot N ) k_s (R \cdot V)^{n} )
* \f]
* where \f$L_o\f$ is the intensity reflected to the observer and \f$L_i\f$ is the intensity from the light source.
* By writing this equation using the BRDF function, we get:
* \f[
* L_o = L_i Refl(w_i, w_o) \\
* L_o = Refl(w_i, w_o)L_i \\
* L_o = \frac{cos\theta_i dw_i}{cos\theta_i dw_i} Refl(w_i, w_o)L_i \\
* L_o = \frac{Refl(w_i, w_o)}{cos\theta_i dw_i}L_i cos\theta_i dw_i
* \f]
* The Phong lighting model can be considered as a special case of BRDF,
* used for materials with reflective properties approximated by:
* \f[
* BRDF(\theta_i, \phi_i, \theta_o, \phi_o) = \frac{Refl(w_i, w_o)}{cos\theta_i dw_i} \\
* BRDF(\theta_i, \phi_i, \theta_o, \phi_o) = \frac{k_d (w_i \times N) + k_s (R \times w_o)^n}{cos\theta_i dw_i}
* \f]
* @param tracer - custom raytracer object
* @param hit - info about ray hitting an object
* @return Color object
*/
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
