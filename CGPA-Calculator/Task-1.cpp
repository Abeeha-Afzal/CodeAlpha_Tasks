#include<iostream>
#include<vector>
#include<string>
using namespace std;
class StudentInfo{
    string name;
    public:
    StudentInfo(string n){
        name = n;
    }
    void display_info(){
        cout<<"Student Name: "<<name<<endl;
    }
};
class Course{
    string grade;     
    int credit_hrs;
    public:
    Course(string g,int c_hr){
        grade = g;
        credit_hrs = c_hr;
    }
    double get_Gradepoints(){
        double points;
        if(grade=="A+"||grade=="A"){
            points = 4;
        }
        else if(grade=="A-"){
            points = 3.7;
        }
        else if(grade=="B+"){
            points = 3.3;
        }
        else if(grade=="B") {
            points = 3.0;
        }
        else if(grade=="B-") {
            points = 2.7;
        }
        else if(grade=="C+"){
            points = 2.3;
        }
        else if(grade=="C"){
            points = 2.0;
        }
        else if(grade=="C-") {
            points = 1.7;
        }
        else if(grade=="D+") {
            points = 1.3;
        }
        else if(grade=="D") {
            points = 1.0;
        }
        else if(grade=="D-") {
            points = 0.7;
        }
        else points = 0;
        return credit_hrs * points;
    }
    int get_CreditHrs(){
        return credit_hrs;
    }
    void display_Course(){
        cout<<"Grade: "<<grade<<endl;
        cout<<"Credit Hours: "<<credit_hrs<<endl;
    }
};
class Semester{
    vector<Course>course;
    public:
    void addCourse(Course c){
        course.push_back(c);
    }
  int get_TotalCredits(){
    int total = 0;
    for(int i = 0;i<(int)course.size(); i++){
        total = total + course[i].get_CreditHrs();
    }
    return total;
}

double get_TotalGradePoints(){
    double total = 0;
    for(int i = 0;i<(int)course.size(); i++){
        total = total + course[i].get_Gradepoints();
    }
    return total;
}
    double Calculate_GPA(){
        return get_TotalGradePoints() / get_TotalCredits();
    }
        void displayCourses(){
        for(int i= 0;i<(int)course.size(); i++){
            cout << "\nCourse "<<i +1<< endl;
            course[i].display_Course();
        }
    }
};
class Student : public StudentInfo{
    Semester semester;
public:
    Student(string n) : StudentInfo(n){}
    void add_Student_Course(Course c){
        semester.addCourse(c);
    }
    void display_Report(){
        display_info();
        cout <<"\nCourse Details" << endl;
        semester.displayCourses();
        cout <<"\nTotal Credit Hours:"<<semester.get_TotalCredits() << endl;
        cout <<"Total Grade Points:"<<semester.get_TotalGradePoints() << endl;
        cout << "\033[1m\033[32mSemester GPA: " << semester.Calculate_GPA() << "\033[0m" << endl;
    }
};
int main(){
    string name;
    int total_courses;
    cout <<"Enter student name: ";
    getline(cin,name);
    Student s1(name);
    cout<<"Enter number of courses: ";
    cin>>total_courses;
    for(int i = 0; i<total_courses; i++){
        string grade;
        int credit_hrs;
        cout<<"\nEnter grade for course "<<i+1<<":";
        cin>>grade;
        cout<<"Enter credit hours for course "<<i+1<<":";
        cin >>credit_hrs;
        Course c1(grade,credit_hrs);
        s1.add_Student_Course(c1);
    }
    cout << "\n===== Final Semester Report =====" << endl;
    s1.display_Report();

    return 0;
}