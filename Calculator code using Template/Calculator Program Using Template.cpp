// Write a C++ program that defines template functions for adding 
//and multiplying two values of different types. Additionally, implement a 
//decision function that first checks if the second number is less than the first 
//number. If the condition is met, perform both addition and multiplication 
//operations using the previously defined functions; otherwise, display a 
//message indicating that no operations were performed. Modify the main
//function to prompt the user for input values and use the decision function to 
//determine and execute the appropriate operations based on the input.

#include <iostream>

using namespace std;


template <class T, class U>
T add(T a, U b) {
    return a + b;
}


template <class T, class U>
T multiply(T a, U b) {
    return a * b;
}


template <class T, class U>
void decision(T a, U b) {
    if (b < a) {
        cout << "Addition: " << add(a, b) << endl;
        cout << "Multiplication: " << multiply(a, b) << endl;
    } else {
        cout << "No operations performed." << endl;
    }
}

int main() {
    double num1, num2;

    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    decision(num1, num2);

    return 0;
}
