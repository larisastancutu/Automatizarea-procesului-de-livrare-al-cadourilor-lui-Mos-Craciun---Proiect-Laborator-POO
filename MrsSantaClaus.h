#ifndef MRSSANTACLAUS_H
#define MRSSANTACLAUS_H

using namespace std;

class MrsSantaClaus
{
private:
    double extra_budget;  // bugetul extra
    int lollipops_number; // nr de acadele pe care il luam de la elfi
    int charcoals_number; // nr de carbuni pe care il luam de la troli

public:
    MrsSantaClaus();  // constructorul clasei MrsSantaClaus
    ~MrsSantaClaus(); // destructorul clasei MrsSantaClaus

    void set_lollipops_number(int x); // setter pentru nr de acadele
    void set_charcoals_number(int x); // setter pentru nr de carbuni

    double get_extra_budget() const; // getter pentru bugetul extra

    void extra_budget_calculations(); // metoda ce calculeaza bugetul extra
};

#endif // MRSSANTACLAUS_H