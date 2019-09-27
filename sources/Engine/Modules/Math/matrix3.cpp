#include "matrix3.h"

matrix3::matrix3()
	: data()
{
	for (size_t i = 0; i < S_SIZE; i++) {
		for (size_t j = 0; j < S_SIZE; j++) {
			data[i][j] = 0.0f;
		}
	}
}

matrix3::matrix3(float m11, float m12, float m13, float m21, float m22, float m23, float m31, float m32, float m33)
	: data()
{
	data[0][0] = m11;
	data[0][1] = m12;
	data[0][2] = m13;
	data[1][0] = m21;
	data[1][1] = m22;
	data[1][2] = m23;
	data[2][0] = m31;
	data[2][1] = m32;
	data[2][2] = m33;
}

matrix3::matrix3(const matrix3& v)
	: data()
{
	for (size_t i = 0; i < S_SIZE; i++) {
		for (size_t j = 0; j < S_SIZE; j++) {
			data[i][j] = v.data[i][j];
		}
	}
}

matrix3& matrix3::operator=(const matrix3& v)
{
	for (size_t i = 0; i < S_SIZE; i++) {
		for (size_t j = 0; j < S_SIZE; j++) {
			data[i][j] = v.data[i][j];
		}
	}
	return *this;
}

float matrix3::element(size_t r, size_t c) const
{
	assert(r < S_SIZE && c < S_SIZE);
	return data[r][c];
}

void matrix3::setElement(size_t r, size_t c, float value)
{
	assert(r < S_SIZE && c < S_SIZE);
	data[r][c] = value;
}

matrix3 matrix3::operator*(const matrix3& matrix) const
{
	matrix3 result;

	for (size_t r = 0; r < S_SIZE; r++) {
		for (size_t c = 0; c < S_SIZE; c++) {
			for (size_t m = 0; m < S_SIZE; m++) {
				result.data[r][c] += data[r][m] * matrix.data[m][c];
			}
		}
	}
	return result;
}

vector3 matrix3::operator*(const vector3& v) const
{
	vector3 result;

	for (size_t r = 0; r < S_SIZE; r++) {
		for (size_t m = 0; m < S_SIZE; m++) {
			result[r] += data[r][m] * v[m];
		}
	}
	return result;
}

void matrix3::transpose()
{
	std::swap(data[0][1], data[1][0]);
	std::swap(data[0][2], data[2][0]);
	std::swap(data[1][2], data[2][1]);
}

matrix3 matrix3::transposed()
{
	return matrix3(data[0][0], data[1][0], data[2][0],
		data[0][1], data[1][1], data[2][1],
		data[0][2], data[1][2], data[2][2]);
}

void matrix3::inverse()
{
	float a11 = data[1][1] * data[2][2] - data[2][1] * data[1][2];
	float a12 = -(data[1][0] * data[2][2] - data[2][0] * data[1][2]);
	float a13 = data[1][0] * data[2][1] - data[2][0] * data[1][1];

	float det = data[0][0] * a11 + data[0][1] * a12 + data[0][2] * a13;
	if (det == 0.f)
		return;

	float a21 = -(data[0][1] * data[2][2] - data[2][1] * data[0][2]);
	float a22 = data[0][0] * data[2][2] - data[2][0] * data[0][2];
	float a23 = -(data[0][0] * data[2][1] - data[2][0] * data[0][1]);

	float a31 = data[0][1] * data[1][2] - data[1][1] * data[0][2];
	float a32 = -(data[0][0] * data[1][2] - data[1][0] * data[0][2]);
	float a33 = data[0][0] * data[1][1] - data[1][0] * data[0][1];

	data[0][0] = a11 / det;
	data[0][1] = a21 / det;
	data[0][2] = a31 / det;

	data[1][0] = a12 / det;
	data[1][1] = a22 / det;
	data[1][2] = a32 / det;

	data[2][0] = a13 / det;
	data[2][1] = a23 / det;
	data[2][2] = a33 / det;

}

matrix3 matrix3::inversed()
{
	matrix3 result(*this);
	result.inverse();
	return result;
}

matrix3 matrix3::identity()
{
	return matrix3(1, 0, 0,
		0, 1, 0,
		0, 0, 1);
}

matrix3 matrix3::translate(float x, float y)
{
	return matrix3(1, 0, x,
		0, 1, y,
		0, 0, 1);
}

matrix3 matrix3::translate(const vector2& v)
{
	return matrix3(1, 0, v.x(),
		0, 1, v.y(),
		0, 0, 1);
}

matrix3 matrix3::scale(float x, float y)
{
	return matrix3(x, 0, 0,
		0, y, 0,
		0, 0, 1);
}

matrix3 matrix3::scale(const vector2& v)
{
	return matrix3(v.x(), 0, 0,
		0, v.y(), 0,
		0, 0, 1);
}

matrix3 matrix3::rotate(float angle)
{
	float cos_a = cosf(angle);
	float sin_a = sinf(angle);

	return matrix3(cos_a, sin_a, 0,
		-sin_a, cos_a, 0,
		0, 0, 1);
}