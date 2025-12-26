#include "GrassCreature.h"
#include "FireCreature.h"
#include "WaterCreature.h"

WaterCreature::WaterCreature(std::string name) : Creature(std::move(name), 110)
{
}

std::string WaterCreature::GetTypeName() const
{
	return "Water";
}

int WaterCreature::BaseDamage() const
{
	return 18;
}

void WaterCreature::Attack(Creature& target)
{
	target.RecieveAttackFrom(*this, BaseDamage());
}

void WaterCreature::RecieveAttackFrom(const FireCreature& attacker, int dmg)
{
	ApplyTypedDamage(attacker, dmg, 0.5f);
}

void WaterCreature::RecieveAttackFrom(const WaterCreature& attacker, int dmg)
{
	ApplyTypedDamage(attacker, dmg, 1.0f);
}

void WaterCreature::RecieveAttackFrom(const GrassCreature& attacker, int dmg)
{
	ApplyTypedDamage(attacker, dmg, 2.0f);
}
