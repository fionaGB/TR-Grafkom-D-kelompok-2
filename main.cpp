#include<Windows.h>
#include<GL\glut.h>
#include<stdlib.h>

void init(void);
void tampil(void);
void mouseMotion(int x,int y);
void mouse(int button, int state, int x, int y);
void keyboard(unsigned char, int, int);
void ukuran(int, int);
float xrot = 0.0f;
float yrot = 0.0f;
float xdiff = 0.0f;
float ydiff = 0.0f;
bool mouseDown = false;
int is_depth;

void silinder(void){
    //batang
    GLUquadricObj *pObj;
    pObj =gluNewQuadric();
    gluQuadricNormals(pObj, GLU_SMOOTH);

    glPushMatrix();
    glColor3ub(104,70,14);
    gluCylinder(pObj, 0.2, 0.2, 10, 25, 25);
    glPopMatrix();
}

void kotak(float x1, float y1, float z1, float x2, float y2, float z2, float x3,
           float y3, float z3, float x4, float y4, float z4)
{
    glVertex3f(x1, y1, z1);
	glVertex3f(x2, y2, z2);
	glVertex3f(x3, y3, z3);
	glVertex3f(x4, y4, z4);
}

int main (int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowSize(1024, 800);
	glutInitWindowPosition(250, 80);
	glutCreateWindow("TR ASDOS");
	init();
	glutDisplayFunc(tampil);
	glutKeyboardFunc(keyboard);
	glutMouseFunc(mouse);
	glutMotionFunc(mouseMotion);
	glutReshapeFunc(ukuran);
	glutMainLoop();
	return 0;
}

void init(void)
{
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glEnable(GL_DEPTH_TEST);
	is_depth = 1;
	glMatrixMode(GL_MODELVIEW);
	glPointSize(9.0);
	glLineWidth(6.0f);
}

void tampil(void)
{
	if (is_depth)
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	else
		glClear(GL_COLOR_BUFFER_BIT);

	//tembok depan
	glBegin(GL_QUADS);
	glColor3f(0.0,0.0,0.5);
	glVertex3f(-20.0, -50.0, 0.0); glVertex3f(20.0, -50.0, 0.0);
	glVertex3f(20.0, 150.0, 0.0); glVertex3f(-20.0, 150.0, 0.0);

    //sisikanan
	glColor3f(0.0,0.0,1.0);
	glVertex3f(20.0, -50.0, 0.0);
	glVertex3f(20.0, -50.0, -3.0);
	glVertex3f(20.0, 150.0, -3.0);
	glVertex3f(20.0, 150.0, 0.0);
    //sisikiri
	glColor3f(0.0,0.0,1.0);
	glVertex3f(-20.0, -50.0, 0.0);
	glVertex3f(-20.0, -50.0, -3.0);
	glVertex3f(-20.0, 150.0, -3.0);
	glVertex3f(-20.0, 150.0, 0.0);
    //sisibelakang
	glColor3f(0.0,1.0,0.0);
	glVertex3f(-20.0, -50.0, -3.0);
	glVertex3f(20.0, -50.0, -3.0);
	glVertex3f(20.0, 150.0, -3.0);
	glVertex3f(-20.0, 150.0, -3.0);

	glColor3f(1.0,0.0,0.0);
	glVertex3f(18.0, -50.0, -3.0);
	glVertex3f(18.0, -50.0, -20.0);
	glVertex3f(18.0, 150.0, -20.0);
	glVertex3f(18.0, 150.0, -3.0);

	glColor3f(1.0,0.0,0.0);
	glVertex3f(-18.0, -50.0, -3.0);
	glVertex3f(-18.0, -50.0, -20.0);
	glVertex3f(-18.0, 150.0, -20.0);
	glVertex3f(-18.0, 150.0, -3.0);

    //sisibelakang1
	glColor3f(0.0,1.0,0.0);
	glVertex3f(-20.0, -50.0, -20.0);
	glVertex3f(20.0, -50.0, -20.0);
	glVertex3f(20.0, 150.0, -20.0);
	glVertex3f(-20.0, 150.0, -20.0);
    //sisibelakangsamping
    glColor3f(0.0,0.0,1.0);
	glVertex3f(-20.0, -50.0, -20.0);
	glVertex3f(-20.0, -50.0, -23.0);
	glVertex3f(-20.0, 150.0, -23.0);
	glVertex3f(-20.0, 150.0, -20.0);

    //sisibelakangsamping
    glColor3f(0.0,0.0,1.0);
	glVertex3f(20.0, -50.0, -20.0);
	glVertex3f(20.0, -50.0, -23.0);
	glVertex3f(20.0, 150.0, -23.0);
	glVertex3f(20.0, 150.0, -20.0);

	//sisibelakang2
    glColor3f(0.0,0.0,1.0);
	glVertex3f(-20.0, -50.0, -23.0);
	glVertex3f(20.0, -50.0, -23.0);
	glVertex3f(20.0, 150.0, -23.0);
	glVertex3f(-20.0, 150.0, -23.0);
    //atapsamping
    glColor3f(1.0,1.0,0.0);
    glVertex3f(18.0, -50.0, -3.0);
	glVertex3f(18.0, -50.0, -20.0);
	glVertex3f(18.0, 150.0, -20.0);
	glVertex3f(18.0, 150.0, -3.0);

	glColor3f(1.0,1.0,0.0);
	kotak(18, 150, -3, 18, 150, -20, 18, 185, -12, 18, 185, -10);
	kotak(18, 185, -12, 18, 185, -10, 18, 187, -10.5, 18, 187, -11.5);
	kotak(-18, 150, -3, -18, 150, -20, -18, 185, -12, -18, 185, -10);
    kotak(-18, 185, -12, -18, 185, -10, -18, 187, -10.5, -18, 187, -11.5);

	glColor3f(0.0,1.0,0.0);
	kotak(-20, 150, -3, 20, 150, -3, 20, 187, -10.5, -20, 187, -10.5);
	kotak(-20, 150, -20, 20, 150, -20, 20, 187, -11.5, -20, 187, -11.5);
	kotak(-20, 187, -10.5, 20, 187, -10.5, 20, 187, -11.5, -20, 187, -11.5);

    glColor3f(0.0,1.0,1.0);
	kotak(20, 150, 0, 20, 150, -3, 20, 187, -10.5, 20, 187, -7.5);
    kotak(-20, 150, 0, -20, 150, -3, -20, 187, -10.5, -20, 187, -7.5);
    kotak(20, 150, -20, 20, 150, -23, 20, 187, -14.5, 20, 187, -11.5);
    kotak(-20, 150, -20, -20, 150, -23, -20, 187, -14.5, -20, 187, -11.5);

    glColor3f(0.0,0.0,1.0);
    kotak(-20, 150, 0, 20, 150, 0, 20, 187, -7.5, -20, 187, -7.5);
    kotak(-20, 150, -23, 20, 150, -23, 20, 187, -14.5, -20, 187, -14.5);
    kotak(-20, 187.1, -7.5, 20, 187.1, -7.5, 20, 187.1, -14.5, -20, 187.1, -14.5);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(-18.0, -50.0, 0.0);
    glVertex3f(-16.0, -36.0, 0.0);
    glVertex3f(-16.0, -40.0, 8.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(1.0,1.0,0.0);
    glVertex3f(18.0, -50.0, 0.0);
    glVertex3f(16.0, -36.0, 0.0);
    glVertex3f(16.0, -40.0, 8.0);
    glEnd();
    glBegin(GL_QUADS);
    glColor3f(1.0,0.5,0.5);
    glVertex3f(-16.0, -36.0, 0.0);
    glVertex3f(-14.0, -31.0, 0.0);
    glVertex3f(-14.0, -35.0, 12.0);
    glVertex3f(-16.0, -40.0, 8.0);

    glVertex3f(16.0, -36.0, 0.0);
    glVertex3f(14.0, -31.0, 0.0);
    glVertex3f(14.0, -35.0, 12.0);
    glVertex3f(16.0, -40.0, 8.0);
    glColor3f(0.0,1.0,1.0);
    glVertex3f(14.0, -31.0, 0.0);
    glVertex3f(12.0, -28.0, 0.0);
    glVertex3f(12.0, -32.0, 16.0);
    glVertex3f(14.0, -35.0, 12.0);

    glVertex3f(-14.0, -31.0, 0.0);
    glVertex3f(-12.0, -28.0, 0.0);
    glVertex3f(-12.0, -32.0, 16.0);
    glVertex3f(-14.0, -35.0, 12.0);

    glColor3f(1.0,0.0,1.0);
    glVertex3f(12.0, -28.0, 0.0);
    glVertex3f(6.0, -22.0, 0.0);
    glVertex3f(6.0, -26.0, 20.0);
    glVertex3f(12.0, -32.0, 16.0);

    glVertex3f(-12.0, -28.0, 0.0);
    glVertex3f(-6.0, -22.0, 0.0);
    glVertex3f(-6.0, -26.0, 20.0);
    glVertex3f(-12.0, -32.0, 16.0);

    glVertex3f(6.0, -22.0, 0.0);
    glVertex3f(3.0, -20.0, 0.0);
    glVertex3f(3.0, -24.0, 20.0);
    glVertex3f(6.0, -26.0, 20.0);

    glVertex3f(-6.0, -22.0, 0.0);
    glVertex3f(-3.0, -20.0, 0.0);
    glVertex3f(-3.0, -24.0, 20.0);
    glVertex3f(-6.0, -26.0, 20.0);

    glVertex3f(-3.0, -20.0, 0.0);
    glVertex3f(3.0, -20.0, 0.0);
    glVertex3f(3.0, -24.0, 20.0);
    glVertex3f(-3.0, -24.0, 20.0);


    glColor3f(0.0,1.0,0.0);
    kotak(-55,-50,50,55,-50,50,55,-50,-50,-55,-50,-50);
    glColor3f(0.6,0.5,0.3);
    kotak(-55,-50,50,55,-50,50,55,-65,50,-55,-65,50);
    kotak(-55,-50,-50,55,-50,-50,55,-65,-50,-55,-65,-50);
    kotak(-55,-65,50,-55,-65,-50,-55,-50,-50,-55,-50,50);
    kotak(55,-65,50,55,-65,-50,55,-50,-50,55,-50,50);

    glColor3f(0.0,0.0,0.0);
    kotak(-55.0,-50.0,65.0,55.0,-50.0,65.0,55.0,-50.0,75.0,-55.0,-50.0,75.0 );
    glColor3f(0.6,0.5,0.3);
    kotak(-55,-50,75,55,-50,75,55,-55,75,-55,-55,75);
    kotak(-55,-55,75,-55,-55,65, -55,-50,65, -55, -50, 75);
    kotak(-55,-50,65,55,-50,65,55,-55,65,-55,-55,65);
    kotak(55,-55,75,55,-55,65,55,-50,65,55, -50, 75);
    glEnd();

    glPushMatrix();
    glColor3f(0.6,0.5,0.3);
    glTranslatef(-30,-50,30);
    glRotatef(90,-10,0,0);
    glutSolidCone(1,20,50,50);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,1.0,0.0);
    glTranslatef(-30,-30,30);
    glScalef(5,5,5);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6,0.5,0.3);
    glTranslatef(30,-50,10);
    glRotatef(90,-10,0,0);
    glutSolidCone(1,20,50,50);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.8,1.0,0.0);
    glTranslatef(30,-30,10);
    glScalef(5,5,5);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6,0.5,0.3);
    glTranslatef(-30,-50,-20);
    glRotatef(90,-10,0,0);
    glutSolidCone(1,20,50,50);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.8,1.0,0.0);
    glTranslatef(-30,-30,-20);
    glScalef(5,5,5);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.6,0.5,0.3);
    glTranslatef(40,-50,-25);
    glRotatef(90,-10,0,0);
    glutSolidCone(1,20,50,50);
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.8,1.0,0.0);
    glTranslatef(40,-30, -25);
    glScalef(5,5,5);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(-30,100,50);
    glScalef(5,5,5);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(-35,100,50);
    glScalef(5,5,5);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(35,100,15);
    glScalef(5,5,5);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(40,100,15);
    glScalef(5,5,5);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(-30,100,50);
    glScalef(5,5,5);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(-35,100,50);
    glScalef(5,5,5);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(30,70,-30);
    glScalef(5,5,5);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(35,70,-30);
    glScalef(5,5,5);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(-45,120,-30);
    glScalef(5,5,5);
    glutSolidDodecahedron();
    glPopMatrix();
    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(-50,120,-30);
    glScalef(5,5,5);
    glutSolidDodecahedron();
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(-50,-45,0);
    glScalef(5,10,70);
    glutSolidCube(1.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(50,-45,0);
    glScalef(5,10,70);
    glutSolidCube(1.2);
    glPopMatrix();

    glPushMatrix();
    glColor3f(0.5,0.5,0.5);
    glTranslatef(0,-45,-45);
    glRotatef(90,0,1,0);
    glScalef(5,10,80);
    glutSolidCube(1.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(20 ,-50,45);
    glRotatef(270,1,0,0);
    silinder();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-20 ,-50,45);
    glRotatef(270,1,0,0);
    silinder();
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(-20,-40,45);
    glutSolidSphere(2,20,20);
    glPopMatrix();
    glPushMatrix();
    glColor3f(1.0,1.0,0.0);
    glTranslatef(20,-40,45);
    glutSolidSphere(2,20,20);
    glPopMatrix();
	glutSwapBuffers();

}

void mouse (int button, int state, int x, int y){
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
		mouseDown = true;
		xdiff = x - yrot;
		ydiff = -y + xrot;
	} else {
		mouseDown = false;
	}
}

void mouseMotion(int x, int y){
	if(mouseDown){
		yrot = x - xdiff;
		xrot = y + xdiff;
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        glLoadIdentity();
        gluLookAt(0.0f, 0.0f, 3.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f);
        glRotatef(xrot, 1.0f, 0.0f, 0.0f);
        glRotatef(yrot, 0.0f, 1.0f, 0.0f);
		glutPostRedisplay();
	}
}

void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case 'w':
	case 'W':
		glTranslatef(0.0, 0.0, 3.0);
		break;
	case 'd':
	case 'D':
		glTranslatef(3.0, 0.0, 0.0);
	case 's':
	case 'S':
		glTranslatef(0.0, 0.0, -3.0);
		break;
	case 'a':
	case 'A':
		glTranslatef(-3.0, 0.0, 0.0);
		break;
	case '7':
		glTranslatef(0.0, 3.0, 0.0);
		break;
	case '9':
		glTranslatef(0.0, -3.0, 0.0);
		break;
	case 'k':
		glRotatef(2.0, 1.0, 0.0, 0.0);
		break;
	case 'i':
		glRotatef(-2.0, 1.0, 0.0, 0.0);
		break;
	case 'l':
		glRotatef(2.0, 0.0, 1.0, 0.0);
		break;
	case 'j':
		glRotatef(-2.0, 0.0, 1.0, 0.0);
		break;
	case '1':
		glRotatef(2.0, 0.0, 0.0, 1.0);
		break;
	case '3':
		glRotatef(-2.0, 0.0, 0.0, 1.0);
		break;
	case '5':
		if (is_depth)
		{
			is_depth = 0;
			glDisable(GL_DEPTH_TEST);
		}
		else
		{
			is_depth = 1;
			glEnable(GL_DEPTH_TEST);
		}
	}
	tampil();
}

void ukuran(int lebar, int tinggi)
{
	if (tinggi == 0) tinggi = 1;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(50.0, lebar / tinggi, 5.0, 800.0);
	glTranslatef(0.0, -5.0, -150.0);
	glMatrixMode(GL_MODELVIEW);
}
