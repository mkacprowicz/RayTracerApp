#pragma once

#include "pch.h"
#include "Material.h"

class PerfectDiffuse : public Material
{
public:
	PerfectDiffuse();
	PerfectDiffuse(Color rgb);

	Color Shade(std::shared_ptr<ImageRT> tracer, std::shared_ptr<HitInfo> hit);

	Color MaterialColor() const { return MaterialColor_; }
	void MaterialColor(Color c) { MaterialColor_ = c; }

private:
	Color MaterialColor_;
};

