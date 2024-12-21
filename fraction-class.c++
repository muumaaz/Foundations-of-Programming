#include <iostream>

// This class represents a fraction with a numerator and denominator
class Fraction {
private:
    int numerator;    // The top number of the fraction
    int denominator;  // The bottom number of the fraction (can't be zero)

    // Helper function to find the Greatest Common Divisor (GCD)
    int findGCD(int a, int b) {
        if (a < 0) a = -a;
        if (b < 0) b = -b;

        while (b != 0) {
            int remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }

    // Helper function to simplify the fraction
    void simplify() {
        int gcd = findGCD(numerator, denominator);
        numerator = numerator / gcd;
        denominator = denominator / gcd;

        // Ensure the negative sign is always in the numerator
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Default constructor
    Fraction() : numerator(0), denominator(1) {}

    // Constructor with parameters
    Fraction(int num, int den) {
        if (den == 0) {
            std::cout << "Error: Denominator cannot be zero!" << std::endl;
            numerator = 0;
            denominator = 1;
        } else {
            numerator = num;
            denominator = den;
            simplify();
        }
    }

    // Getter for numerator
    int getNumerator() {
        return numerator;
    }

    // Getter for denominator
    int getDenominator() {
        return denominator;
    }

    // Setter for numerator
    void setNumerator(int num) {
        numerator = num;
        simplify();
    }

    // Setter for denominator
    void setDenominator(int den) {
        if (den == 0) {
            std::cout << "Error: Denominator cannot be zero!" << std::endl;
            return;
        }
        denominator = den;
        simplify();
    }

    // Convert fraction to decimal
    double toDouble() {
        return (double)numerator / denominator;
    }

    // Arithmetic operators
    Fraction operator+(Fraction other) {
        int newNum = (numerator * other.denominator) + (other.numerator * denominator);
        int newDen = denominator * other.denominator;
        return Fraction(newNum, newDen);
    }

    Fraction operator-(Fraction other) {
        int newNum = (numerator * other.denominator) - (other.numerator * denominator);
        int newDen = denominator * other.denominator;
        return Fraction(newNum, newDen);
    }

    Fraction operator*(Fraction other) {
        int newNum = numerator * other.numerator;
        int newDen = denominator * other.denominator;
        return Fraction(newNum, newDen);
    }

    Fraction operator/(Fraction other) {
        if (other.numerator == 0) {
            std::cout << "Error: Division by zero!" << std::endl;
            return Fraction(0, 1);
        }
        int newNum = numerator * other.denominator;
        int newDen = denominator * other.numerator;
        return Fraction(newNum, newDen);
    }

    // Compound assignment operators
    Fraction& operator+=(Fraction other) {
        *this = *this + other;
        return *this;
    }

    Fraction& operator-=(Fraction other) {
        *this = *this - other;
        return *this;
    }

    Fraction& operator*=(Fraction other) {
        *this = *this * other;
        return *this;
    }

    Fraction& operator/=(Fraction other) {
        *this = *this / other;
        return *this;
    }

    // Stream operators
    friend std::ostream& operator<<(std::ostream& output, Fraction f) {
        output << f.numerator << "/" << f.denominator;
        return output;
    }

    friend std::istream& operator>>(std::istream& input, Fraction& f) {
        char slash;
        input >> f.numerator >> slash >> f.denominator;
        if (f.denominator == 0) {
            std::cout << "Error: Denominator cannot be zero!" << std::endl;
            f.numerator = 0;
            f.denominator = 1;
        } else {
            f.simplify();
        }
        return input;
    }
};