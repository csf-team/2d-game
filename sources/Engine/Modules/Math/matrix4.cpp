#include "matrix4.h"

matrix4::matrix4()
	: data()
{
	for (size_t r = 0; r < S_SIZE; r++) {
		for (size_t c = 0; c < S_SIZE; c++) {
			data[r][c] = 0.0f;
		}
	}
}

matrix4::matrix4(float m11, float m12, float m13, float m14,
	float m21, float m22, float m23, float m24,
	float m31, float m32, float m33, float m34,
	float m41, float m42, float m43, float m44)
	: data()
{
	data[0][0] = m11;
	data[0][1] = m12;
	data[0][2] = m13;
	data[0][3] = m14;
	data[1][0] = m21;
	data[1][1] = m22;
	data[1][2] = m23;
	data[1][3] = m24;
	data[2][0] = m31;
	data[2][1] = m32;
	data[2][2] = m33;
	data[2][3] = m34;
	data[3][0] = m41;
	data[3][1] = m42;
	data[3][2] = m43;
	data[3][3] = m44;
}

matrix4::matrix4(const matrix4& v)
	: data()
{
	for (size_t r = 0; r < S_SIZE; r++) {
		for (size_t c = 0; c < S_SIZE; c++) {
			data[r][c] = v.data[r][c];
		}
	}
}

matrix4& matrix4::operator=(const matrix4& v)
{
	for (size_t r = 0; r < S_SIZE; r++) {
		for (size_t c = 0; c < S_SIZE; c++) {
			data[r][c] = v.data[r][c];
		}
	}

	return *this;
}

float matrix4::element(size_t r, size_t c) const
{
	assert(r < S_SIZE && c < S_SIZE);
	return data[r][c];
}

void matrix4::setElement(size_t r, size_t c, float value)
{
	assert(r < S_SIZE && c < S_SIZE);
	data[r][c] = value;
}

matrix4 matrix4::operator*(const matrix4& matrix) const
{
	matrix4 result;

	for (size_t r = 0; r < S_SIZE; r++) {
		for (size_t c = 0; c < S_SIZE; c++) {
			for (size_t m = 0; m < S_SIZE; m++) {
				result.data[r][c] += data[r][m] * matrix.data[m][c];
			}
		}
	}

	return result;
}

vector4 matrix4::operator*(const vector4& v) const
{
	vector4 result;

	result.setX(data[0][0] * v.x() + data[0][1] * v.y() + data[0][2] * v.z() + data[0][3] * v.w());
	result.setY(data[1][0] * v.x() + data[1][1] * v.y() + data[1][2] * v.z() + data[1][3] * v.w());
	result.setZ(data[2][0] * v.x() + data[2][1] * v.y() + data[2][2] * v.z() + data[2][3] * v.w());
	result.setW(data[3][0] * v.x() + data[3][1] * v.y() + data[3][2] * v.z() + data[3][3] * v.w());

	return result;
}

void matrix4::transpose()
{
	std::swap(data[0][1], data[1][0]);
	std::swap(data[0][2], data[2][0]);
	std::swap(data[1][2], data[2][1]);
	std::swap(data[0][3], data[3][0]);
	std::swap(data[1][3], data[3][1]);
	std::swap(data[2][3], data[3][2]);
}

matrix4 matrix4::transposed()
{
	return matrix4(data[0][0], data[1][0], data[2][0], data[3][0],
		data[0][1], data[1][1], data[2][1], data[3][1],
		data[0][2], data[1][2], data[2][2], data[3][2],
		data[0][3], data[1][3], data[2][3], data[3][3]);
}

void matrix4::inverse()
{
	float inv[S_SIZE][S_SIZE];

	inv[0][0] = data[1][1] * data[2][2] * data[3][3] + data[2][1] * data[3][2] * data[1][3] + data[1][2] * data[2][3] * data[3][1] - data[1][3] * data[2][2] * data[3][1] - data[2][1] * data[1][2] * data[3][3] - data[3][2] * data[2][3] * data[1][1];
	inv[0][1] = data[1][0] * data[2][2] * data[3][3] + data[2][0] * data[3][2] * data[1][3] + data[1][2] * data[2][3] * data[3][0] - data[1][3] * data[2][2] * data[3][0] - data[2][0] * data[1][2] * data[3][3] - data[3][2] * data[2][3] * data[1][0];
	inv[0][2] = data[1][0] * data[2][1] * data[3][3] + data[2][0] * data[3][1] * data[1][3] + data[1][1] * data[2][3] * data[3][0] - data[1][3] * data[2][1] * data[3][0] - data[2][0] * data[1][1] * data[3][3] - data[3][1] * data[2][3] * data[1][0];
	inv[0][3] = data[1][0] * data[2][1] * data[3][2] + data[2][0] * data[3][1] * data[1][2] + data[1][1] * data[2][2] * data[3][0] - data[1][2] * data[2][1] * data[3][0] - data[2][0] * data[1][1] * data[3][2] - data[3][1] * data[2][2] * data[1][0];

	float det = data[0][0] * inv[0][0] - data[0][1] * inv[0][1] + data[0][2] * inv[0][2] - data[0][3] * inv[0][3];

    if (det != 0.f) {

		inv[1][0] = data[0][1] * data[2][2] * data[3][3] + data[2][1] * data[3][2] * data[0][3] + data[0][2] * data[2][3] * data[3][1] - data[0][3] * data[2][2] * data[3][1] - data[2][1] * data[0][2] * data[3][3] - data[3][2] * data[2][3] * data[0][1];
		inv[1][1] = data[0][0] * data[2][2] * data[3][3] + data[2][0] * data[3][2] * data[0][3] + data[0][2] * data[2][3] * data[3][0] - data[0][3] * data[2][2] * data[3][0] - data[2][0] * data[0][2] * data[3][3] - data[3][2] * data[2][3] * data[0][0];
		inv[1][2] = data[0][0] * data[2][1] * data[3][3] + data[2][0] * data[3][1] * data[0][3] + data[0][1] * data[2][3] * data[3][0] - data[0][3] * data[2][1] * data[3][0] - data[2][0] * data[0][1] * data[3][3] - data[3][1] * data[2][3] * data[0][0];
		inv[1][3] = data[0][0] * data[2][1] * data[3][2] + data[2][0] * data[3][1] * data[0][2] + data[0][1] * data[2][2] * data[3][0] - data[0][2] * data[2][1] * data[3][0] - data[2][0] * data[0][1] * data[3][2] - data[3][1] * data[2][2] * data[0][0];

		inv[2][0] = data[0][1] * data[1][2] * data[3][3] + data[1][1] * data[3][2] * data[0][3] + data[0][2] * data[1][3] * data[3][1] - data[0][3] * data[1][2] * data[3][1] - data[1][1] * data[0][2] * data[3][3] - data[3][2] * data[1][3] * data[0][1];
		inv[2][1] = data[0][0] * data[1][2] * data[3][3] + data[1][0] * data[3][2] * data[0][3] + data[0][2] * data[1][3] * data[3][0] - data[0][3] * data[1][2] * data[3][0] - data[1][0] * data[0][2] * data[3][3] - data[3][2] * data[1][3] * data[0][0];
		inv[2][2] = data[0][0] * data[1][1] * data[3][3] + data[1][0] * data[3][1] * data[0][3] + data[0][1] * data[1][3] * data[3][0] - data[0][3] * data[1][1] * data[3][0] - data[1][0] * data[0][1] * data[3][3] - data[3][1] * data[1][3] * data[0][0];
		inv[2][3] = data[0][0] * data[1][1] * data[3][2] + data[1][0] * data[3][1] * data[0][2] + data[0][1] * data[1][2] * data[3][0] - data[0][2] * data[1][1] * data[3][0] - data[1][0] * data[0][1] * data[3][2] - data[3][1] * data[1][2] * data[0][0];

		inv[3][0] = data[0][1] * data[1][2] * data[2][3] + data[1][1] * data[2][2] * data[0][3] + data[0][2] * data[1][3] * data[2][1] - data[0][3] * data[1][2] * data[2][1] - data[1][1] * data[0][2] * data[2][3] - data[2][2] * data[1][3] * data[0][1];
		inv[3][1] = data[0][0] * data[1][2] * data[2][3] + data[1][0] * data[2][2] * data[0][3] + data[0][2] * data[1][3] * data[2][0] - data[0][3] * data[1][2] * data[2][0] - data[1][0] * data[0][2] * data[2][3] - data[2][2] * data[1][3] * data[0][0];
		inv[3][2] = data[0][0] * data[1][1] * data[2][3] + data[1][0] * data[2][1] * data[0][3] + data[0][1] * data[1][3] * data[2][0] - data[0][3] * data[1][1] * data[2][0] - data[1][0] * data[0][1] * data[2][3] - data[2][1] * data[1][3] * data[0][0];
		inv[3][3] = data[0][0] * data[1][1] * data[2][2] + data[1][0] * data[2][1] * data[0][2] + data[0][1] * data[1][2] * data[2][0] - data[0][2] * data[1][1] * data[2][0] - data[1][0] * data[0][1] * data[2][2] - data[2][1] * data[1][2] * data[0][0];

		for (size_t r = 0; r < S_SIZE; r++) {
			for (size_t c = 0; c < S_SIZE; c++) {
				data[r][c] = inv[c][r] / det;

				if ((r + c) % 2 == 1)
					data[r][c] *= -1;
			}
		}
	}
}

matrix4 matrix4::inversed()
{
	matrix4 result(*this);
	result.inverse();
	return result;
}

matrix4 matrix4::identity()
{
	return matrix4(1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
}

matrix4 matrix4::translate(float x, float y, float z)
{
	return matrix4(1, 0, 0, x,
		0, 1, 0, y,
		0, 0, 1, z,
		0, 0, 0, 1);
}

matrix4 matrix4::translate(const vector3& v)
{
	return matrix4(1, 0, 0, v.x(),
		0, 1, 0, v.y(),
		0, 0, 1, v.z(),
		0, 0, 0, 1);
}

matrix4 matrix4::scale(float x, float y, float z)
{
	return matrix4(x, 0, 0, 0,
		0, y, 0, 0,
		0, 0, z, 0,
		0, 0, 0, 1);
}

matrix4 matrix4::scale(const vector3& v)
{
	return matrix4(v.x(), 0, 0, 0,
		0, v.y(), 0, 0,
		0, 0, v.z(), 0,
		0, 0, 0, 1);
}

matrix4 matrix4::rotateX(float angle)
{
	float cos_a = cosf(angle);
	float sin_a = sinf(angle);

	return matrix4(1, 0, 0, 0,
		0, cos_a, -sin_a, 0,
		0, sin_a, cos_a, 0,
		0, 0, 0, 1);
}

matrix4 matrix4::rotateY(float angle)
{
	float cos_a = cosf(angle);
	float sin_a = sinf(angle);

	return matrix4(cos_a, 0, sin_a, 0,
		0, 1, 0, 0,
		-sin_a, 0, cos_a, 0,
		0, 0, 0, 1);
}

matrix4 matrix4::rotateZ(float angle)
{
	float cos_a = cosf(angle);
	float sin_a = sinf(angle);

	return matrix4(cos_a, -sin_a, 0, 0,
		sin_a, cos_a, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
}
