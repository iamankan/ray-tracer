#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

using std::sqrt;

class vec3{
    public:
        double e[3];
        vec3() : e{0,0,0} {} // Default constructor
        vec3(double e0, double e1, double e2) : e{e0,e1,e2} {} // Constructor

        double x() const {return e[0];}
        double y() const {return e[1];}
        double z() const {return e[2];}

        vec3 operator-() const {return vec3(-e[0],-e[1],-e[2]);} // Unary operator: -(1,0,1)=(-1,0,-1)
        double operator[](int i) const {return e[i];} // Index operator: (1,0,1)[1]=0. It returns a copy of e[i]. So, any change/modification to the output does not affect the original data.
        double& operator[](int i) {return e[i];} // Index operator: (1,0,1)[1]=0. Returning reference to e[i]. So, any change, will modify. So, the return is not const.

        vec3& operator+=(const vec3 &v){ // (1,0,1) += (1,0,1) = (2,0,2) or (2,0,2) = (1,0,1) + (1,0,1)
            e[0] += v.e[0];
            e[1] += v.e[1];
            e[2] += v.e[2];
            return *this; // Return reference to the object itself
        }
        /*
                vec3 v(2.0, 3.0, 4.0);
                v *= 2;       // Multiply each component of v by 2
                v *= 1.5;     // Multiply each component of v by 1.5
                v *= 1/t;     // Multiply each component of v by 1/t and update the value of v

            */

        vec3& operator*=(const double t){ // (1,0,1) *= 2 = (2,0,2) or (1,0,1)*2 = (2,0,2)
            e[0] *= t;
            e[1] *= t;
            e[2] *= t;
            return *this; // Return reference to the object itself
        }

        vec3& operator/=(const double t){ // (1,0,1) /= 2 = (0.5,0,0.5) or (1,0,1)/2 = (0.5,0,0.5)
            return *this *= 1/t; // Return reference to the object itself
            
        }

        double length() const { // Length of vector
            return sqrt(length_squared());
        }

        double length_squared() const { // Length of vector squared
            return e[0]*e[0] + e[1]*e[1] + e[2]*e[2];
        }
};

using point3 = vec3; // 3D point
using color = vec3; // RGB color

#endif

// vec3 Utility Functions

inline std::ostream& operator<<(std::ostream &out, const vec3 &v) {
    return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

inline vec3 operator*(double t, const vec3 &v) {
    return vec3(t*v.e[0], t*v.e[1], t*v.e[2]);
}

inline vec3 operator*(const vec3 &v, double t) {
    return t * v;
}

inline vec3 operator/(vec3 v, double t) {
    return (1/t) * v;
}

inline double dot(const vec3 &u, const vec3 &v) {
    return u.e[0] * v.e[0]
         + u.e[1] * v.e[1]
         + u.e[2] * v.e[2];
}

inline vec3 cross(const vec3 &u, const vec3 &v) {
    return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
                u.e[2] * v.e[0] - u.e[0] * v.e[2],
                u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

inline vec3 unit_vector(vec3 v) {
    return v / v.length();
}