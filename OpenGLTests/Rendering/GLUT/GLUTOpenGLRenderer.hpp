#pragma once

#include <GLUT/GLUT.h>

#include <vector>
#include <iostream>

#include "Figures.hpp"

namespace GLUTRender {
    
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
    static bool filling = false;
    
    class GLUTOpenGLRenderer final
    {
    public:
        GLUTOpenGLRenderer() = delete;
        GLUTOpenGLRenderer(int argc, char *argv[]);
        
        template<class ObjectType>
        void AddObjectToRender(ObjectType& object)
        {
            const GraphicObject& obj = dynamic_cast<GraphicObject&>(object);
            allObjects.emplace_back(obj);
        };
        
        void StartMainLoop();
        
        void Initialize();
        
        static std::vector<GraphicObject> allObjects;
    };
    
}
