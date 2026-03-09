#include <iostream>
#include <cstring>
using namespace std;
class Student{
    protected:
    char*name;
    float percent;
    int roll_num;
    double marks[5];
public:
    Student(){
       char temp[80];
       cout<<"Enter name: "<<endl;
       cin>>temp;
       name=new char [strlen(temp+1)];
       strcpy(name,temp);
       cout<<"Enter roll number: "<<endl;
       cin>>roll_num;
       for(int i=0; i<5;i++){
        cout<<"Enter marks for test no."<<i+1<<" : "<<endl;
        cin>>marks[i];
       }
       percent=0;
    }
    
    Student(char *s, int r){
        name = new char[strlen(s)+1];
        strcpy(name,s);
        roll_num=r;
        for(int i=0; i<5;i++){
            cout<<"Enter marks for test no."<<i+1<<" : "<<endl;
            cin>>marks[i];
        }
        percent=0;
    }
    Student(Student &s){
        name=new char[strlen(s.name)+1];
        strcpy(name,s.name);
        roll_num=s.roll_num;
        for(int i=0; i<5;i++){
            marks[i]=s.marks[i];
        }
        percent=s.percent;
    }
    void cal_percent(){
        int sum=0;
        for(int i=0;i<5;i++){
            sum+=marks[i];
        }
        percent=(sum/500.0)*100;
    }
    char* get_name(){
        return name;
    }
    int get_rollnum(){
        return roll_num;
    }
    double get_marks(int i){
        return marks[i-1];
    }
    void set_name(char *s){
        delete []name;
        name = new char[strlen(s)+1];
        strcpy(name,s);
    }
    void set_roll(int r){
        roll_num=r;
    }
    void set_marks(int n){
        double num;
        cout<<"Enter new marks for test "<<n<<" : ";
        cin>>num;
        marks[n-1]=num;
    }
    double highest(){
        double max= marks[0];
        for(int i=0;i<5;i++){
            if(marks[i]>max){
                max=marks[i];
            }
    }
    return max;
}
void grade(){
    cal_percent();
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
void display(){
    cout << "\nName: " << name;
    cout << "\nRoll No: " << roll_num;
    cout << "\nPercentage: " << percent << "%\n";
}

~Student(){
    delete []name;
}
};
class ScienceStudent : public Student {
    double practicalMarks;

public:
    ScienceStudent(char *n, int r) : Student(n, r) {}

    void setPractical() {
        cout << "Enter Practical Marks (out of 150): ";
        cin >> practicalMarks;
    }

    double getPractical() {
        return practicalMarks;
    }

    void calculatePercentage() {
        double sum = 0;
        for(int i = 0; i < 5; i++)
            sum += marks[i];

        sum += practicalMarks;
        percent = (sum / 650) * 100;
    }

    void display() {
        calculatePercentage();
        cout << "\n--- Science Student ---";
        Student::display();
        cout << "Practical Marks: " << practicalMarks << endl;
    }
};
class ArtsStudent : public Student {
    double optionalMarks;

public:
    ArtsStudent(char *n, int r) : Student(n, r) {}

    void setOptional() {
        cout << "Enter Optional Subject Marks (out of 100): ";
        cin >> optionalMarks;
    }

    double getOptional() {
        return optionalMarks;
    }

    void calculatePercentage() {
        double sum = 0;
        for(int i = 0; i < 5; i++)
            sum += marks[i];
            sum += optionalMarks;
            percent = (sum / 600) * 100;
    }
    void display() {
        calculatePercentage();
        cout << "\n--- Arts Student ---";
        Student::display();
        cout << "Optional Marks: " << optionalMarks << endl;
    }
};
int main(){
    char name1[] = "Ayesha";
    ScienceStudent s1(name1, 101);
    s1.setPractical();
    s1.display();
    char name2[] = "Sara";
    ArtsStudent s2(name2, 102);
    s2.setOptional();
    s2.display();
    char name3[] = "Aleena";
    ScienceStudent s3(name3, 103);
    s3.setPractical();
    s3.display();
    char name4[] = "Alishba";
    ScienceStudent s4(name4, 104);
    s4.setPractical();
    s4.display();
    char name5[] = "bushra";
    ArtsStudent s5(name5, 105);
    s5.setOptional();
    s5.display();
    return 0;
}