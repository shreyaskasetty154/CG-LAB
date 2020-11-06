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
  glClearColor( 0.0 , 0.0 , 0.0 , 1.0);
  glEnable(GL_DEPTH_TEST);
  glDepthFunc( GL_LEQUAL );
}
int counter = 0;
void display()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //Overwrites the previous frame. It should always be at the beginning.
  glLoadIdentity();

  glTranslatef(counter/150.0,0.0,-4.0);
  glRotatef(counter, 0.0, 1.0, 0.0);
  counter+=1.5;
  if(counter > 220)
  counter = -220;
  glBegin(GL_TRIANGLES);
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(-0.5,-0.5,0.0);

  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(0.5, -0.5, 0.0);

  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(0.0, 0.5, -2.0);
  glEnd();

  glLoadIdentity();
  glTranslatef(0.0,-0.5,-4.0);
  glRotatef(30,0.0,1.0,0.0);
  glBegin(GL_TRIANGLES);
  glColor3f(0.0, 1.0, 0.0);
  glVertex3f(-0.5,-0.5,0.0);

  glColor3f(1.0, 0.0, 0.0);
  glVertex3f(0.5, -0.5, 0.0);

  glColor3f(0.0, 0.0, 1.0);
  glVertex3f(0.0, 0.5, 0.0);
  glEnd();
  glutSwapBuffers(); // Its telling OpenGL that its ready to draw on window. It should always be at the end.
}
int main(int argc,char** argv)
{
  // Start up the GLUT system
  glutInit( &argc, argv);
  //Initialise the Display mode
  glutInitDisplayMode(GLUT_DOUBLE /*Double buffering*/ | GLUT_RGBA /*Color type- RGB with alpha*/ | GLUT_DEPTH /* 3D or 2D- now its 3D*/);
  glutInitWindowSize(500 , 500); //Initialise the Window size
  glutInitWindowPosition(100, 100); //Initialise Position from the top left corner
  glutCreateWindow("Program for practice"); //Create a window and give it a name
  //Callback function telling GLUT what to do in each frame  or Loop
  initOpenGl();
  glutReshapeFunc( reshape );
  glutDisplayFunc( display );
  glutIdleFunc( display );
   // This is called whenever window is created and when window size changed.
  glutMainLoop();
  return 0;
}
