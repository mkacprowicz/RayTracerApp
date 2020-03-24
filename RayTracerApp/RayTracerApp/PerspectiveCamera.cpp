#include "PerspectiveCamera.h"

Ray PerspectiveCamera::GetRay(float u, float v)
{
	return Ray(this->Origin_, this->LowerLeftCorner_ + u * this->Horizontal_ + v * this->Vertical_ - this->Origin_);
}

void PerspectiveCamera::Render()
{
}