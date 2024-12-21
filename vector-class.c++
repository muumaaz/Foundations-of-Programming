#include <iostream>

// This class represents a 3D vector with x, y, z components
class Vector {
private:
    double x;  // x-component of the vector
    double y;  // y-component of the vector
    double z;  // z-component of the vector

public:
    // Default constructor - creates vector (0,0,0)
    Vector() : x(0.0), y(0.0), z(0.0) {}

    // Constructor with parameters
    Vector(double x_val, double y_val, double z_val) : x(x_val), y(y_val), z(z_val) {}

    // Getters
    double getX() const { return x; }
    double getY() const { return y; }
    double getZ() const { return z; }

    // Setters
    void setX(double x_val) { x = x_val; }
    void setY(double y_val) { y = y_val; }
    void setZ(double z_val) { z = z_val; }

    // Add two vectors
    Vector operator+(const Vector& other) const {
        return Vector(x + other.x, y + other.y, z + other.z);
    }

    // Subtract two vectors
    Vector operator-(const Vector& other) const {
        return Vector(x - other.x, y - other.y, z - other.z);
    }

    // Multiply vector by a scalar (vector * scalar)
    Vector operator*(double number) const {
        return Vector(x * number, y * number, z * number);
    }

    // Scalar product of two vectors (dot product)
    double operator*(const Vector& other) const {
        return x * other.x + y * other.y + z * other.z;
    }

    // Add and assign
    Vector& operator+=(const Vector& other) {
        x += other.x;
        y += other.y;
        z += other.z;
        return *this;
    }

    // Subtract and assign
    Vector& operator-=(const Vector& other) {
        x -= other.x;
        y -= other.y;
        z -= other.z;
        return *this;
    }

    // Assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            x = other.x;
            y = other.y;
            z = other.z;
        }
        return *this;
    }

    // Output operator
    friend std::ostream& operator<<(std::ostream& output, const Vector& v) {
        output << "(" << v.x << ", " << v.y << ", " << v.z << ")";
        return output;
    }

    // Input operator
    friend std::istream& operator>>(std::istream& input, Vector& v) {
        input >> v.x >> v.y >> v.z;
        return input;
    }
};

// Function to multiply a scalar by a vector (scalar * vector)
Vector operator*(double number, const Vector& vec) {
    return vec * number;  // Reuse the existing multiplication operator
}