#pragma once

#include <GLUT/GLUT.h>

#include <vector>
#include <iostream>

#include "Figures.hpp"

namespace GLUTRender {
    
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
    static bool filling = false;
    
    static std::vector<Object> allObjects = {};
    
    class GLUTOpenGLRenderer final
    {
    public:
        GLUTOpenGLRenderer() = delete;
        GLUTOpenGLRenderer(int argc, char *argv[]);
        
        template<class ObjectType>
        GLUTOpenGLRenderer AddObjectToRender(ObjectType& object)
        {
            std::cout << "Begin cast" << std::endl;
            const Object& obj = dynamic_cast<Object&>(object);
            std::cout << "End cast" << std::endl;
            allObjects.emplace_back(obj);
            std::cout << "Obj added" << std::endl;
            
            return *this;
        };
        
        void StartMainLoop();
    };
    
}
