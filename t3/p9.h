//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P9_H
#define PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P9_H

#include <vector>
#include <initializer_list>

template<typename T, std::size_t sz>
class fixed_stack_pusher;

template <typename T, std::size_t sz>
// T -> tipo de datos de los valores que almacenará la pila
// sz -> cantidad FIJA de valores de la pila

class fixed_stack{
    std::vector <T> stack;

    public:
        fixed_stack() = default;

        fixed_stack(std::initializer_list<T> lst){
            for(auto &it : lst){
                if(stack.size() < sz){
                    stack.push_back(it);
                } else {
                    break;
                }
            }
        }
        
        T top(){
            return stack.back();
        }

        void pop(){
            stack.pop_back();
        }
        bool push(T value){
            if(stack.size() < sz){
                stack.push_back(value);
                return true;
            }
            return false;
        }
        bool empty(){
            return stack.empty();
        }

        int size() const{
            return stack.size();
        }

        friend class fixed_stack_pusher<T, sz>;
    };

    template<typename T, std::size_t sz>
    class fixed_stack_pusher{
        private: 
            fixed_stack<T, sz>* stack;

        public:
            fixed_stack_pusher( fixed_stack<T, sz> &stack){
                this->stack = &stack;
            }
            
            fixed_stack_pusher& operator++(){
                return *this;
            }

            fixed_stack_pusher<T, sz> operator++(int){
                return *this;
            }

            fixed_stack_pusher &operator=(T value){
                stack -> push(value);
                return *this;
            }

            fixed_stack_pusher &operator*(){
                return *this;
            }
    };


#endif //PROG3_UNIT2_STANDAR_LIBRARY_V2022_1_P9_H
