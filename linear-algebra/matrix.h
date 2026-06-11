#pragma once

#include "vector.h"

class matrix
{
    std::vector<std::vector<double>> grid;

public:
    matrix(std::vector<std::vector<double>> inputData);

    matrix(const matrix &copy);

    matrix &operator=(const matrix &copy);

    matrix(std::initializer_list<std::initializer_list<double>> init);

    matrix multiply(const matrix &m2);

    matrix transpose();

    void display();

    Vector vector_multiply(const Vector &v);

    static matrix identity(int n);

    static double determinantOf2(const matrix &m);

    static double determinantOf3(const matrix &m);

    matrix inverseOf2();
};
