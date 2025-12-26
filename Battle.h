#pragma once
#include "Party.h"

class Battle
{
public:
	Battle(Party a, Party b);

	void Run();

private:
	void PrintStatus() const;
	void AnnounceWinner() const;

private:
	Party m_a;
	Party m_b;
};

