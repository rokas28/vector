#include "main.h"

int main() {

    vec::vector<int> v;
    vec::vector<int> v1(3,10);
    vec::vector<int> v2(5);
    vec::vector<int> v3{ 5, 10, 20, 8, 8, 9, 5, 4, 10};
    vec::vector<int> v4(4,6);

    vec::vector<int>c{5,50,5,10,5};
    vec::vector<int>d{1,50,5,10,5,2};

    v.assign({1,2,3,4,5});
    for(auto i : v)cout << i << " ";
    cout << endl;
    v.pop_back();
    v.pop_back();
    for(auto i : v)cout << i << " ";
    cout << endl;
    v.push_back(7);
    for(auto i : v)cout << i << " ";
    cout << endl;
    v.swap(v4);
    for(auto i : v)cout << i << " ";
    cout << endl;
    for(auto i : v4)cout << i << " ";
    cout << endl;

    if ((c<d)) std::cout << "c<d\n";
    if (c>d) std::cout << "c>d\n";
    if (c<=d) std::cout << "c<=d\n";
    if (c>=d) std::cout << "c>=d\n";

    v1.emplace(v1.begin(),8);
    v1.emplace_back(5);
    v1.emplace_front(7);
    for(auto i : v1)cout << i << " ";
    cout << endl;

    v3.insert(v3.begin()+3, 5);
    v3.insert(v3.begin(),2, 77);
    v3.insert(v3.begin()+6, {100,4,5,200});
    for(auto i : v3)cout << i << " ";
    cout << endl;
    v3.erase(v3.begin()+1,v3.begin()+3);
    for(auto i : v3)cout << i << " ";
    cout << endl;

    return 0;
}