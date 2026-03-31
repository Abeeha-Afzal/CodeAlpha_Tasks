#include<iostream>
using namespace std;
class  DateTime{
    private:
    int day, month, year, hours, minutes, seconds;
    public:
    DateTime() {
        day = month = year = hours = minutes = seconds = 0;
    }
    void SetValue(int d, int m, int y){
        day = d;
        month = m;
        year = y;
    }
     void SetValue(int d, int m, int y, int h){
        day = d;
        month = m;
        year = y;
        hours = h;
    }
       void SetValue(int d, int m, int y, int h, int min){
        day = d;
        month = m;
        year = y;
        hours = h;
        minutes = min;
    }
       void SetValue(int d, int m, int y, int h, int min, int sec){
        day = d;
        month = m;
        year = y;
        hours = h;
        minutes = min;
        seconds = sec;
    }
    void display(){
        cout<<"Date: "<<day<<"/"<<month<<"/"<<year<<endl;
        cout<<"Time: "<<hours<<":"<<minutes<<":"<<seconds<<endl;
    }
};
int main(){
    DateTime dtime;
    dtime.SetValue(24,3,2026,10,30,45);
    dtime.display();
}