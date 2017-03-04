#include <math.h>
//Simple Vector class
#ifndef __CLASS_VEC3__
#define __CLASS_VEC3__

class vec3 {
    float e[3];
public:
    vec3() { e[0] = 0; e[1] = 0; e[2] = 0; }
    vec3(float _x, float _y, float _z) { e[0] = _x; e[1] = _y; e[2] = _z; }

    inline float x() const { return e[0]; }
    inline float y() const { return e[1]; }
    inline float z() const { return e[2]; }

    inline float operator[](int i) { return e[i]; }
    inline void set(float x, float y, float z) { e[0] = x; e[1] = y; e[2] = z; }

    inline vec3 operator+(vec3 v) { return vec3(e[0] + v[0], e[1] + v[1], e[2] + v[2]); }
    inline vec3 operator-(vec3 v) { return vec3(e[0] - v[0], e[1] - v[1], e[2] - v[2]); }
    //Scaling
    inline vec3 operator*(float s) { return vec3(e[0] * s, e[1] * s, e[2] * s); }
    //Dot product
    inline vec3 operator*(vec3 &v) { return vec3(e[0] * v[0], e[1] * v[1], e[2] * v[2]); }
    inline vec3 operator/(float s) { return vec3(e[0] / s, e[1] / s, e[2] / s); }
    //Cross product
    inline vec3 cross(vec3 &v) { 
        return vec3(e[1] * v[2] - e[2] * v[1],
                    e[2] * v[0] - e[0] * v[2],
                    e[0] * v[1] - e[1] * v[0]);
    }
    //Euclidean length
    inline float length() { return (float)sqrt(e[0] * e[0] + e[1] * e[1] + e[2] * e[2]); }
    //Unit vector
    vec3 normalize() {
        float len = length();
        return (len != 0) ? vec3(e[0] / len, e[1] / len, e[2] / len) : vec3();
    }
};

#endif