#include "ElectionResultsDatabase.hpp"

void ElectionResultsDatabase::addResultsFromFile(const char* filename)
{
	std::fstream file(filename);
	if (!file.is_open())
	{
		return;
	}
	file >> *this;
}

void ElectionResultsDatabase::addSection(SectionVotes section)
{
	sections.push_back(section);
}

int ElectionResultsDatabase::numberOfSections() const
{
	return sections.size();
}

int ElectionResultsDatabase::votesForParty(Party party) const
{
	int partyVotes=0;
	for (int i = 0; i < numberOfSections(); i++) {
		partyVotes += sections[i].SectionVotes::votesForParty(party);
	}

	return partyVotes;
}

Party ElectionResultsDatabase::winningParty() const
{
	int totalP1 = votesForParty(Party::PARTY1);
	int totalP2 = votesForParty(Party::PARTY2);
	int totalP3 = votesForParty(Party::PARTY3);
	
	return partyWithMostVotes(totalP1, totalP2, totalP3);
}

Party ElectionResultsDatabase::partyWithMostVotes(int p1, int p2, int p3) const
{
	if ((p1 > p2 && p1 > p3) || (p1 == p2 && p1 > p3) || (p1 == p3 && p1 > p2))
	{
		return Party::PARTY1;
	}
	if ((p2 > p1 && p2 > p3) || (p2 == p3 && p2 > p1))
	{
		return Party::PARTY2;
	}
	if (p3 > p2 && p3 > p1)
	{
		return Party::PARTY3;
	}
}

std::istream& operator>>(std::istream& input, ElectionResultsDatabase& database)
{
	SectionVotes section;
	while (input >> section)
	{
		database.addSection(section);
	}
	return input;
}

std::ostream& operator<<(std::ostream& output, ElectionResultsDatabase& database)
{
	for (int i = 0; i < database.numberOfSections(); i++)
	{
		output << database.sections[i] << "\n";
	}
	return output;
}
