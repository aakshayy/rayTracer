#pragma once
#include "vec3.h"
#include "Material.h"
#include "Ray.h"
class Object {
public:
	Material material;
    Object(Material _material): material(_material) {}
    virtual bool checkIntersection(Ray &incidentRay, float clipValue, float &tValue) = 0;
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