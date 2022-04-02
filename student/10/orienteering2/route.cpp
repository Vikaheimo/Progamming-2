/*
#############################################################################
# COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures          #
# Project3: Suunnistus / Orienteering                                       #
# File: route.cpp                                                           #
# Description: Implementation for the class route                           #
# Notes:                                                                    #
# Program author:                                                           #
#       Name: Vili Ikäheimo                                                 #
#       Student number: 150286761                                           #
#       UserID: csviik                                                      #
#       E-Mail: vili.ikaheimo@tuni.fi                                       #
#############################################################################
*/
#include "route.hh"

#include "iostream"

Route::Route(std::string name):
name_(name) {

    // set lenght of the route to zero, so that the value can
    // still be used
    lengthOfRoute_ = 0;
}

void Route::addPoint(Point* from, Point* to)
{
    // check if the "from" point allready exists and add it
    // if it doesn't
    if(!IsPoint(from)){
        route_.push_back(from);
    }

    // add "to" point to the route
    route_.push_back(to);
}

std::vector<std::string> Route::getPoints() const
{
    std::vector<std::string> point_names;

    // loop through the route points
    for(auto& point : route_){

        // add each point name to the list
        std::string point_name = point->getName();
        point_names.push_back(point_name);
    }

    return point_names;
}

double Route::getLength()
{
    // check if the lenght of the route hasn't been calculated yet
    if (lengthOfRoute_ == 0){
        CalculateLenght();
    }

    return lengthOfRoute_;
}

int Route::GreatestRise(Point *control_point) const
{
    // return -1 if the point doesn't exist
    if (!IsPoint(control_point)){
        return -1;
    }

    int height_at_start = control_point->getHeight();
    int last_height = 0;
    bool is_found = false;

    for (auto& point : route_){
        int current_height = point->getHeight();

        // set flag true true if the point is found
        if (point == control_point){
           is_found = true;

        // if the point is not found skip over
        } else if (!is_found) {
            continue;

        // break out of the code if the height gets smaller
        } else if (current_height > last_height) {
            break;

        }

        // store last height value
        last_height = current_height;
    }
    return last_height - height_at_start;
}

void Route::CalculateLenght()
{
    std::vector<int> last_coords = route_.front()->getCoordinates();
    double length = 0;
    for(auto& point : route_){
        // get current coordinates and their x and y coordinates
        std::vector<int> current_coords = point->getCoordinates();
        int current_x = current_coords.front();
        int current_y = current_coords.back();

        // get the coordinates of the last point
        int last_x = last_coords.front();
        int last_y = last_coords.back();

        // get the distance between x coordinates and y coordinates
        int distance_x = pow((current_x - last_x), 2);
        int distance_y = pow((current_y - last_y), 2);

        // calculate distance and add it to the lenght
        length += std::sqrt((distance_x + distance_y));

        last_coords = current_coords;

    }
    // update route length
    lengthOfRoute_ = length;
}

bool Route::IsPoint(Point *control_point) const
{
    // loop through the route_ vector
    for(auto& point : route_){

        // check if the value is the same as the one we are
        // looking for
        if(control_point == point){
            return true;
        }
    }
    return false;
}
