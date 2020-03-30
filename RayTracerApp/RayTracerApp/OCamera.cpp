#include "OCamera.h"

/**
* Function that creates a Ray from a camera
* @param u - horizontal offset
* @param v - vertical offset
* @return Ray object
*/
Ray OCamera::GetRay(float u, float v)
{
	return Ray(this->Origin_, this->LowerLeftCorner_ + u * this->Horizontal_ + v * this->Vertical_ - this->Origin_);
}

void OCamera::Render()
{
}