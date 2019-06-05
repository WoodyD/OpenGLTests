#pragma once

#include "Figures.hpp"

#include <vector>

#include <GLUT/GLUT.h>

namespace Render {
    
    void Initialize();
    void Resize(int width, int height);
    void Display(void);
    void Keyboard (unsigned char key, int x, int y);
    void KeyboardSpecial (int key, int x, int y);
    void RenderFigures();
    
    static int screen_width = 640;
    static int screen_height = 480;
    static float rotation_x = 0.f;
    static float rotation_y = 0.f;
    static float rotation_z = 0.f;
    static float rotation_x_increment = 0.f;
    static float rotation_y_increment = 0.f;
    static float rotation_z_increment = 0.f;
    static int filling = 0;
    
    static std::vector<Cube> allCubes;
    
    class GLUTOpenGLRenderer
    {
    public:
        GLUTOpenGLRenderer() = delete;
        GLUTOpenGLRenderer(int argc, char *argv[]);
        
        void AddCubeToRender(const Cube& cube);
        void StartMainLoop();
    };
    
}
