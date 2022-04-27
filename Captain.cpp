#include "Captain.hpp"
#include <iostream>
namespace coup
{
    std::string Captain::role() const
    {
        return "Captin";
    }

    void Captain::steal(Player &player)
    {
        if (this == &player)
        {
            throw std::invalid_argument("Error , you cant steal your self");
        }
        checkTurn();
        checkMustCoup();
        if (player.coins() < 2)
        {
            throw std::invalid_argument("Error , can't steal from this player !");
        }

        player.coins() -= 2;
        coins() += 2;
        lastAction = ActionOp(STEAL, &player);
        game->endTurn(this);
    }

    void Captain::block(Player &player)
    {
        if (this == &player)
        {
            throw std::invalid_argument("Error , you cant block your self");
        }
        if (player.getActionOp().action != STEAL)
        {
            throw std::invalid_argument("Error captain can only block Steal !" + role() + " " + _name);
        }

        player.getActionOp().p1->coins() += 2;
        player.coins() -= 2;
        player.initAction();
    }
}