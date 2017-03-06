#include "vec3.h"

class Camera {
    unsigned int screenWidth;
    unsigned int screenHeight;
public:
    //Position of the eye of the camera
    vec3 eye;
    /* Not needed
    //Direction of the camera
    vec3 lookAt;
    //Up direction of the camera
    vec3 up;
    */

    //Position of the screen window
    const static float WIN_TOP_Y = 1.0f;
    const static float WIN_BOTTOM_Y = 0.0f;
    const static float WIN_RIGHT_X = 1.0f;
    const static float WIN_LEFT_X = 0.0f;


    Camera(unsigned int _w, unsigned int _h) {
        screenWidth = _w;
        screenHeight = _h;
        eye.set(0.5f, 0.5f, -0.5f);
        /* Not needed 
        lookAt.set(0.5f, 0.5f, 0.0f);
        up.set(0.0f, 1.0f, 0.0f);
        */
    }

    unsigned int getScreenWidth() { return screenWidth; }
    unsigned int getScreenHeight() { return screenHeight; }
};