//
// Created by rudri on 10/11/2020.
//

#ifndef PROG3_FUNDAMENTOS_TASK_1_V2025_01_FRACTION_H
#define PROG3_FUNDAMENTOS_TASK_1_V2025_01_FRACTION_H

namespace math::operations{
    class fraction{
        private:
            int numerator;
            int denominator;
        public:
            fraction(int numerator_, int denominator_);
            fraction();

            int get_numerator() const;
            int get_denominator() const;

            fraction operator+(const fraction &f) const;
            fraction operator-(const fraction &f) const;
            fraction operator*(const fraction &f) const;
            fraction operator/(const fraction &f) const;
            bool operator==(const fraction &f) const;

            friend fraction simplify(int numerador, int denominador);

            ~fraction();
    };
    fraction simplify(int numerador, int denominador);
}

#endif //PROG3_FUNDAMENTOS_TASK_1_V2025_01_FRACTION_H
