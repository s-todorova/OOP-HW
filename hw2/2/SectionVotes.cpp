#include "SectionVotes.hpp"

SectionVotes::SectionVotes() : votesParty1(0), votesParty2(0), votesParty3(0)
{
}

SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes)
{
	votesParty1 = party1Votes;
	votesParty2 = party2Votes;
	votesParty3 = party3Votes;
}

int SectionVotes::votesForParty(Party party) const
{
	if (party == Party::PARTY1)
	{
		return votesParty1;
	}
	if (party == Party::PARTY2)
	{
		return votesParty2;
	}
	if (party == Party::PARTY3)
	{
		return votesParty3;
	}
}

std::istream& operator>>(std::istream& input, SectionVotes& sectionVotes)
{
	int votesP1, votesP2, votesP3;
	input >> votesP1 >> votesP2 >> votesP3;
	sectionVotes = SectionVotes(votesP1, votesP2, votesP3);
	
	return input;
}

std::ostream& operator<<(std::ostream& output, SectionVotes& sectionVotes)
{
	output << sectionVotes.votesParty1 << " " << sectionVotes.votesParty2 << " " << sectionVotes.votesParty3;

	return output;
}
