#pragma once

#include <vector>
#include <map>
#include <string>

namespace coup
{
    enum Action
    {
        NONE,
        INCOME,
        FOREIGN_AID,
        COUP,
        TAX,
        ASSASSINATE,
        STEAL,
        TRANSFER
    };


    class Game
    {
    private:
        std::vector<std::string> _players;
        int _turn = -1;

    public:
        int addPlayer(std::string player);
        void deletePlayer(int index);
        void revivePlayer(std::string player);
        void endTurn();
        int getTurnIndex();
        std::vector<std::string> players() const;
        std::string turn();
        std::string winner() const;
    };

}
