#include <iostream>
#include "vec3.h"
//1. Basics
//Tasks: 
//- Set image height, width
//- Setup basic vector operations
//- Output a simple image file (.ppm) with yellow background

void writeColor(vec3 v) {
	v = v * 255.99f;
	std::cout << (int)v.x() << " " << (int)v.y() << " " << (int)v.z() << '\n';
}

int main() {
	unsigned int imageWidth = 600, imageHeight = 400;
	std::cout << "P3\n";
	std::cout << imageWidth << " " << imageHeight << "\n";
	std::cout << "255\n";
	vec3 yellow(1.0f, 1.0f, 0.0f); //RGB value
	for (unsigned int x = 0; x < imageWidth; x++) {
		for (unsigned int y = 0; y < imageHeight; y++) {
			writeColor(yellow);
		}
	}
	return 0;
}