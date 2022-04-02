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
    Point* new_point = new Point(name, height, x, y, marker);
    allPoints_.insert(std::make_pair(name, new_point));
}

bool OrienteeringMap::connect_route(std::string from,
                                    std::string to, std::string route_name)
{
    if (!IsRoute(route_name)){
        Route* new_route = new Route(route_name);
        allRoutes_.insert(std::make_pair(route_name, new_route));
    }
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

}

void OrienteeringMap::route_length(const std::string &name) const
{

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
