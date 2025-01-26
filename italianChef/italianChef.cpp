#include "italianChef.h"
#define ITALIANCHEF_H
#include <iostream>
using namespace std;

ItalianChef::ItalianChef(string name) : Chef(name), flour(0), water(0)
{
    cout << "ItalianChef " << chefName << " constructor" << endl;
}

ItalianChef::~ItalianChef()
{
    cout << "ItalianChef " << chefName << " destructor" << endl;
}

bool ItalianChef::askSecret(string PassWord, int amountOfFlour, int amountOfWater)
{
    if (PassWord == password)
    {
        int Flour = amountOfFlour;
        int Water = amountOfWater;

        flour = amountOfFlour;
        water = amountOfWater;

        cout << "Password ok!" << endl;

        int PIZZA = makepizza();

        cout << "ItalianChef " << chefName << " with " << Flour << " flour and " << Water << " water can make " << PIZZA << " PIZZA\n" << endl;
        return true;
    }
    else
    {
        cout << "Incorrect password!" << endl;
        return false;
    }
}

int ItalianChef::makepizza()
{
    if (flour > 0 && water > 0)
    {
        int pizzas = min(flour / 5, water / 5);
        flour -= pizzas * 5;
        water -= pizzas * 5;
        return pizzas;
    }
    else
    {
        return 0;
    }
}

