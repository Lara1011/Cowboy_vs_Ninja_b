//
// Created by Lara Abu Hamad on 07/05/2023.
//

#include "Point.hpp"
#include <cmath>

namespace ariel{
Point::Point() : x(0.0), y(0.0){};

Point::Point(double num1, double num2) : x(num1), y(num2){};

double Point::distance(Point other) {
    return sqrt(pow(this->x - other.x, 2) + pow(this->y - other.y, 2));
}

 Point Point::moveTowards(Point source, Point destination, double distance) {
    if(distance < 0)
        throw invalid_argument("Distance is negative !");
     double currentDistance = source.distance(destination);
     if (currentDistance <= distance) {
         return destination;
     } else {
         double ratio = distance / currentDistance;
         double newX = source.getX() + ratio * (destination.getX() - source.getX());
         double newY = source.getY() + ratio * (destination.getY() - source.getY());
         return {newX, newY};
     }
}

    double Point::getX() {
        return this->x;
}

    double Point::getY() {
        return this->y;
}

void Point::print() {
    cout << "(" << this->x << "," << this->y << ")" << endl;
}
}