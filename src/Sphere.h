#include "Object.h"
#include <math.h>
#ifndef __CLASS_SPHERE__
#define __CLASS_SPHERE__
class Sphere : public Object {
    vec3 pos;
    float r;
    public:
    Sphere(vec3 _pos, float _r, vec3 _color) : pos(_pos), r(_r), Object(_color) {}
    bool checkIntersection(vec3 origin, vec3 incidentRay, float clipValue, float &tValue) {
        vec3 oc = origin - pos;
        float a = incidentRay * incidentRay;
        float b = oc * incidentRay * 2.0f;
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
#endif