//
// Created by rudri on 10/11/2020.
//
#include <utility>

#ifndef PROG3_FUNDAMENTOS_TASK_2_V2025_01_INVOKE_MULTIPLE_H
#define PROG3_FUNDAMENTOS_TASK_2_V2025_01_INVOKE_MULTIPLE_H

namespace functional::meta{

    template<typename... Fs>
    void invoke_multiple(Fs &&...fs) {
         (std::forward<Fs>(fs)(),...);
    }
} // namespace functional::meta

#endif //PROG3_FUNDAMENTOS_TASK_2_V2025_01_INVOKE_MULTIPLE_H
