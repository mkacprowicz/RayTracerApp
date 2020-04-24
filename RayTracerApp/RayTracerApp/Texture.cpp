#include "Texture.h"

#include "vendor/stb_image/stb_image.h"
#include "vendor/stb_image/stb_image_write.h"

Texture::Texture(const char* filepath)
{
	this->TextureData_ = stbi_load(filepath, &this->TextureWidth_, &this->TextureHeight_, &this->TextureChannels_, 4);
}

Color Texture::GetTexelColor(Vector2 uv)
{
	Color resultColor;

	unsigned char r = 0;
	unsigned char g = 0;
	unsigned char b = 0;
	unsigned char a = 0;

	float temp1 = uv.X() + 0.35f;
	float temp2 = uv.Y() + 0.7f;

	int i = temp1 * TextureHeight();
	int j = (1 - temp2) * TextureWidth() - 0.001;
	if (i < 0) i = 0;
	if (j < 0) j = 0;
	if (i > TextureHeight() - 1) i = TextureHeight() - 1;
	if (j > TextureWidth() - 1) j = TextureWidth() - 1;

	unsigned bytePerPixel = 4;

	const unsigned char* pixelOffset = TextureData() + (i * this->TextureHeight_ + j) * bytePerPixel;
	r = pixelOffset[0];
	g = pixelOffset[1];
	b = pixelOffset[2];
	a = pixelOffset[3];

	resultColor.R(r);
	resultColor.G(g);
	resultColor.B(b);
	resultColor.A(a);

	return resultColor;
}

unsigned char* Texture::TextureData() const
{
	return this->TextureData_;
}
