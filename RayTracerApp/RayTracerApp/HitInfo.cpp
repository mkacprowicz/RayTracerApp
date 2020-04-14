#include "HitInfo.h"

HitInfo::HitInfo()
{
	this->HitObject_ = nullptr;
	this->CurrentWorld_ = nullptr;
	this->Normal_ = Vector();
	this->HitPoint_ = Vector();
	this->HitRay_ = Ray();
	this->Depth_ = 0;
}
