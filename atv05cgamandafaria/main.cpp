#include <GL/glut.h>

#include <math.h>

#include <GL/gl.h>

GLint movePontoY = 0; //para mover o ponto em incrementais (1 em 1)
GLint movePontoX = 0;   // para saber a direção do ponto no eixo y (+ ou -)
GLint direcaoY = 1;   // para saber a direção do ponto no eixo y (+ ou -)
GLint direcaoX = 0;   // para saber a direção do ponto no eixo y (+ ou -)

void timerPonto(int passo) {                //função timerPonto, que verifica o local do ponto para saber quando deve parar de subir (ou descer) o ponto no eixo y
    if (direcaoY == 1) {                     //se a direção for 1, o ponto sobre, se for -1 ele desce
        movePontoY += 1;
        if (movePontoY == 6) {               //se move ponto for igual ao nosso limite superior máximo no eixo y+
            direcaoY = 0;                  // começa a descer no eixo y, quando chegar no limite de 90y
            direcaoX = 1;
        }
    }
    else if (direcaoY == -1) {
        movePontoY -= 1;                     //decrementa nosso moveponto até o limite estipulado
        if (movePontoY == 0) {             //se move ponto for igual ao nosso limite inferior máximo no eixo y-
            direcaoY = 0;                  //começa a subir no eixo y, quando chegar no limite de -90y
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

    glutPostRedisplay();                 //chama a função desenha toda vez que for necessária
    glutTimerFunc(500, timerPonto, 1);      //precisamos chamar a função timer toda vez, Ele executa essa função timer e entra aqui novamente. Até eu querer sair da função timer (neste caso, não queremos sair)
}


void pontoY() {
    glPointSize(20);                   //adiciona espessura do ponto
    glBegin(GL_POINTS);                //glBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
    glColor3f(1,0,1);              //adiciona cor
    glVertex2f(movePontoX, movePontoY);       //desenha um ponto na coordenada x, y, onde y vai ser a variável que criamos para deslocar o ponto neste eixo
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
    glClear(GL_COLOR_BUFFER_BIT);      //buffer padrão (limpa a tela toda vez que a função é chamada)

    glMatrixMode(GL_PROJECTION);       //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity();                  //carrega a projeção
    gluOrtho2D(0,10,0,10);     // define o tamanho do plano cartesiano
    glMatrixMode(GL_MODELVIEW);        // projeção do tipo modelo
    glLoadIdentity();                  // carrega a identidade de projeção de modelo

    glPushMatrix();                   //insere a matriz de transformação corrente na pilha
    rua1();
    rua2();
    linhas();
    pontoY();
    glPopMatrix();

                       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glutSwapBuffers();                 //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers de)
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);                    //double buffer, pois single ficaria piscando, uma vez que ele tem que desenhar e redesenhar | sistema de cores RGB
    glutInitWindowSize(800, 600);                                    //define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 960) / 2,
        (glutGet(GLUT_SCREEN_HEIGHT) - 540) / 2);    //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
    glutCreateWindow("Exemplo Timer");                              //permite a criação de uma janela
    glutDisplayFunc(desenhaObjetos);                                //função de callback - chama a função desenhaObjetos
    glutTimerFunc(500, timerPonto, 1);                                 // três valores disponíveis (tempo (milissegundos) a o nome da função e valor padrão para retorno)
    glClearColor(0,1,0,0);                                          //informa a cor de fundo da tela (branco)
    glutMainLoop();                                                 //loop infinito - escuta as informações do sistema até encerrar a aplicação
    return 0;
}
