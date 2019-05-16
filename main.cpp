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

    v1.emplace(v1.begin(),8);
    v1.emplace_back(5);
    v1.emplace_front(7);
    for(auto i : v1)cout << i << " ";
    cout << endl;

    return 0;
}