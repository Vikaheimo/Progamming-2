/*
 * COMP.CS.110 Ohjelmointi 2: Rakenteet / Programming 2: Structures
 * Project3: Suunnistus / Orienteering
 * File: main.cpp
 *
 * Description:
 *
 * The program is intended for processing navigation routes and its data.
 * First, the program asks the user for the file name from which to save
 * the navigation path information. The file must be in the following format:
 *
 *
 * All numeric values, ie the size of the map, the position of the control
 * points and the height of the control points are positive integrs
 *
 * First line of the file has the size of the map, ie the lenght and the
 * width of the map
 *
 * After the first line, the file should have the control points for the map.
 * Each control point will be on its own line and in the form:
 * name;x-coordinate;y-coordinate;terrain height
 * ;marker of the point (singe character)
 *
 * Control points implementation stops when the input file has a line ROUTES,
 * after which the implementation for the map routes begins
 *
 *
 * Routes are defined by giving the names of the control points that are on
 * the route in order. For example:
 *      control point 1;control point 2; control point 3;
 *
 * Routes and control points may consist of several words
 *
 * If there are no problems with the input file, the command section will
 * start in which you can enter the following commands to look trough the
 * data:
 *
 *
 *      QUIT           : Exits the progam
 *
 *      MAP            : Prints the map
 *
 *      ROUTES         : Prints all routes in alphabetical order
 *
 *      ROUTE <route>  : Prints all the command points in a given route
 *
 *      POINTS         : Prints all the command points
 *
 *      LENGHT <route> : Prints the lenght of a given route
 *
 *      RISE <point>   : Prints the longest rise after a given point
 *                     in all routes
 *
 *
 *
 * Progmam author:
 *      Name: Vili Ikäheimo
 *      Student number: 150286761
 *      UserID: csviik
 *      E-Mail: vili.ikaheimo@tuni.fi
 *
 * Notes about the progam and it's implementation:
 *      Has two classes called Point and Route
*/

#include "orienteeringmap.hh"
#include "parser.hh"
#include "cli.hh"
#include <iostream>

int main()
{
    std::shared_ptr<OrienteeringMap> routes(new OrienteeringMap);
    std::cout << "Input> ";
    std::string input;
    getline(std::cin, input);
    if( not read_input_from_file(input, routes) )
    {
        return EXIT_FAILURE;
    }
    Cli cli(routes);
    while( cli.exec_prompt() ){ }
    return EXIT_SUCCESS;
}


