#pragma once

//#include <GLFW/glfw3.h>

#include "GLUTOpenGLRenderer.hpp"

int main(int argc, char *argv[])
{
    GLUTRender::GLUTOpenGLRenderer renderer (argc, argv);
    Cube cube1 (20.f);
    Cube cube2 (10.f);
    
    renderer.AddObjectToRender(cube1);
    
    renderer.StartMainLoop();
    
    return 0;
}
