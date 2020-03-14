#include "Surface.h"

Surface::Surface()
{
	this->Normal_ = Vector::Zero();
	this->Point_ = Vector::Zero();
}

Surface::Surface(Vector nor, Vector poi)
{
	this->Normal_ = nor;
	this->Point_ = poi;
}
