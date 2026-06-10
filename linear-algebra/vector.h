#pragma once
#include <iostream>
#include <cassert>
#include <vector>
#include <stdexcept>
#include <cmath>

class Vector
{
    std::vector<double> data;

public:
    Vector(const std::vector<double> vals);
    Vector &operator=(const Vector &v);
    double &operator[](size_t index);
    const double &operator[](size_t index) const;
    Vector add(const Vector &v);
    size_t size() const;
    double dot(const Vector &v) const;
    double norm_L1();
    double norm_L2() const;
    Vector normalize() const;
    Vector scale(double scalar);
    double costheta(Vector &v);
    double angle(Vector &v);
    Vector project(Vector &v);
    void display();
};