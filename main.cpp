#include <iostream>
//prvo glad pa onda glfw3
#include <glad/glad.h>
#include <GLFW/glfw3.h>

void frame_buffer_size_callback(GLFWwindow *wwindow, int width, int height);
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
int main() {

    glfwInit();
    // OpenGL 3.3 core

    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR,3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR,3);
    glfwWindowHint(GLFW_OPENGL_PROFILE,GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow *window = glfwCreateWindow(1000,800,"Target Shooting", nullptr, nullptr);
    if(window == nullptr){
        std::cout << "Failed to create the window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    //kazemo OpenGl da zelimo da crta u ovom prozoru
    glfwMakeContextCurrent(window);
    //kazemo dimenzije za renderovanje
    glfwSetFramebufferSizeCallback(window,frame_buffer_size_callback);
    //funkcija koja se automatski poziva cim registruje neku akciju sa u/i uredjaja
    glfwSetKeyCallback(window,key_callback);

    //glad funkcija koja ucitava opengl funkcije
    if(!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)){
        std::cout << "Failed to initialize opengl functions" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }

    //incijalna boja pozadine
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    //redner function
    while(!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
//        update_function();
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}

void frame_buffer_size_callback(GLFWwindow *window, int width, int height){
    glViewport(0,0,width,height);
}
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods){
    if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window,true);
    if(key == GLFW_KEY_H && action == GLFW_PRESS)
        std::cout << "H" << std::endl;
}
