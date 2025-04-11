//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_VECTOR_3D_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_VECTOR_3D_H

namespace geometry{
        class vector_3d{
            private:
                double x, y, z;

            public:

                vector_3d(double x_, double y_, double z_);
                vector_3d();

                double get_x() const;
                double get_y() const;
                double get_z() const;

                vector_3d operator+(const vector_3d &v) const;
                vector_3d operator-(const vector_3d &v) const;
                vector_3d &operator=(const vector_3d &v);

                friend double dot_product(const vector_3d &v1, const vector_3d &v2);

                ~vector_3d();
        };
        double dot_product(const vector_3d &v1, const vector_3d &v2);
}

#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_VECTOR_3D_H
