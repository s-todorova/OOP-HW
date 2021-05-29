#pragma once
#include "Message.hpp"
#include <string>
#include "Subscriber.hpp"

class MovingAverager : public Subscriber {
public:
	MovingAverager(const std::string& id, const size_t windowSize);

	const size_t windowSize;

	void signal(Message) override;
	int read() const override;
	Subscriber* clone() const override;
};