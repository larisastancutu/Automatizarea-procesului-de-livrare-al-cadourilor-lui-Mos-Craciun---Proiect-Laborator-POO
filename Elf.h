#ifndef ELF_H
#define ELF_H

#include <map>
#include <cstring>
#include <string>
#include <vector>
#include "Child.h"

using namespace std;

class Elf
{
private:
	string good_default_gift = "Bicycle";		 // cadou default pentru copilul bun in valoarea de 100$
	string bad_default_gift = "Colored pencils"; // cadou default pentru copilul rau in valoarea de 10$
	vector<int> budget;							 // vectorul in care retinem bugetul pentru fiecare copil
	int lollipops;								 // numarul de acadele
	vector<string> cities;						 // vectorul de orase din care este fiecare copil

protected:
	map<string, string> status_check = {
		{"Bob", "bad"},
		{"Lisa", "good"},
		{"Alexander", "bad"},
		{"Michael", "good"},
		{"Anne", "good"},
		{"Andrew", "good"}}; // lista elfilor cu copiii buni si cei rai sub forma de map
	map<string, int> inventory = {
		{"Drone", 50},
		{"Controller", 50},
		{"Unicorn", 15},
		{"Chocolate", 5},
		{"Headphones", 40},
		{"Ball", 10},
		{"Fifa21", 70},
		{"iPhone12", 1200}};		  // inventarul jucariilor sub forma de map
	vector<vector<string>> elf_gifts; // lista cu ceea ce va primi fiecare copil, fiind pusa sub forma de vector de vector de string-uri

public:
	Elf();			// constructorul clasei Elf
	virtual ~Elf(); // destructorul clasei Elf

	vector<vector<string>> get_elf_gifts() const; // getter pentru lista cu ceea ce va primi fiecare copil
	int get_lollipops() const;					  // getter pentru acadele
	vector<string> get_cities() const;			  // getter pentru lista de orase unde va trebui sa mearga Mos Craciiun

	void grant_budget(vector<Child *> letter); // metoda prin care calculez bugetul pentru fiecare copil
	void gift_list(vector<Child *> letter);	   // metoda prin care se alege ce va primi fiecare copil
	void print_gifts(vector<Child *> letter);  // metoda prin care afisez ce primeste fiecare copil
	void cities_list(vector<Child *> letter);  // metoda pentru a face lista de orase

	virtual void pack(vector<Child *> letter) = 0; // pure virtual function care face clasa Elf sa fie una abstracta
												   // va fi folosita in clasa Troll pentru a calcula ambalajele pentru fetite si baietei
};

#endif // ELF_H