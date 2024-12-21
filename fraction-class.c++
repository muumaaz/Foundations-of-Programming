#include <iostream>

// This class represents a fraction with a numerator and denominator
class Fraction {
private:
    // The top number of the fraction
    int numerator;
    
    // The bottom number of the fraction (can't be zero)
    int denominator;
    
    // Helper function to find the Greatest Common Divisor (GCD)
    // This helps us simplify fractions
    int findGCD(int a, int b) {
        // Make sure we work with positive numbers
        if (a < 0) a = -a;
        if (b < 0) b = -b;
        
        // Keep dividing until we find the GCD
        while (b != 0) {
            int remainder = a % b;
            a = b;
            b = remainder;
        }
        return a;
    }
    
    // Helper function to simplify the fraction (e.g., 2/4 becomes 1/2)
    void simplify() {
        // Find the GCD
        int gcd = findGCD(numerator, denominator);
        
        // Divide both numbers by GCD to simplify
        numerator = numerator / gcd;
        denominator = denominator / gcd;
        
        // Make sure the negative sign is always in the numerator
        if (denominator < 0) {
            numerator = -numerator;
            denominator = -denominator;
        }
    }

public:
    // Default constructor - creates fraction 0/1
    Fraction() {
        numerator = 0;
        denominator = 1;
    }
    
    // Constructor with parameters
    Fraction(int num, int den) {
        if (den == 0) {
            std::cout << "Error: Denominator cannot be zero!" << std::endl;
            // Set to 0/1 if invalid input
            numerator = 0;
            denominator = 1;
        } else {
            numerator = num;
            denominator = den;
            simplify();  // Simplify the fraction right away
        }
    }
    
    // Functions to get the values (getters)
    int getNumerator() {
        return numerator;
    }
    
    int getDenominator() {
        return denominator;
    }
    
    // Functions to set new values (setters)
    void setNumerator(int num) {
        numerator = num;
        simplify();
    }
    
    void setDenominator(int den) {
        if (den == 0) {
            std::cout << "Error: Denominator cannot be zero!" << std::endl;
            return;
        }
        denominator = den;
        simplify();
    }
    
    // Convert fraction to decimal number
    double toDouble() {
        return (double)numerator / denominator;
    }
    
    // Add two fractions
    Fraction operator+(Fraction other) {
        int newNum = (numerator * other.denominator) + 
                    (other.numerator * denominator);
        int newDen = denominator * other.denominator;
        return Fraction(newNum, newDen);
    }
    
    // Subtract two fractions
    Fraction operator-(Fraction other) {
        int newNum = (numerator * other.denominator) - 
                    (other.numerator * denominator);
        int newDen = denominator * other.denominator;
        return Fraction(newNum, newDen);
    }
    
    // Multiply two fractions
    Fraction operator*(Fraction other) {
        int newNum = numerator * other.numerator;
        int newDen = denominator * other.denominator;
        return Fraction(newNum, newDen);
    }
    
    // Divide two fractions
    Fraction operator/(Fraction other) {
        if (other.numerator == 0) {
            std::cout << "Error: Division by zero!" << std::endl;
            return Fraction(0, 1);
        }
        int newNum = numerator * other.denominator;
        int newDen = denominator * other.numerator;
        return Fraction(newNum, newDen);
    }
    
    // Add and assign
    Fraction& operator+=(Fraction other) {
        *this = *this + other;
        return *this;
    }
    
    // Subtract and assign
    Fraction& operator-=(Fraction other) {
        *this = *this - other;
        return *this;
    }
    
    // Multiply and assign
    Fraction& operator*=(Fraction other) {
        *this = *this * other;
        return *this;
    }
    
    // Divide and assign
    Fraction& operator/=(Fraction other) {
        *this = *this / other;
        return *this;
    }
    
    // Print fraction
    friend std::ostream& operator<<(std::ostream& output, Fraction f) {
        output << f.numerator << "/" << f.denominator;
        return output;
    }
    
    // Read fraction
    friend std::istream& operator>>(std::istream& input, Fraction& f) {
        char slash;  // To store the '/' character
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

// Test function to show how to use the Fraction class
int main() {
    // Create some fractions
    Fraction f1(2, 4);    // This will be simplified to 1/2
    Fraction f2(1, 3);
    Fraction f3;          // This will be 0/1
    
    // Print the fractions
    std::cout << "f1 = " << f1 << std::endl;
    std::cout << "f2 = " << f2 << std::endl;
    std::cout << "f3 = " << f3 << std::endl;
    
    // Try some arithmetic
    std::cout << "f1 + f2 = " << (f1 + f2) << std::endl;
    std::cout << "f1 - f2 = " << (f1 - f2) << std::endl;
    std::cout << "f1 * f2 = " << (f1 * f2) << std::endl;
    std::cout << "f1 / f2 = " << (f1 / f2) << std::endl;
    
    // Convert to decimal
    std::cout << "f1 as decimal = " << f1.toDouble() << std::endl;
    
    // Try compound assignment
    f3 = f1;              // f3 is now equal to f1
    f3 += f2;             // Add f2 to f3
    std::cout << "f3 after f1 + f2 = " << f3 << std::endl;
    
    // Read a fraction from the user
    Fraction userFraction;
    std::cout << "Enter a fraction (like this: 1/2): ";
    std::cin >> userFraction;
    std::cout << "You entered: " << userFraction << std::endl;
    
    return 0;
}
