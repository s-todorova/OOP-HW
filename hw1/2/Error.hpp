#pragma once
#include <iostream>

enum class ErrorType {
    None,
    BuildFailed,
    Warning,
    FailedAssertion,
};

class Error {
public:
    Error();
    Error(const char* msg, ErrorType);
    Error(ErrorType);// special constructor for creating objects with None error type
    Error& operator=(const Error&);
    Error(const Error&);
    ~Error();
 
    bool hasMessage() const;   
    const char* getMessage() const;
    ErrorType getType() const;

    static Error newNone();
    static Error newBuildFailed(const char* message);
    static Error newWarning(const char* message);
    static Error newFailedAssertion(const char* message);

private:
    char* message;
    ErrorType type;
    void copyMessage(const char*); //helper function
};