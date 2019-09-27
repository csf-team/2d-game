#pragma once

#include <cmath>
#include <cassert>
#include <algorithm>

struct vector2 {
public:
	vector2();
	vector2(float x, float y);
	vector2(const vector2& v);

	vector2& operator=(const vector2& v);

	float x() const;
	void setX(float x);

	float y() const;
	void setY(float y);

	float getLength() const;
	vector2 getNormalized() const;

	void normalize();

	vector2 operator+(const vector2& v) const;
	vector2 operator-(const vector2& v) const;

	vector2 operator+() const;
	vector2 operator-() const;

	vector2& operator+=(const vector2& v);
	vector2& operator-=(const vector2& v);

	float operator[](size_t index) const;
	float& operator[](size_t index);

	static float dot(const vector2& a, const vector2& b);
	static float cosBetween(const vector2& a, const vector2& b);
	static float angleBetween(const vector2& a, const vector2& b);

	static float distance(const vector2& a, const vector2& b);
private:
	float data[2];
};