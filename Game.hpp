#pragma once

#include <vector>
#include <map>

namespace coup
{
    enum Action
    {
        INCOME,
        FOREIGN_AID,
        COUP,
        TAX,
        ASSASSINATE,
        STEAL,
        EXCHANGE
    };

    class Game
    {
    private:
        std::vector<std::string> _players;
        int _turn = -1;

    public:
        void deletePlayer(std::string player);
        void addPlayer(std::string player);
        void endTurn();
        std::vector<std::string> players() const;
        std::string turn();
        std::string winner() const;
    };

}
