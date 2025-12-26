#include "Creature.h"
#include <iostream>
#include <utility>

Creature::Creature(std::string name, int hp) : m_name(std::move(name)), m_hp(hp)
{
}

Creature::~Creature() = default;


void Creature::TakeDamage(int dmg)
{
	m_hp -= dmg;
	if (m_hp < 0)
		m_hp = 0;
}

bool Creature::IsAlive() const
{
	return m_hp > 0;
}

int Creature::GetHP() const
{
	return m_hp;
}

const std::string& Creature::GetName() const
{
	return m_name;
}

void Creature::ApplyTypedDamage(const Creature& attacker, int baseDamage, float multiplier)
{
	int finalDmg = static_cast<int>(baseDamage * multiplier + 0.5f);

	std::string eff;
	if (multiplier >= 1.5f) eff = "It's super effective!";
	else if (multiplier <= 0.75f) eff = "It's not very effective...";

	std::cout << attacker.GetName() << " (" << attacker.GetTypeName() << ") hits"
		<< m_name << " for " << finalDmg << " damage." << eff << "\n";

	TakeDamage(finalDmg);
}
