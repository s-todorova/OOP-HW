#include "LimitedTwowayCounter.hpp"

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max)
	: Counter(0,1), TwowayCounter(0,1), LimitedCounter(max,0,1), min(min)
{
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial)
	: Counter(initial, 1), TwowayCounter(initial, 1), LimitedCounter(max, initial, 1), min(min)
{
}

LimitedTwowayCounter::LimitedTwowayCounter(int min, int max, int initial, unsigned step)
	: Counter(initial, step), TwowayCounter(initial, step), LimitedCounter(max, initial, step), min(min)
{
}

void LimitedTwowayCounter::increment()
{
	LimitedCounter::increment();
}

void LimitedTwowayCounter::decrement()
{
	int total = Counter::getTotal();
	unsigned step = Counter::getStep();
	int decremented = total;
	decremented -= step;
	if (decremented >= min)
	{
		Counter::setValue(decremented);
	}
}

int LimitedTwowayCounter::getMin() const
{
	return min;
}

int LimitedTwowayCounter::getMax() const
{
	return LimitedCounter::getMax();
}

int LimitedTwowayCounter::getTotal() const
{
	return Counter::getTotal();
}

unsigned LimitedTwowayCounter::getStep() const
{
	return Counter::getStep();
}
