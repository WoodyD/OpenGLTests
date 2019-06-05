#pragma once

//#include <GLFW/glfw3.h>

#include "GLUTOpenGLRenderer.hpp"

int main(int argc, char *argv[])
{
    Render::GLUTOpenGLRenderer renderer (argc, argv);
    Cube cube (10.f);
    
    renderer.AddCubeToRender(cube);
    renderer.StartMainLoop();
    
    return 0;
}
