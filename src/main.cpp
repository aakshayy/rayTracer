#include <iostream>
#include "vec3.h"
#include "camera.h"
/*
2. Camera

Tasks:
- Set up camera, screen parameters
*/

void writeColor(vec3 v) {
	v = v * 255.99f;
	float r = v[0], g = v[1], b = v[2];
	r = (r < 0) ? 0 : r;
	g = (g < 0) ? 0 : g;
	b = (b < 0) ? 0 : b;

	r = (r > 255.99f) ? 255.99f : r;
	g = (g > 255.99f) ? 255.99f : g;
	b = (b > 255.99f) ? 255.99f : b;

	std::cout << (int)r << " " << (int)g << " " << (int)b << '\n';
}

int main() {
	Camera camera(600, 400);
	std::cout << "P3\n";
	std::cout << camera.getScreenWidth() << " " << camera.getScreenHeight() << "\n";
	std::cout << "255\n";

	vec3 background(1.0f, 0.0f, 0.0f); //set background to black
	
	//width of each pixel
	float dx = (Camera::WIN_RIGHT_X - Camera::WIN_LEFT_X) / (camera.getScreenWidth());
	//height of each pixel
	float dy = (Camera::WIN_TOP_Y - Camera::WIN_BOTTOM_Y) / (camera.getScreenHeight());
	
	for (float h = camera.getScreenHeight() - 1; h >= 0; h--) {
		for (float w = 0; w < camera.getScreenWidth(); w++) {
			float x = w * dx;
			float y = h * dy;
			//check if screen coordinates are correct
			writeColor(vec3(x, y, 0));
		}
		std::cout << "\n";
	}
	return 0;
}