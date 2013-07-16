#include <GL/glfw.h>
#include <stdlib.h>
#include <math.h>	
// Math Library Header File
float angle = 0.5f;

double SinTable[90]  = 
{		0
,0.01745
,0.0349
,0.05234
,0.06976
,0.08716
,0.10453
,0.12187
,0.13917
,0.15643
,0.17365
,0.19081
,0.20791
,0.22495
,0.24192
,0.25882
,0.27564
,0.29237
,0.30902
,0.32557
,0.34202
,0.35837
,0.37461
,0.39073
,0.40674
,0.42262
,0.43837
,0.45399
,0.46947
,0.48481
,0.5
,0.51504
,0.52992
,0.54464
,0.55919
,0.57358
,0.58779
,0.60182
,0.61566
,0.62932
,0.64279
,0.65606
,0.66913
,0.682
,0.69466
,0.70711
,0.71934
,0.73135
,0.74314
,0.75471
,0.76604
,0.77715
,0.78801
,0.79864
,0.80902
,0.81915
,0.82904
,0.83867
,0.84805
,0.85717
,0.86603
/*,0.87462
,0.88295
,0.89101
,0.89879
,0.90631
,0.91355
,0.9205
,0.92718
,0.93358
,0.93969
,0.94552
,0.95106
,0.9563
,0.96126
,0.96593
,0.9703
,0.97437
,0.97815
,0.98163
,0.98481
,0.98769
,0.99027
,0.99255
,0.99452
,0.99619
,0.99756
,0.99863
,0.99939
,0.99985
,1*/

};

double CosTable[90]=
{
	1
	,0.99985
	,0.99939
	,0.99863
	,0.99756
	,0.99619
	,0.99452
	,0.99255
	,0.99027
	,0.98769
	,0.98481
	,0.98163
	,0.97815
	,0.97437
	,0.9703
	,0.96593
	,0.96126
	,0.9563
	,0.95106
	,0.94552
	,0.93969
	,0.93358
	,0.92718
	,0.9205
	,0.91355
	,0.90631
	,0.89879
	,0.89101
	,0.88295
	,0.87462
	,0.86603
	,0.85717
	,0.84805
	,0.83867
	,0.82904
	,0.81915
	,0.80902
	,0.79864
	,0.78801
	,0.77715
	,0.76604
	,0.75471
	,0.74314
	,0.73135
	,0.71934
	,0.70711
	,0.69466
	,0.682
	,0.66913
	,0.65606
	,0.64279
	,0.62932
	,0.61566
	,0.60182
	,0.58779
	,0.57358
	,0.55919
	,0.54464
	,0.52992
	,0.51504
	,0.5
	/*,0.48481
	,0.46947
	,0.45399
	,0.43837
	,0.42262
	,0.40674
	,0.39073
	,0.37461
	,0.35837
	,0.34202
	,0.32557
	,0.30902
	,0.29237
	,0.27564
	,0.25882
	,0.24192
	,0.22495
	,0.20791
	,0.19081
	,0.17365
	,0.15643
	,0.13917
	,0.12187
	,0.10453
	,0.08716
	,0.06976
	,0.05234
	,0.0349
	,0.01745
	,0*/

};

void init(void)
{
	glClearColor(0.0f,0.0f,0.0f, 0.0f);
	glShadeModel(GL_FLAT);
	}
void display(void){
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0f,1.0f,1.0f);
	glLoadIdentity();
	gluLookAt(0.0f,0.0f,5.0f,0.0f,0.0f,0.0f,0.0f,1.0f,0.0f);
	glScalef(1.0f,2.0f,1.0f);
	glFlush();
}
void displayPointOnScreen(GLdouble x, GLdouble y, GLdouble z)
{
	glClear( GL_COLOR_BUFFER_BIT );
	glBegin(GL_POINTS);
	glVertex3d(x, y, z);
	glEnd();
}

void displayLine()
{
	glClear( GL_COLOR_BUFFER_BIT );
	glBegin(GL_LINES);
	glVertex3d(0.0f, 0.0f, -0.5f);
	glVertex3d(0.5f, 0.5f, -0.5f);
	glEnd();
}
float x=0.5, y=0;
int  theta=0.0;
void displayTriangles()
{
	//glClear( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT );
	//glShadeModel(GL_SMOOTH);
	//glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);

	//int theta=0;	
	for(int i=0; i<360; i++)
	{
		
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f( x,	y,  1.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f( x=x*cos(double(i)) - y*sin(double(i)),	y=x*sin(double(i)) + y*cos(double(i)),  1.0f);
		
	}
	/*glColor3f(1.0f, 0.0f, 0.0f);
	glVertex3f(-x, -y, 0.0f);

	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex3f( x*CosTable[theta] - y*SinTable[theta], y*CosTable[theta] + x*SinTable[theta], 0.0f);

	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex3f(x, y, 0.0f);*/

    glEnd();
}

void displayPoints()
{
	glBegin(GL_POINTS);

	
	glColor3f(0.0f, 1.0f, 0.0f);

	for(int i=0; i<60; i++)
	{
		theta =i;
		glVertex3f( x*cos(double(i)) - y*sin(double(i)), y*cos(double(i)) + x*sin(double(i)), 0.0f);
	}	

	glEnd();
}
void displayPolygon(){
	glBegin(GL_POLYGON);
	glNormal3f(0.0f,1.0f,0.0f);
	glVertex3f(10.0f,10.0f,20.0f);
	glVertex3f(10.0f,-10.0f,20.0f);
	glVertex3f(-10.0f,10.0f,-20.0f);
	glVertex3f(10.0f,10.0f,-20.0f);
	glEnd();
}
void displayLines()
{

	glBegin(GL_LINES);
	
	glColor3f(0.0f, 1.0f, 0.0f);
	for(int i= 0; i<59; i++)
	{
		theta =i;
			glVertex3f( x*cos(double(i)) - y*sin(double(i)), y*cos(double(i)) + x*sin(double(i)), 0.0f);
	}

	glEnd();
}


struct Matrix2x2
{
	double e00, e01, e10,e11;
	void setRotation(int theta)
	{		
		this->e00 = CosTable[theta];
		this->e01 = SinTable[theta];
		this->e10 = -SinTable[theta];
		this->e11 = CosTable[theta];
	}
};
void renderFrame()
{
	glClear( GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, 0.0f);
	//glRotatef(angle, 0.0f, 0.0f, 1.0f);
	glPolygonMode(GL_FRONT, GL_LINE);
	glPolygonMode(GL_BACK, GL_LINE);
	//displayPoints();
	//displayTriangles();
	//displayLines();
	//glLoadIdentity();
	//glTranslatef(0.0f, 0.0f, -0.3f);
	displayPolygon();
	//glRotatef(-angle, 0.0f, 0.0f, 1.0f);

	//displayTriangle();

	/*angle += 0.5f;
	if(angle > 360)
		angle = 0.5f;*/

	//glEnd();
}

int main( void)
{

	int running = GL_TRUE;

	// Initialise GLFW
	if( !glfwInit() )
	{
		exit( EXIT_FAILURE );
	}

	// Open an OpenGL window
	if( !glfwOpenWindow( 600,600, 0,250,0,0,100,100, GLFW_WINDOW ) )
	{
		glfwTerminate();
		exit( EXIT_FAILURE );
	}

	// Main loop
	while( running )
	{
		// OpenGL rendering goes here ...
		//glClear( GL_COLOR_BUFFER_BIT );

		//displayPointOnScreen(0.0f, 0.0f, -0.5f);
		//displayPointOnScreen(0.5f, 0.5f, -0.5f);
		//displayLine();
		//displayTriangle();
		renderFrame();

		// Swap front and back rendering buffers
		glfwSwapBuffers();

		// Check if ESC key	was pressed or window was closed
		running = !glfwGetKey( GLFW_KEY_ESC ) &&
					glfwGetWindowParam( GLFW_OPENED );
	}

	// Close window and terminate GLFW
	glfwTerminate();

	// Exit program
	exit( EXIT_SUCCESS );
}
