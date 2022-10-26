#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>

GLfloat escala = 1;
GLfloat rotacao = 0;
GLfloat movex = 0, movey = 0;


void teclas(unsigned char tecla, GLint x, GLint y){
    switch(tecla){
        case '+': escala+=0.3;
        break;
        case '-': escala-=0.3;
        break;
        case 'a': rotacao-=3;
        break;
        case 's': rotacao+=3;
    }
    glutPostRedisplay();
}

void setasDirecionais(GLint tecla, GLint x, GLint y){
    switch(tecla){
        case GLUT_KEY_LEFT: movex-=1;
        break;
        case GLUT_KEY_RIGHT: movex+=1;
        break;
        case GLUT_KEY_UP: movey+=1;
        break;
        case GLUT_KEY_DOWN: movey-=1;
        break;
    }
    glutPostRedisplay();
}

void carro(){
    glColor3f(0.87,0.63,0.87);

    glBegin(GL_QUADS);
        glVertex2f(1, 5.2);
        glVertex2f(2, 5.2);
        glVertex2f(2, 5.8);
        glVertex2f(1, 5.8);

    glEnd();
}


void linhas(){
    glLineWidth(5);
    glColor3f(1, 1, 0);

    glBegin(GL_LINE_STRIP);
        glVertex2f(1, 5);
        glVertex2f(2, 5);
        glVertex2f(3, 5);
        glVertex2f(4, 5);
        glVertex2f(5, 5);
        glVertex2f(5, 4);
        glVertex2f(5, 3);
        glVertex2f(5, 2);
        glVertex2f(5, 1);
    glEnd();
}


void rua2(){
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(4, 4);
        glVertex2f(4, 0);
        glVertex2f(6, 0);
        glVertex2f(6, 4);
    glEnd();
}

void rua1(){
    glColor3f(0, 0, 0);
    glBegin(GL_QUADS);
        glVertex2f(0, 4);
        glVertex2f(6, 4);
        glVertex2f(6, 6);
        glVertex2f(0, 6);
    glEnd();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,10,0,10);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        rua1();
    glPopMatrix();

    glPushMatrix();
        rua2();
    glPopMatrix();

    glPushMatrix();
        linhas();
    glPopMatrix();

    glPushMatrix();
        glScalef(escala, escala, 0);
        glRotatef(rotacao, 0,0,1);
        glTranslatef(movex, movey,0);
        carro();
    glPopMatrix();

    glFlush();

}

int main(void){

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
    glutCreateWindow("Introdução ao OpenGL");
    glutDisplayFunc(desenhaObjetos);
    glutKeyboardFunc(teclas);
    glutSpecialFunc(setasDirecionais);
    glClearColor(0,1,0,0);
    glutMainLoop();
    return 0;
}
