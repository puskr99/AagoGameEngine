#ifndef BUTTON_H // Include guard to prevent multiple inclusions
#define BUTTON_H

#include <string> // Required for std::string
#include <GLFW/glfw3.h> // Required for GLFW

class Button {
public:
    float x, y, width, height;
    std::string label;
    bool hovered; // To track if the mouse is hovering over the button

    Button(float x, float y, float width, float height, const std::string& label);
    void draw();
    bool isClicked(float mouseX, float mouseY);
    void updateMouseState(float mouseX, float mouseY, int button, int action);
};

#endif // BUTTON_H
