#include "Elf.h"
#include <iostream>

Elf::Elf() //constructorul clasei Elf
{
	lollipops = 0; //nr de acadele il initializez cu 0;
}

Elf::~Elf() //destructorul clasei Elf
{
	cout << "------------------------> Elf destructor called" << endl;
}

vector<vector<string>> Elf::get_elf_gifts() const //getter pentru lista cu ceea ce va primi fiecare copil
{
	return this->elf_gifts;
}

int Elf::get_lollipops() const //getter pentru acadele
{
	return this->lollipops;
}

vector<string> Elf::get_cities() const // getter pentru lista de orase unde va trebui sa mearga Mos Craciiun
{
	return this->cities;
}

void Elf::grant_budget(vector<Child *> letter) // metoda prin care calculez bugetul pentru fiecare copil ce primeste ca parametru un vector precum cel din main cu scrisorile copiilor
{
	int i = 0;				  // iteratorul i este initial 0
	while (i < letter.size()) // cat timp i este mai mic decat dimensiunea vectorului letter
	{
		for (auto it = this->status_check.cbegin(); it != this->status_check.cend(); ++it) // auto il folosesc pt a lua singur tipul map-ului pentru iterator
		{																				   // parcurg map-ul cu statusul copiilor de la inceput pana la final
			if (it->first == letter.at(i)->get_prenume())								   // daca prima valoare din map este egala cu prenumele copilului care a cris scrisoarea
			{
				if (it->second == "good") // daca copilul a fost bun
				{
					this->budget.push_back(100); // va avea un buget de 100$, introducandu-l in vectorul buget
												 //cout<<letter.at(i)->get_prenume() <<": "<< budget.at(i)<<endl;// asta a fost pentru a verifica daca imi face bine bugetul pentru copii
				}
				else if (it->second == "bad") // daca copilul a fost rau
				{
					this->budget.push_back(10); // va avea un buget de 10$, introducandu-l in vectorul buget
												//cout<<letter.at(i)->get_prenume() <<": "<< budget.at(i)<<endl;
				}
			}
		}
		i++; // crestem i-ul pesntru a trece la urmatoarea scrisoare
	}
}

void Elf::gift_list(vector<Child *> letter) // metoda prin care se alege ce va primi fiecare copil ce primeste ca parametru un vector precum cel din main cu scrisorile copiilor
{
	for (int i = 0; i < letter.size(); i++) // pentru i de la 0, i < nr scrisorilor
	{
		int gift_budget = budget.at(i);											 // retinem bugetul copilului intr-0 variabila
		int gifts_number = 0;													 // numarul cadourilor pe care le va primi fiecare copil, fiind initial 0
		int ok = 0;																 // este pentru a verifica daca cadoul corespunde
		int gift_lollipops = 0;													 // nr de acadele pe care le primeste fiecare copil, initial fiind 0
		vector<string> v;														 // vector intermediar in care vom retine jucariile ce vor fi ulterior bagate in vectorul elf_gifts
		vector<string> copy_wishlist(letter.at(i)->get_wishlist());				 // in acest vector retin wishlist-ul fiecarui copil
		for (auto it = copy_wishlist.cbegin(); it != copy_wishlist.cend(); ++it) // parcurg vectorul copy_wishlist de la inceput pana la final
		{
			ok = 0;																		 // ok ia pentru fiecare jucarie valoarea 0
			for (auto it_inv = inventory.cbegin(); it_inv != inventory.cend(); ++it_inv) // parcurg inventarul elfilor
			{
				if (*it == it_inv->first) // daca prima valoare din inventar corespunde cu ceea ce isi doreste copilul
				{
					ok = 1; // ok ia valoarea 1
					try		// am folosit exceptions pentru a verifica daca se incadreaza in buget
					{
						if (it_inv->second > gift_budget && gifts_number == 0) // daca pretul din inventar al jucariei depaseste bugetul copilului si nr de cadouri este egal cu 0
						{
							if (gift_budget == 100) // daca copilul are bugetul de 100$
							{
								v.push_back(good_default_gift); // copilul va primi cadoul default pentru cei cuminti, adaugandu-l in vectorul v
								gift_budget = 0;				// bugetul copilul devine 0
								gifts_number++;					// nr de cadouri pe care le primeste creste
							}
							else if (gift_budget == 10) // daca copilul are bugetul de 10$
							{
								v.push_back(bad_default_gift); // copilul va primi cadoul default pentru cei rai, adaugandu-l in vectorul v
								gift_budget = 0;			   // bugetul copilul devine 0
								gifts_number++;				   // nr de cadouri pe care le primeste creste
							}
						}
						else		 // daca nu corespunde conditia din if
							throw 0; // aruncam 0
					}
					catch (int x) // daca prindem
					{
						if (it_inv->second <= gift_budget) // daca pretul din inventar al jucariei este mai mic sau egal cu bugetul copilului
						{
							v.push_back(*it);			   // adaugam cadoul in vectorul v
							gift_budget -= it_inv->second; // din bugetul copilului scadem pretul jucariei
							gifts_number++;				   // nr de cadouri pe care le primeste creste
						}
					}
				}
			}
		}
		if (!ok && gifts_number == 0) // daca nu exista nimic pe inventar
		{
			if (gift_budget == 100) // daca copilul are bugetul de 100$
			{
				v.push_back(good_default_gift); // copilul va primi cadoul default pentru cei cuminti
				gift_budget = 0;				// bugetul copilul devine 0
				gifts_number++;					// nr de cadouri creste
			}
			else if (gift_budget == 10) // daca copilul are bugetul de 10$
			{
				v.push_back(bad_default_gift); // copilul va primi cadoul default pentru cei rai
				gift_budget = 0;			   // bugetul copilul devine 0
				gifts_number++;				   // nr de cadouri creste
			}
		}
		if (ok && gift_budget > 0) // daca copilul are cadou si i-au mai ramas bani din buget
		{
			while (gift_budget != 0) // cat timp bugetul nu este 0
			{
				gift_lollipops++; // adaugam acadele
				gift_budget--;	  // scadem bugetul cu 1
			}
			v.push_back(to_string(gift_lollipops) + "_acadele"); // adaugam in vectorul v daca si cate acadele va primi copilul
		}
		this->lollipops += gift_lollipops; // nr total de acadele creste cu nr de acadele ale copilului

		elf_gifts.push_back(v); // adaugam ceea ce va primi copilul in vectorul in care se afla ce primesc toti
	}
}

void Elf::print_gifts(vector<Child *> letter) // metoda prin care afisez ce primeste fiecare copil
{
	cout << endl
		 << "**Children will receive the following gifts:" << endl // afisez un mesaj corespunzator
		 << endl;
	for (int i = 0; i < letter.size(); i++) // parcurg vectorul de scrisori
	{
		cout << i + 1 << ". " << letter.at(i)->get_prenume() << ": ";		 // afisez prenumele copilului
		for (auto it = elf_gifts[i].begin(); it != elf_gifts[i].end(); it++) // parcurg vectrorul cu cadouri
		{
			cout << *it << " "; // afisez ce va primi copilul
		}
		cout << endl;
	}
}

void Elf::cities_list(vector<Child *> letter) // metoda pentru a face lista de orase
{
	cities.push_back("Rovaniemi");			// adaug in vector orasul Rovaniemi din care pleaca Mos Craciun
	for (int i = 0; i < letter.size(); i++) // parcurg vectorul de scrisori
	{
		int ok = 0;									// pentru a verifica daca orasul se afla in vectorul de orase
		for (int it = 0; it != cities.size(); it++) // parcurg vectorul de orase
		{
			try // am folosit exceptions pentru a vedea daca orasul copilului se afla deja in vectorul de orase sau nu
			{
				if (letter.at(i)->get_oras() != cities.at(it)) // daca orasului din scrisoare nu se afla in vectorul de orase
				{
					ok = 1; // ok devine 1
				}
				else		 // daca orasului din scrisoare se afla in vectorul de orase
					throw 0; // aruncam 0
			}
			catch (int x) // daca prindem
			{
				ok = 0; // ok ramane 0
			}
		}
		if (ok) // daca ok e 1
		{
			cities.push_back(letter.at(i)->get_oras()); // adaugam orasul copilului in vectorul de orase
		}
	}
}