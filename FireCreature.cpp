#include "GrassCreature.h"
#include "FireCreature.h"
#include "WaterCreature.h"

FireCreature::FireCreature(std::string name) : Creature(std::move(name), 100)
{
}

std::string FireCreature::GetTypeName() const
{
	return "Fire";
}

int FireCreature::BaseDamage() const
{
	return 20;
}

void FireCreature::Attack(Creature& target)
{
	target.RecieveAttackFrom(*this, BaseDamage());
}

void FireCreature::RecieveAttackFrom(const FireCreature& attacker, int dmg)
{
	ApplyTypedDamage(attacker, dmg, 1.0f);
}

void FireCreature::RecieveAttackFrom(const WaterCreature& attacker, int dmg)
{
	ApplyTypedDamage(attacker, dmg, 2.0f);
}

void FireCreature::RecieveAttackFrom(const GrassCreature& attacker, int dmg)
{
	ApplyTypedDamage(attacker, dmg, 0.5f);
}
