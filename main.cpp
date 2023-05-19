#include<iostream>
#include<stdio.h>

#include "vec3.h"
#include "color.h"
#include "ray.h"

using namespace std;

color ray_color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5*(unit_direction.y() + 1.0);
    return (1.0-t)*color(1.0, 1.0, 1.0) + t*color(0.5, 0.7, 1.0);
}


int main(){
    // Image
    const auto aspect_ratio = 16.0/9.0; // Width/Height
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width/aspect_ratio); // W1/H1 = W2/H2 => 16/9 = W2/H2 => H2 = W2*9/16 => H2 = W2/(W1/H1) => H2 = W2/aspect_ratio

    // Camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio*viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0,0,0); // Eye
    auto horizontal = vec3(viewport_width, 0, 0); // Horizontal length of viewport
    auto vertical = vec3(0, viewport_height, 0); // Vertical length of viewport
    auto lower_left_corner = origin - horizontal/2 - vertical/2 - vec3(0,0,focal_length); // Lower left corner of viewport

    // Render
    cout << "P3\n" << image_width << ' ' << image_height << "\n255\n"; // PPM file format

    for(int j = image_height-1; j >= 0; --j){
        cerr << "\rScanlines remaining: " << j << ' ' << flush; // Print progress to stderr
        for(int i = 0; i < image_width; ++i){
            auto u = double(i)/(image_width-1); // Horizontal
            auto v = double(j)/(image_height-1); // Vertical
            ray r(origin, lower_left_corner + u*horizontal + v*vertical - origin); // Ray from eye to pixel
            color pixel_color = ray_color(r); // Color of pixel
            write_color(cout, pixel_color); // Write color to PPM file
        }
    }

    cerr << "\nDone.\n";


    
}