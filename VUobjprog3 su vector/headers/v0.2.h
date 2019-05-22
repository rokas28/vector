#ifndef UNTITLED_IOSTREAM_INPUT_H
#define UNTITLED_IOSTREAM_INPUT_H

#include "main_header.h"
#include "studentas.h"

void varTikrinimas(std::vector<Studentas>& stud, int y);
void pavTikrinimas(std::vector<Studentas>& stud, int y);
void fTikrinimas(int &f);
void egzIvedimas(std::vector<Studentas>& stud, int y, int f);
void ndIvedimas(std::vector<Studentas>& stud, int y, int f);
void generate( std::vector<Studentas>& stud, int &ilgVar, int &ilgPav );
bool netinkamasPav(const string a);
void ndGen(std::vector<Studentas>& stud, int x, int y);
void egGen(std::vector<Studentas>& stud, int y);
void galutinis(std::vector<Studentas>& stud, int x, int y);
void stringTikrinimas (std::ifstream &df, string a, bool &fail, int eil);
void nd(std::ifstream &df,std::vector<Studentas> &stud, int x, int y, bool &fail, int eil);
void egz(std::ifstream &df,std::vector<Studentas> &stud, int y, bool &fail, int eil);
void rikiavimas(std::vector<Studentas>& stud);

#endif //UNTITLED_IOSTREAM_INPUT_H
