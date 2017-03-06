#pragma once
#include "Object.h"
#include <math.h>
class Sphere : public Object {
    vec3 pos;
    float r;
    public:
    Sphere(vec3 _pos, float _r, Material _material) : pos(_pos), r(_r), Object(_material) {}
    bool checkIntersection(Ray &incidentRay, float clipValue, float &tValue) {
        vec3 oc = incidentRay.o - pos;
        float a = incidentRay.d * incidentRay.d;
        float b = oc * incidentRay.d * 2.0f;
        float c = oc * oc - r * r;
        float d = b * b - 4 * a * c;
        if(d > 0) {
            tValue = (-b - sqrt(d)) / (2 * a);
            if(tValue > clipValue)
                return true;
            tValue = (-b + sqrt(d) / (2 * a));
            if(tValue > clipValue)
                return true;
        }
        return false;
    }
};