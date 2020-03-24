#include "OrtoCamera.h"


/**
* Function that creates a Ray from a camera. Ray has origin equal to \f$ (0, 0, 50) \f$ .
* @param u - horizontal offset
* @param v - vertical offset
* @return Ray object
*/
Ray OrtoCamera::GetRay(float u, float v)
{
	return Ray(Vector(0,0, 50.0f), this->LowerLeftCorner_ + u * this->Horizontal_ + v * this->Vertical_ - Vector(0, 0, 50.0f));
}

void OrtoCamera::Render()
{
}
