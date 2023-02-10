#include <cstdint>
#include <cstdlib>
#include <stdexcept>

// GLFW and OpenGL Functions
#include <glad/glad.h>
#include <GLFW/glfw3.h>

// GLM Vector Math
#include <glm/glm.hpp>

int32_t main(void)
{
    if (!glfwInit()) {
        throw std::runtime_error("Unable to initialize GLFW!");
    }

    // Specify OpenGL version
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);

    // Create GLFW Window
    GLFWwindow* window = glfwCreateWindow(1280, 720, "Base GL Project", nullptr, nullptr);

    // Associate the OpenGL context with this thread
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable VSync

    // Load OpenGL functions
    const auto getProcAddr{reinterpret_cast<GLADloadproc>(glfwGetProcAddress)};
    if (gladLoadGLLoader(getProcAddr) == false) {
        throw std::runtime_error("Error: Failed to load GPU functions");
    }

    // Using a lambda here for breivity, however it does not capture variables.
    glfwSetKeyCallback(window, [](GLFWwindow* window, int32_t key, int32_t scancode, int32_t action, int32_t mode) {
        // Close when pressing escape
        if (key == GLFW_KEY_ESCAPE) {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
        }
    });

    // Main Loop
    while (!glfwWindowShouldClose(window))
    {
        // Process GLFW events (keyboard, window, etc)
        glfwPollEvents();

        // Set the viewport to the full window
        int32_t viewportW, viewportH;
        glfwGetFramebufferSize(window, &viewportW, &viewportH);
        glViewport(0, 0, viewportW, viewportH);

        // Compute a smoothly animated clear color
        const auto time = static_cast<float>(glfwGetTime()) * 0.25F;
        auto r          = (glm::cos(time * 3.14159265F) + 1.0F) * 0.5F;
        auto g          = (glm::sin(time * 1.61803398F) + 1.0F) * 0.5F;
        auto b          = (glm::cos(time * 1.41421356F) + 1.0F) * 0.5F;

        glClearColor(r, g, b, 1.0F);
        glClear(GL_COLOR_BUFFER_BIT);

        // TODO: update game, draw stuff, whatever

        // Present graphics to the window
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return EXIT_SUCCESS;
}
