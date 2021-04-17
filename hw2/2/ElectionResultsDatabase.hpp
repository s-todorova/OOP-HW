#pragma once
#include "SectionVotes.hpp"
#include <vector>
#include <fstream>
#include <iostream>

class ElectionResultsDatabase
{
public:
    void addResultsFromFile(const char* filename);
    void addSection(SectionVotes);
    int numberOfSections() const;

    int votesForParty(Party) const;
    Party winningParty() const;
    Party partyWithMostVotes(int,int,int) const; //helper for comparing total party votes
   
    friend std::istream& operator>>(std::istream&, ElectionResultsDatabase&);
    friend std::ostream& operator<<(std::ostream&, ElectionResultsDatabase&);

private:
    std::vector<SectionVotes> sections;
};