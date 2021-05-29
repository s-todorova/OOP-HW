#pragma once
#include"Subscriber.hpp"
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include <vector>

class Publisher
{
public:
	Publisher() = default;
	virtual ~Publisher() = default;

	virtual void subscribe(Averager*) = 0;
	virtual void subscribe(MovingAverager*) = 0;
	virtual void subscribe(PeriodicSampler*) = 0;

	virtual void unsubscribe(Subscriber*);
	//virtual void unsubscribe(MovingAverager*);
	//virtual void unsubscribe(PeriodicSampler*);

	virtual void signal(Message) = 0;
protected:
	std::vector<Subscriber*> subscribers;
};