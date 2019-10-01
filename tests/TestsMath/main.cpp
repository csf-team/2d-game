#include <QCoreApplication>
#include "testsvector.h"
#include "testsmatrix.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //test vector
    TestsVector::testNormalize();

    //test matrix
    //...code here

    return 0;
}
