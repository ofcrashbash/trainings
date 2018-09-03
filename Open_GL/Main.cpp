#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

void renderScene(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glClearColor(.1, 0.5, 1.0, 1.0);//clear red
	glutSwapBuffers();
}

int main(int argc, char **argv)
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