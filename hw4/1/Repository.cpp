#include "Repository.hpp"

Repository::Repository(const Repository& rhs)
{
	copySubs(rhs);
}

Repository& Repository::operator=(const Repository& rhs)
{
	if (this != &rhs)
	{
		deleteSubs();
		copySubs(rhs);
	}
	return *this;
}

Repository::~Repository()
{
	deleteSubs();
}
	
void Repository::add(Averager* sub)
{
	
	if (sub == nullptr)
	{
		return;
	}
	subscribers.push_back(sub->clone());
}

void Repository::add(MovingAverager* sub)
{
	
	if (sub == nullptr)
	{
		return;
	}
	subscribers.push_back(sub->clone());
}

void Repository::add(PeriodicSampler* sub)
{
	if (sub == nullptr)
	{
		return;
	}
	subscribers.push_back(sub->clone());
}

Subscriber* Repository::get(std::string id)
{
	for (int i = 0; i < subscribers.size(); i++)
	{
		if (subscribers[i]->id == id)
		{
			return subscribers[i];
		}
	}
	return nullptr;
}

void Repository::deleteSubs()
{
	for (auto sub : subscribers)
	{
		delete sub;
	}
	subscribers.clear();
}

void Repository::copySubs(const Repository& rhs)
{
	for (auto sub : rhs.subscribers)
	{
		subscribers.push_back(sub->clone());
	}
}
