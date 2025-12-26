#include "GrassCreature.h"
#include "FireCreature.h"
#include "WaterCreature.h"

GrassCreature::GrassCreature(std::string name) : Creature(std::move(name), 105)
{
}

std::string GrassCreature::GetTypeName() const
{
	return "Grass";
}

int GrassCreature::BaseDamage() const
{
	return 19;
}

void GrassCreature::Attack(Creature& target)
{
	target.RecieveAttackFrom(*this, BaseDamage());
}

void GrassCreature::RecieveAttackFrom(const FireCreature& attacker, int dmg)
{
	ApplyTypedDamage(attacker, dmg, 2.0f);
}

void GrassCreature::RecieveAttackFrom(const WaterCreature& attacker, int dmg)
{
	ApplyTypedDamage(attacker, dmg, 0.5f);
}

void GrassCreature::RecieveAttackFrom(const GrassCreature& attacker, int dmg)
{
	ApplyTypedDamage(attacker, dmg, 1.0f);
}
