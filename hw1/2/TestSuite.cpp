#include "TestSuite.hpp"

TestSuite::TestSuite()
{
	name = "";
}

TestSuite::TestSuite(std::string name)
{
	this->name = name;
	testCases;
}

void TestSuite::add(const TestCase& to_add)
{
	testCases.push_back(to_add);
}

std::vector<TestCase> TestSuite::filterPassing() const
{
	std::vector<TestCase> passing;
	for (int i = 0; i < testCases.size(); i++)
	{
		if (testCases[i].isPassing() == true) 
		{
			passing.push_back(testCases[i]);
		}
	}
	return passing;
}

std::vector<TestCase> TestSuite::filterFailing() const
{
	std::vector<TestCase> failing;
	for (int i = 0; i < testCases.size(); i++)
	{
		if (testCases[i].isPassing() == false)
		{
			failing.push_back(testCases[i]);
		}
	}
	return failing;
}

std::vector<TestCase> TestSuite::filterByErrorType(ErrorType errType) const
{
	std::vector<TestCase> byErrType;
	for (int i = 0; i < testCases.size(); i++)
	{
		if (testCases[i].getErrorType()==errType)
		{
			byErrType.push_back(testCases[i]);
		}
	}
	return byErrType;
}

void TestSuite::removeByErrorType(ErrorType errType)
{
	for (int i = 0; i < testCases.size(); i++) {
		if(testCases[i].getErrorType()==errType)
		{
			testCases.erase(testCases.begin() + i - 1);
		}
	}
}

std::string TestSuite::getName() const
{
	return name;
}

void TestSuite::setName(const std::string& name)
{
	this->name = name;
}
