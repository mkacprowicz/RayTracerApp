#pragma once

#include "pch.h"
#include "PointLight.h"
#include "HitInfo.h"
#include "World.h"

class ImageRT;

//! Material pure abstract class is a representation of phisical material
class Material
{
public :
	virtual Color Shade(std::shared_ptr<ImageRT> tracer, std::shared_ptr<HitInfo> hit) = 0;
};