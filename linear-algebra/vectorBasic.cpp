#include "vector.h"

Vector::Vector(const std::vector<double> vals) : data(vals) {}

Vector &Vector::operator=(const Vector &v)
{
    if (this == &v)
    {
        return *this;
    }
    this->data = v.data;
    return *this;
}

Vector Vector::add(const Vector &v)
{
    assert(data.size() == v.data.size());
    std::vector<double> temp;
    for (size_t i = 0; i < data.size(); i++)
    {
        temp.push_back(data[i] + v.data[i]);
    }
    Vector temp1(temp);
    return temp1;
}

double &Vector::operator[](size_t index)
{
    return data[index];
}

const double &Vector::operator[](size_t index) const
{
    return data[index];
}

size_t Vector::size() const { return data.size(); }

double Vector::dot(const Vector &v) const
{
    assert(data.size() == v.data.size());
    double dot = 0;
    for (size_t i = 0; i < data.size(); i++)
    {
        dot += data[i] * v.data[i];
    }
    return dot;
}

double Vector::norm_L1()
{
    double sum = 0;
    for (auto i : data)
        sum += std::fabs(i);
    return sum;
}

double Vector::norm_L2() const
{
    double L2 = 0;
    for (auto i : data)
        L2 += pow(i, 2);
    return sqrt(L2);
}

Vector Vector::normalize() const
{
    double magnitude = norm_L2();
    std::vector<double> temp;
    for (size_t i = 0; i < data.size(); i++)
    {
        temp.push_back(data[i] / magnitude);
    }
    Vector temp1(temp);
    return temp1;
}

Vector Vector::scale(double scalar)
{
    std::vector<double> temp;
    for (size_t i = 0; i < data.size(); i++)
    {
        temp.push_back(data[i] * scalar);
    }
    Vector temp1(temp);
    return temp1;
}

double Vector::costheta(Vector &v) { return dot(v) / (norm_L2() * (v.norm_L2())); }

double Vector::angle(Vector &v) { return std::acos(costheta(v)); }

Vector Vector::project(Vector &v)
{
    Vector vUnit_Vec = v.normalize();
    double This_mag = norm_L2();
    double scalar = This_mag * costheta(v);
    for (size_t i = 0; i < vUnit_Vec.data.size(); i++)
        vUnit_Vec.data[i] *= scalar;
    return vUnit_Vec;
}

void Vector::display()
{
    std::cout << "[";
    for (size_t i = 0; i < data.size() - 1; i++)
    {
        std::cout << data[i] << ", ";
    }
    std::cout << data[data.size() - 1] << "]\n";
}
