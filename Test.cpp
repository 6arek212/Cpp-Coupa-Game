#include "doctest.h"

#include "Player.hpp"
#include "Game.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
using namespace coup;
#include <fstream>
#include <sstream>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

TEST_CASE("Good Game")
{
    Game game;

    Duke duke{game, "Tarik"};
    Assassin assassin{game, "Wissam"};
    Ambassador ambassador{game, "Gia"};
    Captain captain{game, "Arik"};
    Contessa contessa{game, "Lior"};

    vector<string> players = game.players();
    CHECK(players[0] == "Tarik");
    CHECK(players[1] == "Wissam");
    CHECK(players[2] == "Gia");
    CHECK(players[3] == "Arik");
    CHECK(players[4] == "Lior");

    /**
     * @brief
     *  duke 3
     *  assassin 2
     *  ambassador 1
     *  captain 1
     *  contessa 1
     */
    duke.tax();
    assassin.foreign_aid();
    ambassador.income();
    captain.income();
    contessa.income();

    /**
     * @brief
     *  duke 6
     *  assassin 4
     *  ambassador 2
     *  captain 2
     *  contessa 1
     */

    duke.tax();
    assassin.foreign_aid();
    ambassador.income();
    captain.income();
    contessa.foreign_aid();
    duke.block(contessa);

    /**
     * @brief
     *  duke 10
     *  assassin 1
     *  ambassador 0
     *  captain 4
     *
     */
    duke.tax();
    assassin.coup(contessa);
    ambassador.transfer(assassin, duke);
    captain.steal(ambassador);

    /**
     * @brief
     *  duke 0
     *  ambassador 2
     *  captain 6
     *
     */
    duke.coup(assassin);
    ambassador.foreign_aid();
    captain.foreign_aid();

    /**
     * @brief
     *  duke 3
     *  ambassador 4
     *  captain 8
     *
     */
    duke.tax();
    ambassador.foreign_aid();
    captain.foreign_aid();

    /**
     * @brief
     *  duke 6
     *  ambassador 6
     *  captain 10
     *
     */
    duke.tax();
    ambassador.foreign_aid();
    captain.foreign_aid();

    /**
     * @brief
     *  duke 9
     *  ambassador 8
     *  captain 10
     *
     */
    duke.tax();
    ambassador.foreign_aid();
    captain.coup(ambassador);

    /**
     * @brief
     *  duke 9
     *  captain 2
     *
     */
    duke.tax();
    captain.foreign_aid();

    /**
     * @brief
     *  duke 12
     *  captain 4
     *
     */
    duke.tax();
    captain.foreign_aid();

    /**
     * @brief
     *  
     *  duke won !!
     *
     */
    duke.coup(captain);



    cout << "And the winner is : " << game.winner() << endl;

}