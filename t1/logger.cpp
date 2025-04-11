//
// Created by rudri on 10/11/2020.
//

#include "logger.h"

namespace file::operations{
        logger::logger(const std::string& file_name) {
            flogger.open(file_name, std::ios::app); //abro el archivo en modo append
            if(!flogger.is_open()){
                throw std::runtime_error("Error opening file: " + file_name); //si no se abre lanzo una excepcion
            }
        }

        logger &logger::operator<<(const std::string &message) {
            flogger << message << "\n";
            flogger.flush();
            return *this;
        }

        void logger::write(const std::string &m) {
            flogger << m <<"\n";
            flogger.flush();
        }

        logger::~logger(){
            if (flogger.is_open()){
                flogger.close();
            }
        }
}

