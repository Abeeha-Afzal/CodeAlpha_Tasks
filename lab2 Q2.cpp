#include<iostream>
using namespace std;
class Counter{
    public:
    int value;

    Counter(){
        value = 0;
    }
    int Increment(){
        value = value + 1;
        return value;
    }
    int Decrement(){
        value = value - 1;
        return value;
    }
};
int main(){
    Counter c1;
    cout<<"Original value is:\n "<<c1.value<<endl;
    cout<<"Value after incrementing:\n"<<c1.Increment()<<endl;
    cout<<"Value after decrementing:\n"<<c1.Decrement()<<endl;

}
