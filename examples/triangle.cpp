#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <unistd.h>

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
    return;
} 

void processInput(GLFWwindow* window)
{
    /*
        All input by user is processed here.
    */

    if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
        glfwSetWindowShouldClose(window, true);
    
    return;
}

void render()
{
    // ---------Code to flicker display----------
    static int parity = 0;
    if (parity)
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    else
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    parity = !parity;
    sleep(1);
}

int main()
{
    // initialize GLFW
    glfwInit();

    // configure GLFW to make it use OpenGL Core Profile and GLFW3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    // create a window object
    GLFWwindow* window = glfwCreateWindow(800, 600, "Window", NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create window\n";
        glfwTerminate();
        return -1;
    }
    // make the window the main context for the current thread
    glfwMakeContextCurrent(window);

    // load GLAD functions
    // GLFW provies `glfwGetProcAddress` to point to the OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to load GLAD\n";
        return -1;
    }

    // Specifies to OpenGL the coordinate range of the context
    glViewport(0, 0, 800, 600);

    // register the context window to process any changes mae to the size of the window by the user
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // create the vertex shader object
    // OpenGL core profile shading language version string: 4.50
    const char *vertexShaderSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
    "}\n\0";
    unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
    glCompileShader(vertexShader);
    

    // create the fragment shader object
    const char *fragmentShaderSource = 
    "#version 330 core\n"
    "out vec4 fragColor;\n"
    "void main()\n"
    "{\n"
    "    fragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
    "}\n\0";
    unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
    glCompileShader(fragmentShader);

    // link vertex and fragment shaders into one shader program
    unsigned int shaderProgram = glCreateProgram();
    glAttachShader(shaderProgram, vertexShader);
    glAttachShader(shaderProgram, fragmentShader);
    glLinkProgram(shaderProgram);

    // clear unnecessary objects
    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);

    float vertices[] = 
    {
        -0.5f, -0.5f, 0.0f,
        0.5f, -0.5f, 0.0f,
        0.0f, 0.5f, 0.0f
    };

    // generate a vertex array to combine the `vertexAttribPointer` and VBO
    unsigned int vao, vbo;
    glGenVertexArrays(1, &vao);
    // store the vertex data in GPU memory
    glGenBuffers(1, &vbo);

    glBindVertexArray(vao);

    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(GL_ARRAY_BUFFER, sizeof vertices, vertices, GL_STATIC_DRAW);

    // provide specification of vertex attributes in VBO currently bound
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof (float), (void*)0);
    glEnableVertexAttribArray(0);

    glBindBuffer(GL_ARRAY_BUFFER, 0);

    // render loop
    // each iteration of the loop is called a frame
    while (!glfwWindowShouldClose(window))
    {
        // process all input before updating frame
        processInput(window);

        // set color of window
        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        // make triangle
        glUseProgram(shaderProgram);
        glBindVertexArray(vao);
        glDrawArrays(GL_TRIANGLES, 0, 3);

        // update window
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
         
    std::cout << "Ending program...\n";

    return 0;
}