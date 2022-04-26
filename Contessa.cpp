#include "Contessa.hpp"
#include <iostream>
using namespace coup;

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
            throw "Contessa can only block Assassiantion";
        }

        game->addPlayer(players[player.getActionOp().on1->playerIndex]._name);
        player.getActionOp().on1->setIsCouped(false);
        updateIndexs();
        player.lastAction = ActionOp();
    }
}