#include "Vector.h"

Vector::Vector()
{
	this->X_ = 0.0f;
	this->Y_ = 0.0f;
	this->Z_ = 0.0f;
}

Vector::Vector(float x, float y, float z)
{
	this->X_ = x;
	this->Y_ = y;
	this->Z_ = z;
}

Vector::Vector(Vector v1, Vector v2)
{
	this->X_ = v2.X() - v1.X();
	this->Y_ = v2.Y() - v1.Y();
	this->Z_ = v2.Z() - v1.Z();
}

void Vector::Normalize()
{
	float n = Lenght();

	if (n != 0)
	{
		Div(n);
	}
	//else
}

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

float Vector::Lenght()
{
	return std::sqrt(std::pow(this->X_, 2) + std::pow(this->Y_, 2) + std::pow(this->Z_, 2));
}

float Vector::LenghtSquared()
{
	return std::pow(this->X_, 2) + std::pow(this->Y_, 2) + std::pow(this->Z_, 2);
}

float Vector::Dot(Vector v)
{
	return this->X_ * v.X() + this->Y_ * v.Y() + this->Z_ * v.Z();
}

Vector Vector::Cross(Vector v)
{
	return Vector(this->Y_ * v.Z() - this->Z_ * v.Y(), this->Z_ * v.X() - this->X_ * v.Z(), this->X_ * v.Y() - this->Y_ * v.X());
}

void Vector::Negate()
{
	this->X_ = -this->X_;
	this->Y_ = -this->Y_;
	this->Z_ = -this->Z_;
}

void Vector::Add(Vector v)
{
	this->X_ += v.X();
	this->Y_ += v.Y();
	this->Z_ += v.Z();
}

void Vector::Sub(Vector v)
{
	this->X_ -= v.X();
	this->Y_ -= v.Y();
	this->Z_ -= v.Z();
}

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

void Vector::Mag(float f)
{
	this->X_ *= f;
	this->Y_ *= f;
	this->Z_ *= f;
}

Vector Vector::Reflect(Vector normal)
{
	//return (this - (2 * this->Dot(normal) * normal));
	return (this->ToPoint() - (2 * this->Dot(normal) * normal));
}

Vector Vector::MagProduct(Vector v, float f)
{
	return Vector(v.X() * f, v.Y() * f, v.Z() * f);
}

Vector Vector::ToPoint()
{
	return Vector(this->X_, this->Y_, this->Z_);
}

Vector Vector::Lerp(Vector v, float t)
{
	Vector vec;

	vec.X(this->X_ + t * (v.X() - this->X_));
	vec.Y(this->Y_ + t * (v.Y() - this->Y_));
	vec.X(this->Z_ + t * (v.X() - this->X_));

	return vec;
}

Vector Vector::Zero()
{
	return Vector(0.0f, 0.0f, 0.0f);
}

std::string Vector::ToString()
{
	return "Vector(" + std::to_string(this->X_) + "," + std::to_string(this->Y_) + "," + std::to_string(this->Z_) + ")";
}
