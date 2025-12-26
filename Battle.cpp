#include "Battle.h"
#include <iostream>
#include <utility>

Battle::Battle(Party a, Party b) : m_a(std::move(a)), m_b(std::move(b))
{
}

void Battle::Run()
{
    std::cout << "=== PARTY BATTLE START ===\n\n";

    if (m_a.Active())
        std::cout << m_a.Name() << " sends out " << m_a.Active()->GetName()
        << " (" << m_a.Active()->GetTypeName() << ")!\n";
    if (m_b.Active())
        std::cout << m_b.Name() << " sends out " << m_b.Active()->GetName()
        << " (" << m_b.Active()->GetTypeName() << ")!\n";

    PrintStatus();

    bool aTurn = true;

    while (!m_a.IsDefeated() && !m_b.IsDefeated())
    {
        Party& attackerParty = aTurn ? m_a : m_b;
        Party& defenderParty = aTurn ? m_b : m_a;

        attackerParty.AutoAdvanceIfNeeded();
        defenderParty.AutoAdvanceIfNeeded();

        if (attackerParty.IsDefeated() || defenderParty.IsDefeated())
            break;

        Creature* attacker = attackerParty.Active();
        Creature* defender = defenderParty.Active();

        std::cout << "\n-- " << attackerParty.Name() << "'s turn --\n";
        attacker->Attack(*defender);

        if (!defender->IsAlive())
        {
            std::cout << defender->GetName() << " fainted!\n";
            defenderParty.AutoAdvanceIfNeeded();
        }

        PrintStatus();
        aTurn = !aTurn;
    }

    AnnounceWinner();
}

void Battle::PrintStatus() const
{
	std::cout << "\n";
	m_a.PrintTeamStatus();
	std::cout << "\n";
	m_b.PrintTeamStatus();
	std::cout << "\n";
}

void Battle::AnnounceWinner() const
{
	std::cout << "\n=== BATTLE OVER ===\n";

	const bool aLost = m_a.IsDefeated();
	const bool bLost = m_b.IsDefeated();

	if (aLost && bLost)
	{
		std::cout << "It's a draw! \n";
	}

	else if (bLost)
	{
		std::cout << m_a.Name() << " wins!\n";
	}

	else
	{
		std::cout << m_b.Name() << " wins!\n";
	}
}
