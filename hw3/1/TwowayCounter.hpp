#pragma once
#include "Counter.hpp"

class TwowayCounter : virtual public Counter
{

public:
	TwowayCounter();
	TwowayCounter(int initial);
	TwowayCounter(int initial, unsigned step);

	void increment();
	void decrement();
	int getTotal() const;
	unsigned getStep() const;
};