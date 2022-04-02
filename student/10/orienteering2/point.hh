/*
#############################################################################
# COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures          #
# Project3: Suunnistus / Orienteering                                       #
# File: point.hh                                                            #
# Description: Datastructure that represents a control point in a route     #
# Notes:                                                                    #
# Program author:                                                           #
#       Name: Vili Ikäheimo                                                 #
#       Student number: 150286761                                           #
#       UserID: csviik                                                      #
#       E-Mail: vili.ikaheimo@tuni.fi                                       #
#############################################################################
*/
#ifndef POINT_HH
#define POINT_HH

#include "string"
#include "vector"

class Point
{
public:
    // constructor
    Point(std::string name, int height,
          int x_coord, int y_coord, char marker);

    // a method that returns the name of the point
    std::string getName();

    // a method that returns the height of the point
    int getHeight();

    // a method that returns the marker used on the map
    char getMarker();

    // a method that returns the coordinates of the point
    std::vector<int> getCoordinates();



private:
    std::string name_;
    int height_;

    // first element in the map is the x-coordinate and the
    // second element the y-coordinate
    std::vector<int> coordinates_;

    char mapMarker_;
};

#endif // POINT_HH
