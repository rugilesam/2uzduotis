#include "studentai.h"


void Studentai::veiksmai() {
    string gen;
    string struktura;
    string ats;
    string rus_index;
    
    
    cout << "Norite atlikti veiksmus su vector<studentas> (v) ar list <studentas> (l)" << endl;
    cin >> struktura;
    
    if (struktura == "v")
    {
        vector<Duomenys> grupe;
        
        
        while (true) {
            
            string failas;
            
            cout << "Iveskite failo, kuri norite nuskaityti pavadinima (formatas: pavadinimas.txt): ";
            cin >> failas;
            cout << "Pagal ka noresite rusiuoti rezultatus: p - pavardes, v - vardus, g - galutini bala?\n";
            cin >> rus_index;
            
            int kiekis = kiek_sk(failas);
            
            for (int i = 0; i < 5; i++) {
                
                cout << endl << endl;
                cout << i + 1 << " nuskaitymas" << endl;
                
                auto Nuskaitymo_start = chrono::high_resolution_clock::now();
                nuskaitymas(failas, grupe);
                auto Nuskaitymo_end = chrono::high_resolution_clock::now();
                chrono::duration<double> Nuskaitymo_laikas = Nuskaitymo_end - Nuskaitymo_start;
                cout << kiekis << " irasu nuskaitymas uztruko: " << Nuskaitymo_laikas.count() << " s;" << endl;
                
                
                auto Rusiavimas_start = chrono::high_resolution_clock::now();
                pal_pav(grupe, rus_index);
                auto Rusiavimas_end = chrono::high_resolution_clock::now();
                chrono::duration<double> Rusiavimas_laikas = Rusiavimas_end - Rusiavimas_start;
                cout << kiekis << " irasu rusiavimas pagal " << rus_index << " uztruko: " << Rusiavimas_laikas.count() << " s;" << endl;
                
                
                auto Padalinimo_start = chrono::high_resolution_clock::now();
                vector<Duomenys> vargsiukai;
                vector<Duomenys> kietiakai;
                padalinimas(grupe, vargsiukai);
                kietiakai = grupe;
                auto Padalinimo_end = chrono::high_resolution_clock::now();
                chrono::duration<double> Padalinimo_laikas = Padalinimo_end - Padalinimo_start;
                cout <<kiekis << " irasu surusiavimas i dvi grupes uztruko: " << Padalinimo_laikas.count() << " s;"  << endl;
                
                
                pal_pav(kietiakai, rus_index);
                pal_pav(vargsiukai, rus_index);
                
                
                auto Kietiaku_sp_start = chrono::high_resolution_clock::now();
                padalinto_spausdinimas(kietiakai, "kietiakai.txt");
                auto Kietiaku_sp_end = chrono::high_resolution_clock::now();
                chrono::duration<double> Kietiaku_sp_laikas = Kietiaku_sp_end - Kietiaku_sp_start;
                cout << kiekis << " irasu kietiaku irasymas i faila uztruko: " << Kietiaku_sp_laikas.count() << " s;" << endl;
                
                
                auto Vargsiuku_sp_start = chrono::high_resolution_clock::now();
                padalinto_spausdinimas(vargsiukai, "vargsiukai.txt");
                auto Vargsiuku_sp_end = chrono::high_resolution_clock::now();
                chrono::duration<double> Vargsiuku_sp_laikas = Vargsiuku_sp_end - Vargsiuku_sp_start;
                cout << kiekis << " irasu vargsiuku irasymas i faila uztruko: " << Vargsiuku_sp_laikas.count() << " s;" << endl;
                double visas_laikas = Nuskaitymo_laikas.count() + Rusiavimas_laikas.count() + Padalinimo_laikas.count() + Kietiaku_sp_laikas.count() + Vargsiuku_sp_laikas.count();
                cout << kiekis << " irasu testo laikas: " << visas_laikas << " s;" << endl;
                
                grupe.clear();
                
            }
            
        }
    }
    else if (struktura == "l")
    {
        list<Duomenys> grupe;


        while (true) {
            
                    string failas;
                   
                    cout << "Iveskite failo, kuri norite nuskaityti pavadinima (formatas: pavadinimas.txt): ";
                    cin >> failas;

                    cout << "Pagal ka noresite rusiuoti rezultatus: p - pavardes, v - vardus, g - galutini bala?\n";
                    cin >> rus_index;

                    int kiekis = kiek_sk(failas);

                    for (int i = 0; i < 5; i++) {
                        cout << endl << endl;
                        cout << i + 1 << " nuskaitymas" << endl;

                        auto Nuskaitymo_start = chrono::high_resolution_clock::now();
                        nuskaitymas(failas, grupe);
                        auto Nuskaitymo_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Nuskaitymo_laikas = Nuskaitymo_end - Nuskaitymo_start;
                        cout << kiekis << " irasu nuskaitymas uztruko: " << Nuskaitymo_laikas.count() << " s;" << endl;


                        auto Rusiavimas_start = chrono::high_resolution_clock::now();
                        pal_pav_list(grupe, rus_index);
                        auto Rusiavimas_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Rusiavimas_laikas = Rusiavimas_end - Rusiavimas_start;
                        cout << kiekis << " irasu rusiavimas pagal " << rus_index << " uztruko: " << Rusiavimas_laikas.count() << " s;" << endl;
                        

                        
                        auto Padalinimo_start = chrono::high_resolution_clock::now();
                        list<Duomenys> vargsiukai;
                        list<Duomenys> kietiakai;
                        padalinimas(grupe, vargsiukai);
                        kietiakai = grupe;
                        auto Padalinimo_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Padalinimo_laikas = Padalinimo_end - Padalinimo_start;
                        cout << kiekis << " irasu surusiavimas i dvi grupes uztruko: " << Padalinimo_laikas.count()  << " s;"  << endl;

                        pal_pav_list(kietiakai, rus_index);
                        pal_pav_list(vargsiukai, rus_index);

                        auto Kietiaku_sp_start = chrono::high_resolution_clock::now();
                        padalinto_spausdinimas(kietiakai, "kietiakai.txt");
                        auto Kietiaku_sp_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Kietiaku_sp_laikas = Kietiaku_sp_end - Kietiaku_sp_start;
                        cout << kiekis << " irasu kietiaku irasymas i faila uztruko: " << Kietiaku_sp_laikas.count() << " s;" << endl;


                        auto Vargsiuku_sp_start = chrono::high_resolution_clock::now();
                        padalinto_spausdinimas(vargsiukai, "vargsiukai.txt");
                        auto Vargsiuku_sp_end = chrono::high_resolution_clock::now();
                        chrono::duration<double> Vargsiuku_sp_laikas = Vargsiuku_sp_end - Vargsiuku_sp_start;
                        cout << kiekis << " irasu vargsiuku irasymas i faila uztruko: " << Vargsiuku_sp_laikas.count() << " s;" << endl;
                        double visas_laikas = Nuskaitymo_laikas.count() + Rusiavimas_laikas.count() + Padalinimo_laikas.count()  + Kietiaku_sp_laikas.count() + Vargsiuku_sp_laikas.count();
                        cout << kiekis << " irasu testo laikas: " << visas_laikas << " s;" << endl;

                        grupe.clear();

                    }
        }

    }
}



template <typename S>
void Studentai::skaiciavimas(S &grupe, Duomenys &temp) {
    double suma = 0;

    for (int i = 0; i < temp.nd.size(); i++) {
        suma += temp.nd[i];
    }

    temp.vid = 0.4 * (suma / temp.nd.size()) + 0.6 * temp.egz;

    // Nustatome, kokį konteinerio tipą imti
    typename ContainerTypeTrait<S>::type visipaz;

    for (int i : temp.nd) {
        visipaz.push_back(i);
    }

    visipaz.push_back(temp.egz);

}

template <class P>
void Studentai::pal_pav(P &grupe, string rus_index) {
    sort(grupe.begin(), grupe.end(), [rus_index](Duomenys &a, Duomenys &b) {
        return Studentai::palyginimas(a, b, rus_index);
    });
}
template <class P>
void Studentai::pal_pav_list(P &grupe, string rus_index) {
    grupe.sort([rus_index](Duomenys &a, Duomenys &b) {
        return Studentai::palyginimas(a, b, rus_index);
    });
}

template <class T>
void Studentai::nuskaitymas(const string& failas, T& grupe) {
    std::ifstream in(failas);
    if (!in.is_open()) {
        std::cerr << "Klaida: Failas nerastas." << std::endl;
        return;
    }

    string pavadinimas, praleidziam;
    getline(in, pavadinimas);
    Duomenys temp;
    int laik_kint, suma = 0, m = 0;
    double nd_sk = 0;
    int raidziu_sk = 0;
    for (char ch : pavadinimas) {
        if (isalpha(ch)) {
            raidziu_sk++;
        }
    }

    nd_sk = (raidziu_sk - 6 - 7 - 3) / 2;


    while (in >> temp.vard >> temp.pav) {

        for (int i = 0; i < nd_sk; i++) {
        in >> laik_kint;
            temp.nd.push_back(laik_kint);
            suma+=laik_kint;
        }

    in >> temp.egz;
    getline(in, praleidziam);

        skaiciavimas_2(suma,nd_sk,temp,grupe);
        m++;
    }

    in.close();
}

template <class S>
void Studentai::skaiciavimas_2(int &suma, int nd_sk, Duomenys &temp, S &grupe) {

    temp.vid = static_cast<float>(suma)/nd_sk;

    //Skaiciuojam galutinius balus
    temp.galutinis = static_cast<float>(temp.vid*0.4 + temp.egz*0.6);


    grupe.push_back(temp);
    temp.nd.clear();
    suma = 0;
}

 template <class P>
 void Studentai::padalinimas(P& grupe, P& vargsiukai) {

     // Iš pradinio konteinerio perkeliami vargšiukai į naująjį "vargšiukai" konteinerį
     auto partitionPoint = std::partition(grupe.begin(), grupe.end(), [](const Duomenys& a) {
         return a.galutinis < 5;
     });

     vargsiukai.insert(vargsiukai.end(), partitionPoint, grupe.end());

     // Iš pradinio konteinerio ištrinami vargšiukai
     grupe.erase(partitionPoint, grupe.end());
}

//spausdinimo funkcija kietiakam ir vargsiukam
template <class P>
void Studentai::padalinto_spausdinimas(const P& Duomenys, const string& failo_pav) {
    ofstream out(failo_pav);

    out << left << setw(20) << "Pavarde" << setw(20) << "Vardas" << setw(20) << "Galutinis" << endl;
    out << endl;

    for (const auto& stud : Duomenys) {
        out << left << setw(20) << stud.pav << setw(20) << stud.vard << setw(20) << fixed << setprecision(2) << stud.galutinis << endl;


    }
    out.close();
}

int Studentai::kiek_sk(const string& failas) {
    int kiekis = 0;
    string numberPart;
    bool rastas_sk = false;

    for (char c : failas) {
        if (rastas_sk) {
            if (std::isdigit(c)) {
                numberPart += c;
            }
            else {
                break;  // Sustoja kai suranda ne skaiciu
            }
        }
        else if (std::isdigit(c)) {
            rastas_sk = true;
            numberPart += c;
        }
    }

    if (!numberPart.empty()) {
        // Surinktas skaicius is eilutes paverciamas i sveikajo skaiciu
        std::istringstream(numberPart) >> kiekis;
    }

    return kiekis;
}


//failo generavimas
void Studentai::gen_failas(int stud_gen_sk, int stud_gen_nd) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<int> rand_score(1, 10);



    ofstream out("Kursiokai" + to_string(stud_gen_sk) + ".txt");
    out << left << setw(20) << "Vardas" << setw(20) << "Pavarde";

    for (int m = 1; m <= stud_gen_nd; m++) {
        out << setw(7) << "ND" + to_string(m);
    }

    out << setw(7) << "Egz." << setw(15) << endl;
    out << endl;

    for (int i = 1; i <= stud_gen_sk; i++) {
        Duomenys stud;
        stud.vard = "Vardas" + to_string(i);
        stud.pav = "Pavarde" + to_string(i);
        out << left << setw(20) << stud.vard << setw(20) << stud.pav;
        stud.egz = rand_score(gen);

        double suma = 0;

        for (int j = 0; j < stud_gen_nd; j++) {
            int pazymys = rand_score(gen);
            stud.nd.push_back(pazymys);
            suma += pazymys;

            out << setw(7) << pazymys;
        }
        out << setw(7) << stud.egz << endl;
    }
    out.close();
}


//Palyginimas pagal P,V,G
bool Studentai::palyginimas(Duomenys& a, Duomenys& b, string rus_index) {
    if (rus_index == "p") {
        return a.pav < b.pav;
    }
    else if (rus_index == "v") {
        return a.vard < b.vard;
    }
    else if (rus_index == "g") {
        return a.galutinis < b.galutinis;
    }
    else {
        // Automatinis nustatymas, kai rus_index neatpazintas
        return false;
    }
}


