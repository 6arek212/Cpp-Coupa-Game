#include "Ambassador.hpp"

namespace coup
{
    std::string Ambassador::role()
    {
        return "Ambassador";
    }

    void Ambassador::transfer(Player &player1, Player &player2)
    {
        checkTurn();
        checkMustCoup();
        if (player1.coins() == 0)
        {
            throw "Error cant transfer coins from this player !";
        }
        player1.coins()--;
        player2.coins()++;
        game->endTurn();
    }

    void Ambassador::block(Player &player)
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
