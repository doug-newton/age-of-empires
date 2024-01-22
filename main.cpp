#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include "core/driver.h"

using namespace std;

int main (int argc, char ** argv)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	int width = 1280;
	int height = 960;

	GLFWwindow* window = glfwCreateWindow(width, height, "Age of Empires", NULL, NULL);
	if (window == nullptr) {
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
		return 1;
	}

	glViewport(0, 0, width, height);
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	glfwSetKeyCallback(window, Driver::onKeyEvent);

	Driver::onInit();

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		Driver::onUpdate(1.0);
		Driver::onRender();

		glfwSwapBuffers(window);
	}

	return 0;
}
