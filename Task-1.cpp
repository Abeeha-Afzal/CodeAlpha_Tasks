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
    return total;}
    double Calculate_GPA(){
    if(get_TotalCredits() == 0){
        return 0;
    }
    return get_TotalGradePoints() / get_TotalCredits();
}
    void display_Course(){
    for(int i = 0; i < (int)course.size(); i++){
        cout << "\nCourse " << i + 1 << endl;
        course[i].display_Course();
    }
}
};
class CGPA{
    int prev_credits;
    double prev_CGPA;
public:
    CGPA(int pc,double cg){
        prev_credits=pc;
        prev_CGPA=cg;
    }
    double overallCGPA(double currentPoints,int currentCredits){
    double prev_points = prev_CGPA * prev_credits;
    int totalCredits = prev_credits + currentCredits;
    if(totalCredits == 0){
        return 0;
    }
    return (prev_points + currentPoints) / totalCredits;
}
};
class Student: public StudentInfo{
    Semester semester;
    CGPA cg;
    public:
    Student(string n,int pc,double cgpa) : StudentInfo(n), cg(pc,cgpa){}
    void addCourse(Course c){
        semester.addCourse(c);
    }
    void report(){
        display_info();
        cout<<"\nCourse Details\n";
        semester.display_Course();

        cout<<"\nTotal Credits: "<<semester.get_TotalCredits()<<endl;
        cout << "\033[1;32mSemester GPA: " << semester.Calculate_GPA() << "\033[0m" << endl;
        cout << "\033[1;32mOverall CGPA: "<< cg.overallCGPA(semester.get_TotalGradePoints(),semester.get_TotalCredits())<< "\033[0m" << endl;
}
};

int main(){

    string name;
    int courses;

    int prevCredits;
    double prevCGPA;

    cout<<"Enter student name: ";
    getline(cin,name);

    cout<<"Enter previous total credits: ";
    cin>>prevCredits;

    cout<<"Enter previous CGPA: ";
    cin>>prevCGPA;

    Student s(name,prevCredits,prevCGPA);

    cout<<"Enter number of courses: ";
    cin>>courses;

    for(int i=0;i<courses;i++){
        string grade;
        int credit;
        cout<<"\nGrade for course "<<i+1<<": ";
        cin>>grade;
        cout<<"Credit hours: ";
        cin>>credit;
        Course c(grade,credit);
        s.addCourse(c);
    }
    cout<<"\n===== Final Report =====\n";
    s.report();
    return 0;
}
