/*
#############################################################################
# COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures          #
# Project3: Suunnistus / Orienteering                                       #
# File: orienteeringmap.cpp                                                 #
# Description: Implementation for the class Orienteeringmap                 #
# Program author:                                                           #
#       Name: Vili Ikäheimo                                                 #
#       Student number: 150286761                                           #
#       UserID: csviik                                                      #
#       E-Mail: vili.ikaheimo@tuni.fi                                       #
#############################################################################
*/
#include "orienteeringmap.hh"

OrienteeringMap::OrienteeringMap()
{

}

OrienteeringMap::~OrienteeringMap()
{
    // loop trough the maps with points and routes
    // and delete all the values
    for (auto& route : allRoutes_){
        delete route.second;

    }
    for (auto& point : allPoints_){
        delete point.second;

    }
}

void OrienteeringMap::set_map_size(int width, int height)
{
    mapHeight = height;
    mapWidth = width;
}

void OrienteeringMap::add_point(std::string name, int x, int y,
                                int height, char marker)
{
    // makes a new point and stores the pointer to it in the
    // all points map
    Point* new_point = new Point(name, height, x, y, marker);
    allPoints_.insert(std::make_pair(name, new_point));
}

bool OrienteeringMap::connect_route(std::string from,
                                    std::string to, std::string route_name)
{
    // check if both points exist
    if (!IsPoint(from) or !IsPoint(to)){
        return false;

    // if there is no route called route_name
    }else if (!IsRoute(route_name)){

        // makes a new route and stores it in the all routes map
        Route* new_route = new Route(route_name);
        allRoutes_.insert(std::make_pair(route_name, new_route));
    }

    // adds the points to the route
    allRoutes_.at(route_name)->
            addPoint(allPoints_.at(from), allPoints_.at(to));

    return true;
}

void OrienteeringMap::print_map() const
{
    const int width_for_column_num = 3;
    const int width_for_row_num = 2;

    // print one extra space at the beginning
    std::cout << " ";

    int column_num = 1;

    // while loop for the first print row
    while (column_num <= mapWidth){

        // get the lenght of the current number
        int current_num_length = std::to_string(column_num).length();

        // print the right amount of spaces and the column number after them
        std::cout << std::string((width_for_column_num - current_num_length), ' ')
                  << column_num;

        column_num += 1;
    }
    // reset column number and row number
    column_num = 1;
    int row_num = 1;

    std::cout << std::endl;

    while (row_num<= mapHeight){
        // get the lenght of the current row number
        int current_num_length = std::to_string(row_num).length();

        // print the right amount of spaces and the row number after them
        std::cout << std::string((width_for_row_num - current_num_length), ' ')
                  << row_num;

        while (column_num <= mapWidth){

            // add two spaces before every print
            std::cout << "  ";

            char marker;

            //check if the current coordinates have a point
            if (isPointCoord(column_num, row_num, marker)){
                std::cout << marker;

            // print . if no points are in the current coordinates
            } else{
                std::cout << ".";
            }

            column_num += 1;
        }
        std::cout << std::endl;

        // add one to row num and reset column
        column_num = 1;
        row_num += 1;
    }
}

void OrienteeringMap::print_routes() const
{
    std::cout << "Routes:" << std::endl;

    // loop trough routes map and print all the values on their
    // own rows
    for (const auto& route : allRoutes_){
        std::cout << " - " << route.first << std::endl;
    }
}

void OrienteeringMap::print_points() const
{
    std::cout << "Points:" << std::endl;

    // loop trough points map and print all the values on their
    // own rows
    for (const auto& point : allPoints_){
        std::cout << " - " << point.first << " : "
                  << point.second->getMarker()<<std::endl;
    }
}

void OrienteeringMap::print_route(const std::string &name) const
{
    // check if the route doesn't exist
    if (!IsRoute(name)){
        std::cout << "Error: Route named "<< name <<" can't be found"
                  << std::endl;
        return;
    }
    std::vector<std::string> values_to_print =
            allRoutes_.at(name)->getPoints();

    for (const std::string& point : values_to_print){

        // if the point isnt the first one add -> to the print
        if (point != values_to_print.front()){
            std::cout << " -> ";
        }
        std::cout << point << std::endl;
    }
}

void OrienteeringMap::route_length(const std::string &name) const
{
    // check if the route doesn't exist
    if (!IsRoute(name)){
        std::cout << "Error: Route named "<< name <<" can't be found"
                  << std::endl;
        return;
    }

    double length = allRoutes_.at(name)->getLength();

    std::cout<< std::setprecision(2)
             << "Route " << name << " lenght was " << length <<std::endl;

}

void OrienteeringMap::greatest_rise(const std::string &point_name) const
{
    const int no_rise = 0;
    // check if the point doesn't exist
    if (!IsPoint(point_name)){
        std::cout << "Error: Route named "<< point_name <<" can't be found"
                  << std::endl;
        return;
    }

    // gets the highest rise
    int highest_rise = 0;
    std::vector<std::string> routes_with_highest_rise =
            getHighestRise(highest_rise, point_name);

    if(highest_rise == no_rise){
        std::cout<< "No route rises after point " << point_name << std::endl;
        return;
    }

    std::cout << "Greatest rise after point "
              << point_name << ", "
              << highest_rise <<" meters, is on route(s):"
              << std::endl;

    // loop trough the routes and print them line by line
    for (const auto& route : routes_with_highest_rise){
        std::cout << " - " << route << std::endl;
    }

}

bool OrienteeringMap::IsRoute(std::string route_name) const
{
    for (const auto& route : allRoutes_){
        if (route.first == route_name){
            return true;
        }
    }
    return false;
}

bool OrienteeringMap::IsPoint(std::string point_name) const
{

    for (const auto& point : allPoints_){

        if (point.first == point_name){
            return true;
        }
    }
    return false;
}

std::vector<std::string> OrienteeringMap::getHighestRise(
        int &highest_rise, std::string point_name) const
{
    // a vector to save the routes with the highest rise
    std::vector<std::string> routes_with_the_same_rise;

    // save pointer to the control point
    Point* pointer_to_point = allPoints_.at(point_name);

    for (const auto& route : allRoutes_){
        int current_rise = route.second->GreatestRise(pointer_to_point);

        // check if the current route has a higher rise
        if (current_rise> highest_rise){

            //empty the vector
            routes_with_the_same_rise.clear();

            // add the new route the to the vector and store the
            // highest rise
            routes_with_the_same_rise.push_back(route.first);
            highest_rise = current_rise;

        } else if (current_rise == highest_rise){

            // if some routes have the same highest rise, add them to the
            // vector
            routes_with_the_same_rise.push_back(route.first);
        }
    }
    return routes_with_the_same_rise;
}

bool OrienteeringMap::isPointCoord(int x, int y, char& marker) const
{
    for(const auto& point: allPoints_){
        // store command point x and y coordinates
        int point_x = point.second->getCoordinates().front();
        int point_y = point.second->getCoordinates().back();


        if (point_x == x and point_y == y){

            // set points marker to marker
            marker = point.second->getMarker();
            return true;
        }
    }
    return false;
}
