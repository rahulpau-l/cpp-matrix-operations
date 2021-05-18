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

    m2.transpose();

    std::cout << m2 << std::endl;



    return 0;
}
