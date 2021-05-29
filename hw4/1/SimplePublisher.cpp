#include "SimplePublisher.hpp"

void SimplePublisher::subscribe(Averager* sub)
{
	if (sub == nullptr)
	{
		return;
	}
	subscribers.push_back(static_cast<Subscriber*>(sub));
}

void SimplePublisher::subscribe(MovingAverager* sub)
{
	if (sub == nullptr)
	{
		return;
	}
	subscribers.push_back(static_cast<Subscriber*>(sub));
}

void SimplePublisher::subscribe(PeriodicSampler* sub)
{
	if (sub == nullptr)
	{
		return;
	}
	subscribers.push_back(static_cast<Subscriber*>(sub));
}

void SimplePublisher::signal(Message message)
{
	for (int i = 0; i < subscribers.size(); i++)
	{
		subscribers[i]->signal(message);
	}
}
