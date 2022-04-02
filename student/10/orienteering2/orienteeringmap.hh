/*
#############################################################################
# COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures          #
# Project3: Suunnistus / Orienteering                                       #
# File: orienteeringmap.hh                                                  #
# Description: Datastructure that represents an orienteering map and        #
#        handles information of points and routes                           #
# Notes: * This is a part of an exercise program.                           #
#        * Students aren't allowed to change the public interface!          #
#        * Modifying the private part is allowed (and required).            #
# Program author:                                                           #
#       Name: Vili Ikäheimo                                                 #
#       Student number: 150286761                                           #
#       UserID: csviik                                                      #
#       E-Mail: vili.ikaheimo@tuni.fi                                       #
#############################################################################
*/

#ifndef ORIENTEERINGMAP_HH
#define ORIENTEERINGMAP_HH

#include <string>
#include <map>
#include <vector>
#include "point.hh"
#include "route.hh"
#include "iostream"
#include "iomanip"

class OrienteeringMap
{
public:
    // Constructor and destructor
    OrienteeringMap();
    ~OrienteeringMap();

    // Sets the width and height for the map.
    void set_map_size(int width, int height);

    // Adds a new point in the map, with the given name, position (x and y
    // coordinates), height and marker.
    void add_point(std::string name, int x, int y, int height, char marker);

    // Connects two existing points such that the point 'to' will be
    // immediately after the point 'from' in the route 'route_name'.
    // The given route can be either a new or an existing one,
    // if it already exists, the connection between points will be
    // updated in the aforementioned way.
    // Returns true, if connection was successful, i.e. if both the points
    // exist, otherwise returns false.
    bool connect_route(std::string from,
                       std::string to,
                       std::string route_name);

    // Prints the map.
    void print_map() const;

    // Prints all routes' names, ordered alphabetically.
    void print_routes() const;

    // Prints all points' names and their markers on the map.
    void print_points() const;

    // Prints points belonging to the given route in the order they are
    // in the route.
    void print_route(const std::string& name) const;

    // Prints the given route's combined length,
    // the length is counted as a sum of the distances of adjacent points.
    void route_length(const std::string& name) const;

    // Finds and prints the highest rise in any of the routes after the given
    // point.
    void greatest_rise(const std::string& point_name) const;

private:

    // maps to store points and routes
    std::map<std::string, Point*> allPoints_;
    std::map<std::string, Route*> allRoutes_;

    int mapWidth;
    int mapHeight;

    // Method that return true if a route exists, if it doesn't
    // returns false.
    bool IsRoute(std::string route_name) const;

    // Method that return true if a point exists, if it doesn't
    // returns false.
    bool IsPoint(std::string point_name) const;

    // Method to find the highes rise after a given point. Returns
    // a vector with the names of the routes with the highest rise and
    // stores the highest rise in the parameter highest_rise.
    std::vector<std::string> getHighestRise(
            int& highest_rise, std::string point_name) const;

    // Takes x and y coordinates as parameters and checks if a
    // control point is at the given coordinates. Returns true if
    // there is and puts the marker to the point into marker parameter.
    // If there is no point in the coordinates, returns false.
    bool isPointCoord(int x, int y, char& marker) const ;


};

#endif // ORIENTEERINGMAP_HH
