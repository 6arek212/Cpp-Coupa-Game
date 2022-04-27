#include "Player.hpp"
#include <string>
#include <iostream>

using namespace std;

namespace coup
{
    std::ostream &operator<<(std::ostream &out, const Player &player)
    {
        out << "Player: name: " << player._name << ", "
            << "coins : " << player._coins << ", "
            << "role : " << player.role() << std::endl;
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

    /**
     * @brief check if it your turn to play
     * 
     */
    void Player::checkTurn()
    {

        if (!game->isItMyTurn(*this))
        {
            throw invalid_argument("Error its not your turn " + role() + " " + _name);
        }
    }

    /**
     * @brief checks wheither you must coup or not
     * 
     */
    void Player::checkMustCoup()
    {
        if (this->_coins >= tenCoins)
        {
            throw invalid_argument("You have more than 10 coins you must coup ! " + role());
        }
    }

    /**
     * @brief addes one coin to this player
     * 
     */
    void Player::income()
    {
        checkTurn();
        checkMustCoup();
        this->_coins++;
        lastAction = ActionOp(INCOME);
        game->endTurn(this);
    }

    /**
     * @brief addes two coins to this player , this action can be blocked by a duke
     * 
     */
    void Player::foreign_aid()
    {
        checkTurn();
        checkMustCoup();
        this->_coins += 2;
        lastAction = ActionOp(FOREIGN_AID);
        game->endTurn(this);
    }


    /**
     * @brief coup another player , this action needs 7 coins to perform 
     * 
     * @param player 
     */
    void Player::coup(Player &player)
    {
        if (this == &player)
        {
            throw std::invalid_argument("Error , you cant coup your self");
        }
        checkTurn();
        if (_coins < sevenCoins)
        {
            throw invalid_argument("Error cant coup , you need at least 7 coins ! " + role() + " " + _name);
        }
        game->couped(&player);
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