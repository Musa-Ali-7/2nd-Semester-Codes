#include<iostream>
using namespace std;

class shape {
    public:
        virtual void draw() { // Marking as virtual to support polymorphism
            cout << "drawing shape " << endl;
        }
};

class circle : public shape {
    public:
        void draw() override { // Overriding the base class method
            cout << "Drawing circle " << endl;
        }
};

class rectangle : public shape {
    public:
        void draw() override { // Overriding the base class method
            cout << "drawing rectangle " << endl;
        }
};

int main() {
    circle mycircle; // Correctly create a circle object
    circle* circleptr = &mycircle; // Initialize pointer to the circle object
    circleptr->draw(); // Calls draw method for circle

    rectangle myrectangle; // Correctly create a rectangle object
    rectangle* rectangleptr = &myrectangle; // Initialize pointer to the rectangle object
    rectangleptr->draw(); // Calls draw method for rectangle

    return 0;
}

