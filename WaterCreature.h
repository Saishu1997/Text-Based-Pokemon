#pragma once
#include "Creature.h"

class WaterCreature final : public Creature
{
public:
	explicit WaterCreature(std::string name);

	std::string GetTypeName() const override;
	int BaseDamage() const override;

	void Attack(Creature& target) override;

	void RecieveAttackFrom(const FireCreature& attacker, int dmg) override;
	void RecieveAttackFrom(const WaterCreature& attacker, int dmg) override;
	void RecieveAttackFrom(const GrassCreature& attacker, int dmg) override;
};

