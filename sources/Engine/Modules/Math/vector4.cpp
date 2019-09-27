#include "vector4.h"

vector4::vector4()
	: data{ 0.0f, 0.0f, 0.0f, 0.0f }
{
}

vector4::vector4(float x, float y, float z, float w)
	: data{ x, y, z, w }
{

}

vector4::vector4(const vector4& v)
	: data{ v.data[0], v.data[1], v.data[2], v.data[3] }
{
}

vector4& vector4::operator=(const vector4& v)
{
	data[0] = v.x();
	data[1] = v.y();
	data[2] = v.z();
	data[3] = v.w();

	return *this;
}

float vector4::x() const
{
	return data[0];
}

void vector4::setX(float x)
{
	data[0] = x;
}

float vector4::y() const
{
	return data[1];
}

void vector4::setY(float y)
{
	data[1] = y;
}

float vector4::z() const
{
	return data[2];
}

void vector4::setZ(float z)
{
	data[2] = z;
}

float vector4::w() const
{
	return data[3];
}

void vector4::setW(float w)
{
	data[3] = w;
}

float vector4::getLength() const
{
    return sqrtf(data[0] * data[0] + data[1] * data[1] + data[2] * data[2] + data[3] * data[3]);
}

vector4 vector4::getNormalized() const
{
	vector4 v(*this);
	v.normalize();
	return v;
}

void vector4::normalize()
{
	data[0] /= getLength();
	data[1] /= getLength();
	data[2] /= getLength();
	data[3] /= getLength();
}

vector4 vector4::operator+(const vector4& v) const
{
	return vector4(data[0] + v.x(), data[1] + v.y(), data[2] + v.z(), data[3] + v.w());
}

vector4 vector4::operator-(const vector4& v) const
{
	return vector4(data[0] - v.x(), data[1] - v.y(), data[2] - v.z(), data[3] - v.w());
}

vector4 vector4::operator+() const
{
	return *this;
}

vector4 vector4::operator-() const
{
	return vector4(-data[0], -data[1], -data[2], -data[3]);
}

vector4& vector4::operator+=(const vector4& v)
{
	data[0] += v.x();
	data[1] += v.y();
	data[2] += v.z();
	data[3] += v.w();

	return *this;
}

vector4& vector4::operator-=(const vector4& v)
{
	data[0] -= v.x();
	data[1] -= v.y();
	data[2] -= v.z();
	data[3] -= v.w();

	return *this;
}

float vector4::operator[](size_t index) const
{
	assert(index < 4);
	return data[index];
}

float& vector4::operator[](size_t index)
{
	assert(index < 4);
	return data[index];
}

float vector4::dot(const vector4& a, const vector4& b)
{
	return a.x() * b.x() + a.y() * b.y() + a.z() * b.z() + a.w() * b.w();
}
