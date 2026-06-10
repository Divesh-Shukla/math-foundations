#include "vector.h"
#include "matrix.h"

matrix::matrix(std::vector<std::vector<double>> inputData) : grid(inputData) {}

matrix::matrix(const matrix &copy)
{
    grid = copy.grid;
}

matrix &matrix::operator=(const matrix &copy)
{
    if (this == &copy)
        return *this;
    grid = copy.grid;
    return *this;
}

matrix::matrix(std::initializer_list<std::initializer_list<double>> init)
{
    for (auto row : init)
        grid.push_back(std::vector<double>(row));
}

matrix matrix::multiply(const matrix &m2)
{
    if (grid[0].size() != m2.grid.size())
        throw std::invalid_argument("incompatible matrix dimension for multiplication!\n");
    std::vector<std::vector<double>> temp(this->grid.size(), std::vector<double>(m2.grid[0].size(), 0));
    for (size_t i = 0; i < grid.size(); i++)
    {
        for (size_t j = 0; j < m2.grid[0].size(); j++)
        {
            for (size_t k = 0; k < this->grid[0].size(); k++)
            {
                temp[i][j] += this->grid[i][k] * m2.grid[k][j];
            }
        }
    }
    matrix temp1(temp);
    return temp1;
}

matrix matrix::transpose()
{
    std::vector<std::vector<double>> temp(this->grid[0].size(), std::vector<double>(this->grid.size()));
    for (size_t i = 0; i < this->grid.size(); i++)
        for (size_t j = 0; j < this->grid[0].size(); j++)
            temp[j][i] = this->grid[i][j];
    matrix transpose(temp);
    return transpose;
}

void matrix::display()
{
    for (const auto &row : grid)
    {
        std::cout << "| ";
        for (const auto &elem : row)
            std::cout << elem << " ";
        std::cout << "|\n";
    }
}

Vector matrix::vector_multiply(const Vector &v)
{
    if (grid[0].size() != v.size())
        throw std::invalid_argument("incompatible dimensions for vector multiplication!");
    std::vector<std::vector<double>> temp(grid);
    for (size_t i = 0; i < temp.size(); i++)
    {
        for (size_t j = 0; j < temp[0].size(); j++)
        {
            temp[i][j] *= v[j];
        }
    }
    std::vector<double> sumOfCols(v.size(), 0);
    for (size_t i = 0; i < temp.size(); i++)
    {
        for (size_t j = 0; j < temp[0].size(); j++)
        {
            sumOfCols[i] += temp[i][j];
        }
    }
    Vector resultant(sumOfCols);
    return resultant;
}

matrix matrix::identity(int n)
{
    if (n < 0)
        throw std::invalid_argument("n cannot be less than 0");
    else if (n > 1000)
        throw std::invalid_argument("n can't be larger than 1000!");
    std::vector<std::vector<double>> m(n, std::vector<double>(n, 0));
    for (size_t i = 0; i < n; i++)
        m[i][i] = 1;
    matrix temp(m);
    return temp;
}

double matrix::determinantOf2(const matrix &m)
{
    if (m.grid.size() != m.grid[0].size())
        throw std::invalid_argument("determinant can be found only for square matrix");
    if (m.grid.size() != 2)
        throw std::invalid_argument("dimension of matrix is not 2");
    double value = (m.grid[0][0] * m.grid[1][1]) - (m.grid[0][1] * m.grid[1][0]);
    return value;
}

double matrix::determinantOf3(const matrix &m)
{
    if (m.grid.size() != m.grid[0].size())
        throw std::invalid_argument("determinant can only be found for square matrix");
    if (m.grid.size() != 3)
        throw std::invalid_argument("dimension of matrix is not 3");
    double temp = m.grid[0][0] * ((m.grid[1][1] * m.grid[2][2]) - (m.grid[2][1] * m.grid[1][2]));
    double temp1 = (-1) * m.grid[0][1] * ((m.grid[1][0] * m.grid[2][2]) - (m.grid[2][0] * m.grid[1][2]));
    double temp2 = m.grid[0][2] * ((m.grid[1][0] * m.grid[2][1]) - (m.grid[2][0] * m.grid[1][1]));
    double result = temp + temp1 + temp2;
    return result;
}
