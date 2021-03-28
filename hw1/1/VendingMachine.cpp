#include "VendingMachine.hpp"
#include <cstring>
#pragma warning(disable : 4996)

VendingMachine::VendingMachine()
{
	income = 0.0;
}

VendingMachine::VendingMachine(const VendingMachine& from)
{
    this->income = from.income;
    this->inventory = from.inventory;
}

VendingMachine& VendingMachine::operator=(const VendingMachine& from)
{
	if (&from != this)
	{
        this->income = from.income;
        this->inventory = from.inventory;
	}
	return *this;
}

bool VendingMachine::add_drink(const Drink& to_add)
{
    if (drinkExists(to_add) == false)
    {
        inventory.push_back(to_add);
        return true;
    }
    else
    {
        return false;
    }
}

int VendingMachine::buy_drink(const char* drink_name, const double money)
{
    bool exists = false;
    for (int i = 0; i < inventory.vec_size(); i++)
    {
        if (strcmp(inventory[i].get_name(), drink_name) == 0)
        {
            exists = true;
        }
    }

    unsigned int drinkIndex = findDrink(drink_name);
    if (exists == false) {
        return 2;
    }
    if (exists == true && inventory[drinkIndex].get_price() <= money) {
        income += money;
        inventory.erase(drinkIndex);
        return 0;
    }
    if (exists == true && inventory[drinkIndex].get_price() > money) {
        income += money;
        return 1;
    }
}

double VendingMachine::get_income() const
{
    return income;
}

bool VendingMachine::drinkExists(const Drink& check)
{
    for (int i = 0; i < inventory.vec_size(); i++)
    {
        if (strcmp(inventory[i].get_name(),check.get_name())==0)
        {
            return true;
        }
    }
    return false;
}

int VendingMachine::findDrink(const char* drink_name)
{
    for (int i = 0; i < inventory.vec_size(); i++)
    {
        if (strcmp(inventory[i].get_name(), drink_name) == 0)
        {
            return i;
        }
    }
    return -1; //if drink not found
}
