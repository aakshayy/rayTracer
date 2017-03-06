#pragma once

class Ray {
public:
    vec3 o;
    vec3 d;
    Ray(vec3 _o, vec3 _d): o(_o), d(_d) {}
};
