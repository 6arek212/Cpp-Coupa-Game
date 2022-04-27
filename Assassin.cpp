#include "Assassin.hpp"
#include "iostream"

namespace coup
{
    std::string Assassin::role() const
    {
        return "Assassin";
    }

    void Assassin::coup(Player &player)
    {
        if (this == &player)
        {
            throw std::invalid_argument("Error , you cant coup your self");
        }
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
