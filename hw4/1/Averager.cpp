#include "Averager.hpp"

Averager::Averager(const std::string& id) : Subscriber(id)
{
}

void Averager::signal(Message message)
{
	messages.push_back(message);
}

int Averager::read() const
{
	if (messages.empty())
	{
		return 0;
	}
	int allData = 0, average = 0;
	for (int i = 0; i < messages.size(); i++)
	{
		allData += messages[i].data;
	}
	average = allData / messages.size();

	return average;
}

Subscriber* Averager::clone() const
{
	return new Averager(*this);
}
