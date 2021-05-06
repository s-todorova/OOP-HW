#include "Request.hpp"
int Request::count = 0;

Request::Request(const std::string& message, const std::string& sender) : message(message), sender(sender)
{
	count++;
	ID = count;
}

std::string Request::getMessage() const
{
	return message;
}

std::string Request::getSender() const
{
	return sender;
}

int Request::getCount() const
{
	return count;
}

int Request::getID() const
{
	return ID;
}
