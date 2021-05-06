#include "Semaphore.hpp"

Semaphore::Semaphore() : LimitedTwowayCounter(0,1,0,1)
{
}

Semaphore::Semaphore(bool value) : LimitedTwowayCounter(0,1,1,1)
{
	if (value == false)
	{
		LimitedTwowayCounter::decrement();
	}
}

bool Semaphore::isAvailable() const
{
	return LimitedTwowayCounter::getTotal()>0;
}

void Semaphore::wait()
{
	LimitedTwowayCounter::decrement();
}

void Semaphore::signal()
{
	LimitedTwowayCounter::increment();
}
