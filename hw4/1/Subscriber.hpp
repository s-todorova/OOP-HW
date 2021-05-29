#pragma once
#include <string>
#include <vector>
#include "Message.hpp"

class Subscriber
{
public:
	const std::string id;

	Subscriber(const std::string& = "");
	virtual ~Subscriber() = default;
	
	virtual void signal(Message) = 0;
	virtual int read() const = 0;
	virtual Subscriber* clone() const = 0;

	std::vector<Message> messages;
};