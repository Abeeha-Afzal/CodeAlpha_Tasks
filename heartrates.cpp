#include<iostream>
using namespace std;
class HeartRates{
    string FirstName;
    int roll;
    int date,month,year;
    public:
    HeartRates(string fname,int r,int d,int m,int y){
        FirstName = fname;
        roll = r;
        date = d;
        month = m;
        year = y;
    }
    string getFirstName(){
        return FirstName;
    }
    int getroll(){
        return roll;
    }
    int getdate(){
        return date;
    }
    int getmonth(){
        return month;
    }
    int getyear(){
        return year;
    }
    int getAge(int CurrentYear){
        return CurrentYear - year;
    }
    int getMaximumHeartRate(int CurrentYear){
        int age = getAge(CurrentYear);
        return 220 - age;
    }
    void getTargetHeartRate(int CurrentYear){
        int maxrate = getMaximumHeartRate(CurrentYear);
        double lower = 0.50 * maxrate;
        double upper = 0.85 * maxrate; 
        cout<<"----Target Heart Rate----\n"<<lower<<"-"<<upper<<"beats per minute"<<endl;

    }


};
int main(){
    string name;
    int roll;
    int date,month,year;
    int CurrentYear;

    cout<<"Enter your first name: ";
    cin>>name;
    cout<<"Enter you roll number: ";
    cin>>roll;
    cout<<"Enter your date of birth: ";
    cin>>date;
    cout<<"Enter your month of birth: ";
    cin>>month;
    cout<<"Enter your birth year: ";
    cin>>year;
    cout<<"Enter current year: ";
    cin>>CurrentYear;

    int uniqueId = roll%10;

    HeartRates hr(name,uniqueId,date,month,year);
    
    cout << "\n----- User Information -----\n";
    cout << "First Name: " << hr.getFirstName() << endl;
    cout << "Unique ID (3rd digit of roll): " << hr.getroll() << endl;  // 
    cout << "Birth Date: " << hr.getdate() << "/"
         << hr.getmonth() << "/" << hr.getyear() << endl;

    cout << "Age: " << hr.getAge(CurrentYear) << " years" << endl;
    cout << "Maximum Heart Rate: " << hr.getMaximumHeartRate(CurrentYear) << " bpm" << endl;
    hr.getTargetHeartRate(CurrentYear);

    return 0;
}

