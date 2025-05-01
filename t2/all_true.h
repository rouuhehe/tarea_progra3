//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_2_V2025_01_ALL_TRUE_H
#define PROG3_FUNDAMENTOS_TASK_2_V2025_01_ALL_TRUE_H

// acepta varios bools
// retorna true solo si todos son true
// usa fold expression con &&

namespace utils {
    namespace logic {
        template<typename... T>
        bool all_true(T... t) {
            return (... && t);
        }
    } // namespace logic
} // namespace utils

#endif //PROG3_FUNDAMENTOS_TASK_2_V2025_01_ALL_TRUE_H
