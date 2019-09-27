#include "vector3.h"

vector3::vector3()
	: data{ 0.0f, 0.0f, 0.0f }
{
}

vector3::vector3(float x, float y, float z)
	: data{ x, y, z }
{

}

vector3::vector3(const vector3& v)
	: data{ v.data[0], v.data[1], v.data[2] }
{
}

vector3& vector3::operator=(const vector3& v)
{
	data[0] = v.data[0];
	data[1] = v.data[1];
	data[2] = v.data[2];

	return *this;
}

float vector3::x() const
{
	return data[0];
}

void vector3::setX(float x)
{
	data[0] = x;
}

float vector3::y() const
{
	return data[1];
}

void vector3::setY(float y)
{
	data[1] = y;
}

float vector3::z() const
{
	return data[2];
}

void vector3::setZ(float z)
{
	data[2] = z;
}


float vector3::getLength() const
{
    return sqrtf(data[0] * data[0] + data[1] * data[1] + data[2] * data[2]);
}

vector3 vector3::getNormalized() const
{
	vector3 v(*this);
	v.normalize();
	return v;
}

void vector3::normalize()
{
	data[0] /= getLength();
	data[1] /= getLength();
	data[2] /= getLength();
}

vector3 vector3::operator+(const vector3& v) const
{
	return vector3(data[0] + v.x(), data[1] + v.y(), data[2] + v.z());
}

vector3 vector3::operator-(const vector3& v) const
{
	return vector3(data[0] - v.x(), data[1] - v.y(), data[2] - v.z());
}

vector3 vector3::operator+() const
{
	return *this;
}

vector3 vector3::operator-() const
{
	return vector3(-data[0], -data[1], -data[2]);
}

vector3& vector3::operator+=(const vector3& v)
{
	data[0] += v.x();
	data[1] += v.y();
	data[2] += v.z();

	return *this;
}

vector3& vector3::operator-=(const vector3& v)
{
	data[0] -= v.x();
	data[1] -= v.y();
	data[2] -= v.z();

	return *this;
}

float vector3::operator[](size_t index) const
{
	assert(index < 3);
	return data[index];
}

float& vector3::operator[](size_t index)
{
	assert(index < 3);
	return data[index];
}

float vector3::dot(const vector3& a, const vector3& b)
{
	return a.x() * b.x() + a.y() * b.y() + a.z() * b.z();
}

vector3 vector3::cross(const vector3& a, const vector3& b)
{
	return vector3(a.y() * b.z() - b.y() * a.z(), a.z() * b.x() - a.x() * b.z(), a.x() * b.y() - a.y() * b.x());
}

float vector3::cosBetween(const vector3& a, const vector3& b)
{
	return dot(a, b) / (a.getLength() * b.getLength());
}

float vector3::angleBetween(const vector3& a, const vector3& b)
{
    return acosf(cosBetween(a, b));
}

float vector3::distance(const vector3& a, const vector3& b)
{
	return sqrtf((a.x() - b.x()) * (a.x() - b.x()) +
		(a.y() - b.y()) * (a.y() - b.y()) +
		(a.z() - b.z()) * (a.z() - b.z()));
}
