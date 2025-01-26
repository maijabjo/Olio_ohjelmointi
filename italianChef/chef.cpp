
#include "italianChef.h"
#define ITALIANCHEF_H
#include <iostream>
using namespace std;

Chef::Chef(string name) : chefName(name)
{
    cout << "Chef " << chefName << " constructor" << endl;
}

Chef::~Chef()
{
    cout << "Chef " << chefName << " destructor" << endl;
}

string Chef::getName()
{
    return chefName;
}

int Chef::makeSalad(int items)
{
    int portions = items / 5;
    cout << "Chef " << chefName << " with " << items << " items can make salad " << portions << " portions" << endl;
    return portions;
}

int Chef::makeSoup(int items)
{
    int portions = items / 3;
    cout << "Chef " << chefName << " with " << items << " items can make soup " << portions << " portions\n" << endl;
    return portions;
}
