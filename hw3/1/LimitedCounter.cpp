#include "LimitedCounter.hpp"

LimitedCounter::LimitedCounter(int max) : Counter(0,1), max(max)
{
}

LimitedCounter::LimitedCounter(int max, int initial) : Counter(initial,1), max(max)
{
}

LimitedCounter::LimitedCounter(int max, int initial, unsigned step)
	: Counter(initial,step), max(max)
{
}

void LimitedCounter::increment()
{
	int total = Counter::getTotal();
	unsigned step = Counter::getStep();
	int incremented = total;
	incremented += step;
	if (incremented <= max)
	{
		Counter::setValue(incremented);
	}
}

int LimitedCounter::getMax() const
{
	return max;
}

int LimitedCounter::getTotal() const
{
	return Counter::getTotal();
}

unsigned LimitedCounter::getStep() const
{
	return Counter::getStep();
}
