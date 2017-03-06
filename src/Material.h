#pragma once

enum MaterialType {
    DIFFUSE,
    SPECULAR,
    REFRACT
};

class Material {
public:
    vec3 emission;
    vec3 color;
    MaterialType type;
    Material(vec3 _emission, vec3 _color, MaterialType _type) : emission(_emission), color(_color), type(_type) {}
};