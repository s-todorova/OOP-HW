#pragma once
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include <string>
#include <vector>

class Repository {
public:
	Repository() = default;
	Repository(const Repository&);
	Repository& operator=(const Repository&);
	~Repository();

	void add(Averager*);
	void add(MovingAverager*);
	void add(PeriodicSampler*);

	Subscriber* get(std::string id);
private:
	std::vector<Subscriber*> subscribers;
	void deleteSubs();
	void copySubs(const Repository&);
};