#include "Party.h"
#include <iostream>
#include <utility>

Party::Party(std::string trainerName) : m_trainerName(std::move(trainerName))
{
}

void Party::Add(std::unique_ptr<Creature> creature)
{
	m_team.emplace_back(std::move(creature));
}

Creature* Party::Active()
{
	if (m_activeIndex >= m_team.size())
		return nullptr;

	return m_team[m_activeIndex].get();
}

const Creature* Party::Active() const
{
	if (m_activeIndex >= m_team.size())
		return nullptr;
		
	return m_team[m_activeIndex].get();
}

void Party::AutoAdvanceIfNeeded()
{
	while (m_activeIndex < m_team.size() && !m_team[m_activeIndex]->IsAlive())
	{
		++m_activeIndex;

		if (m_activeIndex < m_team.size())
		{
			std::cout << m_trainerName << " sends out " << m_team[m_activeIndex]->GetName()
				<< " (" << m_team[m_activeIndex]->GetTypeName() << ")!\n";
		}
	}
}

bool Party::IsDefeated() const
{
	for (const auto& p : m_team)
	{
		if (p && p->IsAlive())
			return false;
	}

	return true;
}

const std::string& Party::Name() const
{
	return m_trainerName;
}

void Party::PrintTeamStatus() const
{
	std::cout << m_trainerName << " Team:\n";

	for (size_t i = 0; i < m_team.size(); ++i)
	{
		const auto& p = m_team[i];
		std::cout << " [" << (i == m_activeIndex ? "ACTIVE" : "    ")
			<< "] " << p->GetName()
			<< " (" << p->GetTypeName() << ") HP: " << p->GetHP()
			<< (p->IsAlive() ? "" : " [KO]") << "\n";
	}
}
