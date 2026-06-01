#include <iostream>
#include <vector>
#include <cmath>
#include <cassert>

class Vector
{
    std::vector<double> data;

public:
    Vector(const std::vector<double> vals) : data(vals) {}

    Vector &operator=(const Vector &v)
    {
        if (this == &v)
        {
            return *this;
        }
        this->data = v.data;
        return *this;
    }

    Vector add(const Vector &v)
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

    size_t size() const { return data.size(); }

    double dot(const Vector &v) const
    {
        assert(data.size() == v.data.size());
        double dot = 0;
        for (size_t i = 0; i < data.size(); i++)
        {
            dot += data[i] * v.data[i];
        }
        return dot;
    }

    double norm_L1()
    {
        double sum = 0;
        for (auto i : data)
            sum += std::fabs(i);
        return sum;
    }

    double norm_L2() const
    {
        double L2 = 0;
        for (auto i : data)
            L2 += pow(i, 2);
        return sqrt(L2);
    }

    Vector normalize() const
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

    Vector scale(double scalar)
    {
        std::vector<double> temp;
        for (size_t i = 0; i < data.size(); i++)
        {
            temp.push_back(data[i] * scalar);
        }
        Vector temp1(temp);
        return temp1;
    }

    double costheta(Vector &v) { return dot(v) / (norm_L2() * (v.norm_L2())); }

    double angle(Vector &v) { return std::acos(costheta(v)); }

    Vector project(Vector &v)
    {
        Vector vUnit_Vec = v.normalize();
        double This_mag = norm_L2();
        double scalar = This_mag * costheta(v);
        for (size_t i = 0; i < vUnit_Vec.data.size(); i++)
            vUnit_Vec.data[i] *= scalar;
        return vUnit_Vec;
    }

    void display()
    {
        std::cout << "[";
        for (size_t i = 0; i < data.size() - 1; i++)
        {
            std::cout << data[i] << ", ";
        }
        std::cout << data[data.size() - 1] << "]\n";
    }
};

int main()
{
    // Test Case 1
    Vector v1({3, 4}), v2({1, 0});
    Vector v3 = v1.project(v2);
    std::cout << "Projection of v1 on v2 is: ";
    v3.display();

    // Test Case 2
    Vector a({1, 0, 0}), b({0, 1, 0});
    std::cout << "a.b = " << a.dot(b) << "\n";
    std::cout << "Angle between a and b = " << a.angle(b) << std::endl;

    // Test Case 3
    std::cout << "v1: ";
    v1.display();
    std::cout << "Norm_L1 of v1: " << v1.norm_L1() << std::endl;
    std::cout << "Norm_L2 of v1: " << v1.norm_L2() << std::endl;

    // Test Case 4
    Vector a1({2, -1, 3}), b2({1, 4, -2});
    std::cout << "a2.b2 = " << a1.dot(b2) << std::endl;

    return 0;
}