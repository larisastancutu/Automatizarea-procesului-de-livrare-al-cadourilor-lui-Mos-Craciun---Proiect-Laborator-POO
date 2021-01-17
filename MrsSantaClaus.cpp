#include "MrsSantaClaus.h"
#include <iostream>

MrsSantaClaus::MrsSantaClaus()// constructorul clasei MrsSantaClaus
{
    extra_budget = 0;// initial bugetul extra e 0
}
MrsSantaClaus::~MrsSantaClaus()// destructorul clasei MrsSantaClaus
{
    cout << "------------------------> MrsSantaClaus destructor called" << endl;
}

void MrsSantaClaus::set_lollipops_number(int x)// setter pentru nr de acadele; nr x il iau cu ajutorul getter-ului pentru acadele din clasa Elf
{
    this->lollipops_number = x;
}

void MrsSantaClaus::set_charcoals_number(int x)// setter pentru nr de carbuni; nr x il iau cu ajutorul getter-ului pentru carbuni din clasa Troll
{
    this->charcoals_number = x;
}

double MrsSantaClaus::get_extra_budget() const// getter pentru bugetul extra
{
    return this->extra_budget;
}

void MrsSantaClaus::extra_budget_calculations()// metoda ce calculeaza bugetul extra
{
    extra_budget =  (charcoals_number*0.5) + lollipops_number;// bugetul extra este egal cu nr de carbuni inmultit cu 0.5$ + nr de acadele
}