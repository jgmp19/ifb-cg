#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

float beta = 0;
float delta = 1	;
float stepx = 0.0;
float stepy = 0.0;

void init(void)
{
	glClearColor(0, 0, 0, 0); //define a cor de fundo
	gluOrtho2D(-200, 200, -200, 200);
}


void display(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glPushMatrix();
	glScalef(delta, delta, 1.0);
	glTranslatef(stepx,stepy,1);
	glRotatef(beta, 0, 0, 1);
	// Draw a Red 1x1 Square centered at origin
	glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
		 glColor3f(1.0f, 0.0f, 0.0f); // Red
		 glVertex2f(-10.0f, -10.0f);    // x, y
		 glVertex2f( 10.0f, -10.0f);
		 glVertex2f( 10.0f,  10.0f);
		 glVertex2f(-10.0f,  10.0f);
	glEnd();
	glPopMatrix();
	glFlush();
}

void scale(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP: //faz zoom − in
  	delta *= 1.1;
		break;
	case GLUT_KEY_DOWN: //faz zoom − out
    delta *= 0.9;
		break;
	}
	//forçar o redesenho da tela usando double − buffering
	glutPostRedisplay();
	glFlush();
}

void rotate(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP: //gira sobre o eixo − y
		beta += 1.0;
		break;
	case GLUT_KEY_DOWN: //gira sobre o eixo − y
		beta -= 1.0;
		break;
	}
	glutPostRedisplay();
}

void translate(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
		stepy = stepy + 2.0;
		printf("\n stepy = %f",stepy);
		break;
	case GLUT_KEY_DOWN:
		stepy = stepy - 2.0;
		printf("\n stepy = %f",stepy);
		break;
	case GLUT_KEY_LEFT:
		stepx = stepx - 2.0;
		printf("\n stepx = %f",stepx);
		break;
	case GLUT_KEY_RIGHT:
		stepx = stepx + 2.0;
		printf("\n stepx = %f",stepx);
		break;
	}
	glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y)
{
	// ' q ' ou ' Q ' ou ESC para sair do sistema
	if ('q' == key || 'Q' == key || 27 == key)
	{
		exit(0);
	}
	if ('t' == key || 'T' == key) {
		glutSpecialFunc(translate);
	}
	if ('r' == key || 'R' == key) {
		glutSpecialFunc(rotate);
	}
	if ('s' == key || 'S' == key) {
		glutSpecialFunc(scale);
	}
	if ('m' == key || 'M' == key) {
		glRotatef(180.0f,0,1,0);
		glutPostRedisplay();
	}
	if('i' ==  key || 'I' == key){
		stepx = 0;
		stepy = 0;
		beta = 0;
		delta = 1;
		printf("Chegou aqui\n");
		glutPostRedisplay();
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(400, 350);
	glutCreateWindow("Trabalho");
	init();
	//funções de callback
	glutDisplayFunc(display); //registra função de desenho
	glutKeyboardFunc(keyboard); //registra teclado
	glutMainLoop();
	return 0;
}
