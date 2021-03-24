#pragma once
#include <iostream>

enum class ErrorType {
    None,
    BuildFailed,
    Warning,
    FailedAssertion,
};

class Error {                                //NE E OSVOBODENA PAMETTA!! DA IZMISLQ KAK/KOGA I DALI S DESTRUKTOR
private:
    char* message;
    ErrorType type;

public:
    Error();
    Error(const char*, ErrorType);
    //~Error();

    bool hasMessage() const;   
    const char* getMessage() const;
    ErrorType getType() const;

    static Error newNone();
    static Error newBuildFailed(const char* message);
    static Error newWarning(const char* message);
    static Error newFailedAssertion(const char* message);
};