#include <iostream>
#include "graphics_engine.h"

GraphicsEngine::GraphicsEngine()
{
    window = GraphicsEngine::initialize();
    pCount = 0;
    return;
}

void GraphicsEngine::process_input()
{
    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    return;
}

/**
 * @brief A callback function to process any changes made to the 
 * screen size.
 * 
 * @param window pointer to the current window.
 * @param width, height current dimensions of the window.
 */
void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    WIDTH = width;
    HEIGHT = height;
    glViewport(0, 0, WIDTH, HEIGHT);
    return;
}

GLFWwindow* GraphicsEngine::initialize()
{
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create window\n";
        glfwTerminate();
        exit(1);
    }
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);
    glfwMakeContextCurrent(window);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to load GLAD\n";
        exit(1);
    }
    glViewport(0, 0, WIDTH, HEIGHT);

    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);

    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    glGenVertexArrays(1, &vao);

    return window;
}

void GraphicsEngine::update_window()
{
    glfwSwapBuffers(window);
    glfwPollEvents();
}

int GraphicsEngine::close_window()
{
    return glfwWindowShouldClose(window);
}

void GraphicsEngine::terminate()
{
    glfwTerminate();
}

void GraphicsEngine::set_background_color(float red, float green, float blue, float alpha)
{
    glClearColor(red, green, blue, alpha);
    glClear(GL_COLOR_BUFFER_BIT);
}

void GraphicsEngine::normalize(float &x, float &y, float &z)
{
    x = x*2.0f / WIDTH - 1.0f;
    y = y*2.0f / HEIGHT - 1.0f;
    z = z;
    return;
}

void GraphicsEngine::plot_points(const int* points, int pointCount)
{
    float transformedPoints[pointCount*3];
    for (int i = 0; i < pointCount; i++)
    {
        transformedPoints[i*3] = points[i*3];
        transformedPoints[i*3 + 1] = points[i*3 + 1];
        transformedPoints[i*3 + 2] = points[i*3 + 2];
        normalize(transformedPoints[i*3], transformedPoints[i*3 + 1], transformedPoints[i*3 + 2]);
    }

    unsigned int vbo;
    glGenBuffers(1, &vbo);
    
    glUseProgram(shaderProgram);
    
    glBindVertexArray(vao);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof transformedPoints, transformedPoints, GL_STATIC_DRAW);

    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof (float), (void*)0);
    glEnableVertexAttribArray(0);
    glDrawArrays(GL_POINTS, 0, pointCount); 
}

void GraphicsEngine::add_primitive(int* points, int pointCount)
{
    for (int i = 0; i < pointCount; i++)
        for (int j = 0; j < 3; j++)
            primitives[pCount][i*3 + j] = points[i*3 + j];
    this -> pointCount[pCount++] = pointCount;
}

void GraphicsEngine::load_line(Line line)
{
    int *points = line.get_line();
    int pointCount = line.get_count();
    add_primitive(points, pointCount);
}

void GraphicsEngine::load_circle(Circle circle)
{
    int *points = circle.get_circle();
    int pointCount = circle.get_count();
    add_primitive(points, pointCount);
}

void GraphicsEngine::draw()
{
    for (int i = 0; i < pCount; i++)
        plot_points(primitives[i], pointCount[i]);
}

/* DEBUG

// /
int main()
{
    GraphicsEngine gr;
    gr.load_circle(400, 400, 100);
    gr.draw();
    return 0;
}


// */