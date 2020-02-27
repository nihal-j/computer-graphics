#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

const int HEIGHT = 800;
const int WIDTH = 800;

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

void normalize(float& x, float &y)
{
    /*
        Normalizes `x` and `y` in range (-1, -1) to (1, 1) using 
        defined constants WIDTH and HEIGHT.
    */

    x = x*2.0f / WIDTH - 1.0f;
    y = y*2.0f / HEIGHT - 1.0f;
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
    GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Window", NULL, NULL);
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
    glViewport(0, 0, WIDTH, HEIGHT);

    // register the context window to process any changes mae to the size of the window by the user
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    // create the vertex shader object
    // OpenGL core profile shading language version string: 4.50
    const char *vertexShaderSource = 
    "#version 330 core\n"
    "layout (location = 0) in vec3 aPos;\n"
    "void main()\n"
    "{\n"
    "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);\n"
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

    float cx , cy;
    std::cout << "Specify start X for positive slope: ";
    std::cin >> cx;
    cy = cx;
    float pos_slope[HEIGHT*3 + 3];
    int pc = 0;
    for (int i = 0; cx <= (float)HEIGHT; i += 3)
    {
        pos_slope[i] = cx++, pos_slope[i + 1] = cy++, pos_slope[i + 2] = 0.0f;
        normalize(pos_slope[i], pos_slope[i + 1]);
        pc++;
    }
    std::cout << "Specify start X for negative slope: ";
    std::cin >> cx;
    cy = HEIGHT - cx;
    float neg_slope[HEIGHT*3 + 3];
    int nc = 0;
    for (int i = 0; cy >= 0.0f; i += 3)
    {
        neg_slope[i] = cx++, neg_slope[i + 1] = cy--, neg_slope[i + 2] = 0.0f;
        normalize(neg_slope[i], neg_slope[i + 1]);
        nc++;
    }

    unsigned int vao, vbo_pos, vbo_neg;
    glGenVertexArrays(1, &vao);
    glBindVertexArray(vao);

    glGenBuffers(1, &vbo_pos);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_pos);
    glBufferData(GL_ARRAY_BUFFER, sizeof pos_slope, pos_slope, GL_STATIC_DRAW);

    glGenBuffers(1, &vbo_neg);
    glBindBuffer(GL_ARRAY_BUFFER, vbo_neg);
    glBufferData(GL_ARRAY_BUFFER, sizeof neg_slope, neg_slope, GL_STATIC_DRAW);

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

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

        glBindBuffer(GL_ARRAY_BUFFER, vbo_pos);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof (float), (void*)0);
        glEnableVertexAttribArray(0);
        glDrawArrays(GL_POINTS, 0, pc);

        glBindBuffer(GL_ARRAY_BUFFER, vbo_neg);
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof (float), (void*)0);
        glEnableVertexAttribArray(0);
        glDrawArrays(GL_POINTS, 0, nc);
        
        // update window
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate();
         
    std::cout << "Ending program...\n";

    return 0;
}