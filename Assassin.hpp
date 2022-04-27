#include "Player.hpp"

namespace coup
{

    class Assassin : public Player
    {
    private:
    public:
        Assassin(Game &game, std::string name) : Player(game, name){};
        std::string role() override;
        void coup(Player &player) override;
    };

}