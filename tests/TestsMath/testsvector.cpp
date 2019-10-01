#include "testsvector.h"
#include <QDebug>

void TestsVector::testNormalize()
{
    vector2 vec2(10.3f, 15.7f);
    vec2.normalize();
    if (std::abs(vec2.getLength() - 1.0f) > EPS)
        qDebug() << "bad vec2.normalize(), vec2.getLength() = " << vec2.getLength();
    auto vec2Norm = vec2.getNormalized();
    if (std::abs(vec2Norm.getLength() - 1.0f) > EPS)
        qDebug() << "bad vec2.getNormalized(), vec2Norm.getLength() = " << vec2Norm.getLength();

    vector3 vec3(10.3f, 15.7f, 107.3532f);
    vec3.normalize();
    if (std::abs(vec3.getLength() - 1.0f) > EPS)
        qDebug() << "bad vec3.normalize(), vec3.getLength() = " << vec3.getLength();
    auto vec3Norm = vec3.getNormalized();
    if (std::abs(vec3Norm.getLength() - 1.0f) > EPS)
        qDebug() << "bad vec3.getNormalized(), vec3Norm.getLength() = " << vec3Norm.getLength();

    vector4 vec4(10.3f, 15.7f, 12.4f, 209.6f);
    vec4.normalize();
    if (std::abs(vec4.getLength() - 1.0f) > EPS)
        qDebug() << "bad vec4.normalize(), vec4.getLength() = " << vec4.getLength();
    auto vec4Norm = vec4.getNormalized();
    if (std::abs(vec4Norm.getLength() - 1.0f) > EPS)
        qDebug() << "bad vec4.getNormalized(), vec4Norm.getLength() = " << vec4Norm.getLength();
}
