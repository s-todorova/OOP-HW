#include "Counter.hpp"

Counter::Counter() : value(0), step(1)
{
}

Counter::Counter(int initial) : value(initial), step(1)
{
}

Counter::Counter(int initial, unsigned step) : value(initial), step(step)
{
}

void Counter::increment()
{
	value += step;
}

int Counter::getTotal() const
{
	return value;
}

unsigned Counter::getStep() const
{
	return step;
}

void Counter::setValue(int value)
{
	this->value = value;
}
