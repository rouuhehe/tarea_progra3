//
// Created by rudri on 10/11/2020.
//

#include <cmath>
#include "polynomial.h"

namespace math::operations {

    // constructores 
    polynomial::polynomial(int deg_, double *coeffs_) : deg(deg_) {
        coeffs = new double[deg + 1];
        for (int i = 0; i <= deg; i++) {
            coeffs[i] = coeffs_[i];
        }
    }
    polynomial::polynomial(const polynomial &other) : deg(other.deg) {
        coeffs = new double[deg + 1];
        for (int i = 0; i <= deg; ++i) {
            coeffs[i] = other.coeffs[i];
        }
    }

    polynomial &polynomial::operator=(const polynomial &other){
        if (this != &other) { //verifico que no se le asigne a si mismo :p
            delete[] coeffs; //libero la memoria del polinomio actual

            deg = other.deg;
            coeffs = new double[deg + 1]; //asignp nueva memoria
            for (int i = 0; i <= deg; ++i) {
                coeffs[i] = other.coeffs[i];
            }
        }
        return *this; //devuelvo el objeto actual
    }

    // operador de asignación
    polynomial &polynomial::operator=(polynomial &&other) noexcept {
        if (this!= &other) { //verifico que no se le asigne a si mismo :p
            delete[] coeffs; //libero la memoria del polinomio actual

            deg = other.deg;
            coeffs = other.coeffs; //asignp nueva memoria
            
            other.deg = -1;
            other.coeffs = nullptr; //asigno null a los valores del otro polinomio
        }
        return *this; //devuelvo el objeto actual
    }

    // sobrecarga para operadores 
    polynomial polynomial::operator+(const polynomial &p) const {
        int max_deg = std::max(deg, p.deg); // me quedo con el mayor grado de los dos polinomios ex:3
        double *new_coeffs = new double[max_deg+1]; // reservo memoria para el nuevo polinomio ex: 4

        for (int i = 0; i <= max_deg; i++) {
            new_coeffs[i] = 0; //lo inicializo con 0
        }

        for (int i = 0; i <= deg; i++) { // 1, 2
            new_coeffs[i] += coeffs[i]; //i=0: nc[0] = 0 + 1, i=1: nc[1] = 0 + 2 
        }
        for (int i = 0; i <= p.deg; i++) { //3, 4, nc[0] = 1, nc[1] = 2
            new_coeffs[i] += p.coeffs[i]; //i=0: nc[0] = 1 + 3, i=1: nc[1] = 2 + 4
        } // nc = {4, 6}
        return polynomial(max_deg, new_coeffs); // deg: 3, coeffs: {4, 6}
    }
     
    polynomial polynomial::operator-(const polynomial &p) const {
        int max_deg = std::max(deg, p.deg);
        double *new_coeffs = new double[max_deg+1];

        for (int i = 0; i <= max_deg; i++) {
            new_coeffs[i] = 0;
        }
        
        for (int i = 0; i <= deg; i++) { // 1, 2
            new_coeffs[i] += coeffs[i]; //n[0] = 0 + 1, n[1] = 0 + 2
        }
        for (int i = 0; i <= p.deg; i++) { //3 , 4
            new_coeffs[i] -= p.coeffs[i]; // n[0] = 1 - 3, n[1] = 2 - 4
        }
        return polynomial(max_deg, new_coeffs);
    }

    polynomial polynomial::operator*(const polynomial &p) const{
        int max_deg = deg + p.deg;
        double *new_coeffs = new double[max_deg+1];
        for (int i = 0; i <= max_deg; i++) {
            new_coeffs[i] = 0;
        }

        for (int i = 0; i <= deg; i++) {
            for (int j = 0; j <= p.deg; j++) {
                new_coeffs[i + j] += coeffs[i] * p.coeffs[j]; //cada coef del primer polinomio se multiplica por los coefs del segundo
            }
        }
        return polynomial(max_deg, new_coeffs);
    }

    // operador de salida

    std::ostream &operator<<(std::ostream &os, const polynomial &p) {
        for (int i = 0; i <= p.deg; i++) {
            if(i==0){
                os << p.coeffs[i] << " ";
            } else{
                os << p.coeffs[i] << "x^" << i <<" ";
            }
        }
        os << std::endl;
        return os;
    }

    // funcion friend

    double evaluate(const polynomial &p, double val) {
        double res = 0;
        for(int i=0; i<=p.deg; i++){
            res += p.coeffs[i] * pow(val,i); //val^i
        }
        return res;
    }


    double &polynomial::get_coefficient(int idx){
        return coeffs[idx];
    }

    const double &polynomial::get_coefficient(int idx) const{
        return coeffs[idx];
    }

    int polynomial::get_degree() const{
        return deg;
    }

    // destructor
    polynomial::~polynomial(){
        delete[] coeffs;
    }
}
