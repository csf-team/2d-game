#pragma once

#include "vector2.h"

struct vector3 {
public:
	vector3();
	vector3(float x, float y, float z);
	vector3(const vector3& v);

	vector3& operator=(const vector3& v);

	float x() const;
	void setX(float x);

	float y() const;
	void setY(float y);

	float z() const;
	void setZ(float z);

	float getLength() const;
	vector3 getNormalized() const;

	void normalize();

	vector3 operator+(const vector3& v) const;
	vector3 operator-(const vector3& v) const;

	vector3 operator+() const;
	vector3 operator-() const;

	vector3& operator+=(const vector3& v);
	vector3& operator-=(const vector3& v);

	float operator[](size_t index) const;
	float& operator[](size_t index);

	static float dot(const vector3& a, const vector3& b);
	static vector3 cross(const vector3& a, const vector3& b);
	static float cosBetween(const vector3& a, const vector3& b);
	static float angleBetween(const vector3& a, const vector3& b);
	static float distance(const vector3& a, const vector3& b);

private:
	float data[3];
};