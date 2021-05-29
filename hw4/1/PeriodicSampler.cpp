#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period) : Subscriber(id), period(period)
{
}

void PeriodicSampler::signal(Message message)
{
	signalCount++;
	if ((signalCount - 1) % period == 0)
	{
		messages.push_back(message);
	}
}

int PeriodicSampler::read() const
{
	if (messages.empty())
	{
		return 0;
	}

	return messages[messages.size() - 1].data;
}

Subscriber* PeriodicSampler::clone() const
{
	return new PeriodicSampler(*this);
}
