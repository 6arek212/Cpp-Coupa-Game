#include "Duke.hpp"
using namespace coup;

void Duke::tax()
{
    checkTurn();
    checkMustCoup();
    _coins += 3;
    lastAction = ActionOp(TAX);
    game->endTurn();
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
        throw "Duke can only block a forign aid action !";
    }
    player.coins() -= 2;
    player.lastAction = ActionOp();
    game->endTurn();
}