#ifndef RAY_H
#define RAY_H

#include "vec3.h"

class ray {
    public:
        point3 orig; // Ray origin
        vec3 dir; // Ray direction

        ray() {} // Default constructor
        ray(const point3& origin, const vec3& direction) : orig(origin), dir(direction) {} // Parameterized constructor
        // For Ray.origin() + t*Ray.direction()
        point3 origin() const {return orig;} // Return origin of ray
        vec3 direction() const {return dir;} // Return direction of ray

        point3 at(double t) const { // Return point at t
            return orig + t*dir;
        }

};

#endif