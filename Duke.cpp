#include "Duke.hpp"
#include <iostream>
using namespace coup;

void Duke::tax()
{
    checkTurn();
    checkMustCoup();
    _coins += threeCoins;
    lastAction = ActionOp(TAX);
    game->endTurn(this);
}

std::string Duke::role() const
{
    return "Duke";
}

void Duke::block(Player &player)
{
    if (this == &player)
    {
        throw std::invalid_argument("Error , you cant block your self");
    }

    if (game->isItMyTurn(player))
    {
        throw std::invalid_argument("Cant block him !");
    }

    // blocks the forign aid action !
    if (player.getActionOp().action != FOREIGN_AID)
    {
        throw std::invalid_argument("Duke can only block a forign aid action !" + role() + " " + _name);
    }
    player.coins() -= 2;
    player.initAction();
}