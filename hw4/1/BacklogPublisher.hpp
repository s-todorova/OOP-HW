#pragma once
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "Publisher.hpp"

class BacklogPublisher : public Publisher {
public:

	void subscribe(Averager*) override;
	void subscribe(MovingAverager*) override;
	void subscribe(PeriodicSampler*) override;

	void signal(Message) override;
private:
	std::vector<Message> allMessages;
	void receiveOldMessages(Subscriber*); //helper for sending old messages to new subscribers
};