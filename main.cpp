#include <iostream>
#include "Matrix.h"

int main() {

    std::vector<std::vector<int>> m {
            {1,0,1},
            {2,0,1},
            {0,1,0}
    };

    std::vector<std::vector<int>> n {
            {1,0,1},
            {9,7,1},
            {4,1,8}
    };


    Matrix<int> m1(m);
    Matrix<int> m2(n);

    m1 = m1 + m2; // adding two matrices
    std::cout << m1 << std::endl;
    m1 = m1 - m2; // subtracting two matrices
    std::cout << m1 << std::endl;
    m1 = m1 * m2; // multiplying two matrices
    std::cout << m1 << std::endl;

    m1.transpose();
    std::cout << m1 << std::endl;






    return 0;
}
