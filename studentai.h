#ifndef STUDENTAI_H_INCLUDED
#define STUDENTAI_H_INCLUDED

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <list>
#include <stdio.h>
#include <sstream>
#include <algorithm>
#include <random>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <cctype>
#include <stdexcept>
#include <chrono>

using namespace std;

class Studentai {
public:
    struct Duomenys
    {
        string vard, pav;
        vector <int> nd;
        int egz{};
        float vid{};
        float galutinis{};
    };
    
    void veiksmai();
    
    static bool palyginimas(Studentai::Duomenys& a, Studentai::Duomenys& b, string rus_index);
    
private:

    template <typename S>
    void skaiciavimas(S &grupe, Studentai::Duomenys &temp) ;

    template <class P>
    void pal_pav(P &grupe, string rus_index) ;
    
    template <class P>
    void pal_pav_list(P &grupe, string rus_index) ;

    template <class T>
    void nuskaitymas(const string& failas, T& grupe) ;

    template <class S>
    void skaiciavimas_2(int &suma, int nd_sk, Studentai::Duomenys &temp, S &grupe) ;

    template <class P>
    void padalinimas(P& grupe, P& vargsiukai) ;

//spausdinimo funkcija kietiakam ir vargsiukam
    template <class P>
    void padalinto_spausdinimas(const P& Duomenys, const string& failo_pav);
    
    int kiek_sk(const string& failas);
    void gen_failas(int stud_gen_sk, int stud_gen_nd);
};


// Aibūdiname ContainerTypeTrait šabloną
template <typename S>
struct ContainerTypeTrait;

// Specifikuojame atvejui vector<studentas>
template <>
struct ContainerTypeTrait<vector<Studentai::Duomenys>> {
using type = vector<int>;
};

// Specifikuojame atvejui list<studentas>
template <>
struct ContainerTypeTrait<list<Studentai::Duomenys>> {
    using type = list<int>;
};


#endif
