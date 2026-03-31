#include<iostream>
using namespace std;
class Shape{
    protected:
    float Area;
    public:
    Shape(){
        Area = 0;
    }
    virtual void Calculate_Area() = 0;
    virtual void display(){
        cout<<"Area = "<<Area<<endl;
    }
};
class Circle : public Shape{
    protected:
    float radius;
    public:
    Circle(float r){
        radius = r;
    }
    void Calculate_Area(){
        Area = 3.14*radius*radius;
    }
    void display(){
        cout<<"Area of Circle = "<<Area<<endl;
    }
};
class Rectangle : public Shape{
    protected:
    float length , breadth;
    public:
        Rectangle(float l, float b){
            length = l;
            breadth = b;
        }
        void Calculate_Area(){
                Area = length * breadth;
        }
        void display(){
            cout<<"Area of Rectangle = "<<Area<<endl;
        }
};
int main(){
    Circle c(3);
    c.Calculate_Area();
    c.display();

    Rectangle r(4,5);
    r.Calculate_Area();
    r.display();
}