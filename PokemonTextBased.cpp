#include "Battle.h"
#include "FireCreature.h"
#include "WaterCreature.h"
#include "GrassCreature.h"

#include <memory>

int main()
{
	Party player("Player");

	player.Add(std::make_unique<WaterCreature>("Aqualis"));
	player.Add(std::make_unique<FireCreature>("Pyron"));
	player.Add(std::make_unique<GrassCreature>("Leafor"));

	Party enemy("Enemy");

	enemy.Add(std::make_unique<GrassCreature>("Bramble"));
	enemy.Add(std::make_unique<WaterCreature>("Torrent"));
	enemy.Add(std::make_unique<FireCreature>("Cinder"));

	Battle battle(std::move(player), std::move(enemy));
	battle.Run();

	return 0;
}