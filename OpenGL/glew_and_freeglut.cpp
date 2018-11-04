#include "glew_and_freeglut.h"

using namespace std;

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor((GLclampf).1, (GLclampf)0.5, (GLclampf)1.0, (GLclampf)1.0);//clear red
	glutSwapBuffers();
}


int start_window(int argc, char *argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
	glutInitWindowPosition(500, 500);
	glutInitWindowSize(800, 600);
	glutCreateWindow("OpenGL First Window");


	glewInit();
	if (glewIsSupported("GL_VERSION_4_5"))
		cout << " GLEW Version is 4.5" << endl;
	else
		cout << "GLEW 4.5 not supported" << endl;

	glEnable(GL_DEPTH_TEST);
	// register callbacks
	glutDisplayFunc(renderScene);//this func is pretty important!
	glutMainLoop();
	return 0;
}