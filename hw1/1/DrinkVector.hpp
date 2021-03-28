#pragma once
#include "drink.hpp"

class DrinkVector
{
public:
    DrinkVector();
    DrinkVector(const DrinkVector&);
    DrinkVector& operator=(const DrinkVector&);
    ~DrinkVector();

    Drink& operator[](unsigned int index);

    int vec_size() const;
    void push_back(Drink element);
    bool erase(unsigned int index);

private:
    Drink* array;
    unsigned int size;

    void copyArray(const Drink* src, unsigned int size);
};