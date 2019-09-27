#pragma once

#include "matrix3.h"

struct matrix4 {
public:
	matrix4();
	matrix4(float m11, float m12, float m13, float m14,
			float m21, float m22, float m23, float m24,
			float m31, float m32, float m33, float m34,
			float m41, float m42, float m43, float m44);

	matrix4(const matrix4& v);

	matrix4& operator=(const matrix4& v);

	float element(size_t r, size_t c) const;
	void setElement(size_t r, size_t c, float value);

	matrix4 operator*(const matrix4& matrix) const;
	vector4 operator*(const vector4& v) const;

	void transpose();
	matrix4 transposed();

	void inverse();
	matrix4 inversed();

	static matrix4 identity();

	static matrix4 translate(float x, float y, float z);
	static matrix4 translate(const vector3& v);

	static matrix4 scale(float x, float y, float z);
	static matrix4 scale(const vector3& v);

	static matrix4 rotateX(float angle);
	static matrix4 rotateY(float angle);
	static matrix4 rotateZ(float angle);

private:
	static constexpr size_t S_SIZE = 4;
	
	float data[S_SIZE][S_SIZE];
};