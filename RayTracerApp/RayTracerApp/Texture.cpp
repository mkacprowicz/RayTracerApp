#include "Texture.h"

#include "vendor/stb_image/stb_image.h"
#include "vendor/stb_image/stb_image_write.h"

/**
* Texture constructor
* @param filepath - path to the texture file
*/
Texture::Texture(const char* filepath)
{
	this->TextureData_ = stbi_load(filepath, &this->TextureWidth_, &this->TextureHeight_, &this->TextureChannels_, 4);
}

/**
* The simplest example of texturing reproduces a rectangular texture \f$ (x, z) \in [-1, +1] x [-1, +1] \f$ on the (x,z) plane. 
* Having a point on the plane (x, 0, z), coordinates, \f$ v \f$ can be calculated: \f[ u = \frac{(z + 1)}{2} \\ v = \frac{(x - 1)}{2} \f]
* Having the calculated intersection point of the coordinates (x, y, z) find the appropriate coordinate coordinates \f$ \phi \f$ and \f$ \theta \f$
* assuming that the radius of such a sphere is \f$ r = 1 \f$ . Coordinate \f$ \phi \f$ will be the same as in the case of a cylinder, 
* one should consider the value \f$ \theta \f$ . By using the running properties of the new coordinate system:
* \f$ \theta = \cos^{-1}(y) \f$. Where \f$ \theta = \cos^{-1}(y) \f$ can be represented as \f$ acos(y). acos(y) \in [0, \pi ] \f$ however, 
* \f$ \theta = 0 \f$ when \f$ v = 1 \f$. Parameters (u, v) will be calculated: \f[ u = \frac{ \phi }{2 \pi } \\ v = 1 - \frac{ \theta }{ \pi }  \f]
* @param uv - uv vector
* @returns Color of a pixel
*/
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
