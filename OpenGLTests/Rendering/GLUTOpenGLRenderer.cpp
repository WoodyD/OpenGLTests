#include "GLUTOpenGLRenderer.hpp"

namespace Render {
    
    GLUTOpenGLRenderer::GLUTOpenGLRenderer(int argc, char *argv[]) {
        glutInit(&argc, argv);
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
        glutInitWindowSize(screen_width,screen_height);
        glutInitWindowPosition(0,0);
        glutCreateWindow("Test OpenGL window");
        
        glutDisplayFunc(Display);
        glutIdleFunc(Display);
        glutReshapeFunc (Resize);
        glutKeyboardFunc (Keyboard);
        glutSpecialFunc (KeyboardSpecial);
        
        Initialize();
    }
    
    void GLUTOpenGLRenderer::AddCubeToRender(const Cube& cube) {
        allCubes.push_back(cube);
    }
    
    void GLUTOpenGLRenderer::StartMainLoop() {
        glutMainLoop();
    }
    
    void Initialize()
    {
        glClearColor(0.0, 0.0, 0.2, 0.0);
        glShadeModel(GL_SMOOTH);
        glViewport(0, 0, screen_width, screen_height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, (GLfloat)screen_width/(GLfloat)screen_height, 1.0f,1000.0f);
        glEnable(GL_DEPTH_TEST);
        glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
    }
    
    void Resize (int width, int height)
    {
        screen_width = width;
        screen_height = height;
        glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glViewport(0, 0, screen_width, screen_height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(45.0f, (GLfloat)screen_width/(GLfloat)screen_height, 1.0f, 1000.0f);
        glutPostRedisplay ();
    }
    
    void Display (void)
    {
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0, 0.0, -50);
        rotation_x = rotation_x + rotation_x_increment;
        rotation_y = rotation_y + rotation_y_increment;
        rotation_z = rotation_z + rotation_z_increment;
        if (rotation_x > 359) rotation_x = 0;
        if (rotation_y > 359) rotation_y = 0;
        if (rotation_z > 359) rotation_z = 0;
        glRotatef(rotation_x, 1.0, 0.0, 0.0);
        glRotatef(rotation_y, 0.0, 1.0, 0.0);
        glRotatef(rotation_z, 0.0, 0.0, 1.0);
        
        glBegin(GL_TRIANGLES);
        
        RenderFigures();
        
        glEnd();
        glFlush();
        glutSwapBuffers();
    }
    
    void RenderFigures()
    {
        for(auto& cube : allCubes)
        {
            int l_index;
            FigureBase::obj_type cur_cube = cube.GetCube();
            for (l_index = 0; l_index < 12; l_index++)
            {
                glColor3f(1.0, 0.0, 0.0);
                glVertex3f(cur_cube.vertex[cur_cube.polygon[l_index].a].x, cur_cube.vertex[cur_cube.polygon[l_index].a].y, cur_cube.vertex[cur_cube.polygon[l_index].a].z);
                glColor3f(0.0, 1.0, 0.0);
                glVertex3f(cur_cube.vertex[cur_cube.polygon[l_index].b].x, cur_cube.vertex[cur_cube.polygon[l_index].b].y, cur_cube.vertex[cur_cube.polygon[l_index].b].z);
                glColor3f(0.0,0.0,1.0);
                glVertex3f(cur_cube.vertex[cur_cube.polygon[l_index].c].x, cur_cube.vertex[cur_cube.polygon[l_index].c].y, cur_cube.vertex[cur_cube.polygon[l_index].c].z);
            }
        }
    }
    
    void Keyboard (unsigned char key, int x, int y)
    {
        switch (key)
        {
            case ' ':
                rotation_x_increment=0;
                rotation_y_increment=0;
                rotation_z_increment=0;
                break;
            case 'r': case 'R':
                if (filling == 0)
                {
                    glPolygonMode (GL_FRONT_AND_BACK, GL_FILL);
                    filling = 1;
                }
                else
                {
                    glPolygonMode (GL_FRONT_AND_BACK, GL_LINE);
                    filling = 0;
                }
                break;
        }
    }
    
    void KeyboardSpecial (int key, int x, int y)
    {
        switch (key)
        {
            case GLUT_KEY_UP:
                rotation_x_increment = rotation_x_increment +0.005;
                break;
            case GLUT_KEY_DOWN:
                rotation_x_increment = rotation_x_increment -0.005;
                break;
            case GLUT_KEY_LEFT:
                rotation_y_increment = rotation_y_increment +0.005;
                break;
            case GLUT_KEY_RIGHT:
                rotation_y_increment = rotation_y_increment -0.005;
                break;
        }
    }
}
