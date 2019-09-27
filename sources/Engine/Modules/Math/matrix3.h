#pragma once

#include "vector4.h"

struct matrix3 {
public:
	matrix3();
	matrix3(float m11, float m12, float m13,
			float m21, float m22, float m23,
			float m31, float m32, float m33);

	matrix3(const matrix3& v);

	matrix3& operator=(const matrix3& v);

	float element(size_t r, size_t c) const;
	void setElement(size_t r, size_t c, float value);

	matrix3 operator*(const matrix3& matrix) const;
	vector3 operator*(const vector3& v) const;

	void transpose();
	matrix3 transposed();

	void inverse();
	matrix3 inversed();

	static matrix3 identity();

	static matrix3 translate(float x, float y);
	static matrix3 translate(const vector2& v);

	static matrix3 scale(float x, float y);
	static matrix3 scale(const vector2& v);

	static matrix3 rotate(float angle);

private:
	static constexpr size_t S_SIZE = 3;

	float data[S_SIZE][S_SIZE];
};