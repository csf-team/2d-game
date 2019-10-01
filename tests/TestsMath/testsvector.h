#ifndef TESTSVECTOR_H
#define TESTSVECTOR_H

#include "Math/vector2.h"
#include "Math/vector3.h"
#include "Math/vector4.h"

const float EPS = 1e-9f;

class TestsVector
{
public:
    TestsVector() = default;

    static void testNormalize();
};

#endif // TESTSVECTOR_H
