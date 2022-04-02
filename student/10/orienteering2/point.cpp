/*
#############################################################################
# COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures          #
# Project3: Suunnistus / Orienteering                                       #
# File: point.cpp                                                           #
# Description: Implementation of the point class                            #
# Notes:                                                                    #
# Program author:                                                           #
#       Name: Vili Ikäheimo                                                 #
#       Student number: 150286761                                           #
#       UserID: csviik                                                      #
#       E-Mail: vili.ikaheimo@tuni.fi                                       #
#############################################################################
*/
#include "point.hh"

Point::Point(std::string name, int height,
             int x_coord, int y_coord, char marker):
name_(name), height_(height), mapMarker_(marker){

    // add x-coordinate as the first element and
    // y-coordinate as the second element
    coordinates_.push_back(x_coord);
    coordinates_.push_back(y_coord);
}

std::string Point::getName()
{
    return name_;
}

int Point::getHeight()
{
    return height_;
}

char Point::getMarker()
{
    return mapMarker_;
}

std::vector<int> Point::getCoordinates()
{
    return coordinates_;
}
