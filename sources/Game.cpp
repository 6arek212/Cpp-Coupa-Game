#include "Game.hpp"
#include <iostream>
#include <algorithm>
#include "Player.hpp"
#include <iostream>
namespace coup
{

    void Game::hasPlayers() const
    {
        if (_players.empty())
        {
            throw "Error no players !";
        }
    }

    bool compareFun(Player *p1, Player *p2)
    {
        return p1->getPlayerIndex() < p2->getPlayerIndex();
    }

    /**
     * @brief remove the p2 player from the current game
     *
     * @param p2 Player to remove
     */
    void Game::couped(Player *p2)
    {
        Player *temp = _players[(size_t)_turn];

        _players.erase(std::remove(_players.begin(), _players.end(), p2), _players.end());
        if (temp != _players[(size_t)_turn] || _turn >= _players.size())
        {
            _turn--;
        }
    }

    /**
     * @brief re-join this p2 player to the game
     *
     * @param p2 Player
     */
    void Game::uncoup(Player *p2)
    {
        Player *temp = _players[(size_t)_turn];

        _players.push_back(p2);
        std::sort(_players.begin(), _players.end(), compareFun);

        if (temp != _players[(size_t)_turn])
        {
            _turn = (++_turn) % (int)_players.size();
        }
        p2->setCouped(false);
    }

    /**
     * @brief addes a new player to the list of players
     * @param player
     */
    void Game::addPlayer(Player &player)
    {
        if (_players.size() == MAX_PLAYER_COUNT)
        {
            throw std::invalid_argument("Error we have max players capacity");
        }

        if (this->hasStarted)
        {
            throw std::invalid_argument("Cant add playes, the game already started !");
        }

        if (_turn == -1)
        {
            _turn = 0;
        }
        _players.push_back(&player);
        player.setPlayerIndex((int)(_players.size() - 1));
    }

    /**
     * @brief check if its this players turn
     *
     * @param player
     * @return true this player turn
     * @return false its not his turn
     */
    bool Game::isItMyTurn(Player &player)
    {
        hasPlayers();
        return _players[(size_t)_turn] == &player;
    }

    /**
     * @brief move the turn to the next player
     *
     * @param p
     */
    void Game::endTurn(Player *p)
    {
        if (!hasStarted && _players.size() <= 1)
        {
            throw std::invalid_argument("No enough players");
        }
        p->checkTurn();
        hasPlayers();
        _turn = (_turn + 1) % (int)_players.size();

        if (!hasStarted)
        {
            hasStarted = true;
        }
    }

    /**
     * @return std::vector<std::string> list of players names
     */
    std::vector<std::string> Game::players() const
    {
        std::vector<std::string> p;
        for (Player *player : _players)
        {
            p.push_back(player->getName());
        }
        return p;
    }

    /**
     * @brief return the current players name
     *
     * @return std::string
     */
    std::string Game::turn()
    {
        hasPlayers();
        return _players[(size_t)_turn]->getName();
    }

    /**
     * @brief return the winner name if the game is finished otherwise it will throw an exception
     *
     * @return std::string the winners name
     */
    std::string Game::winner() const
    {
        if (!this->hasStarted)
        {
            throw std::invalid_argument("The game not started yet");
        }
        hasPlayers();
        if (_players.size() > 1)
        {
            throw "Error the game is still alive";
        }
        return _players[0]->getName();
    }
}