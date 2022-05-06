#include "Contessa.hpp"
#include <iostream>
namespace coup
{

    std::string Contessa::role() const
    {
        return "Contessa";
    }

    /**
     * @brief contessa can block an assassin , meaning the assassinated played will return to the game
     *
     * @param player
     */
    void Contessa::block(Player &player)
    {
        isCoupedCheck(player);
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

        if (player.getActionOp().action != ASSASSINATE)
        {
            throw std::invalid_argument("Contessa can only block Assassiantion !" + role() + " " + _name);
        }

        game->uncoup(player.getActionOp().p1);
        player.initAction();
    }
}