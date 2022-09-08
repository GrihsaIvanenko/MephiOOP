#include "matrix.h"

#include <iostream>

int main()
{
    matrix::Matrix* mat = nullptr;
    int codeError = matrix::readMatrix(mat);
    if (codeError) {
        std::cout << matrix::ERROR_DESCRIPTION[codeError] << '\n';
        return 0;
    }
    matrix::Result* res = matrix::countResult(mat);
    matrix::print(mat, res);
    mat->~Matrix();
    res->~Result();
    return 0;
}

