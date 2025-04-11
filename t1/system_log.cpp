//
// Created by rudri on 10/11/2020.
//

#include "system_log.h"

namespace performance::monitoring{
        system_log::system_log(const std::string& filename){
            file.open(filename, std::ios::app);
        }
        system_log::~system_log(){
            file.close();
        }
        void system_log::start(const std::string &message){
            file << message;
            file.flush();
        }
        void system_log::stop(const std::string &message){
            file <<"," << message << "\n";
            file.flush();
        }
}

