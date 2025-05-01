//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_2_V2025_01_APPLY_TO_ALL_H
#define PROG3_FUNDAMENTOS_TASK_2_V2025_01_APPLY_TO_ALL_H



namespace meta::utility{

    template<auto F, typename... Args>
    void apply_to_all(Args&&... args){
        (F(args), ...);
    }

    template<typename F, typename... Args>
    void apply_to_all(F &&f, Args&&... args){
        (f(args), ...);
    }


} //namespace meta::utility

#endif //PROG3_FUNDAMENTOS_TASK_2_V2025_01_APPLY_TO_ALL_H
