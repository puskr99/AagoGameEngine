#include "button.h" // Include your header file
#include<iostream>

Button::Button(float x, float y, float width, float height, const std::string& label)
    : x(x), y(y), width(width), height(height), label(label) {}


void Button::draw() {
    // Set up the OpenGL state
    glBegin(GL_QUADS);
    if (hovered) {
        glColor3f(0.8f, 0.8f, 0.8f); // Change color on hover (light gray)
    } else {
        glColor3f(1.0f, 1.0f, 1.0f); // Default button color (white)
    }
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();

}


bool Button::isClicked(float mouseX, float mouseY) {
    return mouseX >= x && mouseX <= x + width &&
           mouseY >= y && mouseY <= y + height;
}


void Button::updateMouseState(float mouseX, float mouseY, int button, int action) {
    hovered = isClicked(mouseX, mouseY); // Check if the mouse is hovering over the button

    if (hovered) {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            std::cout << "Mouse pressed over button" << std::endl;
        }
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_RELEASE) {
            std::cout << "Mouse released over button" << std::endl;
        }
    } else {
        if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS) {
            std::cout << "Mouse pressed outside button" << std::endl;
        }
    }
}
