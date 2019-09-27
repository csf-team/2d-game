#include "vector2.h"

vector2::vector2() : vector2(0.0f, 0.0f)
{
}

vector2::vector2(float x, float y) : data{ x ,y }
{
}

vector2::vector2(const vector2& v) : data{ v.x(), v.y() }
{
}

vector2& vector2::operator=(const vector2& v)
{
	data[0] = v.x();
	data[1] = v.y();
	return *this;
}

float vector2::x() const
{
	return data[0];
}

void vector2::setX(float x)
{
	data[0] = x;
}

float vector2::y() const
{
	return data[1];
}

void vector2::setY(float y)
{
	data[1] = y;
}

float vector2::getLength() const
{
	return sqrtf(data[0] * data[0] + data[1] * data[1]);
}

vector2 vector2::getNormalized() const
{
	return vector2(data[0] / getLength(), data[1] / getLength());
}

void vector2::normalize()
{
	data[0] /= getLength();
	data[1] /= getLength();
}

vector2 vector2::operator+(const vector2& v) const
{
	return vector2(data[0] + v.x(), data[1] + v.y());
}

vector2 vector2::operator-(const vector2& v) const
{
	return vector2(data[0] - v.x(), data[1] - v.y());
}

vector2 vector2::operator+() const
{
	return vector2(*this);
}

vector2 vector2::operator-() const
{
	return vector2(-data[0], -data[1]);
}

vector2& vector2::operator+=(const vector2& v)
{
	data[0] += v.x();
	data[1] += v.y();
	return *this;
}

vector2& vector2::operator-=(const vector2& v)
{
	data[0] -= v.x();
	data[1] -= v.y();
	return *this;
}

float vector2::operator[](size_t index) const
{
	assert(index < 2);
	return data[index];
}

float& vector2::operator[](size_t index)
{
	assert(index < 2);
	return data[index];
}

float vector2::dot(const vector2& a, const vector2& b)
{
	return a.x() * b.x() + a.y() * b.y();
}

float vector2::cosBetween(const vector2& a, const vector2& b)
{
	return dot(a, b) / (a.getLength() * b.getLength());
}

float vector2::angleBetween(const vector2& a, const vector2& b)
{
	return acosf(cosBetween(a, b));
}

float vector2::distance(const vector2& a, const vector2& b)
{
    return sqrtf((a.x() - b.x()) * (a.x() - b.x()) +
		(a.y() - b.y()) * (a.y() - b.y()));
}
