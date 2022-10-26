#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>

GLfloat escala=1;
GLfloat rotacao=0;
GLfloat movex = -50, movey = 20;
int velo = 40;
int max = -45;
int cont = 0;


GLint direcao = 1;   // para saber a dire��o do ponto no eixo y (+ ou -)

void timerPonto(int passo){


    if (direcao == 1){
       movex += 0.3;
       movey-=1;
        if(movey == -54 ){
            direcao = 2;
        }
    } else if(direcao == 2){
        movex += 0.3;
        movey += 1;
        if(movey == max){
            direcao = 1;
        }
    }

    if(cont == 2){
        velo = 25;
    }
    if(cont == 100){
        velo = 35;
        max = -50;
    }
    cont++;
    glutPostRedisplay();

    if(movex <= -15){
         glutTimerFunc(velo,timerPonto,1);
    }

}

void quadrado(){
    glPointSize(30);                   //adiciona espessura do ponto
    glBegin(GL_POINTS);                //glBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glColor3f(1,0,1);              //adiciona cor
        glVertex2f(movex, movey);       //desenha um ponto na coordenada x, y, onde y vai ser a vari�vel que criamos para deslocar o ponto neste eixo
    glEnd();
}

void teclado(unsigned char tecla, GLint x, GLint y){
   if(tecla == 'a'){
     glutTimerFunc(25,timerPonto,1);
   }
}

void desenhaObjetos(){

 glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-60,60,-60,60);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    quadrado();
    glPopMatrix();


	glutSwapBuffers();

}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,650);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
	glutCreateWindow("Exemplo Timer");
    glutDisplayFunc(desenhaObjetos);
    glutTimerFunc(10,timerPonto,1);
    glutKeyboardFunc(teclado);
    glClearColor(0.99,0.91,0.06,0);
    glutMainLoop();
    return 0;
}
