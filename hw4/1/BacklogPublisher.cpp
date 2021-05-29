#include "BacklogPublisher.hpp"

void BacklogPublisher::subscribe(Averager* sub)
{
	if (sub == nullptr)
	{
		return;
	}
	subscribers.push_back(static_cast<Subscriber*>(sub));
	receiveOldMessages(sub);
}

void BacklogPublisher::subscribe(MovingAverager* sub)
{
	if (sub == nullptr)
	{
		return;
	}
	subscribers.push_back(static_cast<Subscriber*>(sub));
	receiveOldMessages(sub);
}

void BacklogPublisher::subscribe(PeriodicSampler* sub)
{
	if (sub == nullptr)
	{
		return;
	}
	subscribers.push_back(static_cast<Subscriber*>(sub));
	receiveOldMessages(sub);
}

void BacklogPublisher::signal(Message message)
{
	for (int i = 0; i < subscribers.size(); i++)
	{
		subscribers[i]->signal(message);
	}
	allMessages.push_back(message);
}

void BacklogPublisher::receiveOldMessages(Subscriber* sub)
{
	for (int i = 0; i < allMessages.size(); i++)
	{
		sub->signal(allMessages[i]);
	}
}
