/*//INLINE FUNCTION:

#include <iostream>
using namespace std;

class Student {
    string name;
    int roll;
    int marks[3];

    public:
    void set_name(string n) {
        name = n;
    }

    void set_roll(int r) {
        roll = r;
    }

    void set_marks(int m1, int m2, int m3) {
        marks[0] = m1;
        marks[1] = m2;
        marks[2] = m3;
    }

    void print_student() {
    cout << "Student name: <" << name << ">" << endl;
    cout << "Roll number: <" << roll << ">" << endl;
    cout << "Marks:" << endl;
    cout << "Quiz1: <" << marks[0] << ">" << endl;
    cout << "Quiz2: <" << marks[1] << ">" << endl;
    cout << "Quiz3: <" << marks[2] << ">" << endl;
}


    float Avg() {
        return (marks[0] + marks[1] + marks[2]) / 3.0;
    }
};

int main() {
    Student s;

    s.set_name("Abeeha");
    s.set_roll(114);
    s.set_marks(80, 85, 90);

    s.print_student();
    cout << "Average: " << s.Avg();

    return 0;
}
*/

//OUT OF LINE FUNCTION:
#include <iostream>
using namespace std;

class Student {
    string name;
    int roll;
    int marks[3];

public:
    void set_name(string n);
    void set_roll(int r);
    void set_marks(int m1, int m2, int m3);
    void print_student();
    float Avg();
};

void Student::set_name(string n) {
    name = n;
}

void Student::set_roll(int r) {
    roll = r;
}

void Student::set_marks(int m1, int m2, int m3) {
    marks[0] = m1;
    marks[1] = m2;
    marks[2] = m3;
}

void Student::print_student() {
    cout << "Student name: <" << name << ">" << endl;
    cout << "Roll number: <" << roll << ">" << endl;
    cout << "Marks:" << endl;
    cout << "Quiz1: <" << marks[0] << ">" << endl;
    cout << "Quiz2: <" << marks[1] << ">" << endl;
    cout << "Quiz3: <" << marks[2] << ">" << endl;
}

float Student::Avg() {
    return (marks[0] + marks[1] + marks[2]) / 3.0;
}

int main() {
    Student s;

    s.set_name("Abeeha");
    s.set_roll(114);
    s.set_marks(80, 85, 90);

    s.print_student();
    cout << "Average: " << s.Avg();

    return 0;
}
