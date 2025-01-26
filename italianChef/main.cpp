#include "Chef.h"
#include "italianChef.h"
#define ITALIANCHEF_H
#include <iostream>
using namespace std;
#include <iostream>
#include <string>

using namespace std;

int main()
{
    string chefName = "Gordon";
    string italianChefName = "Mario";

    Chef chef(chefName);

    int saladItems;
    cout << "The amount of salad items: ";
    cin >> saladItems;
    chef.makeSalad(saladItems);

    int soupItems;
    cout << "The amount of soup items: ";
    cin >> soupItems;
    chef.makeSoup(soupItems);

    ItalianChef italianChef(italianChefName);

    string password;
    int flour, water;

    cout << "What is the password for Italian chef: ";
    cin >> password;

    cout << "How much flour? ";
    cin >> flour;

    cout << "How much water? ";
    cin >> water;

    italianChef.askSecret(password, flour, water);
    return 0;
}
