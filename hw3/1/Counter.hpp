#pragma once

class Counter
{
public:
	Counter();
	Counter(int initial);
	Counter(int initial, unsigned step);

	void increment();
	int getTotal() const;
	unsigned getStep() const;

private:
	int value;
	unsigned step;
protected:
	void setValue(int value);
};