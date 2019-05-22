# VU objektinio programavimo trečia užduotis

Užduoties reikalavimus galite pamatyti [čia](https://github.com/objprog/paskaitos2019/wiki/3-oji-u%C5%BEduotis).  
Norint paleisti programą, jums reikia parsisiųsti norimą versiją ir paleisti `CMakeLists.txt` programos paleidimo failą.  

## [V0.1](https://github.com/rokas28/VUobjprog2/releases/tag/v0.1) (2019-02-17)
### Pridėta:
- Pirminė programos verisja.
-	`CMakeLists.txt` - Programos paleidimo failas.
- `main.cpp` failas. Kodas parašytas naudojantis vektoriais.
- `main_arr.cpp` failas. Kodas parašytas naudojantis dinaminiu masyvu.
- `.gitignore` failas.
- `README.md` failas.
- Galimybė įvesti studentų duomenis ranka, arba juos generuoti atsitiktine tvarka.

Šioje versijoje yra nemažai bug'ų, kurie bus sutvarkyti kitose versijose.  
  
Naudojimosi instrukcija:
- Jei norite pridėti studentą spauskite 1.
- Įveskite studento vardą.
- Įveskite studento pavardę.
- Jei norite įvseti studento egzamino pažymį ranka, spauskite 1, jei norite jį atsitiktinai sugeneruoti, spauskite 0.
- Įveskite egzamino rezultatą (jei paspaudėte 0).
- Jei norite įvseti studento namų darbų pažymius ranka, spauskite 1, jei norite juos atsitiktinai sugeneruoti, spauskite 0.
- Įveskite namų darbų rezultatus, kai visi namu darbu rezultatai bus suvesti, spauskite 0 (jei paspaudėte 1).
- Iveskite kiek namų darbų pažymių norite sugeneruoti (jei paspaudėte 0).
- Jei norite pridėti dar vieną studentą spauskite 1, jei ne 0.

## [V0.2](https://github.com/rokas28/VUobjprog2/releases/tag/v0.2) (2019-02-20)

### Pridėta:
- `./build/students.txt` failas, tekstiniem studentų įvesties duomenim.
- Galiybė nuskaityti duomenis iš pateikto duomenų failo.
- Sutvarkytas studentų duomenų išvedimo rūšiavimas ir lygiavimas.

### Koreguota:
- main.cpp failas.
- Sutvarkyti v0.1 versijos bug'ai vedant neteisingus duomenis ranka.

## [v0.3](https://github.com/rokas28/VUobjprog2/releases/tag/v0.3) (2019-02-23)

### Pridėta:
- main.cpp pridėtas `try catch` blokas, tikrinantis ar yra aptinkamas duomenų failas. Jei jo nėra, duomenys tuomet įvedinėjami ranka.

### Koreguota:
- main.cpp failas suskaidomas į: `main.cpp`,`main_header.h`,`struct_header.h`,`functions.cpp`.

## [v0.4](https://github.com/rokas28/VUobjprog2/releases/tag/v0.4) (2019-03-03)

### Pridėta:
- Studentų atsitiktinis generavimas į duomenų failą.
- Studentų rušiavimas į skirtingas kategorijas (skirstoma pagal galtuinį balą skaičiuojamą su pažymių vidurkiais).
- `./build/galvociai.txt` - studentai kurių balas yra 5 ir daugiau.
- `./build/vargsiukai.txt` - studentai kurių balas yra iki 5.
- Programos spartos matavimas naudojant `std::chrono`.

### Koreguota:
- functions.cpp failas. 

Programos veikimo sparta yra labai lėta, dėl tam tikrų klaidų kodo parašyme.

### [v0.4.1](https://github.com/rokas28/VUobjprog2/releases/tag/v0.4.1) (2019-03-04)

### Koreguota:
- Sutvarkya programos veikimo sparta ir optimizuotas jos veikimo laikas.

**Programos veikimo greičio (spartos) analizė**  

Kiekvienas studentas turi po 6 namų darbus.  
10 studentų:
```
Generavimas užtruko 0.0401591sec  
Skaitymas ir rušiavimas užtruko 0.0900437sec  
Išvedimas užtruko 0.175006sec  
```
100 studentų:  
```
Generavimas užtruko 0.0551987sec  
Skaitymas ir rušiavimas užtruko 0.00936983sec  
Išvedimas užtruko 0.0198203sec.  
```
1000 studentų:  
```
Generavimas užtruko 0.199804sec  
Skaitymas ir rušiavimas užtruko 0.07426sec  
Išvedimas užtruko 0.0388713sec  
```
10000 studentų:  
```
Generavimas užtruko 0.833397sec  
Skaitymas ir rušiavimas užtruko 1.05593sec  
Išvedimas užtruko 0.410506sec  
```
100000 studentų:  
```
Generavimas užtruko 6.51713sec  
Skaitymas ir rušiavimas užtruko 10.1496sec  
Išvedimas užtruko 3.3808sec  
```
1000000 studentų:  
```
Generavimas užtruko 66.9845sec  
Skaitymas ir rušiavimas užtruko 109.726sec  
Išvedimas užtruko 33.6921sec  
```
## [v0.5](https://github.com/rokas28/VUobjprog2/releases/tag/v0.5) (2019-03-10)

### Pridėta:
- `./functions/deque_functions.cpp` - funkcijos skirtos deque tipui.  
- `./functions/list_functions.cpp` - funkcijos skirtos list tipui.

### Koreguota:
- Iš`./functions/functions.cpp` perkeltos į `./functions/iostream_input_functions.cpp` funkcijos, skirtos įvesdinėti studentų duomenis ranka į ekraną.

Yra skaičiuojamas programos laikas, naudojant skirtingus duomenų konteinerius.

**Konteinerių testavimas:**

100 stdentų:  
```
Vector skaitymas ir rušiavimas užtruko 0.0172545sec
Vector išvedimas užtruko 0.0180264sec

List skaitymas ir rušiavimas užtruko 0.00458568sec
List išvedimas užtruko 0.2569425sec

Deque skaitymas ir rušiavimas užtruko 0.00625848sec
Deque išvedimas užtruko 0.0064563sec
```
1000 stdentų:  
```
Vector skaitymas ir rušiavimas užtruko 0.0601525sec
Vector išvedimas užtruko 0.0356498sec

List skaitymas ir rušiavimas užtruko 0.0676589sec
List išvedimas užtruko 0.0513542ec

Deque skaitymas ir rušiavimas užtruko 0.07856954sec
Deque išvedimas užtruko 0.0286541sec
```
10000 stdentų:  
```
Vector skaitymas ir rušiavimas užtruko 0.868945sec
Vector išvedimas užtruko 0.3862145sec

List skaitymas ir rušiavimas užtruko 0.501058sec
List išvedimas užtruko 0.2254125sec

Deque skaitymas ir rušiavimas užtruko 0.575698sec
Deque išvedimas užtruko 0.207854sec
```
100000 stdentų:  
```
Vector skaitymas ir rušiavimas užtruko 5.23413sec
Vector išvedimas užtruko 1.65535sec

List skaitymas ir rušiavimas užtruko 4.918sec
List išvedimas užtruko 1.81334sec

Deque skaitymas ir rušiavimas užtruko 5.32219sec
Deque išvedimas užtruko 1.76306sec
```
Galima matyti jog greičiausiai veikia list tipo duoenų konteineris. Vektoriaus ir deque spartos laikai yra panašūs ir svyruoja.

## [v1.0](https://github.com/rokas28/VUobjprog2/releases/tag/v1.0) (2019-03-24)

### Pridėta:
- Galutinė programos versija.
- Studentų skaidymas į du skirtingus konteinerius(1 strategija). Iki šiol programa buvo parašyta pagal antrą strategiją.
- Pridėtos funkcijos leidžiančios programai skaičiuoti ir pagal 1 strategiją.

### Koreguota:
- main.cpp faile išimtas try cach blokas. 

**Programos strategijų spartos matavimas:**  

100 studentų:  
```
Failo generavimas uztruko 0.0166667sec

Vector rusiavimas uztruko(2 strategija) 0.00241723sec
Vector isvedimas uztruko(2 strategija) 0.0145358sec

List rusiavimas uztruko(2 strategija) 0.00143631sec
List isvedimas uztruko(2 strategija) 0.0140246sec

Deque rusiavimas uztruko(2 strategija) 0.00395528sec
Deque isvedimas uztruko(2 strategija) 0.00902195sec

Vector rusiavimas uztruko(1 strategija) 0.00382974sec
Vector isvedimas uztruko(1 strategija) 0.0186023sec

List rusiavimas uztruko(1 strategija) 0.00213456sec
List isvedimas uztruko(1 strategija) 0.00867815sec

Deque rusiavimas uztruko(1 strategija) 0.00159631sec
Deque isvedimas uztruko(1 strategija) 0.0100094sec

Vector rusiavimas uztruko(su stable_partition) 0.000461538sec
```
1000 studentų:  
```
Failo generavimas uztruko 0.177447sec

Vector rusiavimas uztruko(2 strategija) 0.0249243sec
Vector isvedimas uztruko(2 strategija) 0.0423742sec

List rusiavimas uztruko(2 strategija) 0.0164697sec
List isvedimas uztruko(2 strategija) 0.0392779sec

Deque rusiavimas uztruko(2 strategija) 0.0321145sec
Deque isvedimas uztruko(2 strategija) 0.0616213sec

Vector rusiavimas uztruko(1 strategija) 0.0471253sec
Vector isvedimas uztruko(1 strategija) 0.0628135sec

List rusiavimas uztruko(1 strategija) 0.0715524sec
List isvedimas uztruko(1 strategija) 0.0503696sec

Deque rusiavimas uztruko(1 strategija) 0.0344591sec
Deque isvedimas uztruko(1 strategija) 0.0418158sec

Vector rusiavimas uztruko(su stable_partition) 0.00460964sec
```
10000 studentų:  
```
Failo generavimas uztruko 0.706272sec

Vector rusiavimas uztruko(2 strategija) 0.26133sec
Vector isvedimas uztruko(2 strategija) 0.276337sec

List rusiavimas uztruko(2 strategija) 0.173108sec
List isvedimas uztruko(2 strategija) 0.271526sec

Deque rusiavimas uztruko(2 strategija) 0.195009sec
Deque isvedimas uztruko(2 strategija) 0.336301sec

Vector rusiavimas uztruko(1 strategija) 0.310294sec
Vector isvedimas uztruko(1 strategija) 0.290751sec

List rusiavimas uztruko(1 strategija) 0.167759sec
List isvedimas uztruko(1 strategija) 0.360693sec

Deque rusiavimas uztruko(1 strategija) 0.200047sec
Deque isvedimas uztruko(1 strategija) 0.383927sec

Vector rusiavimas uztruko(su stable_partition) 0.0388193sec
```
100000 studentų:  
```
Failo generavimas uztruko 6.06982sec

Vector rusiavimas uztruko(2 strategija) 2.48271sec
Vector isvedimas uztruko(2 strategija) 2.43356sec

List rusiavimas uztruko(2 strategija) 2.20417sec
List isvedimas uztruko(2 strategija) 2.634sec

Deque rusiavimas uztruko(2 strategija) 2.29506sec
Deque isvedimas uztruko(2 strategija) 2.90855sec

Vector rusiavimas uztruko(1 strategija) 2.41303sec
Vector isvedimas uztruko(1 strategija) 2.80808sec

List rusiavimas uztruko(1 strategija) 2.50176sec
List isvedimas uztruko(1 strategija) 2.4293sec

Deque rusiavimas uztruko(1 strategija) 1.87861sec
Deque isvedimas uztruko(1 strategija) 3.00293sec

Vector rusiavimas uztruko(su stable_partition) 0.437255sec
```
Galima matyti, jog antra strategija, nors ir ne labai žymiai, bet yra greitesnė už pirmą strategiją.
Duomenų konteinerių tipuose greičiausias yra list tipo konteineris.
Naudojant `stable_partition` algoritmą vektoriaus greitis abai žymiai išauga ir tuomet stipriai lenkia kito tipo konteinerius.

## [v1.1](https://github.com/rokas28/VUobjprog3/releases/tag/v1.1) (2019-04-10)

### Pridėta:
- Studento klasės funkcijos `studentas.cpp`.
- Class konstruktorius, `set` ir `get` reikiamų duomenų funkcijos.

### Koreguota:
- main.cpp išimta list ir deque konteinerių spartos matavimai.
- Išimtos nenaudojamos funkcijos.
- Studentai pakeisti iš `struct` į `class`.

**Struct ir Class palyginimas:**

10000 studentų `struct` tipo:
```
Failo generavimas uztruko 0.944738sec
Vector rusiavimas uztruko 0.0638831sec
Vector isvedimas uztruko 0.287301sec
```
100000 studentų `struct` tipo:
```
Failo generavimas uztruko 6.50524sec
Vector rusiavimas uztruko 0.748016sec
Vector isvedimas uztruko 3.65606sec
```
10000 studentų `Class` tipo:
```
Failo generavimas uztruko 0.607438sec
Vector rusiavimas uztruko 0.0321473sec
Vector isvedimas uztruko 0.348387sec
```
100000 studentų `Class` tipo:
```
Failo generavimas uztruko 4.15574sec
Vector rusiavimas uztruko 0.35197sec
Vector isvedimas uztruko 3.49539sec
```
Programa su studentų `Class` tipu, galima matyti, veiki šiek tiek greičiau, nei su studentų `struct` tipu.  

**Optimizavimo flag'ų palyginimas:**  

100000 studentų, `O1` tipo flag'as:
```
Failo generavimas uztruko 4.27965sec
Vector rusiavimas uztruko 0.326014sec
Vector isvedimas uztruko 3.13245sec
```
100000 studentų, `O2` tipo flag'as:
```
Failo generavimas uztruko 3.73657sec
Vector rusiavimas uztruko 0.279388sec
Vector isvedimas uztruko 2.96582sec
```
100000 studentų, `O3` tipo flag'as:
```
Failo generavimas uztruko 3.90214sec
Vector rusiavimas uztruko 0.270159sec
Vector isvedimas uztruko 2.77907sec
```
## [v1.2](https://github.com/rokas28/VUobjprog3/releases/tag/v1.2) (2019-04-26)

### Pridėta:
- Pridėti `== != << >> < > copy` operatoriai.

### Koreguota:
- Kur yra reikalingi, programoje naudojami nauji operatoriai.
- Studenato galutinis balas perkeltas iš public į private.

## [v1.5](https://github.com/rokas28/VUobjprog3/releases/tag/v1.5) (2019-05-09)

### Pridėta:
- Base class Zmogus `zmogus.h`.
- Base class yra abstrakčioji klasė, kurios objektų negalima sukurti.

### Koreguota:
- Studentas class pakeista į derived.

## Laiko matavimai naudojant std::vector ir savadarbį vec::vector

### Naudojant 100000 studentų ir 100000 int tipo duomenų
```
studentu perskirstymas su std::vector 30
Irasymas i std::vector uztruko 6.53912sec
std::vector rusiavimas uztruko 3.82666sec
std::vector isvedimas uztruko 3.51958sec

std::vector uztruko su int tipo duomenimis 0.0393854sec
std::vector perskirste kartu: 30


studentu perskirstymas su vec:vector 17
Irasymas i vec::vector uztruko 10.5352sec
vec::vector rusiavimas uztruko 4.04097sec
vec::vector isvedimas uztruko 3.48666sec

vec::vector uztruko su int tipo duomenimis 0.00206728sec
vec::vector perskirste kartu: 17
```