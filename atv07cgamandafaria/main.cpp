#include <GL/gl.h>
#include <GL/glut.h>

int movex = 0, movey = 0;

void ponto(){
    glPointSize(20);
    glBegin(GL_POINTS);
        glColor3f(0.93, 0.51, 0.93);
        glVertex2f(movex,movey);
    glEnd();
}

void triangulo(){
    glPointSize(20);
    glColor3f(0.93, 0.51, 0.93);
    glBegin(GL_TRIANGLES);
        glVertex2d(movex, movey);
    glEnd();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,600,600,0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        ponto();
        //triangulo();
    glPopMatrix();

glutSwapBuffers();
}

void movimentaMouse (int x, int y){
    movex = x;
    movey = y;
    glutPostRedisplay();
}


void gerenciaMouse (int botao, int estado, int x, int y){
    if (botao == GLUT_LEFT_BUTTON)
    if (estado == GLUT_DOWN){
        movex = 10;
        movey = 10;
    }

    if (botao == GLUT_RIGHT_BUTTON)
    if (estado == GLUT_DOWN){
        movex = 590;
        movey = 10;
    }

    if (botao == GLUT_MIDDLE_BUTTON)
    if (estado == GLUT_DOWN){
        glutDisplayFunc(triangulo);
    }else if(estado == GLUT_UP){
        ponto();
    }

glutPostRedisplay();
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(320,150);
        glutCreateWindow("Funcao Mouse - Interacao");
    glutDisplayFunc(desenhaObjetos);
    glutMouseFunc(gerenciaMouse);
    glClearColor(1,1,1,0);
    glutMainLoop();
return 0;
}
