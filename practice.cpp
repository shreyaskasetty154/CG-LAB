#ifdef __APPLE__
#include <GLUT/GLUT.h>
#else
#include <GL/glut.h>
#endif

#include<stdio.h>

void reshape( int w, int h )
{
  glViewport( 0 , 0 , w , h ); //tells in which part of the window should OpenGl draw.
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(60, (float ) w / (float) h, 1.0, 10.0);
  glMatrixMode(GL_MODELVIEW);
}
void initOpenGl()
{
//Color Channels-red, green, blue, alpha
  glClearColor( 1 , 1 , 1 , 1.0);
  glColor3f(1.0, 0.0, 0.0);
  glPointSize(3.0);
  gluOrtho2D(10, 500, 10, 500);
}
void display()
{
  glClear(GL_COLOR_BUFFER_BIT); //Overwrites the previous frame. It should always be at the beginning.
  glBegin(GL_TRIANGLE_FAN);
  glVertex2f(100,100);
  glVertex2f(100,150);
  glVertex2f(150,150);
  glVertex2f(150,100);
  glVertex2f(200,120);
  glEnd();
  glutSwapBuffers(); // Its telling OpenGL that its ready to draw on window. It should always be at the end.
}
int main(int argc,char** argv)
{
  glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(5, 5);
	glutCreateWindow("Bresenline");
	glutDisplayFunc(display);
	initOpenGl();
	glutMainLoop();
  return 0;
}
