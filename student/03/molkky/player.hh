#ifndef PLAYER_HH
#define PLAYER_HH
#include <string>

class Player
{
public:
    Player(std::string);

    std::string get_name();

    void add_points(int number_of_points);

    bool has_won();

    int get_points();
private:
    int points_amount_;
    std::string player_name_;

};

#endif // PLAYER_HH
