#include "Ambassador.hpp"
#include <iostream>
namespace coup
{
    std::string Ambassador::role() const
    {
        return "Ambassador";
    }

    /**
     * @brief transfer one coin from player1 to player2
     *
     * @param player1
     * @param player2
     */
    void Ambassador::transfer(Player &player1, Player &player2)
    {
        if (!hasSameGame(player1) || !hasSameGame(player2))
        {
            throw std::invalid_argument("These players are not in the same game !");
        }

        checkTurn();
        checkMustCoup();
        if (player1.coins() == 0)
        {
            throw std::invalid_argument("Error cant transfer coins from this player ! " + role() + " " + _name);
        }
        player1.coins()--;
        player2.coins()++;
        lastAction = ActionOp(TRANSFER, &player1, &player2);
        game->endTurn(this);
    }

    /**
     * @brief block a stealing player
     *
     * @param player
     */
    void Ambassador::block(Player &player)
    {
        if (!hasSameGame(player))
        {
            throw std::invalid_argument("These players are not in the same game !");
        }

        if (this == &player)
        {
            throw std::invalid_argument("Error , you cant block your self");
        }
        if (game->isItMyTurn(player))
        {
            throw std::invalid_argument("Cant block him !");
        }
        if (player.getActionOp().action != STEAL)
        {
            throw std::invalid_argument("Error Ambassador can only block Steal " + role() + " " + _name);
        }

        player.getActionOp().p1->coins() += player.getActionOp().coins;
        player.coins() -= player.getActionOp().coins;
        player.initAction();
    }

}
