#include <iostream>
using namespace std;

class myclass {
    int data[2];   

public:
    int* p;     

public:
    myclass() {
        p = data;   
    }

    void set_data(int a, int b) {
        p[0] = a;
        p[1] = b;
    }
    void display() {
        cout << p[0] << " " << p[1] << endl;
    }
};

int main() {
    myclass* cp;
    cp = new myclass[3];
    cp[0].set_data(10, 20);
    cp[1].set_data(30, 40);
    cp[2].set_data(50, 60);

    for(int i = 0; i < 3; i++) {
        cout << "Object " << i + 1 << ": ";
        cp[i].display();
    }

    delete[] cp;   // free memory
    return 0;
}
