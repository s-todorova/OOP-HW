#pragma once
#include <iostream>

enum class ErrorType {
    None,
    BuildFailed,
    Warning,
    FailedAssertion,
};

/// It has a type and an optional message
class Error {
private:
    char* message;
    ErrorType type;

public:
    Error();
    Error(const char*, ErrorType);
    ~Error();

    bool hasMessage() const;   
    const char* getMessage() const;/// Retrieve the message of an error if such exists, else return nullptr   
    ErrorType getType() const; /// Retrieve the type of the error

    static Error newNone(); /// Create a new error of type None with no message 
    static Error newBuildFailed(const char* message);     /// new error of type BuildFailed with a message
    static Error newWarning(const char* message);     /// new error of type Warning with a message
    static Error newFailedAssertion(const char* message);     /// new error of type FailedAssertion with a message
};