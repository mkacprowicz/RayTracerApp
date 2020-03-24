#include "OrtoCamera.h"

Ray OrtoCamera::GetRay(float u, float v)
{
	return Ray(Vector(0,0, 50.0f), this->LowerLeftCorner_ + u * this->Horizontal_ + v * this->Vertical_ - Vector(0, 0, 50.0f));
}

void OrtoCamera::Render()
{
}
