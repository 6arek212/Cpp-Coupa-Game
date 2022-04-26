#include "Captain.hpp"

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
        game->endTurn();
    }

    void Captain::block(Player &player)
    {
        if (player.getActionOp().action != STEAL)
        {
            throw "Error captain can only block Steal";
        }

        player.getActionOp().on1->coins() -= 2;
        player.getActionOp().on2->coins() += 2;
        player.lastAction = ActionOp();
    }
}