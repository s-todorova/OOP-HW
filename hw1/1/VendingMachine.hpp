#pragma once
#include "drink.hpp"
#include "DrinkVector.hpp"

class VendingMachine
{
public:
    VendingMachine();
    VendingMachine(const VendingMachine& from);
    VendingMachine& operator=(const VendingMachine& from);

    bool add_drink(const Drink& to_add);
    int buy_drink(const char* drink_name, const double money);

    double get_income() const;
    friend void printInv(VendingMachine a);

private:
    double income;
    DrinkVector inventory;
    //helper functions:
    bool drinkExists(const Drink& check);
    int findDrink(const char* drink_name);
};
