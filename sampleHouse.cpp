#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

/*
 * Adaptado de:
 *   https://github.com/mdrkb/3D-House-using-OpenGL-and-C-/blob/master/main.cpp
*/

#define AZUL     0.0, 0.0, 1.0
#define VERMELHO 1.0, 0.0, 0.0
#define AMARELO  1.0, 1.0, 0.0
#define VERDE    0.0, 1.0, 0.0
#define CYAN     1.0, 0.0, 1.0
#define LARANJA  0.8, 0.6, 0.1
#define ROSEO    0.7, 0.1, 0.6
#define CINZA    0.6, 0.6, 0.6

static GLfloat vertices[30]={
  0.0,  30.0, 30.0, /* 0 */
  20.0, 30.0, 30.0, /* 1 */
  30.0, 20.0, 30.0, /* 2 */
  30.0,  0.0, 30.0, /* 3 */
  0.0,   0.0, 30.0, /* 4 */
  0.0,  30.0,  0.0, /* 5 */
  30.0, 30.0,  0.0, /* 6 */
  30.0,  0.0,  0.0, /* 7 */
  0.0,   0.0,  0.0, /* 8 */
  30.0, 30.0, 20.0  /* 9 */
}; 

static GLubyte frenteIndices[]    = {0,4,3,2,1};
static GLubyte trasIndices[]      = {5,6,7,8};
static GLubyte esquerdaIndices[]  = {0,5,8,4};
static GLubyte direitaIndices[]   = {2,3,7,6,9};
static GLubyte topoIndices[]      = {0,1,9,6,5};
static GLubyte fundoIndices[]     = {3,4,8,7};
static GLubyte trianguloIndices[] = {1,2,9};
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;

// XZ position of the camera
float x=0.0f,z=7.0f;

float door_angle = 0.0f;

// angle for rotating
float angle = 0.0f;

void init(void) {
    // sky color
    glClearColor(0.0, 0.7, 1.0, 1.0);
}

void drawHouse(){

    // Front side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
    glColor3f(0.0f, 0.0f, 0.65f);

        glBegin(GL_QUADS);  // Wall
            glVertex3f(0.3,0,1);
            glVertex3f(2,0,1);
            glVertex3f(2,-1.5,1);
            glVertex3f(0.3,-1.5,1);
        glEnd();

        glBegin(GL_QUADS);  // Wall
            glVertex3f(-2,0,1);
            glVertex3f(-0.3,0,1);
            glVertex3f(-0.3,-1.5,1);
            glVertex3f(-2,-1.5,1);
        glEnd();

        glBegin(GL_QUADS);  // Wall
		glVertex3f(0.3, 0, 1);
		glVertex3f(-0.3, 0, 1);
		glVertex3f(-0.3, -0.25, 1);
		glVertex3f(0.3,-0.25, 1);
	glEnd();

        glColor3f(0.4f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Roof
            glVertex3f(-2.2,0.5,0);
            glVertex3f(2.2,0.5,0);
            glVertex3f(2.2,-0.1,1.25);
            glVertex3f(-2.2,-0.1,1.25);
        glEnd();

        glColor3f(0.7f, 0.7f, 0.0f);
        glBegin(GL_QUADS);  // Window Left
            glVertex3f(-1.5,-0.3,1.0001);
            glVertex3f(-0.75,-0.3,1.0001);
            glVertex3f(-0.75,-0.8,1.0001);
            glVertex3f(-1.5,-0.8,1.0001);
        glEnd();

        glBegin(GL_QUADS);  // Window Right
            glVertex3f(1.5,-0.3,1.0001);
            glVertex3f(0.75,-0.3,1.0001);
            glVertex3f(0.75,-0.8,1.0001);
            glVertex3f(1.5,-0.8,1.0001);
        glEnd();
    glPopMatrix();

    // Back side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.65f);
        glBegin(GL_QUADS);  // Wall
            glVertex3f(-2,0,-1);
            glVertex3f(2,0,-1);
            glVertex3f(2,-1.5,-1);
            glVertex3f(-2,-1.5,-1);
        glEnd();

        glColor3f(0.4f, 0.0f, 0.0f);
        glBegin(GL_QUADS);  // Roof
            glVertex3f(-2.2,0.5,0);
            glVertex3f(2.2,0.5,0);
            glVertex3f(2.2,-0.1,-1.25);
            glVertex3f(-2.2,-0.1,-1.25);
        glEnd();

        glBegin(GL_QUADS);  // Window Left
             glVertex3f(-1.5,-0.3,-1.0001);
             glVertex3f(-0.75,-0.3,-1.0001);
             glVertex3f(-0.75,-0.8,-1.0001);
             glVertex3f(-1.5,-0.8,-1.0001);
        glEnd();

        glBegin(GL_QUADS);  // Window Right
             glVertex3f(1.5,-0.3,-1.0001);
             glVertex3f(0.75,-0.3,-1.0001);
             glVertex3f(0.75,-0.8,-1.0001);
             glVertex3f(1.5,-0.8,-1.0001);
        glEnd();
    glPopMatrix();

    // Right side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.65f);
        glBegin(GL_QUADS);  // Wall
             glVertex3f(2,0,1);
             glVertex3f(2,0,-1);
            glVertex3f(2,-1.5,-1);
             glVertex3f(2,-1.5,1);
        glEnd();

        glBegin(GL_TRIANGLES);  // Wall Upper
             glVertex3f(2,0.5,0);
             glVertex3f(2,0,1);
             glVertex3f(2,0,-1);
        glEnd();
    glPopMatrix();

    // Left side
    glPushMatrix();
    glTranslatef(0.0f, 1.3f, 0.0f);
        glColor3f(0.0f, 0.0f, 0.65f);
        glBegin(GL_QUADS);  // Wall
                glVertex3f(-2,0,1);
                glVertex3f(-2,0,-1);
               glVertex3f(-2,-1.5,-1);
                glVertex3f(-2,-1.5,1);
        glEnd();

        glBegin(GL_TRIANGLES);  // Wall Upper
               glVertex3f(-2,0.5,0);
               glVertex3f(-2,0,1);
               glVertex3f(-2,0,-1);
        glEnd();
    glPopMatrix();
}

void drawDoor() {

    glPushMatrix();
		glTranslatef(-0.3f, 0.5f, 1);
        glRotatef (door_angle, 0,1,0);
    	glTranslatef(0.3f, 0, 0);
        glColor3f(0.7f, 0.7f, 0.7f);
        glScalef(0.6, 1.1, 0.1f);
        glutSolidCube(1.0);
    glPopMatrix();

}

void changeSize(int w, int h){

    // Prevent a divide by zero, when window is too short
    // (you cant make a window of zero width).
    if (h == 0) h = 1;
    float ratio = w * 1.0 / h;

    // Use the Projection Matrix
    glMatrixMode(GL_PROJECTION);

    // Reset Matrix
    glLoadIdentity();

    // Set the viewport to be the entire window
    glViewport(0, 0, w, h);

    // Set the correct perspective.
    gluPerspective(45.0f, ratio, 0.1f, 100.0f);

    // Get Back to the Modelview
    glMatrixMode(GL_MODELVIEW);
}

void renderScene(void){

    // Para ver os objetos em modo polígono (somente os traços)	
    //glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    // Clear Color and Depth Buffers
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Reset transformations
    glLoadIdentity();

    // Set the camera
    gluLookAt(x, 1.0f, z, x+lx, 1.0f, z+lz, 0.0f, 1.0f, 0.0f);

    // Draw ground
   glEnableClientState(GL_VERTEX_ARRAY);
  glVertexPointer(3, GL_FLOAT, 0, vertices);

  glColor3f (AZUL); /* frente */
  glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, frenteIndices);

  glColor3f (AMARELO); /* esquerda */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, esquerdaIndices);

  glColor3f (VERMELHO); /* tras */
  glDrawElements(GL_POLYGON, 4, GL_UNSIGNED_BYTE, trasIndices);

  glColor3f (VERDE); /* direita */
  glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, direitaIndices);

  glColor3f (CYAN); /* topo */
  glDrawElements(GL_POLYGON, 5, GL_UNSIGNED_BYTE, topoIndices);

  glColor3f (LARANJA); /* fundo */
  glDrawElements(GL_QUADS, 4, GL_UNSIGNED_BYTE, fundoIndices);

  glColor3f (CINZA); /* triangulo */
  glDrawElements(GL_POLYGON, 3, GL_UNSIGNED_BYTE, trianguloIndices);

  glDisableClientState (GL_VERTEX_ARRAY);

  glPopMatrix();

    glFlush();
    glutSwapBuffers();
}


void processNormalKeys(unsigned char key, int x, int y) {
    switch(key){
        case 'o':
            if(door_angle <= 118.0f) door_angle += 2.0f;
            glutPostRedisplay();
        break;

        case 'c':
            if(door_angle >= 2.0f) door_angle -= 2.0f;
            glutPostRedisplay();
        break;

        case 27:
            exit(0);
        break;
    }
}


void processSpecialKeys(int key, int xx, int yy){

float fraction = 0.5f;

    switch (key) {

        case GLUT_KEY_LEFT :
            angle -= 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
        break;
        case GLUT_KEY_RIGHT :
            angle += 0.05f;
            lx = sin(angle);
            lz = -cos(angle);
        break;
        case GLUT_KEY_UP :
            x += lx * fraction;
            z += lz * fraction;
        break;
        case GLUT_KEY_DOWN :
            x -= lx * fraction;
            z -= lz * fraction;
        break;
    }
}

int main(int argc, char **argv){

    // init GLUT and create window
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(50,50);
    glutInitWindowSize(800,600);
    glutCreateWindow("House 3D");

    init();

    // register callbacks
    glutDisplayFunc(renderScene);
    glutReshapeFunc(changeSize);
    glutIdleFunc(renderScene);
    glutKeyboardFunc(processNormalKeys);
    glutSpecialFunc(processSpecialKeys);

    // OpenGL init
    glEnable(GL_DEPTH_TEST);

    // enter GLUT event processing cycle
    glutMainLoop();

    return 1;
}