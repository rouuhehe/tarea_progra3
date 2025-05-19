//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P8_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P8_H

#include <fstream>
#include <vector>
#include <deque>
#include <list>
#include <forward_list>
#include <string>


template<typename T>
void insert(std::vector<T>& c, const T& val) { c.push_back(val); }

template<typename T>
void insert(std::deque<T>& c, const T& val) { c.push_back(val); }

template<typename T>
void insert(std::list<T>& c, const T& val) { c.push_back(val); }

template<typename T>
void insert(std::forward_list<T>& c, const T& val) { c.push_front(val); }


template<typename T>
void ordenar(std::vector<T>& c) {
    std::sort(c.begin(), c.end());
}

template<typename T>
void ordenar(std::deque<T>& c) {
    std::sort(c.begin(), c.end());
}

template<typename T>
void ordenar(std::list<T>& c) {
    c.sort();
}

template<typename T>
void ordenar(std::forward_list<T>& c) {
    c.sort();
}
template<template<typename...>class contenedor = std::vector>
auto filter_codes(const std::string &file_name,  char code) {
    contenedor<std::string> res;

    std::ifstream in(file_name);
    std::string line;
    while (std::getline(in, line)) {
        if (line[0] == code)
            insert(res,line);
    }

    ordenar(res);
    return res;
}

#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P8_H
