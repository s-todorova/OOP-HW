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
	copyMessage(msg);
	this->type = errType;
}

Error::Error(ErrorType err)
{
	this->type = err;
	this->message = nullptr;
}

Error& Error::operator=(const Error& rhs)
{
	if (&rhs != this)
	{
		delete[] message;
		copyMessage(rhs.message);
		this->type = rhs.type;
	}
	return *this;
}

Error::Error(const Error& rhs)
{
	copyMessage(rhs.message);
	this->type = rhs.type;
}

Error::~Error()
{
	delete[] message;
}

bool Error::hasMessage() const
{
	if (message==nullptr)
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
	Error None(ErrorType::None);
	return None;
}

Error Error::newBuildFailed(const char* message)
{
	Error BuildFailed(message,ErrorType::BuildFailed);
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

void Error::copyMessage(const char* src)
{
	if (src == nullptr)
	{
		message = nullptr;
	}
	else
	{
		int msgLength = strlen(src);
		message = new char[msgLength + 1];
		strcpy(message, src);
	}
}