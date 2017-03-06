#pragma once
#include "vec3.h"
#include "Material.h"
class Object {
public:
    vec3 color;
    Object(vec3 _color): color(_color) {}
    virtual bool checkIntersection(vec3 origin, vec3 incidentRay, float clipValue, float &tValue) = 0;
};

struct IntersectObject
{
    Object * object;
    float tValue;
    IntersectObject(Object * _object, float _tValue) : object(_object), tValue(tValue) {}
};

bool IntersectObjectCompare (IntersectObject a, IntersectObject b) {
    return (a.tValue < b.tValue);
}