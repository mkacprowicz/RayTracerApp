#include "Reflective.h"

#include "ImageRT.h"
/**
* Constructor for Reflective class
*/
Reflective::Reflective(Color materialColor, float diffuse, float specular, float exponent, float reflectivity)
{
	this->Direct_ = std::make_shared<Phong>(materialColor, diffuse, specular, exponent);
	this->Reflectivity_ = reflectivity;
	this->ReflectionColor_ = materialColor;
}

Reflective::Reflective(Color materialColor, float diffuse, float specular, float exponent, float reflectivity, std::shared_ptr<Texture> texture)
{
	this->Direct_ = std::make_shared<Phong>(materialColor, diffuse, specular, exponent);
	this->Reflectivity_ = reflectivity;
	this->ReflectionColor_ = materialColor;
	this->MaterialTexture = texture;
}

/**
* The mirror reflection depends on the position of the observer and will change depending on his position. 
* It should be emphasized here that the mirror reflection does not define the surface having the reflection properties of other objects like a mirror,
* it more defines the directional reflection of light and thus the creation of a characteristic flare in the form of a light spot. 
* To obtain a surface that simulates mirror behavior, you would need to perform a ray recursion to find the intensity from the reflected object.
* To calculate the intensity on a mirror surface, calculate the reflected vector and the vector directed to the observer:
* \f[
* I_{out} = I_{in} (k_s cos^n \Theta) \\
* I_{out} = I_{in} (k_s (R\cdot V)^n)
* \f]
* The equation for calculating the direction of the reflected ray R:
* \f[
* R = I - 2 \times (N \cdot I) \cdot N
* \f]
* \f$R\f$ is the directional vector of the reflected ray, \f$I\f$ is the direction of the origin of the ray, and \f$N\f$ is normal at the intersection. 
* Having the direction of the reflected ray we should also have its point of origin. 
* Which is the intersection of the object with the incoming ray.
* @param tracer - custom raytracer object
* @param hit - info about ray hitting an object
* @return Color object
*/
Color Reflective::Shade(std::shared_ptr<ImageRT> tracer, std::shared_ptr<HitInfo> hit)
{
	Vector toCameraDirection = -hit->HitRay().Direction();

	Color radiance = this->Direct_->Shade(tracer, hit);
	Vector reflectionDirection = toCameraDirection.ReflectProduct(toCameraDirection, hit->Normal());
	Ray reflectedRay(hit->HitPoint(), reflectionDirection);

	Color temp = tracer->ShadeRay(hit->CurrentWorld(), reflectedRay, hit->Depth(), this->UV) * this->ReflectionColor_ * this->Reflectivity_;
	radiance = radiance + temp;

	if (IsTextured())
	{
		temp = this->MaterialTexture->GetTexelColor(this->UV);
		//radiance = radiance * temp;
		radiance = temp;
	}

	return radiance;
}
