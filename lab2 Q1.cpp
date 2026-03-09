#include <iostream>  
#include <cmath>  
using namespace std;

class Complex_No {
public:
    float real;     
    float imaginary;  

    // Default Constructor
    Complex_No() {
        real = 0;
        imaginary = 0;
    }

    // Parameterized constructor
    Complex_No(float r, float i) {
        real = r;
        imaginary = i;
    }

    // Copy constructor
    Complex_No(const Complex_No& c) {
        real = c.real;
        imaginary = c.imaginary;
    }
    double Magnitude() {
        return sqrt((real * real) + (imaginary * imaginary));
    }
    Complex_No add(Complex_No c) {
        Complex_No temp;
        temp.real = real + c.real;
        temp.imaginary = imaginary + c.imaginary;
        return temp;
    }
    void Display() {
        cout << real << " + " << imaginary << "i" << endl;
    }
};
int main() {

    Complex_No c1;                 // Default constructor
    Complex_No c2(4,4);           // Parameterized constructor
    Complex_No c3(c2);             // Copy constructor
    cout << "Complex number c1: ";
    c1.Display();

    cout << "Complex number c2: ";
    c2.Display();

    cout << "Complex number c3: ";
    c3.Display();

    Complex_No c4 = c2.add(c3);  
    cout << "Sum of c2 and c3: ";
    c4.Display();

    cout << "Magnitude of c2: " << c2.Magnitude() << endl;

    return 0;
}
