#include "../headers/main_header.h"
#include "../headers/v0.2.h"

void varTikrinimas(std::vector<studentas>& stud, int y){
    cout << "Iveskite studento varda " << endl;
    cin >> stud[y].vardas;
    while(!netinkamasPav(stud[y].vardas)) {
        cout << "Netinkamas vardas, iveskite kita ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> stud[y].vardas;
    }
}

void pavTikrinimas(std::vector<studentas>& stud, int y){
    cout << "Iveskite studento pavarde" << endl;
    cin >> stud[y].pavarde;
    while(!netinkamasPav(stud[y].pavarde)) {
        cout << "Netinkama pavarde, iveskite kita ";
        cin.clear();
        cin.ignore(256, '\n');
        cin >> stud[y].pavarde;
    }
}

void fTikrinimas(int &f){
    while (f!=0 && f!=1){
        cout << "Ivestas neteisingas simbolis, pasirinkite dar karta " << endl;
        cin >> f;
    }
}

void egzIvedimas(std::vector<studentas>& stud, int y, int f){
    if (f==1){
        while(true){
            int eg = 0;
            cout << "Iveskite egzamino rezultata" << endl;
            cin >> eg;
            if( !cin.fail() && eg>= 0 && eg <= 10){
                if(eg!=0) {
                    stud[y].egzaminas = eg;
                    break;
                }
            }
            else {
                cout << "Netinkamas pazymys, iveskite kita" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                continue;
            }
        }
    }
    else if(f==0){
        egGen(stud,y);
    }
}

void ndIvedimas(std::vector<studentas>& stud, int y, int f){
    int k=0;
    int q=1;
    if (f==1){
        cout << "Iveskite namu darbu rezultatus, kai visi namu darbu rezultataibus suvesti, spauskite 0" << endl;
        while(q!=0){
            cout << "Iveskite namu darbu pazymi " << endl;
            cin >> q;
            if(!cin.fail() && q >= 0 && q <= 10){
                if(q!=0) {
                    stud[y].nd.push_back(q);
                    k++;
                }
            }
            else {
                cout << "Netinkamas pazymys, iveskite kita" << endl;
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                q=1;
                continue;

            }
        }

        galutinis(stud,k,y);
    }
    else if(f==0){
        cout << "Iveskite kiek namu darbu pazymiu norite sugeneruoti" << endl;
        int n = 0;
        while(true) {
            cin >> n;
            if (!cin.fail() && n != 0) {
                break;
            } else {
                cout << "Ivestas blogas simbolis, iveskite skaiciu" << endl;
                cin.clear();
                cin.ignore(256, '\n');
                continue;
            }
        }
        ndGen(stud,n,y);
        galutinis(stud,n,y);
    }
}

void generate( std::vector<studentas>& stud, int &ilgVar, int &ilgPav ){
    int i = 0;
    int st = 0;
    stud.reserve(100);
    while(true){
        cout << "Jei norite prideti studenta spauskite 1, jei norite uzbaigti, spauskite 0" << endl;
        cin >> st;
        if (st==1){
            stud.emplace_back(studentas());
            int f;
            varTikrinimas(stud,i);
            pavTikrinimas(stud,i);
            if(stud[i].vardas.length()>ilgVar) ilgVar = stud[i].vardas.length();
            if(stud[i].pavarde.length()>ilgPav) ilgPav = stud[i].pavarde.length();
            cout << "Jei norite ivseti studento egzamino pazymi ranka, spauskite 1, jei norite ji atsitiktinai sugeneruoti, spauskite 0" << endl;
            cin >> f;
            fTikrinimas(f);
            egzIvedimas(stud,i,f);
            cout << "Jei norite ivseti studento namu darbu pazymius ranka, spauskite 1, jei norite juos atsitiktinai sugeneruoti, spauskite 0" << endl;
            cin >>f;
            fTikrinimas(f);
            ndIvedimas(stud,i,f);
            i++;
        }
        else break;
    }
    stud.shrink_to_fit();
};

bool netinkamasPav(const string a){
    for (char i : a) {
        if (!(( i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z'))) return false;
    }
    return true;
}

void ndGen(std::vector<Studentas>& stud, int x, int y){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(1, 10);
    int a;
    for(int j = 0; j < x; j++){
        a=random(gen);
        stud[y].set_mark(a);
    }
}

void egGen(std::vector<Studentas>& stud, int y){
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> random(1, 10);
    stud[y].set_exam(random(gen));
}



void galutinis(std::vector<Studentas>& stud, int x, int y){
    stud[y].vidGalutinis =  0.4 * stud[y].ndSum(x)/x + 0.6 * stud[y].get_exam();
    stud[y].medGalutinis =  0.4 * stud[y].mediana(x,y) + 0.6 * stud[y].get_exam();
}

void stringTikrinimas (std::ifstream &df, string a, bool &fail, int eil){
    if(!netinkamasPav(std::move(a))) {
        df.clear();
        df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        fail = true;
        cout << "Ivestas netinkamas vardas arba pavarde " << eil << " eiluteje. Del to studento duomenys nebuvo nuskaityti. " << endl;
    }
}

void nd(std::ifstream &df,std::vector<Studentas> &stud, int x, int y, bool &fail, int eil){
    int q=0;
    for(int j = 0; j < x; j++){
        df >> q;
        if(!df.fail() && q > 0 && q <= 10){
            stud[y].set_mark(q);
        }
        else {
            df.clear();
            df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            fail = true;
            cout << "Ivestas netinkamas namu darbu pazymys " << eil << " eiluteje. Del to studento duomenys nebuvo nuskaityti." << endl;
            break;
        }
    }
}

void egz(std::ifstream &df,std::vector<Studentas> &stud, int y, bool &fail, int eil){
    int q=0;
    df >> q;
    if(!df.fail() && q > 0 && q <= 10){
        stud[y].set_exam(q);
    }
    else {
        df.clear();
        df.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        fail = true;
        cout << "Ivestas netinkamas egzamino pazymys " << eil << " eiluteje. Del to studento duomenys nebuvo nuskaityti." << endl;
    }

}

void rikiavimas(std::vector<Studentas>& stud) {
    sort(stud.begin(), stud.end(), [](const Studentas &lhs, const Studentas &rhs) {
        if (lhs.vardas != rhs.vardas) {
            return lhs.vardas < rhs.vardas;
        } else {
            return lhs.pavarde < rhs.pavarde;
        }
    });
}