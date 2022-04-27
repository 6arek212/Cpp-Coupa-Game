#pragma once

#include <vector>
#include <string>
#include <algorithm>

namespace coup
{
    class Player;

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

    class ActionOp
    {
    public:
        Action action;
        Player *p1;
    
        ActionOp(Action action = NONE, Player *p1 = NULL)
        {
            this->action = action;
            this->p1 = p1;
        }
    };


    class Game
    {
    private:
        std::vector<Player *> _players;
        int _turn = -1;

    public:
        void addPlayer(Player &player);
        bool isItMyTurn(Player &player);
        void endTurn(Player *p);
        void couped(Player *p2);
        void uncoup(Player *p2);
        void hasPlayers() const;

        std::vector<std::string> players() const;
        std::string turn();
        std::string winner() const;
    };

}
