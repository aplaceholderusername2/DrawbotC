#include <GLFW/glfw3.h>
#include <stdio.h>
#include <unistd.h>



int main(){

	if(!glfwInit())	fprintf(stderr, "init failed...\n");
	else 			fprintf(stderr, "init success!");


	GLFWwindow* window = glfwCreateWindow(640, 480, "DiM", NULL, NULL);
	
	if(!window)
    	fprintf(stderr, "0n ");
	
	else{
		fprintf(stderr, "0k ");
		glfwMakeContextCurrent(window);
	}

	int i = 0;
	double time;
	int width, height;
	
	glfwGetFramebufferSize(window, &width, &height);
	glViewport(0, 0, width, height);


	float vertices[] = {

		-0.5, 0.5, 0.0, //top left
		0.5, 0.5, 0.0,	//top right
		0.5, -0.5, 0.0,	//bottom right
		-0.5, -0.5, 0.0 //bottom left


	};

	while (!glfwWindowShouldClose(window) && i < 1000){
		
		glClear(GL_COLOR_BUFFER_BIT);
		
		//rendering
		glEnableClientState(GL_VERTEX_ARRAY);
		glVertexPointer(3, GL_FLOAT, 0, vertices);
		glDrawArrays(GL_QUADS, 0, 4);
		glDisableClientState(GL_VERTEX_ARRAY);
		//rendering

		usleep(16);
		time = glfwGetTime();
		glfwSwapBuffers(window);
		glfwPollEvents();
			
    }

	return 0;

}
