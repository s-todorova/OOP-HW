#include "Developer.hpp"
#include "TeamLead.hpp"

Developer::Developer(const std::string& name) : name(name), salary(0.0), leader(nullptr)
{
}

Developer::Developer(const std::string& name, double salary, TeamLead* leader) : name(name),salary(salary),leader(leader)
{
}

std::string Developer::getName() const
{
	return name;
}

double Developer::getSalary() const
{
	return salary;
}

TeamLead* Developer::getTeamLead() const
{
	return leader;
}

void Developer::setInitialSalary(double amount)
{
	if (salary == 0)
	{
		salary = amount;
	}
}

void Developer::setTeamLead(TeamLead* lead)
{
	leader = lead;
}

void Developer::increaseSalary(double amount)
{
	salary += amount;
}

void Developer::decreaseSalary(double amount)
{
	salary -= amount;
}

void Developer::sendLeavingRequest()
{
	if (leader != nullptr)
	{
		LeavingRequest leavingRequest(getName());
		leader->addLeavingRequest(leavingRequest);
	}
}

void Developer::sendPromotionRequest(double amount)
{
	if (leader != nullptr)
	{
		PromotionRequest promotionRequest(getName(), amount);
		leader->addPromotionRequest(promotionRequest);
	}
}
