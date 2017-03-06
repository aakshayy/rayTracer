#include <iostream>
#include <vector>
#include <algorithm>
#include "vec3.h"
#include "camera.h"
#include "Sphere.h"
#include "Triangle.h"

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

void loadObjects(std::vector<Object *> &objects) {
    Material sphereMaterial(vec3(), vec3(1.0f, 1.0f, 0.0f), DIFFUSE);
    Material leftWall(vec3(), vec3(0.75f, 0.25f, 0.25f), DIFFUSE);
    Material rightWall(vec3(), vec3(0.25f, 0.75f, 0.25f), DIFFUSE);
    Material plainWall(vec3(), vec3(0.75f, 0.75f, 0.75), DIFFUSE);

    objects.push_back(new Sphere(vec3(0.5f, 0.2f, 0.5), 0.2f, sphereMaterial));
    
    //Cornell Box
    //LEFT FACE
    objects.push_back(new Triangle(vec3(0, 0, 0), vec3(0, 1, 1), vec3(0, 0, 1), leftWall));
    objects.push_back(new Triangle(vec3(0, 0, 0), vec3(0, 1, 0), vec3(0, 1, 1), leftWall));
    //RIGHT FACE
    objects.push_back(new Triangle(vec3(1, 0, 0), vec3(1, 0, 1), vec3(1, 1, 1), rightWall));
    objects.push_back(new Triangle(vec3(1, 0, 0), vec3(1, 1, 1), vec3(1, 1, 0), rightWall));
    //TOP FACE 
    objects.push_back(new Triangle(vec3(1, 1, 0), vec3(1, 1, 1), vec3(0, 1, 1), plainWall));
    objects.push_back(new Triangle(vec3(1, 1, 0), vec3(0, 1, 1), vec3(0, 1, 0), plainWall));
    //BACK FACE
    objects.push_back(new Triangle(vec3(0, 0, 1), vec3(1, 1, 1), vec3(1, 0, 1), plainWall));
    objects.push_back(new Triangle(vec3(0, 0, 1), vec3(0, 1, 1), vec3(1, 1, 1), plainWall));
    //BOTTOM FACE
    objects.push_back(new Triangle(vec3(0, 0, 0), vec3(1, 0, 1), vec3(1, 0, 0), plainWall));
    objects.push_back(new Triangle(vec3(0, 0, 0), vec3(0, 0, 1), vec3(1, 0, 1), plainWall));
    //FRONT FACE
    objects.push_back(new Triangle(vec3(0, 0, 0), vec3(1, 0, 0), vec3(1, 1, 0), plainWall));
    objects.push_back(new Triangle(vec3(0, 0, 0), vec3(1, 1, 0), vec3(0, 1, 0), plainWall));
}

vec3 getShadeAtPixel(Ray &incidentRay, std::vector<Object *> &objects) {
    vec3 color(0.0f, 0.0f, 0.0f); //set background to black
    float tValue;
    std::vector<IntersectObject> intersectedObjects;

    for (unsigned int i = 0; i < objects.size(); i++) {
        if(objects[i]->checkIntersection(incidentRay, 1, tValue)) {
            intersectedObjects.push_back(IntersectObject(objects[i], tValue));
        }
    }
    
    if(intersectedObjects.size() > 0) {
        color = intersectedObjects[0].object->material.color;
    }
    return color;
}

int main() {
    Camera camera(400, 400);
    std::cout << "P3\n";
    std::cout << camera.getScreenWidth() << " " << camera.getScreenHeight() << "\n";
    std::cout << "255\n";

    //width of each pixel
    float dx = (Camera::WIN_RIGHT_X - Camera::WIN_LEFT_X) / (camera.getScreenWidth());
    //height of each pixel
    float dy = (Camera::WIN_TOP_Y - Camera::WIN_BOTTOM_Y) / (camera.getScreenHeight());
    
    std::vector<Object *> objects;
    loadObjects(objects);

    float x, y = Camera::WIN_TOP_Y;
    for (float h = camera.getScreenHeight() - 1; h >= 0; h--, y-= dy) {
        x = Camera::WIN_LEFT_X;
        for (float w = 0; w < camera.getScreenWidth(); w++, x+= dx) {
            Ray incidentRay(camera.eye, vec3(x, y, 0) - camera.eye);
            vec3 color = getShadeAtPixel(incidentRay, objects);
            writeColor(color);
        }
        std::cout << "\n";
    }
    return 0;
}