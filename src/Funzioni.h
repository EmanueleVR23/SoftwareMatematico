#include <fstream>
#include <cstdlib> //per randomizzare la scelta
#include <ctime>
#include <glibmm/ustring.h>
using namespace std;

#ifndef SOFTWAREMATEMATICO_FUNZIONI_H
#define SOFTWAREMATEMATICO_FUNZIONI_H

const int range=50;

class GUI;

class Funzioni {
    int correzione;
    string domanda;
    int risposta;
public:
    Funzioni();
    Glib::ustring CreaDomanda();
    friend ostream& operator<<(ostream& output, Funzioni& p);
    friend istream& operator>>(istream& input, Funzioni& p);
    operator bool();
    friend GUI;
};


#endif //SOFTWAREMATEMATICO_FUNZIONI_H
