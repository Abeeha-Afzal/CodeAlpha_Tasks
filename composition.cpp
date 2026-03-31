/*#include<iostream>
using namespace std;
class Engine{
    public:
    string type;
    public:
    Engine(string t){
        type = t;
        cout<<"Engine Created:"<<endl;
    }
    void display(){
        cout<<"Type: "<<type<<endl;
    }
};
class Wheels{
    public:
    Wheels(){
        cout<<"Wheels created: "<<endl;
    }
    void display(){
        cout<<"Wheel Rotating"<<endl;
    }
};
class Car{
    public:
    Engine e;
    Wheels w1,w2;
    public:
    Car():e("Petrol"){
        cout<<"Car Created"<<endl;
    }
    void display(){
        e.display();
        w1.display();
        w2.display();
    }
};
int main(){
    Car c1;
    c1.display();
}
*/

//Obj relationships
#include<iostream>
using namespace std;
class Vehicle{
    public:
    Vehicle(){
        cout<<"Vehicle Created."<<endl;
    }
    void showType(){
        cout<<"This is a vehicle."<<endl;
    }
};
class Engine{
    public:
    string type;
    public:
    Engine(string t){
        type = t;
        cout<<"Engine created."<<endl;
    }
    void display(){
        cout<<"Engine: "<<type<<endl;
    }
};
class Wheels{
    public:
    Wheels(){
        cout<<"Wheels Created."<<endl;
    }
    void display(){
        cout<<"Wheel rotating"<<endl;
    }
};
class Car: public Vehicle{
    public:
    Wheels w1,w2;
    Engine* engine;
    public:
    Car(Engine* e){
        engine = e;
        cout<<"Car created"<<endl;
    }
    void display(){
        showType();
        engine->display();
        w1.display();
        w2.display();    }
};
int main(){
    Engine e1("PETROL");
    Car c1(&e1);
    c1.display();
}