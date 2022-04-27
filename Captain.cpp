#include "Captain.hpp"
#include <iostream>
namespace coup
{
    std::string Captain::role()
    {
        return "Captin";
    }

    void Captain::steal(Player &player)
    {
        checkTurn();
        checkMustCoup();
        player.coins() -= 2;
        coins() += 2;
        lastAction = ActionOp(STEAL, &player);
        game->endTurn(this);
    }

    void Captain::block(Player &player)
    {
        if (player.getActionOp().action != STEAL)
        {
            throw std::invalid_argument("Error captain can only block Steal !" + role() + " " + _name);
        }

        player.getActionOp().p1->coins() += 2;
        player.coins() -= 2;
        player.initAction();
    }
}