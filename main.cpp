#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>
#include <string>
using namespace std;

#include "fulfillment.h"
#include "geometric_transformation.h"

namespace principal {
#define sair 0
    int window;

    void drawTxtBmp(int x, int y, void *fonte, string texto) {
        glRasterPos2f(x, y);
        for(int i=0;i<texto.length();i++)
            glutBitmapCharacter(fonte, texto.at(i));
    }

    void display(void) {
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(0.0, 0.0, 0.0);
        drawTxtBmp(10, 240, GLUT_BITMAP_TIMES_ROMAN_24, "1-Preenchimento.");
        drawTxtBmp(120, 240, GLUT_BITMAP_TIMES_ROMAN_24, "2-Transformacoes geometricas.");
        drawTxtBmp(120, 80, GLUT_BITMAP_TIMES_ROMAN_24, "ESC-Finalizar.");
        glFlush();
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case '1': fulfillment();
                break;
            
            case '2': geometric_transformation();
                break;

            case 27: printf("Finalizando PROGRAMA.");
                exit(0);
                break;
        }
    }

    void init(void) {
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(1024, 768);
        glutInitWindowPosition(100, 100);
        window = glutCreateWindow("Menu principal");
        glClearColor(1.0, 1.0, 1.0, 1.0);
        glOrtho(0, 256, 0, 256, -1, 1);
        glutDisplayFunc(display);
        glutKeyboardFunc(keyboard);
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    principal::init();
    glutMainLoop();
    return (0);
}