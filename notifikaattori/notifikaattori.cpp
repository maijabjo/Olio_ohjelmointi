#include "notifikaattori.h"

Notifikaattori::Notifikaattori() {
    cout << "Luodaan notifikaattori" << endl;
}

void Notifikaattori::lisaa(Seuraaja *seuraaja)
{
    cout << "Notifikaattori lisaa seuraajan " << seuraaja->getNimi()<< endl;
    seuraaja->next = seuraajat;
    seuraajat = seuraaja;
}

void Notifikaattori::poista(Seuraaja *seuraaja)
{
    cout << "Notifikaattori poistaa seuraajan " << seuraaja->getNimi() << endl;
    Seuraaja* nyt = seuraajat;
    Seuraaja* ennen = nullptr;

    while (nyt!= nullptr) {
        if (nyt == seuraaja) {
            if (ennen!= nullptr) {
                ennen->next = nyt->next;
            } else {
                seuraajat = nyt->next;
            }
            return;
        }
        ennen = nyt;
        nyt = nyt->next;
    }
}

void Notifikaattori::tulosta()
{
    cout << "Notifikaattorin seuraajat:" << endl;
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen!= nullptr) {
        cout << "Seuraaja " << nykyinen->getNimi() << endl;
        nykyinen = nykyinen->next;
    }
}

void Notifikaattori::postita(string viesti)
{
    cout << "Notifikaattori postaa viestin " << viesti << endl;
    Seuraaja* nykyinen = seuraajat;
    while (nykyinen != nullptr) {
        nykyinen->paivitys(viesti);
        nykyinen = nykyinen->next;
    }
}
