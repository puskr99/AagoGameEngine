#include <iostream>
#include <GLFW/glfw3.h>
#include "UI/buttons/base_button/base_button.h" // Include your Button class
#include "UI/buttons/checkbox/checkbox.h" // Include your Button class

Button myButton(100, 100, 200, 50, "Click Me"); // Button instance
CheckBox mycheckBox(200, 200, 25, 25, "Accept Terms");

double xpos, ypos; // Mouse position variables

void cursor_position_callback(GLFWwindow* window, double x, double y) {
    xpos = x; // Update mouse position
    ypos = y;

    // Update button hover state
    myButton.updateMouseState(xpos, ypos, -1, -1); // Pass -1 for button and action since we are only updating hover state
}

void mouse_button_callback(GLFWwindow* window, int button, int action, int mods) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        double xpos, ypos;
        glfwGetCursorPos(window, &xpos, &ypos); // Get mouse position

        if (myButton.isClicked(xpos, ypos)) { // Check if the button was clicked
            myButton.updateMouseState(xpos, ypos, button, action);
        }

        if (mycheckBox.isClicked(xpos, ypos) && action == GLFW_PRESS) { // Check if the checkbox was clicked
            mycheckBox.onMouseClick(xpos, ypos);

        }
    }
}

int main() {
    // Initialize GLFW
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        return -1;
    }

    // Create a windowed mode window and its OpenGL context
    GLFWwindow* window = glfwCreateWindow(640, 480, "Hello World", nullptr, nullptr);
    if (!window) {
        glfwTerminate();
        std::cerr << "Failed to create GLFW window" << std::endl;
        return -1;
    }

    // Make the window's context current
    glfwMakeContextCurrent(window);

    // Set the cursor position and mouse button callbacks
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);

    // Set OpenGL viewport
    glViewport(0, 0, 640, 480);
    
    // Set the projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0, 640, 480, 0, -1, 1); // Set up orthographic projection
    glMatrixMode(GL_MODELVIEW);

    // Set the clear color (background color)
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black background

    while (!glfwWindowShouldClose(window)) {
        // Clear the screen
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Draw the button
        myButton.draw();
        mycheckBox.draw();

        // Swap front and back buffers
        glfwSwapBuffers(window);

        // Poll for and process events
        glfwPollEvents();
    }

    // Clean up and exit
    glfwDestroyWindow(window);
    glfwTerminate();
    return 0;
}