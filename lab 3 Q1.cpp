#include<iostream>
using namespace std;
class Student{
    string name;
    int roll_number;
    int marks;
    public:
    void set_data(string n,int r,int m){
        name = n;
        roll_number = r;
        marks = m;
    }
    void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Roll Number: "<<roll_number<<endl;
        cout<<"Marks: "<<marks<<endl;
    }
    int getRoll(){
        return roll_number;
    }
};
int main(){
    Student s[10];
    Student *p = s;

    string name;
    int roll_number;
    int marks;
    for(int i=0;i<10;i++){
        cout << "\nEnter record of student "<<i + 1<< endl;
        cout<<"Enter Name:\n";
        cin>>name;
        cout<<"Enter Roll Number:\n";
        cin>>roll_number;
        cout<<"Enter Marks:\n";
        cin>>marks;
        p[i].set_data(name,roll_number,marks);
    }
    cout<<"\n-------All Records------\n";
    for(int i=0;i<10;i++){
        cout << "\nStudent " << i + 1 << endl;
        p[i].display();

    }
    int SearchRoll;
    cout<<"Enter Roll No to search:\n";
    cin>>SearchRoll;
    for(int i = 0;i<10;i++){
        if(p[i].getRoll()==SearchRoll){
            cout<<"\nRecord found\n";
            p[i].display();
    }

    }

}