#pragma once

#include "pch.h"
#include "PointLight.h"
#include "HitInfo.h"
#include "World.h"
#include "Texture.h"

class ImageRT;

//! Material pure abstract class is a representation of phisical material
class Material
{
public :
	virtual Color Shade(std::shared_ptr<ImageRT> tracer, std::shared_ptr<HitInfo> hit) = 0;
	
	bool IsTextured() const { if (MaterialTexture == nullptr) return false; return true; }
	
	std::shared_ptr<Texture> MaterialTexture;
	Vector2 UV;
};