#include <windows.h>  // for MS Windows
#include <GL/glut.h>  // GLUT, include glu.h and gl.h
#include<math.h>>
#include<iostream>
using namespace std;
#define PI acos(-1)


/* Handler for window-repaint event. Call back when the window first appears and
whenever the window needs to be re-painted. */
GLdouble c1=0.0;GLdouble c2=0.0;
void circle(GLfloat x, GLfloat y, GLfloat radius);
void drawCircle(GLdouble x, GLdouble y, GLfloat r, GLint steps);
void initGL()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void Idle()
{
    glutPostRedisplay();//// marks the current window as needing to be redisplayed
}
void reshape(GLsizei width, GLsizei height) {  // GLsizei for non-negative integer
   // Compute aspect ratio of the new window
   if (height == 0) height = 1;                // To prevent divide by 0
   GLfloat aspect = (GLfloat)width / (GLfloat)height;

   // Set the viewport to cover the new window
   glViewport(0, 0, width, height);

   // Set the aspect ratio of the clipping area to match the viewport
   glMatrixMode(GL_PROJECTION);  // To operate on the Projection matrix
   glLoadIdentity();             // Reset the projection matrix
   if (width >= height) {
     // aspect >= 1, set the height from -1 to 1, with larger width
      gluOrtho2D(-1.0 * aspect, 1.0 * aspect, -1.0, 1.0);
   } else {
      // aspect < 1, set the width to -1 to 1, with larger height
     gluOrtho2D(-1.0, 1.0, -1.0 / aspect, 1.0 / aspect);
   }
}

void drawSritishowdho(GLfloat x , GLfloat y, GLfloat z){

    glLoadIdentity();//Reset the current matrix

    glPushMatrix();glTranslatef(x,y,z);

    //flagstand
    glBegin(GL_QUADS);
    glColor3ub(0,0,0);
    glVertex2f(-0.965,0);
    glVertex2f(-0.965,0.75);
    glVertex2f(-0.96,0.75);
    glVertex2f(-0.96,0);

    //greenFlag
    glBegin(GL_QUADS);
    glColor3ub(46,125,50);
    glVertex2f(-0.965,0.60);
    glVertex2f(-0.965,0.75);
    glVertex2f(-0.75,0.75);
    glVertex2f(-0.75,0.60);



    GLfloat i=0.143;
    GLfloat j=-1;
    GLfloat k=+1;
    int color=50;

    for(i;i<1;i+=0.143)
    {
        glBegin(GL_TRIANGLES);
        glColor3ub(color,color,color);
        glVertex2f(j,0);
        glVertex2f(0,i);
        glVertex2f(k,0);
        glEnd();
        j+=0.143;
        k-=0.143;
        color+=5;
    }
    glBegin(GL_TRIANGLES);
    glColor3ub(color,color,color);
    glVertex2f(-.1,0);
    glVertex2f(0,1);
    glVertex2f(.1,0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(70,70,70);
    glVertex2f(0,.2);
    glVertex2f(-.07,.3);
    glVertex2f(0,.4);
    glVertex2f(.07,.3);
    glEnd();
    //redcircle
    glColor3ub(198,40,40);
    drawCircle(-.8575,0.675,.055,100);
    glPopMatrix();
    //glFlush();
}


void display() {
    glClearColor(0.568, 0.788, 0.792, 1.0f); // Set background color to black and opaque
	glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer (background)
	glMatrixMode(GL_MODELVIEW);


	//clouds1
	glColor3ub(84,110,122);
    drawCircle(c1-0.6,.8,.12,100);
    drawCircle(c1-0.5,.8,.12,100);
    glColor3ub(96,125,139);
    drawCircle(c1-0.7,.8,.09,100);
    drawCircle(c1-0.6,.85,.12,100);

    //clouds2
    glColor3ub(96,125,139);
    drawCircle(c2+0.6,.6,.12,100);
    drawCircle(c2+0.5,.6,.09,100);
    glColor3ub(84,110,122);
    drawCircle(c2+0.7,.6,.09,100);
    drawCircle(c2+0.6,.65,.12,100);



    glBegin(GL_QUADS);
    glColor3ub(76,175,80);
    glVertex2f(-2,-2);
    glVertex2f(-2,-0.3);
    glVertex2f(2,-0.3);
    glVertex2f(2,-2);
    glEnd();

    glBegin(GL_QUADS);
    glColor3ub(121,85,72);
    glVertex2f(-2,-.4);
    glVertex2f(-2,-.3);
    glVertex2f(2,-0.3);
    glVertex2f(2,-.4);
    glEnd();
    glBegin(GL_QUADS);
    glColor3ub(141,110,99);
    glVertex2f(-2,-.4);
    glVertex2f(-2,-.5);
    glVertex2f(2,-0.5);
    glVertex2f(2,-.4);
    glEnd();


    drawSritishowdho(0,-0.3,0);
    //
    c1+=0.0001;
	if(c1>2.00)
    {
        c1=-1.00;
    }
    c2-=0.0001;
	if(c2<-2.00)
    {
        c2=1.00;
    }

    //gluOrtho2D(-2,2,-2,2);
	//cout<<x;
	glFlush();  // Render now
	//glFlush();  // Render now

	glutSwapBuffers();
}





void drawCircle(GLdouble x, GLdouble y, GLfloat r, GLint steps)
{
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(x,y);
    GLfloat angle;
    for(GLint i=0;i<=steps;++i)
    {
        angle = i *2.0f *PI / steps ;
        glVertex2f(cos(angle)*r+x,sin(angle)*r+y);

    }
    glEnd();
}

//3.141592653
/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
	glutInitWindowSize(600, 600);                // Initialize GLUT
	glutCreateWindow("OpenGL Flag Draw"); // Create a window with the given title
	   // Set the window's initial width & height
	glutDisplayFunc(display);
	initGL();
    glutIdleFunc(Idle); // Register display callback handler for window re-paint
    glutReshapeFunc(reshape);
	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
