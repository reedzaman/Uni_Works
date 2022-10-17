#include <windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>

#else
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glext.h>

#endif

//#include <GL/freeglut.h>
//#include <GL/gl.h>
#include <stdlib.h>
#include <math.h>


double cPosition = 0.0;
float cl = 1.0;
float cl_0 = 1.0;
float cl_1 = 0.8;


void init()
{
    glClearColor(0.5, 0.8 , 0.91, 0);
    glOrtho(-600, 600, -600, 600, -600, 600);
}


void circle(double x, double y, double r){
    glBegin(GL_POLYGON);

    for( float i = 0; i < 10; i+= 0.1){
        glVertex2d(x + r * cos(i), y+r*sin(i));
    }
    glEnd();
}


void cloud(){
    glPushMatrix();
    glTranslated(cPosition, 0, 0);

    glPushMatrix();

        glColor3f(cl, cl, cl);
        circle(0,30,100);
        circle(100, -50, 100);
        circle(-100, -50, 90);
        circle(0, -100, 80);





        /*glColor3f(1, 1, 1);
        glTranslated(cPosition, 100, 0);
        circle(0, 0, 100);
        circle(0, -100, 80);
        circle(100, -50, 100);
        */

    glPopMatrix();

    glPopMatrix();

}

void cloudMoveLeft(){
    cPosition -= 1;
    if ( cPosition < -780){
        cPosition = 780;
    }
    glutPostRedisplay();
}

void cloudMoveRight(){
    cPosition += 1;
    if ( cPosition > 780){
        cPosition = -780;
    }
    glutPostRedisplay();
}

void mouseKey(int button, int state, int x, int y){
    switch(button){
    case GLUT_LEFT_BUTTON:
        if(state == GLUT_DOWN){
            glutIdleFunc(cloudMoveLeft);
        }
        else if(state == GLUT_UP){
            glutIdleFunc(NULL);
            glutPostRedisplay();
        }
        break;

    case GLUT_RIGHT_BUTTON:
        if(state == GLUT_DOWN){
            glutIdleFunc(cloudMoveRight);
        }
        else if(state == GLUT_UP){
            glutIdleFunc(NULL);
            glutPostRedisplay();
        }
        break;

    default:
        break;
    }
}

void myDisplay()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0, 0, 0);



    glColor3f(1, 1, 1);
    cloud();

        glColor3f(0.0, 0.5, 0.9);
        glBegin(GL_POLYGON);
            glVertex2d(0,0);
            glVertex2d(150,0);
            glVertex2d(100,-300);
            glVertex2d(120,-300);
            glVertex2d(80,-600);
            glVertex2d(100,-300);
        glEnd();
    glFlush();

}

void keyBoardKey(unsigned char key, int x, int y){
    switch(key){
    case 'a':
        cl = cl_1;
        glutPostRedisplay();
        break;
    case 'b':
        cl = cl_0;
        glutPostRedisplay();
        break;
    case 'c':
        break;
    default:
        break;
    }
}

int main(int argc, char **argv)
{

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(600, 600);
    glutInitWindowPosition(10, 10);

    glutCreateWindow("This is a practice glut program by Reed Zaman");
    init();

    glutDisplayFunc(myDisplay);
    glutMouseFunc(mouseKey);
    glutKeyboardFunc(keyBoardKey);

    glutMainLoop();

    return 0;
}
