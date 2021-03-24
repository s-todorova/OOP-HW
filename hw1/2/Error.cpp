#include "Error.hpp"
#include <cstring>
#pragma warning(disable : 4996)

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

//Error::~Error()
//{
//	delete[] message;
//}

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
	Error BuildFailed(message, ErrorType::BuildFailed);
	return BuildFailed;
}

Error Error::newWarning(const char* message)
{
	Error Warning(message, ErrorType::Warning);
	return Warning;
}

Error Error::newFailedAssertion(const char* message)
{
	Error FailedAssertion(message, ErrorType::FailedAssertion);
	return FailedAssertion;
}
