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

class Studentas {
private:
    string vard_;
    string pav_;
    double egz_;
    vector<int> nd;
    float galutinis_;
    float vid_;
public:
    Studentas() : egz_(0) { }  // default konstruktorius
    Studentas(std::istream& is);
    
  ~Studentas() {};
    std::string getName() const { return vard_; }
    std::string getSurname() const { return pav_; }
    vector<int> getNd() const { return nd; }
    int GautiEgzaminas() const { return egz_; }
    float getGalutinis() const { return galutinis_; }
    float getVid() const { return vid_; }
    int GautiDydi() const { return nd.size(); }
    double GP(int, double);
    
    void setStudentas(std::string, std::string);
    void setEgzaminas(int);
    void setGalutinis(float);
    void setVid(float);
    void setName(string);
    void setSurname(string);
    void SetNd(int);
    void EmptyNd();
    void SortNd();

};

bool palyginimas(const Studentas& a, const Studentas& b, string rus_index);
void skaiciavimas(int& suma, int nd_sk, Studentas& temp, vector<Studentas>& grupe);
void skaiciavimas_2(int &suma, int nd_sk, Studentas& temp, vector<Studentas>& grupe);
void isvedimas(vector<Studentas> &grupe, string gen, string ats,string rus_index);
void isvedimas_list(list<Studentas> &grupe, string gen, string ats,string rus_index);

int kiek_sk(const string& failas);
void gen_failas(int stud_gen_sk, int stud_gen_nd);
void nuskaitymas(const string& failas, vector<Studentas>& grupe);
void pal_pav( vector<Studentas>& grupe, string rus_index);
void pal_pav_list(vector<Studentas>& grupe, string rus_index);
void padalinimas(vector<Studentas>& grupe, vector<Studentas>& vargsiukai);
void padalinto_spausdinimas(const vector<Studentas>& Studentas, const string& failo_pav);

#endif
