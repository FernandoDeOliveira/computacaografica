#include <stdlib.h>
#include <stdio.h>
#include <GL/freeglut.h>
#include <string>
using namespace std;

#include "fulfillment.h"

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
        drawTxtBmp(10, 240, GLUT_BITMAP_TIMES_ROMAN_24, "1-Introducao.");
        drawTxtBmp(120, 240, GLUT_BITMAP_TIMES_ROMAN_24, "2-Preenchimento.");
        drawTxtBmp(10, 220, GLUT_BITMAP_TIMES_ROMAN_24, "3-Transformacoes geometricas.");
        drawTxtBmp(120, 220, GLUT_BITMAP_TIMES_ROMAN_24, "4-Animacao braco.");
        drawTxtBmp(10, 200, GLUT_BITMAP_TIMES_ROMAN_24, "5-Animacao pinball.");
        drawTxtBmp(120, 200, GLUT_BITMAP_TIMES_ROMAN_24, "6-Mao.");
        drawTxtBmp(10, 180, GLUT_BITMAP_TIMES_ROMAN_24, "7-Iluminacao.");
        drawTxtBmp(120, 180, GLUT_BITMAP_TIMES_ROMAN_24, "8-Colisao.");
        drawTxtBmp(10, 160, GLUT_BITMAP_TIMES_ROMAN_24, "9-Fonte.");
        drawTxtBmp(120, 160, GLUT_BITMAP_TIMES_ROMAN_24, "a-Textura.");
        drawTxtBmp(10, 140, GLUT_BITMAP_TIMES_ROMAN_24, "b-Curva.");
        drawTxtBmp(120, 140, GLUT_BITMAP_TIMES_ROMAN_24, "c-Superfície Bezier Grid.");
        drawTxtBmp(10, 120, GLUT_BITMAP_TIMES_ROMAN_24, "d-Superfície Bezier Mesh.");
        drawTxtBmp(120, 120, GLUT_BITMAP_TIMES_ROMAN_24, "e-Malha de poligonos-MUITO INTERESSANTE.");
        drawTxtBmp(10, 100, GLUT_BITMAP_TIMES_ROMAN_24, "f-Blending.");
        drawTxtBmp(120, 100, GLUT_BITMAP_TIMES_ROMAN_24, "g-Transparencia.");
        drawTxtBmp(10, 80, GLUT_BITMAP_TIMES_ROMAN_24, "h-Neblina.");
        drawTxtBmp(120, 80, GLUT_BITMAP_TIMES_ROMAN_24, "ESC-Finalizar.");
        glFlush();
    }

    void keyboard(unsigned char key, int x, int y) {
        switch (key) {
            case '2': fulfillment();
                break;

            case 27:printf("Finalizando PROGRAMA.");
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