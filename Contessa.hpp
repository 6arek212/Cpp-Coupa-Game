#include "Player.hpp"
#include <string>

namespace coup
{

    class Contessa : public Player
    {
    private:
    public:
        Contessa(Game &game, std::string name) : Player(game, name){};
        std::string role() override;
        void block(const Player &player);
    };

}
