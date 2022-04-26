#include "Duke.hpp"
using namespace coup;

void Duke::tax()
{
    checkTurn();
    _coins += 3;
    game->endTurn();
}

std::string Duke::role()
{
    return "Duke";
}

void Duke::block(const Player &player)
{
    // blocks the forign aid action !
}