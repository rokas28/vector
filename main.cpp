#include <iostream>
#include "vector.h"

using std::cout;
using std::endl;

int main() {

    vec::vector<int> v;
    vec::vector<int> v1(3, 10);
    vec::vector<int> v2(5);
    vec::vector<int> v3{ 5, 10, 20, 8, 8, 9 };

    cout << v1.size() << endl;
    cout << v1.capacity() << endl;

    v1.push_back(2);
    v1.push_back(5);
    v1.push_back(3);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);
    v1.push_back(4);

    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
    cout << v1[3] << endl;

    return 0;
}