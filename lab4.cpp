#include <iostream>
#include <cstring>
using namespace std;

class Student {
    char *name;
    int roll_num;
    double marks[5];
    float percent;

public:
    Student() {
        char temp[80];
        cout << "Enter name: ";
        cin >> temp;
        name = new char[strlen(temp) + 1];  
        strcpy(name, temp);
        cout << "Enter roll number: ";
        cin >> roll_num;

        for (int i = 0; i < 5; i++) {
            cout << "Enter marks for test no. " << i + 1 << " : ";
            cin >> marks[i];
        }

        percent = 0;
    }

    Student(char *s, int r, double m[5]) {
        name = new char[strlen(s) + 1];
        strcpy(name, s);
        roll_num = r;

        for (int i = 0; i < 5; i++) {
            marks[i] = m[i];
        }

        percent = 0;
    }

    Student(Student &s) {
        name = new char[strlen(s.name) + 1];
        strcpy(name, s.name);
        roll_num = s.roll_num;

        for (int i = 0; i < 5; i++) {
            marks[i] = s.marks[i];
        }

        percent = s.percent;
    }

    ~Student() {
        delete[] name;
    }

    char* get_name() {
        return name;
    }

    int get_rollnum() {
        return roll_num;
    }

    double get_marks(int i) {
        return marks[i - 1];
    }

    float get_percent() {
        return percent;
    }

    void set_name(char *s) {
        delete[] name;
        name = new char[strlen(s) + 1];
        strcpy(name, s);
    }

    void set_roll(int r) {
        roll_num = r;
    }

    void set_marks(int n, double val) {
        marks[n - 1] = val;
    }

    void set_percent(float p) {
        percent = p;
    }

    void calc_percent();
    void grade();
    double highest_mark();
    void display();
};

void Student::calc_percent() {
    double sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += marks[i];
    }
    percent = (sum / 500) * 100;
}

void Student::grade() {
    calc_percent();
    cout << "Percentage: " << percent << "%\n";

    if (percent >= 80)
        cout << "Grade: A\n";
    else if (percent >= 60)
        cout << "Grade: B\n";
    else if (percent >= 50)
        cout << "Grade: C\n";
    else
        cout << "Grade: F\n";
}

double Student::highest_mark() {
    double max = marks[0];
    for (int i = 1; i < 5; i++) {
        if (marks[i] > max)
            max = marks[i];
    }
    return max;
}

void Student::display() {
    cout << "\nName: " << name;
    cout << "\nRoll No: " << roll_num << endl;
    grade();
    cout << "Highest Mark: " << highest_mark() << endl;
}

int main() {
    Student *s;
    s = new Student[5]; 

    for (int i = 0; i < 5; i++) {
        cout << "\nStudent " << i + 1 << " Details:\n";
        s[i].display();
    }

    delete[] s;
    return 0;
}
