#include <string>
#include <vector>

namespace coup
{

    class Player
    {
    private:
        Game *game;
        string _name;
        int _coins;

    public:
        Player(Game &game, string name);
        void income();
        void foreign_aid();
        void coup();
        int coins();
        int role();

        friend std::ostream &operator<<(std::ostream &out, const Player &player);
    };

    class Game
    {
    private:
        std::vector<Player> _players;
        int turn = -1;

    public:
        void addPlayer(Player player);
        vector<Player> players();
    };

}
