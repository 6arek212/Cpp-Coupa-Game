#include "Contessa.hpp"
#include <iostream>
namespace coup
{

    std::string Contessa::role()
    {
        return "Contessa";
    }

    void Contessa::block(Player &player)
    {
        if (player.getActionOp().action != ASSASSINATE)
        {
            throw std::invalid_argument("Contessa can only block Assassiantion !" + role() + " " + _name);
        }

        game->uncoup(player.getActionOp().p1);
        player.initAction();
    }
}