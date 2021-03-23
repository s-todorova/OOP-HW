#include "Error.hpp"
#include <cstring>

Error::Error()
{
	message = new char[1];
	strcpy(message, "");
	this->type = ErrorType::None;
}

Error::Error(const char* msg, ErrorType errType)
{
	message = new char[strlen(msg) + 1];
	strcpy(message, msg);
	this->type = errType;
}

Error::~Error()
{
	delete[] message;
}

bool Error::hasMessage() const
{
	if (strcmp(this->message, "") == 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}

const char* Error::getMessage() const
{
	if (hasMessage() == true)
	{
		return message;
	}
	return nullptr;
}

ErrorType Error::getType() const
{
	return type;
}

Error Error::newNone()
{
	Error None;
	return None;
}

Error Error::newBuildFailed(const char* message)
{
	Error BuildFailed("The build has failed!", ErrorType::BuildFailed);
	return BuildFailed;
}

Error Error::newWarning(const char* message)
{
	Error Warning("Warning!", ErrorType::Warning);
	return Warning;
}

Error Error::newFailedAssertion(const char* message)
{
	Error FailedAssertion("Failed Assertion!", ErrorType::FailedAssertion);
	return FailedAssertion;
}
