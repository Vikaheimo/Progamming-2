#include "orienteeringmap.hh"

OrienteeringMap::OrienteeringMap()
{

}

OrienteeringMap::~OrienteeringMap()
{
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
    // if there is no route called route_name
    if (!IsRoute(route_name)){

        // makes a new route and stores it in the all routes map
        Route* new_route = new Route(route_name);
        allRoutes_.insert(std::make_pair(route_name, new_route));
    }
    // tries to add a new point to the given route and stores the
    // return value
    bool value = allRoutes_.at(route_name)->addPoint(allPoints_.at(to));

    return value;
}

void OrienteeringMap::print_map() const
{

}

void OrienteeringMap::print_routes() const
{

}

void OrienteeringMap::print_points() const
{

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

    for (std::string& point : values_to_print){

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

    std::cout << "Route " << name << " lenght was " << length <<std::endl;

}

void OrienteeringMap::greatest_rise(const std::string &point_name) const
{

}

bool OrienteeringMap::IsRoute(std::string route_name) const
{
    for (auto& route : allRoutes_){
        if (route.first == route_name){
            return true;
        }
    }
    return false;
}
