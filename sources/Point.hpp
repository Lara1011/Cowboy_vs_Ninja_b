//
// Created by Lara Abu Hamad on 07/05/2023.
//

#ifndef CPP_HW4_POINT_H
#define CPP_HW4_POINT_H
#include <iostream>
using namespace std;

namespace ariel{
class Point {
private:
    double x;
    double y;

public:
    Point();
    Point(double num1, double num2);
    double distance(Point other);
    static Point moveTowards(Point source, Point destination, double distance);
    double getX();
    double getY();
    void print();
};
}


#endif //CPP_HW4_POINT_H
