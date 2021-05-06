#pragma once
#include <string>

class Request
{
public:
	Request(const std::string& message = "", const std::string& sender = "");
	
	std::string getMessage() const;
	std::string getSender() const;
	int getCount() const;
	int getID() const;

private:
	std::string message;
	std::string sender;
	static int count;
	int ID;
};