#include "TwowayCounter.hpp"

TwowayCounter::TwowayCounter() : Counter()
{
}

TwowayCounter::TwowayCounter(int initial) : Counter(initial)
{
}

TwowayCounter::TwowayCounter(int initial, unsigned step) : Counter(initial,step)
{
}

void TwowayCounter::increment()
{
	Counter::increment();
}

void TwowayCounter::decrement()
{
	int newValue = Counter::getTotal();
	newValue -= Counter::getStep();
	Counter::setValue(newValue);
}

int TwowayCounter::getTotal() const
{
	return Counter::getTotal();
}

unsigned TwowayCounter::getStep() const
{
	return Counter::getStep();
}
