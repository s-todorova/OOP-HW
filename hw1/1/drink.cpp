#include "drink.hpp"
#include <cstring>
#pragma warning(disable : 4996)

Drink::Drink()
{
	name = new char[1];
	strcpy(name, "");
	calories = 0;
	quantity = 0.0;
	price = 0.0;
}

Drink::Drink(const char* init_name, const int init_calories, const double& init_quantity, const double& init_price)
{
	copyName(init_name);
	calories = init_calories;
	quantity = init_quantity;
	price = init_price;
}

Drink::Drink(const Drink& rhs)
{
	copyName(rhs.name);
	calories = rhs.calories;
	quantity = rhs.quantity;
	price = rhs.price;
}

Drink& Drink::operator=(const Drink& rhs)
{
	if (&rhs != this)
	{
		set_name(rhs.name);
		calories = rhs.calories;
		quantity = rhs.quantity;
		price = rhs.price;
	}
	return *this;
}

bool Drink::operator==(const Drink& rhs) const
{
	if (strcmp(name, rhs.name) != 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

Drink::~Drink()
{
	delete[] name;
}

const char* Drink::get_name() const
{
	return name;
}

int Drink::get_calories() const
{
	return calories;
}

double Drink::get_quantity() const
{
	return quantity;
}

double Drink::get_price() const
{
	return price;
}

void Drink::set_name(const char* new_name)
{
	delete[] name;
	copyName(new_name);
}

void Drink::copyName(const char* src)
{
	name = new char[strlen(src) + 1];
	strcpy(name, src);
}