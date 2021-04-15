#pragma once

template <typename T>
class Optional {
public:
    Optional();
    Optional(const T& value);

    //Optional& operator=(const Optional&);
    bool is_none() const;
    T get_value() const;

private:
    T value;
    bool isEmpty;
};

template<typename T>
Optional<T>::Optional()
{
    this->value = T();
    isEmpty = true;
}

template<typename T>
Optional<T>::Optional(const T& value) : value(value)
{
    isEmpty = false;
}

//template<typename T>
//Optional<T>& Optional<T>::operator=(const Optional& rhs)
//{
//    this->value = rhs.value;
//    this->isEmpty = rhs.isEmpty;
//}

template<typename T>
bool Optional<T>::is_none() const
{
    return isEmpty;
}

template<typename T>
T Optional<T>::get_value() const
{
    return value;
}
