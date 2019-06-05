#pragma once

//#include <GLFW/glfw3.h>

#include "GLUTOpenGLRenderer.hpp"

int main(int argc, char *argv[])
{
    GLUTRender::GLUTOpenGLRenderer renderer (argc, argv);
    Cube cube1 (10.f);
    Cube cube2 (3.f);
    
    renderer.AddObjectToRender(cube1).AddObjectToRender(cube2);
    
    renderer.StartMainLoop();
    
    return 0;
}
