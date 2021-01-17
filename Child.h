#ifndef CHILD_H //header-ul pentru clasa care contine datele copiilor ca atribute
#define CHILD_H

#include <vector>
#include <cstring>
#include <string>

using namespace std;

class Child //clasa Child care contine datele copiilor ca atribute
{
private:
	string nume;
	string prenume;
	int varsta;
	string oras;
	string culoare_plic;
	vector<string> wishlist;

public:
	Child(string nm, string pn, int v, string o, string cp, vector<string> wl); //constructor cu parametrii pentru clasa Child pentru a creea obiecte de acest tip
	virtual ~Child();															//destructor pentru clasa Child
	void set_nume(string nm);													//setters pentru fiecare atribut
	void set_prenume(string pn);
	void set_varsta(int v);
	void set_oras(string o);
	void set_culoare_plic(string cp);
	void set_wishlist(vector<string> &wl);

	string get_nume() const; //getters pentru fiecare atribut
	string get_prenume() const;
	int get_varsta() const;
	string get_oras() const;
	string get_culoare_plic() const;
	vector<string> get_wishlist() const;

	friend ostream &operator<<(ostream &out, const Child &c); //friend function si overloading pe operatorul << pentru polimorfism
};

ostream &operator<<(ostream &out, const Child &c);

#endif // CHILD_H