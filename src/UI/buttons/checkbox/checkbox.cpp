#include "checkbox.h"
#include "iostream"

CheckBox::CheckBox(float x, float y, float width, float height, const std::string& label)
    : Button(x, y, width, height, label), checked(false) {} // Initialize the checkbox


void CheckBox::toggle() {
    checked = !checked; // Toggle the checked state
    std::cout << "Toggled"<<checked<< " "<<std::endl;
    if (checked) {
        // Draw a checkmark inside the checkbox
        glColor3f(1.0f, 1.0f, 1.0f); // Set color for checkmark (white)
        glBegin(GL_LINES);
        glVertex2f(x + 10, y + height / 2); // Starting point of the checkmark
        glVertex2f(x + width / 2, y + height - 10); // Point for the diagonal
        glVertex2f(x + width / 2, y + height - 10);
        glVertex2f(x + width - 10, y + 10); // End point of the checkmark
        glEnd();
    }
}


bool CheckBox::isChecked() {
    return checked; // Return the current checked state
}


void CheckBox::draw() {
    Button::draw(); // Call the parent draw method for basic button drawing

    // Draw a checkmark if the checkbox is checked
    if (checked) {
        // Draw a checkmark inside the checkbox
        glColor3f(1.0f, 1.0f, 1.0f); // Set color for checkmark (white)
        glBegin(GL_LINES);
        glVertex2f(x + 10, y + height / 2); // Starting point of the checkmark
        glVertex2f(x + width / 2, y + height - 10); // Point for the diagonal
        glVertex2f(x + width / 2, y + height - 10);
        glVertex2f(x + width - 10, y + 10); // End point of the checkmark
        glEnd();
    }
}

// Optionally, you may want to add a method to handle mouse clicks specifically for the checkbox
void CheckBox::onMouseClick(float mouseX, float mouseY) {
    if (isClicked(mouseX, mouseY)) { // Check if the checkbox was clicked
        toggle(); // Toggle the checked state
    }
}
