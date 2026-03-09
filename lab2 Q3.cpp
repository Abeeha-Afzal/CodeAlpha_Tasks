#include<iostream>
using namespace std;
class Counter{
    private:
    int value;
    public:
    Counter(int v){
        value = v;
    }
    friend void reset(Counter& c);
    void Display(){
        cout<<value<<endl;
    }
};
void reset(Counter& c){
    c.value = 0;
}
int main(){
    Counter c1(6);
    reset(c1);
    c1.Display();
}

 