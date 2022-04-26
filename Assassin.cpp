#include "Assassin.hpp"

namespace coup
{
    std::string Assassin::role()
    {
        return "Assassin";
    }

    void Assassin::assassinate(Player &player)
    {
        checkTurn();
        checkMustCoup();
        game->deletePlayer(player.playerIndex);
        player.setIsCouped(true);
        updateIndexs();
    }
}
