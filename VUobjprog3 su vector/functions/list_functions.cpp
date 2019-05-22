#include "../headers/main_header.h"
#include "../headers/studentas.h"
#include "../headers/list_header.h"

void failoSkaitymas(std::list<studentas> &stud, int &ilgVar, int &ilgPav){
    std::list<studentas>::iterator it;
    std::ifstream df (data);
    if (!df) throw "Duomenu failas nerastas";
    int i=0;
    int eil=0;
    int n = ndSk(df);
    stud.emplace_back(studentas());
    it = stud.begin();
    int a=0;
    while(true) {
        if (df.eof() == 1) break;
        eil++;
        df >> it->vardas >> it->pavarde;
        if (it->vardas.length() > ilgVar) ilgVar = it->vardas.length();
        if (it->pavarde.length() > ilgPav) ilgPav = it->pavarde.length();
        int q;
        int sum=0;
        for(int u=0;u<6;u++){
            df >> q;
            it->nd.emplace_back(q);
            sum = sum + q;
        }
        df >> it->egzaminas;
        it->vidGalutinis =  0.4 * sum/n + 0.6 * it->egzaminas;
        if(it->vidGalutinis>=5)a++;
        if (df.eof() == 1) break;
        i++;
        stud.emplace_back(studentas());
        it++;
    }
};

void rusiavimas(std::list<studentas>& stud) {
    stud.sort([](const studentas &lhs, const studentas &rhs) {
        return ( lhs.vidGalutinis > rhs.vidGalutinis );
    });
};

void skirstymas(std::list<studentas>& stud, std::list<studentas>& vargsiukai){
    rusiavimas(stud);
    std::list<studentas>::iterator it;
    it = stud.begin();
    for(auto l : stud){
        if(l.vidGalutinis >= 5) it++;
    }
    vargsiukai.splice(vargsiukai.begin(), stud, it, stud.end() );
}

void skirstymas2(std::list<studentas>& stud, std::list<studentas>& vargsiukai, std::list<studentas>& galvociai){
    rusiavimas(stud);
    std::list<studentas>::iterator it;
    it = stud.begin();
    for(auto l : stud){
        if(l.vidGalutinis >= 5) it++;
    }
    galvociai.splice(galvociai.begin(), stud, stud.begin(), it);
    vargsiukai.splice(vargsiukai.begin(), stud, it, stud.end());
}

void isvedimas( std::list<studentas> stud, std::list<studentas> vargsiukai, int ilgVar, int ilgPav){
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