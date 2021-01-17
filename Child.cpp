#include "Child.h"
#include <iostream>

Child::Child(string nm, string pn, int v, string o, string cp, vector<string> wl) //constructorul cu parametrii al clasei Child
{
	this->nume = nm;
	this->prenume = pn;
	this->varsta = v;
	this->oras = o;
	this->culoare_plic = cp;
	this->wishlist = wl;
}

Child::~Child() //destructorul clasei Child
{
	cout << "------------------------> Child destructor called" << endl;
}

void Child::set_nume(string nm) //setter pentru numele copilului
{
	this->nume = nm;
}

void Child::set_prenume(string pn) //setter pentru prenumele copilului
{
	this->prenume = pn;
}

void Child::set_varsta(int v) //setter pentru varsta copilului
{
	this->varsta = v;
}

void Child::set_oras(string o) //setter pentru orasul din care este copilul
{
	this->oras = o;
}

void Child::set_culoare_plic(string cp) //setter pentru culoarea plicului copilului(roz pentru fetite si albastru pentru baietei)
{
	this->culoare_plic = cp;
}

void Child::set_wishlist(vector<string> &wl) //setter pentru lista de dorinte a copilului
{
	this->wishlist = wl;
}

string Child::get_nume() const //getter pentru numele copilului
{
	return this->nume;
}

string Child::get_prenume() const //getter pentru prenumele copilului
{
	return this->prenume;
}

int Child::get_varsta() const //getter pentru varsta copilului
{
	return this->varsta;
}

string Child::get_oras() const //getter pentru orasul din care este copilul
{
	return this->oras;
}

string Child::get_culoare_plic() const //getter pentru culoarea plicului copilului(roz pentru fetite si albastru pentru baietei)
{
	return this->culoare_plic;
}

vector<string> Child::get_wishlist() const //getter pentru lista de dorinte a copilului
{
	return this->wishlist;
}

ostream &operator<<(ostream &out, const Child &c) //afiseaza atributele clasei Child si supraincarca operatorul <<
{
	out << c.get_nume() << " " << c.get_prenume() << ", " << c.get_varsta() << " years, " << c.get_oras() << ", " << c.get_culoare_plic() << " envelope, ";
	out << "wishlist { "; // afisez ce datele fiecarui copil
	for (unsigned i = 0; i < c.get_wishlist().size() - 1; i++)
	{
		out << c.get_wishlist()[i] << ", "; // afisez wishlist-ul fiecarui copil
	}
	out << c.get_wishlist()[c.get_wishlist().size() - 1] << " }" << endl;
	return out;
}