#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>


void rotacaoTriangulo(){
    glColor3f(0.93, 0.51, 0.93);
    glRotatef(45,0,0,1);
    glBegin(GL_TRIANGLES);
        glVertex2f(-5, 1);
        glVertex2f(-3, 1);
        glVertex2f(-4, 3);
    glEnd();
}

void rotacaoPoligono(){
    glColor3f(0.87, 0.19, 0.39);
    glRotatef(60,0,0,1);
    glBegin(GL_POLYGON);
        glVertex2f(3, 1);
        glVertex2f(4, 1);
        glVertex2f(5, 2);
        glVertex2f(4, 3);
        glVertex2f(3, 3);
        glVertex2f(2, 2);
    glEnd();
}

void poligono(){
    glColor3f(0.87, 0.19, 0.39);
    glBegin(GL_POLYGON);
        glVertex2f(3, 1);
        glVertex2f(4, 1);
        glVertex2f(5, 2);
        glVertex2f(4, 3);
        glVertex2f(3, 3);
        glVertex2f(2, 2);
    glEnd();
}

void triangulo(){
    glColor3f(0.93, 0.51, 0.93);
    glBegin(GL_TRIANGLES);
        glVertex2f(-5, 1);
        glVertex2f(-3, 1);
        glVertex2f(-4, 3);
    glEnd();
}

void cartesiano(){
    glLineWidth(1);
    glColor3f(0,0,0);
    glBegin(GL_LINES);
        glVertex2f(-6, 0);
        glVertex2f(6, 0);
        glVertex2f(0, -6);
        glVertex2f(0, 6);
    glEnd();
}


void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        cartesiano();
    glPopMatrix();

    glPushMatrix();
        triangulo();
    glPopMatrix();

    glPushMatrix();
        poligono();
    glPopMatrix();

    glPushMatrix();
        rotacaoPoligono();
    glPopMatrix();

    glPushMatrix();
        rotacaoTriangulo();
    glPopMatrix();

	glFlush();
}

int main(void){

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
    glutCreateWindow("Introdução ao OpenGL");
    glutDisplayFunc(desenhaObjetos);
    glClearColor(1,1,1,0);
    glutMainLoop();
    return 0;
}
