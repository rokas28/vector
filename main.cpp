#include <iostream>
#include "vector.h"

using std::cout;
using std::endl;

int main() {

    vec::vector<int> v;
    vec::vector<int> v1(3, 10);
    vec::vector<int> v2(5);
    vec::vector<int> v3{ 5, 10, 20, 8, 8, 9 };

    /*v.assign(3,20);
    cout << v[2] << endl;*/
    /*v.assign(3,20);
    for(auto i : v){
        cout << i << endl;
    }*/
    /*cout << v3.begin() << endl;
    cout << v3.end() << endl;*/
    /*v = v3;
    cout << v[2] << endl;
    cout << v3[2] << endl;*/

    /*cout << v1.size() << endl;
    cout << v1.capacity() << endl;
    cout << v.empty() << endl;
    cout << v1.empty() << endl;*/

    /*v3.at(2) = 50;
    cout << v3[2] << endl;
    cout << v3.back() << endl;
    cout << v3.front() << endl;*/

    /*v1.push_back(2);
    v1.push_back(5);
    v1.push_back(3);
    v1.push_back(6);
    v1.push_back(7);
    v1.push_back(8);
    v1.push_back(9);
    v1.push_back(4);
    cout << v1.size() << endl;
    cout << v1.capacity() << endl;
    cout << v1[3] << endl;*/

    return 0;
}