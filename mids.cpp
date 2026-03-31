#include<iostream>
#include<string>
using namespace std;
class InventoryItem{
    protected:
    string name;
    double unitprice;
    public:
    virtual void Input(){
        cout<<"Enter item name: ";
        getline(cin,name);
        do{
            cout<<"Enter unit price: ";
            cin>>unitprice;
        }while(unitprice<=0);
    }
    virtual double TotalCost(){
        return unitprice;
    }
    virtual void display(){
        cout<<"Name: "<<name<<endl;
        cout<<"Unit Price: "<<unitprice<<endl;
        cout<<"Total Cost: "<<TotalCost<<endl;
    }
    virtual ~InventoryItem();
};
class BulkItem:public InventoryItem{
    protected:
    int quantity;
    public:
    void input(){
        InventoryItem::Input();
        do{
            cout<<"Enter Quantity: ";
            cin>>quantity;
        }while(quantity<=0);
    }
    double TotalCost(){
        InventoryItem::TotalCost();
        return unitprice*quantity;
    }
    void display(){
        InventoryItem::display();
        cout<<"Quantity: "<<quantity<<endl;
    }
};
