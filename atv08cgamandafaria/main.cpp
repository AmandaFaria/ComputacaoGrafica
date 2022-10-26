#include <GL/gl.h>
#include <GL/glut.h>
#include<iostream>

using namespace std;


GLfloat r = 0, g = 0, b = 0;
int submenucor, submenuForma;
int cond = 0;

int disp[2][4] = {
    {0, 0, 107, 107},
    {30, 80, 80, 30}
};

void quadrado(){

    glBegin(GL_QUADS);
                glVertex2i(disp[0][0], disp[1][0]);
                glVertex2i(disp[0][1], disp[1][1]);
                glVertex2i(disp[0][2], disp[1][2]);
                glVertex2i(disp[0][3], disp[1][3]);
    glEnd();


}

void desenhaObjeto(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
       gluOrtho2D(0,800,600,0);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glColor3f(r, g, b);
    glPushMatrix();


        quadrado();
    glPopMatrix();

 	glutSwapBuffers();
}

void escolheCor(int opcao){
    switch(opcao){
        case 0:
            r = 1;
            g = 0;
            b = 0;
        break;
        case 1:
            r = 0;
            g = 1;
            b = 0;
        break;
        case 2:
            g = 0;
            b = 1;
        break;
    }
    glutPostRedisplay();
}

void escolheForma(int opcao){
    switch(opcao){
        case 3:
            disp[0][0] = 323;
            disp[1][0] = 228;
            disp[0][1] = 323;
            disp[1][1] = 343;
            disp[0][2] = 430;
            disp[1][2] = 343;
            disp[0][3] = 430;
            disp[1][3] = 228;
        break;
        case 4:
            disp[0][0] = 376;
            disp[1][0] = 228;
            disp[0][1] = 323;
            disp[1][1] = 343;
            disp[0][2] = 430;
            disp[1][2] = 343;
            disp[0][3] = 376;
            disp[1][3] = 228;
        break;
        case 5:

            disp[0][0] = 373;
            disp[1][0] = 192;
            disp[0][1] = 455;
            disp[1][1] = 280;
            disp[0][2] = 365; //
            disp[1][2] = 360;
            disp[0][3] = 278;
            disp[1][3] = 270;

        break;
    }
    glutPostRedisplay();
}

void menuCor(){
    submenucor = glutCreateMenu(escolheCor);
    glutAddMenuEntry("Vermelho", 0);
    glutAddMenuEntry("Verde", 1);
    glutAddMenuEntry("Azul", 2);
}


void menuForma(){
    submenuForma = glutCreateMenu(escolheForma);
    glutAddMenuEntry("Quadrado", 3);
    glutAddMenuEntry("Triangulo", 4);
    glutAddMenuEntry("Losangulo", 5);
}


void criaMenu(){
    menuCor();
    menuForma();
    glutCreateMenu(0);
    glutAddSubMenu("Escolha a Cor", submenucor);
    glutAddSubMenu("Escolha a forma", submenuForma);
    glutAttachMenu(GLUT_RIGHT_BUTTON);

}

void gerenciaMouse(int botao, int estado, int x, int y){
    if(botao == GLUT_RIGHT_BUTTON)
        if(estado == GLUT_DOWN){
            criaMenu();
        }
    glutPostRedisplay();
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(320,150);
	glutCreateWindow("Função Menu - Interação");
    glutDisplayFunc(desenhaObjeto);
    glutMouseFunc(gerenciaMouse);
    glClearColor(1,1,1,0);
    glutMainLoop();
    return 0;
}
