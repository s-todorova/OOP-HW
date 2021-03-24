#pragma once
#include <string>
#include "Error.hpp"

class TestCase {
    Error error;
    std::string name;
public:
    TestCase(const std::string& name = "", const Error& error = Error::newNone());

    std::string getName() const;
    bool isPassing() const; // A test is passing if its Error is None or Warning
    bool hasError() const; // test has an error if its Error is different from None.
    ErrorType getErrorType() const;  /// Retrieve the type of Error this test has (it could be None)
    std::string getErrorMessage() const;     /// Retrieve the message of the error if Error has one, otherwise return an empty string
};