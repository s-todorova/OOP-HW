#pragma once
#include "Message.hpp"
#include <string>
#include <vector>
#include "Subscriber.hpp"

class Averager : public Subscriber {
public:
	Averager(const std::string& id);

	void signal(Message) override;
	int read() const override;
	Subscriber* clone() const override;
};