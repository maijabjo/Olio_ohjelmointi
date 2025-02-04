#include "asiakas.h"
#include <iostream>
using namespace std;

int main() {
    string asiakas1 = "Aapeli";
    double luottoraja1 = 1000;
    double luotonSiirto1 = 150;

    string asiakas2 = "Bertta";
    double luottoraja2 = 1000;
    double siirtoSumma = 50;

    Asiakas as1(asiakas1, luottoraja1);
    as1.showSaldo();

    as1.talletus(luotonSiirto1);
    as1.luotonNosto(luotonSiirto1);
    as1.showSaldo();

    Asiakas as2(asiakas2, luottoraja2);
    as2.showSaldo();

    cout << "\n" << asiakas1 << endl;
    as1.showSaldo();

    as1.tiliSiirto(siirtoSumma, as2);

    cout << "\n" << asiakas2 << endl;
    as2.showSaldo();

    return 0;
}
