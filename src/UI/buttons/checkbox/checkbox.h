#ifndef CHECKBOX_H // Include guard to prevent multiple inclusions
#define CHECKBOX_H

#include "../base_button/base_button.h" // Include Button class header

class CheckBox : public Button {
private:
    bool checked; // Variable to keep track of the checkbox state
public:
    CheckBox(float x, float y, float width, float height, const std::string &label);
    void toggle(); // Toggle the checkbox state
    bool isChecked(); // Return the checked state
    void draw(); // Override the draw method to render checkbox
    void onMouseClick(float mouseX, float mouseY); // Do something when clicked
};

#endif // CHECKBOX_H
