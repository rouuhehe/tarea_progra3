//
// Created by rudri on 10/11/2020.
//
#include "vector_3d.h"

namespace geometry{
    vector_3d::vector_3d(double x_, double y_, double z_) : x(x_), y(y_), z(z_){}
    vector_3d::vector_3d() : x(0), y(0), z(0){}

    double vector_3d::get_x() const { return x;}
    double vector_3d::get_y() const { return y;}
    double vector_3d::get_z() const { return z;}

    vector_3d vector_3d::operator+(const vector_3d &v) const{
        return vector_3d(x + v.x, y + v.y, z + v.z);
    }
    vector_3d vector_3d::operator-(const vector_3d &v) const{
        return vector_3d(x - v.x, y - v.y, z - v.z);
    }

    vector_3d &vector_3d::operator=(const vector_3d &v) = default;
    
    
    double dot_product(const vector_3d &v1, const vector_3d &v2){
        return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
    }

    vector_3d::~vector_3d() = default;
}




