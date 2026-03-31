/*#include<iostream>
using namespace std;
class Book{
    public:
    string name;
    public:
    Book(string n){
        name = n;
        cout<<"Book Constructor called";
    }
    void display(){
        cout<<"Book: "<<name;
    }
};
class Library{
    public:
    string location;
    Book* book;
    public:
    Library(Book* b,string loc){
        book =b;
        location = loc;
        cout<<"Library Constructor called";
    }
    void display(){
        cout<<"Location: "<<location;
        book->display();
    }
};
int main(){
    Book mybook("Harry Potter");
    Library l(&mybook,"123street");
    l.display();
}
*/

#include<iostream>
using namespace std;
class Course{
    string Coursename;
    public:
    Course(string n){
        Coursename = n;
        cout<<"Course constructor called"<<endl;
    }
    void show(){
        cout<<"Course: "<<Coursename<<endl;
    }
};
class Student{
    string name;
    Course* course;
    public:
    Student(Course* c,string n){
        course = c;
        name = n;
        cout<<"Student created:"<<name<<endl;
    }
    void show(){
        cout<<name<<"Enrolled In";
        course->show();
    }
};
int main(){
    Course c1("OOP");
    Course c2("DS");
    Student s1(&c1,"Abeeha");
    s1.show();
    s1.show();
}