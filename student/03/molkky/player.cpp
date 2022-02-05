#include "player.hh"
#include <string>
#include "iostream"
Player::Player(std::string name):
    player_name_(name){
    points_amount_ = 0;

}

std::string Player::get_name()
{
    return player_name_;
}

void Player::add_points(int number_of_points)
{
    points_amount_ += number_of_points;
    if (points_amount_ > 50){
        points_amount_ = 25;
        std::cout << get_name() <<" gets penalty points!" << std::endl;
    }
}

bool Player::has_won()
{
    return points_amount_ == 50;
}

int Player::get_points()
{
    return points_amount_;
}
