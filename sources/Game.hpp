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
        Player *p2;
        int coins;

        ActionOp(Action action = NONE, Player *p1 = NULL, Player *p2 = NULL, int coins = 0)
        {
            this->action = action;
            this->p1 = p1;
            this->p2 = p2;
            this->coins = coins;
        }
    };

    class Game
    {
    private:
        static const int MAX_PLAYER_COUNT = 6;
        std::vector<Player *> _players;
        int _turn = -1;
        bool hasStarted = false;

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
