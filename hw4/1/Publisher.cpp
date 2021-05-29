#include "Publisher.hpp"

//void Publisher::unsubscribe(Averager* sub)
//{
//	if (sub == nullptr)
//	{
//		return;
//	}
//
//	for (int i = 0; i < subscribers.size(); i++)
//	{
//		if (subscribers[i]->id == sub->id)
//		{
//			this->subscribers.erase(this->subscribers.begin() + i);
//		}
//	}
//}
//
//void Publisher::unsubscribe(MovingAverager* sub)
//{
//	if (sub == nullptr)
//	{
//		return;
//	}
//
//	for (int i = 0; i < subscribers.size(); i++)
//	{
//		if (subscribers[i]->id == sub->id)
//		{
//			this->subscribers.erase(this->subscribers.begin() + i);
//		}
//	}
//}

void Publisher::unsubscribe(Subscriber* sub)
{
	if (sub == nullptr)
	{
		return;
	}

	for (int i = 0; i < subscribers.size(); i++)
	{
		if (subscribers[i]->id == sub->id)
		{
			subscribers.erase(subscribers.begin() + i);
		}
	}
}
