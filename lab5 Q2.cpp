//Q7
#include<iostream>
using namespace std;
class Product{
    string name;
    float productId;
    public:
    Product(string p, float pid){
        name = p;
        productId = pid;
    }
    void show(){
        cout<<"Product Name: "<<name<<endl;
        cout<<"Product ID: "<<productId<<endl;
    }
};
class UtilityItems:public Product{
    float discount;
    public:
    UtilityItems(string n,float pid,float d):Product(n,pid){
        discount = d;
    }
    void show(){
        Product::show();
        cout<<"Discount: "<<discount<<endl;
    }
};
class FoodItems:public Product{
    string exp_date;
    public:
    FoodItems(string n,float pid,string exp):Product(n,pid){
        exp_date = exp;
    }
    void show(){
        Product::show();
            cout<<"Expiry Date: "<<exp_date<<endl;
    }

};
int main(){
    UtilityItems u("broom",101,2);
    FoodItems f("Pomegranate",901,"01-03-2026");
    cout<<"\n----UTILITY ITEMS----\n";
    u.show();
    cout<<"\n----FOOD ITEMS----\n";
    f.show();
}
