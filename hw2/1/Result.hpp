#pragma once
#include "Error.hpp"
#include "Optional.hpp"

template<typename T>
class Result {
public:
    Result();
    Result(const T& result);
    Result(const std::string& error_message);

    bool operator==(const Error&) const;
    bool operator==(const T&) const;
    Optional<T> get_result() const;
    Optional<Error> get_error() const;

private:
    Optional<T> result;
    Optional<Error> error;
};

template<typename T>
Result<T>::Result()
{
    Optional<Error> noError; //create empty error and result
    Optional<T> empty;       //as default values
    error = noError;
    result = empty;
}

template<typename T>
Result<T>::Result(const T& result) : result(result)
{
    Optional<Error> noError;
    error = noError;
}

template<typename T>
Result<T>::Result(const std::string& error_message)
{
    error = Optional<Error>(error_message);
}

template<typename T>
bool Result<T>::operator==(const Error& rhs) const
{
    if (!error.is_none())
    {
        return true;
    }
    return false;
}

template<typename T>
bool Result<T>::operator==(const T& rhs) const
{
    if (error.is_none() && !(result.is_none()))
    {
        return true;
    }
    return false;
}

template<typename T>
Optional<T> Result<T>::get_result() const
{
    return result;
}

template<typename T>
Optional<Error> Result<T>::get_error() const
{
    return error;
}