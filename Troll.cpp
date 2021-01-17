#include "Troll.h"
#include <iostream>

Troll::Troll() // constructorul clasei Troll
{
    charcoals = 0; // nr de carbuni este initial egal cu 0
    girl_pack = 0; // nr de ambalaje pentru fete este initial egal cu 0
    boy_pack = 0;  // nr de ambalaje pentru baieti este initial egal cu 0
}

Troll::~Troll() // destructorul clasei Troll
{
    cout << "------------------------> Troll destructor called" << endl;
}

int Troll::get_girl_pack() const // getter pentru ambalajele pentru fete
{
    return this->girl_pack;
}

int Troll::get_boy_pack() const // getter pentru ambalajele pentru baieti
{
    return this->boy_pack;
}

int Troll::get_charcoals() const // getter pentru carbuni
{
    return this->charcoals;
}

void Troll::pack(vector<Child *> letter) // overriding la functia virtuala pura din clasa Elf care calculeaza nr de ambajale si de carbuni
{
    for (int i = 0; i < letter.size(); i++) // parcurg vectorul de scrisori
    {
        try // am folosit exceptions pentru a verifica daca copilul e fata sau baiat
        {
            if (letter.at(i)->get_culoare_plic() == "pink") // daca culoarea plicului copilului e roz
            {
                this->girl_pack++; // crestem nr de ambalaje pentru fete
            }
            else         // daca nu e roz
                throw 0; // aruncam 0
        }
        catch (int x) // daca prindem
        {
            if (letter.at(i)->get_culoare_plic() == "blue") // daca culoarea plicului copilului e albastru
            {
                this->boy_pack++; // crestem nr de ambalaje pentru baieti
            }
        }
        for (auto it = status_check.cbegin(); it != status_check.cend(); ++it) // parcurgem map-ul cu statusul copiilor
        {
            if (it->first == letter.at(i)->get_prenume()) // daca prima valoare din map corespunde cu prenumele copilului
            {
                if (it->second == "bad") // daca copilul a fost rau
                {
                    elf_gifts[i].push_back("charcoal"); // adaugam un carbune in punga copilului
                    this->charcoals++;                  // crestem nr de carbuni
                }
            }
        }
    }
}