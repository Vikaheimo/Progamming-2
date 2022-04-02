/*
#############################################################################
# COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures          #
# Project3: Suunnistus / Orienteering                                       #
# File: route.hh                                                            #
# Description: Datastructure that represents a route and handles            #
# route information                                                         #
# Notes:                                                                    #
# Program author:                                                           #
#       Name: Vili Ikäheimo                                                 #
#       Student number: 150286761                                           #
#       UserID: csviik                                                      #
#       E-Mail: vili.ikaheimo@tuni.fi                                       #
#############################################################################
*/
#ifndef ROUTE_HH
#define ROUTE_HH

#include "vector"
#include "string"
#include "point.hh"
#include "cmath"

class Route
{
public:
    // constructor
    Route(std::string name);

    // method that adds a control point to the end of the route
    // returns true if it was succesfull otherwise false
    void addPoint(Point* from,Point* to);

    // a method that returns the names of the control points in a route
    std::vector<std::string> getPoints() const;

    // a method that returns the lenght of the route
    double getLength();

    // a method that returns the highest rise from a given point
    // if the point doesnt exist, returns -1 and if there is no rise
    // after a given point return 0.
    int GreatestRise(Point* control_point) const;



private:
    // add a vector that has all the command points that are in the route
    std::vector<Point*> route_;

    std::string name_;
    double lengthOfRoute_;

    // calculates the length of the route
    void CalculateLenght();

    // method that returns true if a point is in the route
    // otherwise returns false
    bool IsPoint(Point* control_point) const;
};

#endif // ROUTE_HH
