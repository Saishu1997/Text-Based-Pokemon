#pragma once
#include <string>

class FireCreature;
class WaterCreature;
class GrassCreature;


class Creature
{
public:
	Creature(std::string name, int hp);
	virtual ~Creature();

	virtual void Attack(Creature& target) = 0;
	virtual int BaseDamage() const = 0;
	virtual std::string GetTypeName() const = 0;

	virtual void RecieveAttackFrom(const FireCreature& attacker, int baseDamage) = 0;
	virtual void RecieveAttackFrom(const WaterCreature& attacker, int baseDamage) = 0;
	virtual void RecieveAttackFrom(const GrassCreature& attacker, int baseDamage) = 0;

	void TakeDamage(int dmg);
	bool IsAlive() const;
	
	int GetHP() const;
	const std::string& GetName() const;

protected:
	void ApplyTypedDamage(const Creature& attacker, int baseDamage, float multiplier);

protected:
	std::string m_name;
	int m_hp;
};

