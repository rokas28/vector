#include "main.h"

int main() {

    vec::vector<int> v;
    vec::vector<int> v1(3,10);
    vec::vector<int> v2(5);
    vec::vector<int> v3{ 5, 10, 20, 8, 8, 9, 5, 4, 10};

    vec::vector<int>c{5,50,5,10,5};
    vec::vector<int>d{1,50,5,10,5,2};

    if ((c<d)) std::cout << "c<d\n";
    if (c>d) std::cout << "c>d\n";
    if (c<=d) std::cout << "c<=d\n";
    if (c>=d) std::cout << "c>=d\n";

    return 0;
}