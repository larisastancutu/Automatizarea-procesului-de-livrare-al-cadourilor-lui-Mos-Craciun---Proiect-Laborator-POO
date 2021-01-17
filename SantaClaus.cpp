#include "SantaClaus.h"
#include <iostream>

SantaClaus::SantaClaus() // constructorul clasei SantaClaus
{
    total_km = FLT_MAX; // initial luam valoarea maxima pentru float ca nr de km totali
}

SantaClaus::~SantaClaus() // destructorul clasei SantaClaus

{
    cout << "------------------------> SantaClaus destructor called" << endl;
}

float SantaClaus::get_total_km() const // getter pentru nr total de km
{
    return this->total_km;
}

void SantaClaus::short_road() //aflarea celui mai scurt drum este facuta cu Travellig Salesman
{
    float maxx_value = FLT_MAX; // valoarea maxima ia valoarea maxima de float pentru a putea calcula drumul minim
    int start_node = 0;         // varful de start e 0
    vector<int> vertex;         //vector de pozitii pentru varfuri
    for (int i = 0; i < graph.size(); i++)
    {
        if (i != start_node) // vectorul de pozitii retine toate varfurile in afara de cel de start
            vertex.push_back(i);
    }
    for (int i = 0; i < graph.size(); i++) // vectorul cu ordinea oraselor retine toate nodurile
    {
        cities_positions.push_back(i);
    }

    do
    {
        float current_km = 0;                   // km curenti initial au valoarea 0
        start_node = 0;                         // varful de start este mereu 0
        for (int i = 0; i < vertex.size(); i++) //parcurg nodurile
        {
            current_km += graph[start_node].at(vertex.at(i)); // la valoarea drumului adaugam distanta dintre nodul de start si varful de pe pozitia i
            start_node = vertex.at(i);                        // varful de pe pozitia i devine nodul de start
        }
        //current_km += graph[start_node].at(0);// am scos asta pentru a nu aduna si drumul de intoarecere
        total_km = Santa_claus_min_funtion<float>(total_km, current_km); // pentru a afla nr totali de km si sa fie cat mai mic, calculam minimul dintre total_km actual si cuurent_km cu ajutorul functiei de min facuta cu ajutorul templates
        if (maxx_value > current_km)                                     // verific daca valoarea maxima este mai mare decat km curenti pentru a retine ordinea oraselor in vectorul cities_position
        {
            int x = 1;                              // am luat o variabila de pentru pozitia orasului in cities_positions si este de la 1 deoarece pe pozitia 0 este orasul Rovaniemi
            maxx_value = current_km;                // valoarea maxima primeste valoarea km curenti
            for (int i = 0; i < vertex.size(); i++) // parcurgem vectorul de pozitii
            {
                cities_positions.at(x) = vertex.at(i); // pe pozitia xdin cities_positions vom pune orasul care se afla pe pozitia i in vectorul vertex
                x++;                                   // crestem x-ul
            }
        }
    } while (next_permutation(vertex.begin(), vertex.end()));
}

void SantaClaus::print_road(vector<string> route_list) // metoda ce afiseaza vectorul cu orase in ordinea in care trebuie parcurse
{
    cout << endl
         << "**Santa's route is: ";             // afisez un mesaj corespunzator
    for (int i = 0; i < route_list.size(); i++) // parcurg vectorul cu orase de la elfi
    {
        cout << " -> " << route_list.at(cities_positions.at(i)); // afisez orasul corect
    }
    cout << endl;
}