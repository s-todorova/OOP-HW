#pragma once
#include <string>
#include "LeavingRequest.hpp"
#include "PromotionRequest.hpp"

class TeamLead;

class Developer
{
public:
	Developer(const std::string& name);
	Developer(const std::string& name,double salary, TeamLead* leader);
	
	std::string getName() const;
	double getSalary() const;
	TeamLead* getTeamLead() const;

	void setInitialSalary(double amount);
	void setTeamLead(TeamLead* lead); 
	void increaseSalary(double amount); 
	void decreaseSalary(double amount);

	void sendLeavingRequest();
	void sendPromotionRequest(double amount);
private:
	std::string name;
	TeamLead* leader;
protected:
	double salary;
};