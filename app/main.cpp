#include <iostream>

/// GLEW
#define GLEW_STATIC
#include <GL/glew.h>

/// GLFW
#include <GLFW/glfw3.h>

const GLint WIDTH = 800;
const GLint HEIGHT = 600;

int main()
{
    glfwInit();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // MAC
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);

    GLFWwindow *window =
        glfwCreateWindow(WIDTH, HEIGHT, "Learn OpenGL", nullptr, nullptr);

    /// MAC
    int screenWidth;
    int screenHeight;
    glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
    ///

    if (nullptr == window)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();

        return -1;
    }

    glfwMakeContextCurrent(window);

    if (GLEW_OK != glewInit())
    {
        std::cout << "Failed to initialize GLEW" << std::endl;

        return -1;
    }

    glViewport(0, 0, screenWidth, screenHeight);

    std::cout << "OpenGL Version: " << glGetString(GL_VERSION)
              << std::endl; /// 4.1 ATI-4.12.7

    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
    }


    glfwTerminate();

    return 0;
}
