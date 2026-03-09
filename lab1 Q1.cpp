/*//INLINE FUNCTION:

#include <iostream>
using namespace std;

class Complex {
    int real, imag;

    public:
    void set_real() {
        cout << "Enter real part: ";
        cin >> real;
    }

    void set_imag() {
        cout << "Enter imaginary part: ";
        cin >> imag;
    }

    void display() {
        cout <<"The Complex Number is: "<< real << "+" << imag << "i";
    }
};

int main() {
    Complex c;
    c.set_real();
    c.set_imag();
    c.display();
    return 0;
}
*/

//OUT OF LINE FUNCTION:

#include <iostream>
using namespace std;

class Complex {
    int real, imag;
 
    public:
    void set_real();
    void set_imag();
    void display();
};

void Complex::set_real() {
    cout << "Enter real part: ";
    cin >> real;
}

void Complex::set_imag() {
    cout << "Enter imaginary part: ";
    cin >> imag;
}

void Complex::display() {
    cout <<"The Complex Number is: "<< real << "+" << imag << "i";
}

int main() {
    Complex c;
    c.set_real();
    c.set_imag();
    c.display();
    return 0;
}
