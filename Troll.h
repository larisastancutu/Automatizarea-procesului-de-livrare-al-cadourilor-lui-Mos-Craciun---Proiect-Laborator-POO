#ifndef TROLL_H
#define TROLL_H

#include <map>
#include <cstring>
#include <string>
#include <vector>
#include "Child.h"
#include "Elf.h"

using namespace std;

class Troll : public Elf // clasa Troll mosteneste clasa Elf
{
private:
    int girl_pack; // nr de ambalaje pentru fete
    int boy_pack;  // nr de ambalaje pentru baieti
    int charcoals; // nr de carbuni

public:
    Troll();  // constructorul clasei Troll
    ~Troll(); // destructorul clasei Troll

    int get_girl_pack() const; // getter pentru ambalajele pentru fete
    int get_boy_pack() const;  // getter pentru ambalajele pentru baieti
    int get_charcoals() const; // getter pentru carbuni

    void pack(vector<Child *> letter); // overriding la functia virtuala pura din clasa Elf
};

#endif // TROLL_H