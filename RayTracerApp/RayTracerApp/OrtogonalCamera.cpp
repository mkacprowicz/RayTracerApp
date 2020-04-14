#include "OrtogonalCamera.h"


OrtogonalCamera::OrtogonalCamera()
{
	this->EyePosition_ = Vector::Zero();
	this->Angle_ = 0;
	this->CameraSize_ = Vector2(1.0f, 1.0f);
}
OrtogonalCamera::OrtogonalCamera(Vector eye, float angle, Vector2 size)
{
	this->EyePosition_ = eye;
	this->Angle_ = angle;
	this->CameraSize_ = size;
}

/**
* To generate the image in orthogonal (parallel) projection, we consider the view body that has a rectangular shape.
* This projection is suitable for depicting objects for which we want to avoid perspective distortion. To achieve that we are
* sending a ray from the center of each pixel of the projection plane toward the stage. 
* The plane should be set to the center of the coordinate system. To locate the center of a pixel, perform a simple operation:
* \f[
* pixel\_width = \frac{2.0}{vertical\_image\_resolution} \\
* pixel\_height = \frac{2.0}{horizontal\_image\_resolution}
* \f]
* Having the size of the pixel it's plausible to find it's center in the coordinate system:
* \f[
* center\_x = -1.0 + (x + 0.5) * pixel\_width; \\
* center\_y = 1.0 - (y + 0.5) * pixel\_height;
* \f]
* @param uv - horizontal and vertical offset
* @return Ray object
*/
Ray OrtogonalCamera::GetRay(Vector2 uv)
{
	Vector direction(std::sin(this->Angle_), 0, std::cos(this->Angle_));
	direction = direction.NormalizeProduct();

	Vector2 offsetFromCenter(uv.X() * this->CameraSize_.X(), uv.Y() * this->CameraSize_.Y());

	Vector position(this->EyePosition_.X() + offsetFromCenter.X() * std::cos(this->Angle_), this->EyePosition_.Y() + offsetFromCenter.Y(), this->EyePosition_.Z() + offsetFromCenter.X() * std::sin(this->Angle_));

	return Ray(position, direction);
}