#include "Game.hpp"
#include <iostream>
#include <algorithm>

namespace coup
{
    int Game::getTurnIndex()
    {
        return this->_turn;
    }

    int Game::addPlayer(std::string player)
    {
        _players.push_back(player);
        if (_turn == -1)
        {
            _turn = 0;
        }
        return _players.size() - 1;
    }

    void Game::deletePlayer(int index)
    {
        _players.erase(_players.begin() + index);
    }

    void Game::revivePlayer(std::string player)
    {
    }

    std::vector<std::string> Game::players() const
    {
        return this->_players;
    }

    std::string Game::turn()
    {
        if (this->_turn == -1)
        {
            throw "Error no players";
        }

        return _players[(size_t)_turn];
    }

    std::string Game::winner() const
    {
        if (_turn == -1)
        {
            throw "Error the game has not started";
        }

        if (_players.size() > 1)
        {
            throw "Error the game is still live";
        }

        return _players[0];
    }

    void Game::endTurn()
    {
        _turn = (_turn + 1) % (int)_players.size();
    }
}