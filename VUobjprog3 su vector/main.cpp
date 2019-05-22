#include "headers/main_header.h"
#include "headers/studentas.h"
#include "headers/zmogus.h"

int main() {

    vector<Studentas> stud;
    vector<Studentas> vargsiukaii;
    std::chrono::time_point<std::chrono::high_resolution_clock> start, end;
    std::chrono::duration<float> duration;

    int ilgVar = 0;
    int ilgPav = 0;
    static const int N = 100000;
    fileGenerate(N);
    start_c(start);

    std::vector<Studentas> stud1;
    std::vector<Studentas> vargsiukaii1;

    failoSkaitymas(stud1,ilgVar,ilgPav,N);
    end_c(end);
    std::chrono::duration<double> time5 = end-start;
    cout << "Irasymas i std::vector uztruko " << time5.count() << "sec"  << endl;
    //ailoSkaitymas(stud,ilgVar,ilgPav,N);
    start_c(start);
    skirstymas(stud1,vargsiukaii1,N);
    //vargsiukaii = vargsiukai(stud);
    end_c(end);
    std::chrono::duration<double> time6 = end-start;
    cout << "std::vector rusiavimas uztruko " << time6.count() << "sec" << endl;
    start_c(start);
    isvedimas(stud1,vargsiukaii1,ilgVar,ilgPav);
    end_c(end);
    std::chrono::duration<double> time7 = end-start;
    cout << "std::vector isvedimas uztruko " << time7.count() << "sec" << endl << endl;
    stud1.resize(1);
    std::chrono::time_point<std::chrono::high_resolution_clock> start1, end1;
    std::chrono::duration<float> duration1;

    unsigned int sz = 100000;

    int n = 0;
    start1 = std::chrono::high_resolution_clock::now();
    std::vector<int> b;
    for (int i = 1; i <= sz; ++i){
        if(b.capacity() == b.size()){
            n++;
        }
        b.push_back(i);
    }

    end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time10 = end1-start1;
    cout << "std::vector uztruko su int tipo duomenimis " << time10.count() << "sec"  << endl;
    cout << "std::vector perskirste kartu: " << n << endl;
    cout << endl << endl;

    failoSkaitymas(stud,ilgVar,ilgPav,N);
    end_c(end);
    std::chrono::duration<double> time1 = end-start;
    cout << "Irasymas i vec::vector uztruko " << time1.count() << "sec"  << endl;
    //failoSkaitymas(stud,ilgVar,ilgPav,N);
    start_c(start);
    skirstymas(stud,vargsiukaii,N);
    //vargsiukaii = vargsiukai(stud);
    end_c(end);
    std::chrono::duration<double> time2 = end-start;
    cout << "vec::vector rusiavimas uztruko " << time2.count() << "sec" << endl;
    start_c(start);
    isvedimas(stud,vargsiukaii,ilgVar,ilgPav);
    end_c(end);
    std::chrono::duration<double> time3 = end-start;
    cout << "vec::vector isvedimas uztruko " << time3.count() << "sec" << endl;
    cout << endl;

    n = 0;
    start1 = std::chrono::high_resolution_clock::now();
    vec::vector<int> a;
    for (int i = 1; i <= sz; i++){
        if(a.capacity() == a.size()){
            n++;
        }
        a.push_back(i);
    }

    end1 = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> time9 = end1-start1;
    cout << "vec::vector uztruko su int tipo duomenimis " << time9.count() << "sec"  << endl;
    cout << "vec::vector perskirste kartu: " << n << endl;

    return 0;
}