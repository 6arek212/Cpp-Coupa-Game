#include "Player.hpp"

namespace coup
{

    class Ambassador : public Player
    {
    private:
    public:
        Ambassador(Game &game, std::string name) : Player(game, name){};
        void transfer(Player &player1, Player &player2);
        std::string role() override;
        void block(Player &player);
    };

}
