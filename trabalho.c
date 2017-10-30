#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

float beta = 0;
float delta = 1	;
float stepx = 0.0;
float stepy = 0.0;
int pressed = 0;

void init(void)
{
	glClearColor(0, 0, 0, 0); 
	gluOrtho2D(-200, 200, -200, 200);
}

void display(void)
{
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); 
	glClear(GL_COLOR_BUFFER_BIT);         
	if ((stepy > 0) && (pressed == 1)){
		glRotatef(-180.0f,1,1,0);
	}
	else if((stepy < 0) && (pressed == 1)	){
		glRotatef(180.0f,1,1,0);
	}
	pressed = 0;
	glPushMatrix();
	glTranslatef(stepx,stepy,1.0);
	glScalef(delta, delta, 1.0);
	glRotatef(beta, 0, 0, 1);
	glBegin(GL_QUADS);              
		 glColor3f(0.5f, 0.2f, 0.5f); 
		 glVertex2f(-20.0f, -20.0f);    
		 glVertex2f( 20.0f, -20.0f);
		 glVertex2f( 20.0f,  20.0f);
		 glVertex2f(-20.0f,  20.0f);
	glEnd();
	glPopMatrix();
	glFlush();
}

void scale(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP:
  		delta *= 1.1;
		break;
	case GLUT_KEY_DOWN: 
    		delta *= 0.9;
		break;
	}
	glutPostRedisplay();
}

void rotate(int key, int x, int y)
{
	switch (key)
	{
	case GLUT_KEY_UP: 
		beta += 1.0;
		break;
	case GLUT_KEY_DOWN: 
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
		pressed = 1;
		glutPostRedisplay();
	}
	if('i' ==  key || 'I' == key){
		stepx = 0;
		stepy = 0;
		beta = 0;
		delta = 1;
		glutPostRedisplay();
	}
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
	glutInitWindowSize(400, 400);
	glutCreateWindow("Trabalho");
	init();
	glutDisplayFunc(display); 
	glutKeyboardFunc(keyboard);
	glutMainLoop();
	return 0;
}
