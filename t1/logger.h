//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_LOGGER_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_LOGGER_H

#include <fstream>
#include <string>
#include <iostream>

namespace file{
    namespace operations{
        class logger{
            private:
                std::ofstream flogger;
            public:
                logger(const std::string& file_name); //aqui lo abro
                ~logger();
                logger &operator<<(const std::string &message);
                void write(const std::string &m);
        };
    }
}

#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_LOGGER_H
