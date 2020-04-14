#include "Vector.h"

/**
* Default constructor. Creates a Vector object that has is equal \f$ (0, 0, 0) \f$
* @return Vector object
*/
Vector::Vector()
{
	this->X_ = 0.0f;
	this->Y_ = 0.0f;
	this->Z_ = 0.0f;
}

/**
* Basic constructor. Creates a Vector object that has is equal \f$ (x, y, z) \f$
* @param x - first vector value
* @param y - second vector value
* @param z - third vector value
* @return Vector object
*/
Vector::Vector(float x, float y, float z)
{
	this->X_ = x;
	this->Y_ = y;
	this->Z_ = z;
}

/**
* Basic constructor. Creates a Vector object that has is equal to a difference of Vector v1 and Vector v2 \f$ (v_{1x} - v_{2x}, v_{1y} - v_{2y}, v_{1z} - v_{2z}) \f$
* @param v1 - first vector
* @param v2 - second vector
* @return Vector object
*/
Vector::Vector(Vector v1, Vector v2)
{
	this->X_ = v2.X() - v1.X();
	this->Y_ = v2.Y() - v1.Y();
	this->Z_ = v2.Z() - v1.Z();
}

/**
* Normalization of a Vector object
*/
void Vector::Normalize()
{
	float n = Lenght();

	if (n != 0)
	{
		Div(n);
	}
	//else
}

/**
* Normalization of a copy of a Vector object
* @return Vector object
*/
Vector Vector::NormalizeProduct()
{
	Vector newV(this->X_, this->Y_, this->Z_);

	float n = this->Lenght();

	if (n != 0)
	{
		newV.Div(n);
		return newV;
	}
	else
	{
		return newV;
		// throw Excpetion ("Could't normalize");
	}
}

/**
* Function that counts length of a Vector according to the formula \f$ d = \sqrt{x^2 + y^2 + z^2} \f$
* @return length of the vector
*/
float Vector::Lenght()
{
	return std::sqrt(std::pow(this->X_, 2) + std::pow(this->Y_, 2) + std::pow(this->Z_, 2));
}

/**
* Function that counts squared length of a Vector according to the formula \f$ d^2 = x^2 + y^2 + z^2 \f$
* @return squared length of the vector
*/
float Vector::LenghtSquared()
{
	return std::pow(this->X_, 2) + std::pow(this->Y_, 2) + std::pow(this->Z_, 2);
}

/**
* Function that counts dot a Vector according to the formula \f$ d = x \cdot x^v + y \cdot y_v + z \cdot z_v \f$
* @param v - vector to dot with
* @return squared length of the vector
*/
float Vector::Dot(Vector v)
{
	return this->X_ * v.X() + this->Y_ * v.Y() + this->Z_ * v.Z();
}

Vector Vector::Cross(Vector v)
{
	return Vector(this->Y_ * v.Z() - this->Z_ * v.Y(), this->Z_ * v.X() - this->X_ * v.Z(), this->X_ * v.Y() - this->Y_ * v.X());
}

/**
* Function that negates the current vector
*/
void Vector::Negate()
{
	this->X_ = -this->X_;
	this->Y_ = -this->Y_;
	this->Z_ = -this->Z_;
}

/**
* Function adds a Vector according to the formula \f$ v_3 = [x_1 + x_2, y_1 + y_2, z_1 + z_2] \f$
* @param v - Vector to add
* @return sum of two vectors
*/
void Vector::Add(Vector v)
{
	this->X_ += v.X();
	this->Y_ += v.Y();
	this->Z_ += v.Z();
}

/**
* Function that adds a Vector according to the formula \f$ v_3 = [x_1 - x_2, y_1 - y_2, z_1 - z_2] \f$
* @param v - Vector to subtract
* @return sum of two vectors
*/
void Vector::Sub(Vector v)
{
	this->X_ -= v.X();
	this->Y_ -= v.Y();
	this->Z_ -= v.Z();
}

/**
* Function that divides a Vector according to the formula \f$ v_3 = [\frac{x_1}{f}, \frac{y_1}{f}, \frac{z_1}{f}] \f$
* @param f - number to divide
* @return result of a division of a vector
*/
void Vector::Div(float f)
{
	if (f != 0)
	{
		this->X_ /= f;
		this->Y_ /= f;
		this->Z_ /= f;
	}
	else
	{
		throw std::invalid_argument("Can't divide by 0");
	}
}

/**
* Function that multiplies a Vector and a scalar according to the formula \f$ v_3 = [x_1 * f, y_1 * f, z_1 * f] \f$
* @param f - number to multiply
*/
void Vector::Mag(float f)
{
	this->X_ *= f;
	this->Y_ *= f;
	this->Z_ *= f;
}

/**
* Function that reflects a Vector from a Normal
* @param normal - a normal to relfect from
* @return Vector object
*/
Vector Vector::Reflect(Vector normal)
{
	//return (this - (2 * this->Dot(normal) * normal));
	return (this->ToPoint() - (2 * this->Dot(normal) * normal));
}

/**
* Function that reflects a Vector from a Normal
* @param vec - a vector that will be reflect
* @param normal - a normal to relfect from
* @return copy of vector object
*/
Vector Vector::ReflectProduct(Vector vec, Vector normal)
{
	float dot = normal.Dot(vec);
	return normal * dot * 2 - vec;
}

/**
* Function that multiplies a Vector and a scalar according to the formula \f$ v_3 = [x_1 * f, y_1 * f, z_1 * f] \f$
* @param f - number to multiply
* @return result of a multiplication of a vector
*/
Vector Vector::MagProduct(Vector v, float f)
{
	return Vector(v.X() * f, v.Y() * f, v.Z() * f);
}

/**
* Function that gets a starting point of a vector
* @return Vector object
*/
Vector Vector::ToPoint()
{
	return Vector(this->X_, this->Y_, this->Z_);
}


/**
* Function that does the linear interpolation between two vectors
* @param v - vector to interpolate
* @param t - interpolant in range [0, 1]
* @return Vector object
*/
Vector Vector::Lerp(Vector v, float t)
{
	Vector vec;

	vec.X(this->X_ + t * (v.X() - this->X_));
	vec.Y(this->Y_ + t * (v.Y() - this->Y_));
	vec.X(this->Z_ + t * (v.X() - this->X_));

	return vec;
}

/**
* Function that creates Vector in \f$ [0, 0, 0] \f$
* @return Vector object
*/
Vector Vector::Zero()
{
	return Vector(0.0f, 0.0f, 0.0f);
}

/**
* Overlaoded << operator for debug purposes.
* Example:
* @code
* Vector vector();
* std::cout << vector;
* @endcode
* Output:
* @code
* "Vector(0,0,0)"
* @endcode
*/
std::ostream& operator<<(std::ostream& os, const Vector& vec)
{
	os << "Vector(" << std::to_string(vec.X_) << "," << std::to_string(vec.Y_) << "," + std::to_string(vec.Z_) << ")";
	return os;
}
