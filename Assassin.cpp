#include "Assassin.hpp"
#include "iostream"

namespace coup
{
    std::string Assassin::role() const
    {
        return "Assassin";
    }

    /**
     * @brief coup a player with 3 coins only !
     *
     * @param player
     */
    void Assassin::coup(Player &player)
    {
        if (!hasSameGame(player))
        {
            throw std::invalid_argument("These players are not in the same game !");
        }
        
        if (this == &player)
        {
            throw std::invalid_argument("Error , you cant coup your self");
        }
        checkTurn();
        if (coins() < threeCoins)
        {
            throw std::invalid_argument("Error Assassin can coup with 3 coins " + _name);
        }

        if (coins() >= sevenCoins)
        {
            coins() -= sevenCoins;
            lastAction = ActionOp(COUP, &player);
        }
        else
        {
            coins() -= threeCoins;
            lastAction = ActionOp(ASSASSINATE, &player);
        }

        game->couped(&player);
        game->endTurn(this);
    }
}
