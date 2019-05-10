#include "main.h"
#include <vector>

int main() {

    vec::vector<int> v;
    vec::vector<int> v1(3,10);
    vec::vector<int> v2(5);
    vec::vector<int> v3{ 5, 10, 20, 8, 8, 9, 5, 4, 10};

    std::vector<int>a{5,50,5};
    std::vector<int>b{5,50,5,10};

    vec::vector<int>c{5,50,5,10,5};
    vec::vector<int>d{1,50,5,10};

    if (a<b) std::cout << "a<b\n";
    if (a>b) std::cout << "a>b\n";
    if (a<=b) std::cout << "a<=b\n";
    if (a>=b) std::cout << "a>=b\n";

    if ((c<d)) std::cout << "c<d\n";
    if (c>d) std::cout << "c>d\n";
    /*if (c<=d) std::cout << "c<=d\n";
    if (c>=d) std::cout << "c>=d\n";*/

    return 0;
}