# VU objektinio programavimo ketvirta užduotis

Tai yra savadarbis `vec::vector` konteinerio kūrimas.  
Užduoties reikalavimus galite pamatyti [čia](https://github.com/objprog/paskaitos2019/wiki/4-oji-u%C5%BEduotis).  

### std::vector ir vec::vector palyginimas, naudojant `push_back()` funkciją
10000 int elementų:
```
vec::vector uztruko 0.000215385sec
std::vector uztruko 0.00247138sec
```
100000 int elementų:
```
vec::vector uztruko 0.00138995sec
std::vector uztruko 0.0159409sec
```
1000000 int elementų:
```
vec::vector uztruko 0.0121456sec
std::vector uztruko 0.156614sec
```
10000000 int elementų:
```
vec::vector uztruko 0.163004sec
std::vector uztruko 1.6131sec
```
Naudojamas laiko matavimo kodas:
```javascript
#include "main.h"

int main() {

    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

    unsigned int sz = 10000000;

    start = std::chrono::high_resolution_clock::now();
    vec::vector<int> a;
    for (int i = 1; i <= sz; ++i)
        a.push_back(i);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time = end-start;
    cout << "vec::vector uztruko " << time.count() << "sec"  << endl;
    
    
    start = std::chrono::high_resolution_clock::now();
    std::vector<int> b;
    for (int i = 1; i <= sz; ++i)
        b.push_back(i);
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time1 = end-start;
    cout << "std::vector uztruko " << time1.count() << "sec"  << endl;

    return 0;
}
```
### std::vector ir vec::vector atminties perskirstymų palyginimas užpildant 10000000 elementų
```
vec::vector perskirste kartu: 24
std::vector perskirste kartu: 41
```
Naudojamas laiko matavimo kodas:
```javascript
#include "main.h"

int main() {

    unsigned int sz = 10000000;

    int n = 0;

    vec::vector<int> a;
    for (int i = 1; i <= sz; ++i){
        if(a.capacity() == a.size()){
            n++;
        }
        a.push_back(i);
    }
    cout << "vec::vector perskirste kartu: " << n << endl;

    n = 0;

    std::vector<int> b;
    for (int i = 1; i <= sz; ++i){
        if(b.capacity() == b.size()){
            n++;
        }
        b.push_back(i);
    }
    cout << "std::vector perskirste kartu: " << n << endl;

    return 0;
}
```
### std::vector ir vec::vector palyginimas [VUobjprog3](https://github.com/rokas28/VUobjprog3) užduotyje su 100000 studentų įrašų
```
Irasymas i std::vector uztruko 3.8255sec
std::vector rusiavimas uztruko 2.59316sec
std::vector isvedimas uztruko 2.26464sec
```
```
Irasymas i vec::vector uztruko 4.80187sec
vec::vector rusiavimas uztruko 2.66218sec
vec::vector isvedimas uztruko 2.12293sec
```
### Assign funkcija
```javascript

        void assign(size_t count, const T& val) {
            assign(0, count, val);
        }

        void assign(size_t first, size_t last, const T& val) {
            n = last;
            for (size_t i = first; (i < last) && (i < n); i++)
                elem[i] = val;
        }

        void assign(std::initializer_list<T> il){
            n = static_cast<std::size_t>(il.size());
            cap = static_cast<std::size_t>(il.size());
            elem = new T[il.size()];
            std::move(il.begin(), il.end(), elem);
        }
```
Assign funkcija yra skirta priskirti reikšmes vektoriui.
### Iteratorius begin
```javascript
        T* begin() {
            if (n == 0) cout << "empty vector" << endl;
            return elem;
        }
```
Iteratorius begin yra skirtas rasti vektoriaus pradžią.
### Swap funkcija
```javascript
        void swap(vector<T> & v){
            vector<T> a;
            a.elem = new T[v.n];
            a.n = v.n;
            a.n = v.cap;
            std::move(v.begin(), v.end(), a.begin());
            v.elem = new T[n];
            v.n = n;
            v.cap = cap;
            std::move(&elem[0], &elem[n], v.begin());
            elem = new T[a.n];
            n = a.n;
            cap = a.cap;
            std::move(a.begin(), a.end(), elem);
        }
```
Funkcija swap yra skirta apkeisti dviejų vektorių elemntus vietomis.
### Pop_back funkcija 
```javascript
        void pop_back() {
            if (!n)
                return;
            else
                n--;
        }
```
Funkcija pop_back yra skirta sumažinti vektorių vienu elementu.
### Operatorius<
```javascript
    template < typename T >
    bool operator< (const vector <T>& left, const vector <T>& right) {

        if(left.empty() && right.empty()) return false;
        else if (left.empty()) return true;
        else if (right.empty()) return false;
        else {
            int i = 0;
            while(left[i]==right[i]){
                if((i+1 > left.n)||(i+1 > right.n)) break;
                i++;
            }
            if(left[i] < right[i]) return true;
            else if(left[i] == right[i]){
                if(left.n < right.n) return true;
                else return false;
            }
            else return false;
        }
    }
```
Operatorius < yra skirtas palyginti ar pirminio vektoriaus elementai yra mažesni už antro.