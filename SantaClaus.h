#ifndef SANTACLAUS_H
#define SANTACLAUS_H

#include <cstring>
#include <string>
#include <vector>
#include <cfloat>// este pentru FLT_MAX
#include <algorithm> // pentru next_permutation()
#include "Child.h"
#include "Elf.h"
#include "SantaClaus_min_function.cpp"

using namespace std;

class SantaClaus
{
private:
    vector<vector<float>> graph = {{0, 2091.33, 2197.60, 2169.82, 2126.32, 2214.61},
                                    {2091.33, 0, 262.41, 113.27, 49.85, 202.90},
                                    {2197.60, 262.41, 0, 163.04, 287.13, 83.41},
                                    {2169.82, 113.27, 163.04, 0, 126.19, 91.78},
                                    {2126.32, 49.85, 287.13, 126.19, 0, 217.62},
                                    {2214.61, 202.90, 83.41, 91.78, 217.62, 0}}; // graful cu distante, fiind sub forma de vector de vector de float
    vector<int> cities_positions;                                                // vector cu pozitiile oraselor
    float total_km;                                                             // nr total de km parcursi de Mos Craciun

public:
    SantaClaus();  // constructorul clasei SantaClaus
    ~SantaClaus(); // destructorul clasei SantaClaus

    float get_total_km() const; // getter pentru nr total de km

    void short_road();                          // metoda ce calculeaza cel mai scurt drum
    void print_road(vector<string> route_list); // metoda ce afiseaza vectorul cu orase in ordinea in care trebuie parcurse
};

#endif // SANTACLAUS_H