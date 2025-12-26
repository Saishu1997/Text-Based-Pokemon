#pragma once
#include "Creature.h"
#include <memory>
#include <vector>
#include <string>

class Party
{
public:
	explicit Party(std::string trainerName);

	void Add(std::unique_ptr<Creature> creature);

	Creature* Active();
	const Creature* Active() const;

	void AutoAdvanceIfNeeded();
	bool IsDefeated() const;

	const std::string& Name() const;
	void PrintTeamStatus() const;

private:
	std::string m_trainerName;
	std::vector<std::unique_ptr<Creature>> m_team;
	size_t m_activeIndex = 0;
};

