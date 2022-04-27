#include "Duke.hpp"
#include <iostream>
using namespace coup;

void Duke::tax()
{
    checkTurn();
    _coins += 3;
    game->endTurn(this);
}

std::string Duke::role()
{
    return "Duke";
}

void Duke::block(Player &player)
{
    // blocks the forign aid action !
    if (player.getActionOp().action != FOREIGN_AID)
    {
        throw std::invalid_argument("Duke can only block a forign aid action !" + role() + " " + _name);
    }
    player.coins() -= 2;
    player.initAction();
}