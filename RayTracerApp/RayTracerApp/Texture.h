#pragma once

#include "pch.h"
#include "Vector.h"
#include "Color.h"

class Texture
{
public:
	Texture(const char* filepath);

	Color GetTexelColor(Vector2 uv);

	int TextureWidth() const { return TextureWidth_; }
	void TextureWidth(int t) { TextureWidth_ = t; }
	int TextureHeight() const { return TextureHeight_; }
	void TextureHeight(int t) { TextureHeight_ = t; }

	unsigned char* TextureData() const;

private:

	unsigned char* TextureData_{};

	int TextureWidth_{};
	int TextureHeight_{};
	int TextureChannels_{};

	float plusX = 0;
	float plusY = 0;
};

