#include "../headers/main_header.h"
#include "../headers/studentas.h"
#include "../headers/deque_header.h"

void failoSkaitymas(std::deque<studentas> &stud, int &ilgVar, int &ilgPav){
    std::ifstream df (data);
    if (!df) throw "Duomenu failas nerastas";
    int i=0;
    int eil=0;
    int n = ndSk(df);
    stud.emplace_back(studentas());
    while(true) {

        if (df.eof() == 1) break;
        eil++;
        df >> stud[i].vardas >> stud[i].pavarde;
        if (stud[i].vardas.length() > ilgVar) ilgVar = stud[i].vardas.length();
        if (stud[i].pavarde.length() > ilgPav) ilgPav = stud[i].pavarde.length();
        int q;
        int sum=0;
        for(int u=0;u<6;u++){
            df >> q;
            stud[i].nd.emplace_back(q);
            sum = sum + q;
        }
        df >> stud[i].egzaminas;
        stud[i].vidGalutinis =  0.4 * sum/n + 0.6 * stud[i].egzaminas;
        if (df.eof() == 1) break;
        i++;
        stud.emplace_back(studentas());
    }

    df.seekg(0);
    df.clear();
    stud.shrink_to_fit();
};

void rusiavimas(std::deque<studentas>& stud) {
    sort(stud.begin(), stud.end(), [](const studentas &lhs, const studentas &rhs) {
        return ( lhs.vidGalutinis > rhs.vidGalutinis );
    });
};

void skirstymas(std::deque<studentas>& stud, std::deque<studentas>& vargsiukai, int x){
    rusiavimas(stud);
    int i = x;
    int k =0;
    while(stud[i].vidGalutinis < 5){
        k++;
        i--;
    }
    std::move(stud.end()-k, stud.end(),std::back_inserter(vargsiukai));
    stud.erase (stud.end()-k, stud.end());
}
void skirstymas2(std::deque<studentas>& stud, std::deque<studentas>& vargsiukai, std::deque<studentas>& galvociai, int x){
    rusiavimas(stud);
    int i = x;
    int k =0;
    while(stud[i].vidGalutinis < 5){
        k++;
        i--;
    }
    std::move(stud.begin(), stud.end()-k-2, std::back_inserter(galvociai));
    std::move(stud.end()-k, stud.end(),std::back_inserter(vargsiukai));
}

void isvedimas( std::deque<studentas> stud, std::deque<studentas> vargsiukai, int ilgVar, int ilgPav){
    std::ofstream gs ("galvociai.txt");
    std::ofstream bs ("vargsiukai.txt");

    gs << std::left << std::setw(ilgVar + 3) << "vardas";
    gs << std::setw(ilgPav + 3) << "Pavarde" << std::setw(10) << "Galutiis(vid.)   "  << endl;
    for(int w=0;w<(ilgVar+ilgPav+6+14);w++) gs << "-";gs <<endl;
    for (auto &i : stud) {
        gs << std::left <<  std::setw(ilgVar+3) << i.vardas << std::setw(ilgPav+3) << i.pavarde;
        gs << std::setw(17) << std::fixed << std::setprecision(2) << i.vidGalutinis << endl;
    }
    gs.close();
    bs << std::left << std::setw(ilgVar + 3) << "vardas";
    bs << std::setw(ilgPav + 3) << "Pavarde" << std::setw(10) << "Galutiis(vid.)   " << endl;
    for(int w=0;w<(ilgVar+ilgPav+6+14);w++) bs << "-";bs <<endl;
    for (auto &i : vargsiukai) {
        bs << std::left <<  std::setw(ilgVar+3) << i.vardas << std::setw(ilgPav+3) << i.pavarde;
        bs << std::setw(17) << std::fixed << std::setprecision(2) << i.vidGalutinis << endl;
    }
    bs.close();
};