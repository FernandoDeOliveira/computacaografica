#ifndef FULFILLMENT_H
#define FULFILLMENT_H
#include <GL/freeglut.h>
#include <stdlib.h>

GLfloat r, g, b;
GLubyte tux[] = {
    0x0, 0xff, 0xff, 0x0,
    0x0, 0xf0, 0xf, 0x0,
    0x0, 0xf0, 0xf, 0x0,
    0x0, 0xf0, 0xf, 0x0,
    0x0, 0xf0, 0xf, 0x0,
    0x0, 0xf0, 0xf, 0x0,
    0x0, 0xf0, 0xf, 0x0,
    0x0, 0xf0, 0xf, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0xff, 0xff, 0x0,
    0x0, 0xf0, 0x0, 0x0,
    0x0, 0xf0, 0x0, 0x0,
    0x0, 0xf0, 0x0, 0x0,
    0x0, 0xf0, 0x0, 0x0,
    0x0, 0xf0, 0x0, 0x0,
    0x0, 0xf0, 0x0, 0x0,
    0x0, 0xf0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
    0x0, 0x0, 0x0, 0x0,
};

namespace fulfill {
    int window;
    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT);
        glDisable(GL_POLYGON_STIPPLE);

        glPolygonMode(GL_BACK, GL_LINE);
        glColor3f(1.0, 1.0, 0.0);
        glBegin(GL_POLYGON);
        glVertex2i(30, 226);
        glVertex2i(113, 226);
        glVertex2i(113, 143);
        glVertex2i(30, 143);
        glEnd();

        glPolygonMode(GL_BACK, GL_FILL);
        glColor3f(1.0, 0.0, 1.0);
        glBegin(GL_POLYGON);
        glVertex2i(143, 226);
        glVertex2i(226, 226);
        glVertex2i(226, 143);
        glVertex2i(143, 143);
        glEnd();

        glBegin(GL_POLYGON);
        glColor3f(r, g, b);
        glVertex2i(30, 113);
        glColor3f(0.0, 1.0, 0.0);
        glVertex2i(113, 113);
        glColor3f(0.0, 0.0, 1.0);
        glVertex2i(113, 30);
        glColor3f(1.0, 1.0, 0.0);
        glVertex2i(30, 30);
        glEnd();

        glEnable(GL_POLYGON_STIPPLE);
        glColor3f(1.0, 0.0, 1.0);
        glPolygonStipple(tux);
        glBegin(GL_POLYGON);
        glVertex2i(143, 113);
        glVertex2i(226, 113);
        glVertex2i(226, 30);
        glVertex2i(143, 30);
        glEnd();
        glFlush();
        glutSwapBuffers();
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case 27:
                printf("Fim do preenchimento.");
                glutDestroyWindow(fulfill::window);
                break;
        }
    }

    void changeColor(int button, int state, int x, int y) {
        switch (button) {
            case GLUT_LEFT_BUTTON:
                if (state == GLUT_DOWN && ((30<=x) && (x<=113)) && ((145<=y) && (y<=226))) {
                    r = (GLfloat) rand() / (RAND_MAX + 1.0);
                    g = (GLfloat) rand() / (RAND_MAX + 1.0);
                    b = (GLfloat) rand() / (RAND_MAX + 1.0);
                    glutPostRedisplay();
                }
                break;
        }
    }

    void init(void) {
        glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
        glutInitWindowSize(256, 256);
        glutInitWindowPosition(100, 100);
        fulfill::window = glutCreateWindow("Preenchendo regiões");

        glClearColor(1.0, 1.0, 1.0, 1.0);
        glOrtho(0, 256, 0, 256, -1, 1);
        r = 0; g = 1; b = 0;

        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
        glutMouseFunc(changeColor);
    }
}

void fulfillment() {
    fulfill::init();
    glutMainLoop();
}



#endif /* FULFILLMENT_H */

