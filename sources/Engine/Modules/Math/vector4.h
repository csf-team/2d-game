#pragma once

#include "vector3.h"

struct vector4 {
public:
	vector4();
	vector4(float x, float y, float z, float w);
	vector4(const vector4& v);

	vector4& operator=(const vector4& v);

	float x() const;
	void setX(float x);

	float y() const;
	void setY(float y);

	float z() const;
	void setZ(float z);

	float w() const;
	void setW(float w);

	float getLength() const;
	vector4 getNormalized() const;

	void normalize();

	vector4 operator+(const vector4& v) const;
	vector4 operator-(const vector4& v) const;

	vector4 operator+() const;
	vector4 operator-() const;

	vector4& operator+=(const vector4& v);
	vector4& operator-=(const vector4& v);

	float operator[](size_t index) const;
	float& operator[](size_t index);

	static float dot(const vector4& a, const vector4& b);

private:
	float data[4];
};