#include "LightIntensity.h"

/**
* Basic constructor. Creates LightIntensity object with paramters equal to (r, g, b)
* @param r - red color parameter
* @param g - green color parameter
* @param b - blue color parameter
* @return LightIntensity object
*/
LightIntensity::LightIntensity(float r, float g, float b)
{
	this->R_ = r; 
	this->G_ = g;
	this->B_ = b;
}

/**
* Basic constructor. Creates LightIntensity object with paramters equal to (r, g, 0)
* @param r - red color parameter
* @param g - green color parameter
* @return LightIntensity object
*/
LightIntensity::LightIntensity(float r, float g)
{
	this->R_ = r;
	this->G_ = g;
	this->B_ = 0.0f;
}

/**
* Basic constructor. Creates LightIntensity object with paramters equal to (r, 0, 0)
* @param r - red color parameter
* @return LightIntensity object
*/
LightIntensity::LightIntensity(float r)
{
	this->R_ = r;
	this->G_ = 0.0f;
	this->B_ = 0.0f;
}

/**
* Basic constructor. Creates LightIntensity object with paramters equal to (0, 0, 0)
* @return LightIntensity object
*/
LightIntensity::LightIntensity()
{
	this->R_ = 0.0f;
	this->G_ = 0.0f;
	this->B_ = 0.0f;
}

/**
* Function that adds values to the color
* @param r - red color value to add
* @param g - green color value to add
* @param b - blue color value to add
* @return LightIntensity object
*/
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

/**
* Overloaded += operator that replaces current attributes with a sum of colors
* @return LightIntensity object
*/
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

/**
* Overloaded + operator that that sums two colors
* @return LightIntensity object
*/
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

/**
* Overloaded - operator that that subtracts two colors
* @return LightIntensity object
*/
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

/**
* Overloaded -= operator that replaces current attributes with a difference of colors 
* @return LightIntensity object
*/
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

/**
* Overloaded *= operator that multiplies two LigtIntensity objects and replaces current one
* @return LightIntensity object
*/
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

/**
* Overloaded *= operator that divides two LigtIntensity objects and replaces current one
* @return LightIntensity object
*/
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

/**
* Overloaded * operator that multiplies LigtIntensity object by a float number
* @return LightIntensity object
*/
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

/**
* Overloaded * operator that multiplies two LigtIntensity objects
* @return LightIntensity object
*/
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

/**
* Overloaded * operator that divides two LigtIntensity objects
* @return LightIntensity object
*/
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

/**
* Overlaoded << operator for debug purposes.
* Example:
* @code
* LightIntensity light(1,2,3);
* std::cout << light;
* @endcode
* Output:
* @code
* "R: 1, G: 2, B: 3"
* @endcode
*/
std::ostream& operator<<(std::ostream& str, LightIntensity& li)
{
	str << "R: " << std::to_string(li.R()) << ", G: " << std::to_string(li.G()) << ", B: " << std::to_string(li.B());
	return str;
}
