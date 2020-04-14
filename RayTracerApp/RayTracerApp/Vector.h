#pragma once
#include "pch.h"


struct Vector2
{
	float X_;
	float Y_;

	float X() const { return X_; }
	void X(float x) { X_ = x; }
	float Y() const { return Y_; }
	void Y(float y) { Y_ = y; }

	Vector2(float x, float y) : X_(x), Y_(y) {}
	Vector2() { X_ = 0; Y_ = 0; }
};



//! Vector class which is a representation of a 3D vector
/**
* The <code>Vector</code> class is a representation of 
* a geometric object that has magnitude (or length) and direction. 
* Vectors can be added to other vectors according to vector algebra.
*
*/
class Vector
{
public:
	Vector();
	Vector(float x, float y, float z);
	Vector(Vector v1, Vector v2);

	Vector Cross(Vector v);
	Vector NormalizeProduct();
	float Lenght();
	float LenghtSquared();
	float Dot(Vector v);
	void Normalize();
	void Negate();
	void Add(Vector v);
	void Sub(Vector v);
	void Div(float f);
	void Mag(float f);

	Vector Reflect(Vector normal);
	Vector ReflectProduct(Vector vec, Vector normal);

	Vector Lerp(Vector v, float t);
	Vector ToPoint();
	static Vector MagProduct(Vector v, float f);
	static Vector Zero();


	float X() const	{ return X_; }
	void X(float x)	{ X_ = x; }
	float Y() const { return Y_; }
	void Y(float y) { Y_ = y; }
	float Z() const { return Z_; }
	void Z(float z) { Z_ = z; }

	friend std::ostream& operator<<(std::ostream& os, const Vector& vec);

private:
	float X_;
	float Y_;
	float Z_;
};

inline static Vector operator*(float scalar, Vector right)
{
	return Vector(right.X() * scalar, right.Y() * scalar, right.Z() * scalar);
}

inline static Vector operator*(Vector left, float scalar)
{
	return Vector(left.X() * scalar, left.Y() * scalar, left.Z() * scalar);
}

inline static Vector operator*(Vector left, Vector right)
{
	return Vector(left.X() * right.X(), left.Y() * right.Y(), left.Z() * right.Z());
}

inline static Vector operator+(Vector left, Vector right)
{
	return Vector(left.X() + right.X(), left.Y() + right.Y(), left.Z() + right.Z());
}

inline static Vector operator-(Vector left, Vector right)
{
	return Vector(left.X() - right.X(), left.Y() - right.Y(), left.Z() - right.Z());
}

inline static Vector operator-(Vector left)
{
	return Vector(-left.X(), -left.Y(), -left.Z());
}

inline static bool operator==(Vector left, Vector right)
{
	return (left.X() == right.X() && left.Y() == right.Y() && left.Z() == right.Z());
}

inline static bool operator!=(Vector left, Vector right)
{
	return (left.X() != right.X() || left.Y() != right.Y() || left.Z() != right.Z());
}

inline static Vector operator/(Vector left, float scalar)
{
	Vector vec;

	float inverse = 1.0f / scalar;

	vec.X(left.X() * inverse);
	vec.Y(left.Y() * inverse);
	vec.Z(left.Z() * inverse);

	return vec;
}