#include "asiakas.h"
#include <iostream>
#include <string>

using namespace std;

Asiakas::Asiakas(string nimi, double luottoRaja) : nimi(nimi), kayttotili(nimi), luottotili(nimi, luottoRaja)
{
    cout << "Asiakkuus luotu " << nimi << endl;
}

string Asiakas::getNimi()
{
    return nimi;
}

void Asiakas::showSaldo()
{
    cout << "Kayttotilin saldo " << kayttotili.getBalance() << endl;
    cout << "Luottotilin saldo " << luottotili.getBalance() << "\n" << endl;
}

bool Asiakas::talletus(double summa)
{
    return kayttotili.deposit(summa);
}

bool Asiakas::nosto(double summa)
{
    return kayttotili.withdraw(summa);
}

bool Asiakas::luotonMaksu(double summa)
{
    return luottotili.deposit(summa);
}

bool Asiakas::luotonNosto(double summa)
{
    return luottotili.withdraw(summa);
}

bool Asiakas::tiliSiirto(double summa, Asiakas &maksunVastaanottaja)
{
    if (summa <= 0) {
        cout << "Summan on oltava suurempi kuin 0." << endl;
        return false;
    }

    cout << "Pankkitili: " << nimi << " siirtaa " << summa << " " << maksunVastaanottaja.nimi << ":lle" << endl;

    if (!nosto(summa)) {
        cout << "Tilin saldo ei riitä." << endl;
        return false;
    } if (!maksunVastaanottaja.talletus(summa)) {
        cout << "Summaa ei voida siirtää." << endl;
        return false;
    }
        return true;
}
