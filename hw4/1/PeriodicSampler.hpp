#pragma once
#include "Message.hpp"
#include <string>
#include "Subscriber.hpp"

class PeriodicSampler : public Subscriber {
public:
	PeriodicSampler(std::string id, size_t period);

	void signal(Message) override;
	int read() const override;
	Subscriber* clone() const override;
private:
	size_t period;
	unsigned signalCount = 0;
};