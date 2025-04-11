//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_POINT_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_POINT_H

#include <iostream>

namespace geometry{
    class point{
        private:
            double x, y;
        public:
            point(double x_, double y_);

            double get_x() const;
            double get_y() const;

            point operator+(const point &p) const;
            point operator-(const point &p) const;
            bool operator==(const point &p) const;

            friend std::ostream &operator<<(std::ostream &os, const point &p);

            ~point();

    };
} // namespace point


#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_POINT_H
