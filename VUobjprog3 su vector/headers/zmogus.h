#ifndef UNTITLED_ZMOGUS_H
#define UNTITLED_ZMOGUS_H

#include "main_header.h"

class Zmogus {
private:
    string vardas, pavarde;
public:
    void set_name(string &a){ vardas = a; };
    void set_lastname (string &a) {pavarde = a; };
    string get_name() const {return vardas; };
    string get_lastname() const {return pavarde; };
    virtual void tipas() = 0;
    Zmogus(string a, string b) {
        vardas = a;
        pavarde = b;
    };
    Zmogus(){};
};

#endif //UNTITLED_ZMOGUS_H
