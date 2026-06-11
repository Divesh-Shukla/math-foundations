#include "matrix.h"

int main()
{
    matrix m1({{1, 3}, {5, 9}});
    matrix m2({{2, 7}, {3, 2}});
    matrix m3 = m1.multiply(m2);
    std::cout << "m3: \n";
    m3.display();

    std::cout << "m3 transpose: \n";
    m3 = m3.transpose();
    m3.display();

    matrix m4 = {{1, 2, 3}, {4, 5, 6}};
    try
    {
        matrix m5 = m4.multiply(m1);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Caught: " << e.what() << "\n";
    }

    matrix m5 = m1.multiply(m4);

    std::cout << "m5: \n";
    m5.display();

    matrix i0 = matrix::identity(0);
    matrix i1 = matrix::identity(1);
    matrix i2 = matrix::identity(2);
    matrix i3 = matrix::identity(3);
    matrix i_ = {{}};
    try
    {
        matrix i_ = matrix::identity(-1);
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Caught: " << e.what() << "\n";
    }
    std::cout << "i0: \n";
    i0.display();
    std::cout << "i1: \n";
    i1.display();
    std::cout << "i2: \n";
    i2.display();
    std::cout << "i3: \n";
    i3.display();
    std::cout << "i_: \n";
    i_.display();

    std::cout << "Determinant of m1: " << matrix::determinantOf2(m1) << "\n";
    std::cout << "Determinant of m2: " << matrix::determinantOf2(m2) << "\n";
    try
    {
        std::cout << "Determinant of m4: " << matrix::determinantOf2(m4) << "\n";
    }
    catch (const std::invalid_argument &e)
    {
        std::cout << "Caught: " << e.what() << "\n";
    }

    matrix m6 = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    std::cout << "Determinant of m6: " << matrix::determinantOf3(m6) << "\n";

    Vector v({1, 6});
    Vector v1 = i2.vector_multiply(v);
    std::cout << "v1: ";
    v1.display();

    matrix m7 = m1.inverseOf2();
    matrix m8 = m1.multiply(m7);
    std::cout << "m1*m1Inv: \n";
    m8.display();

    return 0;
}