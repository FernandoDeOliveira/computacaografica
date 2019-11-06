#ifndef GEOMETRIC_TRANSFORMATION_H
#define GEOMETRIC_TRANSFORMATION_H
#include <GL/freeglut.h>

namespace geoTrans{
    static int rotation_point_1 = 0, rotation_point_2 = 0;
    int window;

    void display(){
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0, 0.0, 0.0);
        glBegin(GL_LINES);
        glVertex2i(-250, 0);
        glVertex2i(250, 0);
        glVertex2i(0, -250);
        glVertex2i(0, 250);
        glEnd();

        glColor3f(1.0, 1.0, 1.0);
        glPushMatrix();
        glTranslatef(0.0, 0.0, 0.0);
        glRotatef((GLfloat) rotation_point_1, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);

        glPushMatrix();
        glScalef(2.0, 0.4, 1.0);
        glutWireCone(1.0, 1.0, 5, 5);
        glPopMatrix();

        glTranslatef(2.0, 0.0, 0.0); 
        glRotatef((GLfloat) rotation_point_2, 0.0, 0.0, 1.0);
        glTranslatef(1.0, 0.0, 0.0);

        glPushMatrix();
        glScalef(2.0, 0.4, 1.0);
        glutWireSphere(1.0, 10, 10);
        glPopMatrix();

        glPopMatrix();
        glutSwapBuffers();
    }

    void reshape(int width, int height){
        glViewport(0, 0, (GLsizei) width, (GLsizei) height);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        gluPerspective(65.0, (GLfloat) width / (GLfloat) height, 1.0, 20.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0, 0.0, -10.0);
    }

    void keyboard(unsigned char key, int x, int y){
        switch (key)
        {
        case 'a':
            rotation_point_1 = (rotation_point_1 + 5) % 360;
            glutPostRedisplay();
            break;
        case 'd':
            rotation_point_1 = (rotation_point_1 - 5) % 360;
            glutPostRedisplay();
            break;
        case 'w':
            rotation_point_2 = (rotation_point_2 + 5) % 360;
            glutPostRedisplay();
            break;
        case 's':
            rotation_point_2 = (rotation_point_2 - 5) % 360;
            glutPostRedisplay();
            break;
        case 27:
                glutDestroyWindow(geoTrans::window);
                break;
        }
    }

void init(){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    geoTrans::window = glutCreateWindow("geo trans");
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    }
} 

void geometric_transformation(){
    geoTrans::init();
    glutMainLoop();
}

#endif