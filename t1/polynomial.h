//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_POLYNOMIAL_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_POLYNOMIAL_H

#include <iostream>

namespace math{
    namespace operations{ 
        class polynomial{
            // ex: double coeffs[] = {2,3,4}; representa 2 + 3x +4x^2 
            // => a + bx + cx^2 + dx^3 + ...
            private:
                int deg; //grado del polinomio
                double *coeffs;
            public: 
                polynomial(int deg_, double *coeffs_);
                polynomial(const polynomial &other); //constructor de copia
                

                double& get_coefficient(int idx);              // version sin const ojala corra xfavor 
                const double& get_coefficient(int idx) const; // version con const
                int get_degree() const; 

                //operador de asignacion
                polynomial &operator=(const polynomial &other);
                polynomial &operator=(polynomial &&other) noexcept; 

                polynomial operator+(const polynomial &p) const; //suma de polinomios
                polynomial operator-(const polynomial &p) const; //resta de polinomios
                polynomial operator*(const polynomial &p) const; //multiplicacion de polinomios
                
                friend std::ostream &operator<<(std::ostream &os, const polynomial &p); //operador de salida
                friend double evaluate(const polynomial &p, double val);
                ~polynomial(); //destructor
        };

        double evaluate(const polynomial &p, double val);

    } // namespace operations
    
} // namespace math


#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_POLYNOMIAL_H
