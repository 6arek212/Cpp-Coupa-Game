#include "Player.hpp"
#include <string>
#include <iostream>

using namespace std;

namespace coup
{
    std::ostream &operator<<(std::ostream &out, const Player &player)
    {
        out << "Player: name: " << player._name << " "
            << "coins : " << player._coins << std::endl;
        return out;
    }

    Player::Player(Game &game, std::string &name)
    {
        this->_coins = 0;
        this->_name = name;
        this->game = &game;
        this->playerIndex = -1;
        this->game->addPlayer(*this);
    }

    void Player::checkTurn()
    {

        if (!game->isItMyTurn(*this))
        {
            throw invalid_argument("Error its not your turn " + role() + " " + _name);
        }
    }

    void Player::checkMustCoup()
    {
        if (this->_coins >= tenCoins)
        {
            throw invalid_argument("You have more than 10 coins you must coup ! " + role());
        }
    }

    void Player::income()
    {
        checkTurn();
        checkMustCoup();
        this->_coins++;
        lastAction = ActionOp(INCOME);
        game->endTurn(this);
    }

    void Player::foreign_aid()
    {
        checkTurn();
        checkMustCoup();
        this->_coins += 2;
        lastAction = ActionOp(FOREIGN_AID);
        game->endTurn(this);
    }

    void Player::coup(Player &player)
    {
        checkTurn();
        if (_coins < sevenCoins)
        {
            throw invalid_argument("Error cant coup , you need at least 7 coins ! " + role() + " " + _name);
        }
        _coins -= sevenCoins;
        lastAction = ActionOp(COUP, &player);
        game->endTurn(this);
    }

    int &Player::coins()
    {
        return _coins;
    }

    const ActionOp &Player::getActionOp() const
    {
        return lastAction;
    }

    void Player::initAction()
    {
        this->lastAction = ActionOp();
    }

}