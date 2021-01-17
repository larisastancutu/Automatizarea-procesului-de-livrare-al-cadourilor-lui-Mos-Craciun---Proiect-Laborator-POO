//LAPONIA -> MAREA BRITANIE

#include "Child.cpp" // am inclus headers
#include "Elf.cpp"
#include "Troll.cpp"
#include "MrsSantaClaus.cpp"
#include "SantaClaus.cpp"
#include <iostream>

using namespace std;

int main()
{
	vector<Child *> letter; // vector de scrisori de tipul Child*

	//adaug copiii in vectorul de scrisori
	letter.push_back(new Child("Walker", "Bob", 7, "Manchester", "blue", {"Drone", "Controller"}));
	letter.push_back(new Child("Smith", "Lisa", 5, "London", "pink", {"Barbie", "Unicorn", "Chocolate"}));
	letter.push_back(new Child("Parker", "Alexander", 6, "London", "blue", {"Chocolate", "Fifa21"}));
	letter.push_back(new Child("Forbes", "Michael", 10, "Birmingham", "blue", {"Headphones", "Ball"}));
	letter.push_back(new Child("Loud", "Anne", 9, "Liverpool", "pink", {"iPhone12"}));
	letter.push_back(new Child("Stan", "Andrew", 10, "Oxford", "blue", {"PS5", "Chocolate"}));

	cout << endl
		 << "**The letters are:\n " << endl; // afisez scisorile
	for (int i = 0; i < letter.size(); i++)
	{
		cout << i + 1 << ". " << *letter.at(i);
	}
	cout << endl;

	Troll troll;								   // obiectul de tipul Troll
	Elf *elf = &troll;							   // cum clasa Elf este abstracta am declarat astfel obiectul elf
	elf->grant_budget(letter);					   // apelez calcularea bugetului din elf
	elf->gift_list(letter);						   // creez lista cu ce cadou va primi fiecare copil
	elf->print_gifts(letter);					   // afisez ce cadouri va primi fiecare copil
	elf->cities_list(letter);					   // creez lista de orase
	vector<string> route_list = elf->get_cities(); //am salvat lista cu orasele de la elfi intr-un vector pentru a il folosi ca parametru in clasa SantaClaus
	cout << endl;

	troll.pack(letter); // trolii impacheteaza cadouri in ambalaje specifice
	cout << endl
		 << "**Trolls used:" << endl
		 << endl;
	cout << "Packages for girls: " << troll.get_girl_pack() << endl; // afisez ambalajele pentru fete cu ajutorul getter-ului
	cout << "Packages for boys: " << troll.get_boy_pack() << endl;	 // afisez ambalajele pentru baieti cu ajutorul getter-ului
	cout << endl;

	MrsSantaClaus mrs_santa_claus;								 // obiectul clasei MrsSantaClaus
	mrs_santa_claus.set_lollipops_number(elf->get_lollipops());	 // setez nr de acadele cu ajutorul setter-lui din MrsSantaClaus si a getter-ului din clasa Elf
	mrs_santa_claus.set_charcoals_number(troll.get_charcoals()); // setez nr de carbuni cu ajutorul setter-lui din MrsSantaClaus si a getter-ului din clasa Troll
	mrs_santa_claus.extra_budget_calculations();				 // calculez bugetul extra folosit
	cout << endl
		 << "**Total amount: " << mrs_santa_claus.get_extra_budget() << "$" << endl; // afisez bugetul extra cu ajutorul getter-ului
	cout << endl;

	SantaClaus santa_claus;															// obiectul clasei SantaClaus
	santa_claus.short_road();														// calzulez cel mai scurt drum
	santa_claus.print_road(route_list);												// afisez orasele in ordinea parcurgerii
	cout << "**Total kilometres: " << santa_claus.get_total_km() << " km " << endl; // afisez km totali cu ajutorul getter-ului
	cout << endl;

	for (int i = 0; i < letter.size(); i++)
	{
		delete letter.at(i); // sterg toate instantele clasei Child
	}

	return 0;
}