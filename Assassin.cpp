#include "Assassin.hpp"
#include "iostream"

namespace coup
{
    std::string Assassin::role()
    {
        return "Assassin";
    }

    void Assassin::coup(Player &player)
    {
        checkTurn();
        if (coins() < threeCoins)
        {
            throw std::invalid_argument("Error Assassin can coup with 3 coins " + _name);
        }
        game->couped(&player);
        coins() -= 3;
        lastAction = ActionOp(ASSASSINATE, &player);
        game->endTurn(this);
    }
}
