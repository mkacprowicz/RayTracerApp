#include "LightIntensity.h"

LightIntensity::LightIntensity(float r, float g, float b)
{
	this->R_ = r; 
	this->G_ = g;
	this->B_ = b;
}

LightIntensity::LightIntensity(float r, float g)
{
	this->R_ = r;
	this->G_ = g;
	this->B_ = 0.0f;
}

LightIntensity::LightIntensity(float r)
{
	this->R_ = r;
	this->G_ = 0.0f;
	this->B_ = 0.0f;
}

LightIntensity::LightIntensity()
{
	this->R_ = 0.0f;
	this->G_ = 0.0f;
	this->B_ = 0.0f;
}

void LightIntensity::Add(float r, float g, float b)
{
	this->R_ += r;
	if (this->R_ > 255)
	{
		this->R_ = 255;
	}
	else if (this->R_ < 0)
	{
		this->R_ = 0;
	}

	this->G_ += g;
	if (this->G_ > 255)
	{
		this->G_ = 255;
	}
	else if (this->G_ < 0)
	{
		this->G_ = 0;
	}

	this->B_ += b;
	if (this->B_ > 255)
	{
		this->B_ = 255;
	}
	else if (this->B_ < 0)
	{
		this->B_ = 0;
	}
}

void LightIntensity::operator+=(LightIntensity& li)
{
	this->R_ += li.R();
	if (this->R_ > 255)
	{
		this->R_ = 255;
	}
	else if (this->R_ < 0)
	{
		this->R_ = 0;
	}

	this->G_ += li.G();
	if (this->G_ > 255)
	{
		this->G_ = 255;
	}
	else if (this->G_ < 0)
	{
		this->G_ = 0;
	}

	this->B_ += li.B();
	if (this->B_ > 255)
	{
		this->B_ = 255;
	}
	else if (this->B_ < 0)
	{
		this->B_ = 0;
	}
}

LightIntensity LightIntensity::operator+(LightIntensity& li)
{
	this->R_ += li.R();
	if (this->R_ > 255)
	{
		this->R_ = 255;
	}
	else if (this->R_ < 0)
	{
		this->R_ = 0;
	}

	this->G_ += li.G();
	if (this->G_ > 255)
	{
		this->G_ = 255;
	}
	else if (this->G_ < 0)
	{
		this->G_ = 0;
	}

	this->B_ += li.B();
	if (this->B_ > 255)
	{
		this->B_ = 255;
	}
	else if (this->B_ < 0)
	{
		this->B_ = 0;
	}

	return LightIntensity(this->R_, this->G_, this->B_);
}

LightIntensity LightIntensity::operator-(LightIntensity& li)
{
	this->R_ -= li.R();
	if (this->R_ > 255)
	{
		this->R_ = 255;
	}
	else if (this->R_ < 0)
	{
		this->R_ = 0;
	}

	this->G_ -= li.G();
	if (this->G_ > 255)
	{
		this->G_ = 255;
	}
	else if (this->G_ < 0)
	{
		this->G_ = 0;
	}

	this->B_ -= li.B();
	if (this->B_ > 255)
	{
		this->B_ = 255;
	}
	else if (this->B_ < 0)
	{
		this->B_ = 0;
	}

	return LightIntensity(this->R_, this->G_, this->B_);
}

LightIntensity LightIntensity::operator-=(LightIntensity& li)
{
	this->R_ -= li.R();
	if (this->R_ > 255)
	{
		this->R_ = 255;
	}
	else if (this->R_ < 0)
	{
		this->R_ = 0;
	}

	this->G_ -= li.G();
	if (this->G_ > 255)
	{
		this->G_ = 255;
	}
	else if (this->G_ < 0)
	{
		this->G_ = 0;
	}

	this->B_ -= li.B();
	if (this->B_ > 255)
	{
		this->B_ = 255;
	}
	else if (this->B_ < 0)
	{
		this->B_ = 0;
	}

	return *this;
}

LightIntensity LightIntensity::operator*=(LightIntensity& li)
{
	this->R_ *= li.R();
	if (this->R_ > 255)
	{
		this->R_ = 255;
	}
	else if (this->R_ < 0)
	{
		this->R_ = 0;
	}

	this->G_ *= li.G();
	if (this->G_ > 255)
	{
		this->G_ = 255;
	}
	else if (this->G_ < 0)
	{
		this->G_ = 0;
	}

	this->B_ *= li.B();
	if (this->B_ > 255)
	{
		this->B_ = 255;
	}
	else if (this->B_ < 0)
	{
		this->B_ = 0;
	}

	return *this;
}

LightIntensity LightIntensity::operator/=(LightIntensity& li)
{
	this->R_ /= li.R();
	if (this->R_ > 255)
	{
		this->R_ = 255;
	}
	else if (this->R_ < 0)
	{
		this->R_ = 0;
	}

	this->G_ /= li.G();
	if (this->G_ > 255)
	{
		this->G_ = 255;
	}
	else if (this->G_ < 0)
	{
		this->G_ = 0;
	}

	this->B_ /= li.B();
	if (this->B_ > 255)
	{
		this->B_ = 255;
	}
	else if (this->B_ < 0)
	{
		this->B_ = 0;
	}

	return *this;
}

LightIntensity LightIntensity::operator*(float num)
{
	this->R_ *= num;
	if (this->R_ > 255)
	{
		this->R_ = 255;
	}
	else if (this->R_ < 0)
	{
		this->R_ = 0;
	}

	this->G_ *= num;
	if (this->G_ > 255)
	{
		this->G_ = 255;
	}
	else if (this->G_ < 0)
	{
		this->G_ = 0;
	}

	this->B_ *= num;
	if (this->B_ > 255)
	{
		this->B_ = 255;
	}
	else if (this->B_ < 0)
	{
		this->B_ = 0;
	}

	return LightIntensity(this->R_, this->G_, this->B_);
}

LightIntensity LightIntensity::operator*(LightIntensity& li)
{
	this->R_ *= li.R();
	if (this->R_ > 255)
	{
		this->R_ = 255;
	}
	else if (this->R_ < 0)
	{
		this->R_ = 0;
	}

	this->G_ *= li.G();
	if (this->G_ > 255)
	{
		this->G_ = 255;
	}
	else if (this->G_ < 0)
	{
		this->G_ = 0;
	}

	this->B_ *= li.B();
	if (this->B_ > 255)
	{
		this->B_ = 255;
	}
	else if (this->B_ < 0)
	{
		this->B_ = 0;
	}

	return LightIntensity(this->R_, this->G_, this->B_);
}

LightIntensity LightIntensity::operator/(float num)
{
	this->R_ /= num;
	if (this->R_ > 255)
	{
		this->R_ = 255;
	}
	else if (this->R_ < 0)
	{
		this->R_ = 0;
	}

	this->G_ /= num;
	if (this->G_ > 255)
	{
		this->G_ = 255;
	}
	else if (this->G_ < 0)
	{
		this->G_ = 0;
	}

	this->B_ /= num;
	if (this->B_ > 255)
	{
		this->B_ = 255;
	}
	else if (this->B_ < 0)
	{
		this->B_ = 0;
	}

	return LightIntensity(this->R_, this->G_, this->B_);
}

std::ostream& operator<<(std::ostream& str, LightIntensity& li)
{
	str << "R: " << std::to_string(li.R()) << ", G: " << std::to_string(li.G()) << ", B: " << std::to_string(li.R());
	return str;
}
