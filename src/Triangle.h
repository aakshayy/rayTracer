#include "Object.h"
#ifndef __CLASS_TRIANGLE__
#define __CLASS_TRIANGLE__
class Triangle : public Object {
    vec3 v1;
    vec3 v2;
    vec3 v3;
    public:
    Triangle(vec3 _v1, vec3 _v2, vec3 _v3, vec3 _color) : v1(_v1), v2(_v2), v3(_v3), Object(_color) {}
    bool checkIntersection(vec3 origin, vec3 incidentRay, float clipValue, float &tValue) {
        float EPSILON = 0.000001;
        vec3 e1 = v2 - v1;
        vec3 e2 = v3 - v1;
        vec3 p = incidentRay.cross(e2);
        float d = e1 * p;
        if(d > -EPSILON && d < EPSILON) 
            return false;
        vec3 tvec = origin - v1;
        float invD = 1.0f / d;
        float u = tvec * p * invD;
        if (u < 0.0f || u > 1.0f) 
            return false;
        vec3 q = tvec.cross(e1);
        float v = incidentRay * q * invD;
        if (v < 0 || (u + v) > 1.0f) 
            return false;
        float t = e2 * q * invD;
        if(t > clipValue){
            tValue = t;
            return true;
        }
        return false;
    }
};
#endif