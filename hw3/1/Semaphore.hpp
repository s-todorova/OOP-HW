#pragma once
#include "LimitedTwowayCounter.hpp"

class Semaphore : public LimitedTwowayCounter
{
public:
	Semaphore();
	Semaphore(bool value);

	bool isAvailable() const;
	void wait();
	void signal();
};
