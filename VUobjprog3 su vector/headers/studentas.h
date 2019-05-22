#ifndef UNTITLED_STUDENTAS_H
#define UNTITLED_STUDENTAS_H

#include "main_header.h"
#include "zmogus.h"
#include "vector.h"

using vec::vector;

class Studentas : public Zmogus {
private:
    int egzaminas;
    double vidGalutinis;
    std::vector<int > nd;
public:
    Studentas(string a, string b) : Zmogus(a,b){};
    Studentas(){};
    void set_vidGalutinis (double &a) { vidGalutinis = a; };
    double get_vidGalutinis() const { return vidGalutinis; };
    double medGalutinis = 0;
    void set_exam (int a);
    int get_exam() {return egzaminas; };
    void set_mark(int a);
    void tipas() {
      cout << "Tai yra studentas" << endl;
    };
    double ndSum(int x);
    double mediana(int x, int y);
    friend bool operator== (const Studentas &a, const Studentas &b) { return a.get_vidGalutinis() == b.get_vidGalutinis(); };
    friend bool operator!= (const Studentas &a, const Studentas &b) { return a.get_vidGalutinis() != b.get_vidGalutinis(); };
    friend std::ostream& operator << (std::ostream &out, const Studentas a) {
        out << std::left <<  std::setw(13+3) << a.get_name() << std::setw(14+3) << a.get_lastname();
        out << std::setw(17) << std::fixed << std::setprecision(2) << a.get_vidGalutinis() << endl;
        return out;
    };
    friend std::istream &operator >> (std::istream & in, Studentas & a) {
        string b;
        cout << " Iveskite varda " << endl;
        in >> b;
        a.set_name(b);
        cout << "Iveskite pavarde " << endl;
        in >> b;
        a.set_lastname(b);
        cout << "Iveskite namu darbu skaiciu ";
        int n;
        in >> n;
        int q;
        int sum = 0;
        for(int u=0;u<n;u++){
            cout << "Iveskite namu darbu pazymi " << endl;
            in >> q;
            if(!in.fail() && q >= 0 && q <= 10){
                if(q!=0) {
                    a.set_mark(q);
                    sum = sum + q;
                }
            }
            else {
                cout << "Netinkamas pazymys, iveskite kita" << endl;
                in.clear();
                in.ignore(256, '\n');
                u--;
                continue;

            }
        }
        while(true){
            int eg = 0;
            cout << "Iveskite egzamino rezultata" << endl;
            in >> eg;
            if( !in.fail() && eg>= 0 && eg <= 10){
                if(eg!=0) {
                    a.egzaminas = eg;
                    break;
                }
            }
            else {
                cout << "Netinkamas pazymys, iveskite kita" << endl;
                in.clear();
                in.ignore(256, '\n');
                continue;
            }
        }
        double galutinis;
        galutinis =  0.4 * sum/n + 0.6 * a.get_exam();
        a.set_vidGalutinis(galutinis);
        return in;
    };
    friend bool operator > (const Studentas &a, const Studentas &b) { return a.get_vidGalutinis() > b.get_vidGalutinis(); };
    friend bool operator < (const Studentas &a, const Studentas &b) { return a.get_vidGalutinis() < b.get_vidGalutinis(); };

    Studentas& operator= (const Studentas &a) {
        if(a == *this) return *this;
        string b;
        b = a.get_name();
        set_name(b);
        b = a.get_lastname();
        set_lastname(b);
        vidGalutinis = a.get_vidGalutinis();
        return *this;
    };
};

int ndSk(std::ifstream &df);
void fileGenerate(int x);
void failoSkaitymas(vector<Studentas> &stud, int &ilgVar, int &ilgPav, int N);
void rusiavimas(vector<Studentas>& stud);
bool negavoSkolos(const Studentas& s);
vector<Studentas> vargsiukai(vector<Studentas>& stud);
void isvedimas( vector<Studentas> stud, vector<Studentas> vargsiukai, int ilgVar, int ilgPav);
void start_c(std::chrono::time_point<std::chrono::high_resolution_clock> &start);
void end_c(std::chrono::time_point<std::chrono::high_resolution_clock> &end);

void skirstymas(vector<Studentas>& stud, vector<Studentas>& vargsiukai, int x);

void rusiavimas(std::vector<Studentas>& stud);
void failoSkaitymas(std::vector<Studentas> &stud, int &ilgVar, int &ilgPav, int N);
void skirstymas(std::vector<Studentas>& stud, std::vector<Studentas>& vargsiukai, int x);
void isvedimas( std::vector<Studentas> stud, std::vector<Studentas> vargsiukai, int ilgVar, int ilgPav);

#endif //UNTITLED_STUDENTAS_H
