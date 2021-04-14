#pragma once
#include <vector>

class Vector4D {

public:
    Vector4D(); //default constructor
    Vector4D(double, double, double, double);

    double& operator[](unsigned int index);
    Vector4D& operator=(const Vector4D&);
    
    Vector4D operator+(const Vector4D&) const;
    Vector4D& operator+=(const Vector4D&);
    Vector4D operator-(const Vector4D&) const;
    Vector4D& operator-=(const Vector4D&);

    Vector4D operator*(const Vector4D&) const;
    Vector4D& operator*=(const Vector4D&);
    Vector4D operator/(const Vector4D&) const;
    Vector4D& operator/=(const Vector4D&);

    Vector4D operator*(const double) const;
    Vector4D& operator*=(const double);
    Vector4D operator/(const double) const;
    Vector4D& operator/=(const double);

    bool operator==(const Vector4D&) const;
    bool operator!=(const Vector4D&) const;
    
    bool operator<(const Vector4D&) const;
    bool operator>(const Vector4D&) const;
    bool operator<=(const Vector4D&) const;
    bool operator>=(const Vector4D&) const;

    bool operator!() const;
    Vector4D operator-() const;

private:
    std::vector<double> vec;
};