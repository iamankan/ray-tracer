#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    // Image height and width
    const int image_width = 400;
    const int image_height = 200;

    // Render
    cout << "P3\n" << image_width << ' ' << image_height << "\n255\n";

    // Loop over pixels
    for(int j = 0;j< image_height;j++){
        for(int i=0;i<image_width;i++){
            auto r = double(i) / (image_width-1);
            auto g = double(j) / (image_height-1);
            auto b = 0.25;

            // Convert to 0-255
            int ir = static_cast<int>(255.999 * r);
            int ig = static_cast<int>(255.999 * g);
            int ib = static_cast<int>(255.999 * b);

            // Print to stdout
            cout << ir << ' ' << ig << ' ' << ib << '\n';
        }
    }

    cerr << "\nDone.\n";
    
}