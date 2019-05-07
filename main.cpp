#include <iostream>
#include "vector.h"

int main() {

    //vec::vector<int> v1;
    vec::vector<int> v{ 5, 10 };
    v.push_back(2);
    std::cout << v.size() << std::endl;
    std::cout << v[0] << std::endl;

    return 0;
}