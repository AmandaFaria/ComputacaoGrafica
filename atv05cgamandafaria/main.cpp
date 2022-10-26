#include <GL/glut.h>

#include <math.h>

#include <GL/gl.h>

GLint movePontoY = 0; //para mover o ponto em incrementais (1 em 1)
GLint movePontoX = 0;   // para saber a dire��o do ponto no eixo y (+ ou -)
GLint direcaoY = 1;   // para saber a dire��o do ponto no eixo y (+ ou -)
GLint direcaoX = 0;   // para saber a dire��o do ponto no eixo y (+ ou -)

void timerPonto(int passo) {                //fun��o timerPonto, que verifica o local do ponto para saber quando deve parar de subir (ou descer) o ponto no eixo y
    if (direcaoY == 1) {                     //se a dire��o for 1, o ponto sobre, se for -1 ele desce
        movePontoY += 1;
        if (movePontoY == 6) {               //se move ponto for igual ao nosso limite superior m�ximo no eixo y+
            direcaoY = 0;                  // come�a a descer no eixo y, quando chegar no limite de 90y
            direcaoX = 1;
        }
    }
    else if (direcaoY == -1) {
        movePontoY -= 1;                     //decrementa nosso moveponto at� o limite estipulado
        if (movePontoY == 0) {             //se move ponto for igual ao nosso limite inferior m�ximo no eixo y-
            direcaoY = 0;                  //come�a a subir no eixo y, quando chegar no limite de -90y
            direcaoX = -1;
        }
    }
    else if (direcaoX == 1) {
        movePontoX += 1;
        if (movePontoX == 6) {
            direcaoY = -1;
            direcaoX = 0;
        }
    }
    else if (direcaoX == -1) {
        movePontoX -= 1;
        if (movePontoX == 4) {
            direcaoY = 1;
            direcaoX = 0;
        }
    }

    glutPostRedisplay();                 //chama a fun��o desenha toda vez que for necess�ria
    glutTimerFunc(500, timerPonto, 1);      //precisamos chamar a fun��o timer toda vez, Ele executa essa fun��o timer e entra aqui novamente. At� eu querer sair da fun��o timer (neste caso, n�o queremos sair)
}


void pontoY() {
    glPointSize(20);                   //adiciona espessura do ponto
    glBegin(GL_POINTS);                //glBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
    glColor3f(1,0,1);              //adiciona cor
    glVertex2f(movePontoX, movePontoY);       //desenha um ponto na coordenada x, y, onde y vai ser a vari�vel que criamos para deslocar o ponto neste eixo
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


void desenhaObjetos(void) {
    glClear(GL_COLOR_BUFFER_BIT);      //buffer padr�o (limpa a tela toda vez que a fun��o � chamada)

    glMatrixMode(GL_PROJECTION);       //proje��o dos pontos definidos no plano cartesiano
    glLoadIdentity();                  //carrega a proje��o
    gluOrtho2D(0,10,0,10);     // define o tamanho do plano cartesiano
    glMatrixMode(GL_MODELVIEW);        // proje��o do tipo modelo
    glLoadIdentity();                  // carrega a identidade de proje��o de modelo

    glPushMatrix();                   //insere a matriz de transforma��o corrente na pilha
    rua1();
    rua2();
    linhas();
    pontoY();
    glPopMatrix();

                       //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    glutSwapBuffers();                 //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers de)
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);                    //double buffer, pois single ficaria piscando, uma vez que ele tem que desenhar e redesenhar | sistema de cores RGB
    glutInitWindowSize(800, 600);                                    //define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 960) / 2,
        (glutGet(GLUT_SCREEN_HEIGHT) - 540) / 2);    //medidas usadas para posicionar a janela no meio da tela - isso depende da resolu��o do monitor
    glutCreateWindow("Exemplo Timer");                              //permite a cria��o de uma janela
    glutDisplayFunc(desenhaObjetos);                                //fun��o de callback - chama a fun��o desenhaObjetos
    glutTimerFunc(500, timerPonto, 1);                                 // tr�s valores dispon�veis (tempo (milissegundos) a o nome da fun��o e valor padr�o para retorno)
    glClearColor(0,1,0,0);                                          //informa a cor de fundo da tela (branco)
    glutMainLoop();                                                 //loop infinito - escuta as informa��es do sistema at� encerrar a aplica��o
    return 0;
}
