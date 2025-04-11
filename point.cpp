//
// Created by rudri on 10/11/2020.
//

#include "point.h"

namespace geometry {
    point::point(double x_, double y_) : x(x_), y(y_) {}

    double point::get_x() const{return x;}
    double point::get_y() const{return y;}

    point point::operator+(const point &p) const{
        return point(x + p.x, y + p.y);
    }
    point point::operator-(const point &p) const{
        return point(x - p.x, y - p.y);
    }
    bool point::operator==(const point &p) const{
        return (x == p.x && y == p.y);
    }

    std::ostream& operator<<(std::ostream &os, const point &p) {
        os << "[" << p.x << ", " << p.y << "]";
        return os;
    }

    point::~point() = default;

            
}

