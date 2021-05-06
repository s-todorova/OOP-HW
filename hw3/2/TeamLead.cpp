#include "TeamLead.hpp"

TeamLead::TeamLead(const std::string& name, double salary) : Developer(name,salary,this)
{
}

std::vector<Developer*> TeamLead::getTeam() const
{
	return team;
}

void TeamLead::addDeveloperToTeam(Developer* developer, double salary)
{
	if (developer != nullptr)
	{
		developer->setInitialSalary(salary);
		developer->setTeamLead(this);
		team.push_back(developer);
	}
}

void TeamLead::removeDeveloperFromTeam(const std::string& name) //da go napravq da raboti za povtarqshti se imena
{
	for (int i = team.size()-1; i >= 0; i--)
	{
		if (team[i]->getName() == name)
		{
			team[i]->setTeamLead(nullptr);
			team.erase(team.begin() + i);
			return;
		}
	}
}

void TeamLead::increaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < team.size(); i++)
	{
		team[i]->increaseSalary(amount);
	}
}

void TeamLead::decreaseTeamSalariesBy(double amount)
{
	for (int i = 0; i < team.size(); i++)
	{
		team[i]->decreaseSalary(amount);
	}
}

void TeamLead::addLeavingRequest(const LeavingRequest& leavingRequest)
{
	leavingRequests.push_back(leavingRequest);
}

void TeamLead::addPromotionRequest(const PromotionRequest& promotionRequest)
{
	promotionRequests.push_back(promotionRequest);
}

void TeamLead::fulfillLeavingRequests()
{
	for (int i = 0; i < leavingRequests.size(); i++)
	{
		removeDeveloperFromTeam(leavingRequests[i].getSender());
	}
	
	leavingRequests.clear();
}

void TeamLead::fulfillPromotionRequests()
{
	for (int i = 0; i < promotionRequests.size(); i++)
	{
		for (int j = 0; j < team.size(); j++)
		{
			if (promotionRequests[i].getSender() == team[j]->getName())
			{
				team[j]->increaseSalary(promotionRequests[i].getAmount());
			}
		}
	}
	
	promotionRequests.clear();
}
