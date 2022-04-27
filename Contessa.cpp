#include "Contessa.hpp"
#include <iostream>
namespace coup
{

    std::string Contessa::role() const
    {
        return "Contessa";
    }

    void Contessa::block(Player &player)
    {
        if (this == &player)
        {
            throw std::invalid_argument("Error , you cant block your self");
        }
        if (player.getActionOp().action != ASSASSINATE)
        {
            throw std::invalid_argument("Contessa can only block Assassiantion !" + role() + " " + _name);
        }

        game->uncoup(player.getActionOp().p1);
        player.initAction();
    }
}