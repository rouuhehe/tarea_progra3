//
// Created by rudri on 10/11/2020.
//

#include <iostream>
#include <numeric>
#include "fraction.h"

namespace math::operations{

    fraction::fraction(int numerator_, int denominator_) : numerator(numerator_), denominator(denominator_) {}
    fraction::fraction() : numerator(1), denominator(1) {}

    int fraction::get_numerator() const {
        return numerator;
    }

    int fraction::get_denominator() const {
        return denominator;
    }

    fraction fraction::operator*(const fraction &f) const{
        return simplify(numerator*f.numerator, denominator*f.denominator);
    }

    fraction fraction::operator+(const fraction &f) const{
        if(denominator == f.denominator){
            int n = numerator + f.numerator;
            return simplify(n, denominator);
        } 
        int n = numerator*f.denominator + f.numerator*denominator;
        int d = denominator*f.denominator;
        return simplify(n, d); 
    }
    bool fraction::operator==(const fraction &f) const{
        return numerator*f.denominator == denominator*f.numerator;
    }

    fraction fraction::operator/(const fraction &f) const{
        return simplify(numerator*f.denominator, denominator*f.numerator);
    }

    fraction fraction::operator-(const fraction &f) const{
        if(denominator == f.denominator){
            int n = numerator - f.numerator;
            return simplify(n, denominator);
        } 
        int n = numerator*f.denominator - f.numerator*denominator;
        int d = denominator*f.denominator;
        return simplify(n, d);
    }

    fraction simplify(int numerator, int denominator){
        int mcd = std::gcd(numerator, denominator);
        return fraction(numerator/mcd, denominator/mcd); 
    }

    fraction::~fraction()=default;
}