#include "DrinkVector.hpp"
#include <cstring>

DrinkVector::DrinkVector() : array(nullptr), size(0)
{
}

DrinkVector::DrinkVector(const DrinkVector& rhs) // : size(rhs.size)
{
    copyArray(rhs.array, rhs.size);
}

DrinkVector& DrinkVector::operator=(const DrinkVector& rhs)
{
    if (&rhs != this)
    {
        delete[] array; // don't worry; deleting nullptr is totally fine
        copyArray(rhs.array, rhs.size);
    }
    return *this;
}

DrinkVector::~DrinkVector()
{
    delete[] array;
}

Drink& DrinkVector::operator[](unsigned int index)
{
    return array[index];
}

unsigned int DrinkVector::vec_size() const
{
    return size;
}

void DrinkVector::push_back(Drink element)
{
    const unsigned int newSize = size + 1;
    Drink* newArray = new Drink[newSize];
    if (array)
    {
        for (int i = 0; i < size; i++)
        {
            newArray[i] = array[i];
        }
    }
    newArray[newSize - 1] = element;

    delete[] array;
    array = newArray;
    size = newSize;
}

bool DrinkVector::erase(unsigned int index)
{
    if (!array)
    {
        return false;
    }

    if (index >= size)
    {
        return false;
    }

    if (size == 1)
    {
        delete[] array;
        array = nullptr;
        size = 0;
        return true;
    }

    const unsigned int newSize = size - 1;
    Drink* newArray = new Drink[newSize];

    for (int i = 0; i < index; i++)
    {
        newArray[i] = array[i];
    }

    for (int i = index; i < newSize; i++)
    {
        newArray[i] = array[i + 1];
    }

    delete[] array;

    array = newArray;
    size = newSize;
    return true;
}

void DrinkVector::copyArray(const Drink* source, unsigned int size)
{
    if (!size)
    {
        array = nullptr;
        return;
    }

    array = new Drink[size];
    for (int i = 0; i < size; i++)
    {
        array[i] = source[i];
    }

    this->size = size;
}
