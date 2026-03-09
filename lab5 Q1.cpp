//  Q4 
#include<iostream>
using namespace std;
class Post{
    string name;
    string to;
    float StampCost;
    public:
    Post(){
        StampCost = 1;
        to = " ";
    }
    void read(){
        cout<<"Enter name: ";
        cin>>name;
        cout<<"Enter Receiver's Address: ";
        cin>>to;
        cout<<"Enter the stampcost: ";
        cin>>StampCost;
    }
    void Print(){
        cout<<"Name: "<<name<<endl;
        cout<<"Receivers Address: "<<to<<endl;
        cout<<"Stamp Cost: "<<StampCost<<endl;
    }
    float TotalCost(){
        return StampCost;
    }

};
class RegisteredPost : public Post{
    float weight;
    float RegistrationCost;
    public:
    RegisteredPost(){
        weight = 20;
        RegistrationCost = 10;
    }
    void read(){
        Post::read();
        cout<<"Enter Weight: ";
        cin>>weight;
        cout<<"Enter the Registration Cost: ";
        cin>>RegistrationCost;
    }
    void Print(){
        Post::Print();
        cout<<"Weight: "<<weight<<endl;
        cout<<"Registration Cost: "<<RegistrationCost<<endl;
    }
    float TotalCost(){
        return Post::TotalCost()+RegistrationCost;
    }
};
//Q5 continued...
class InsuredRegisteredPost : public RegisteredPost{
    int amtInsured;
    public:
    InsuredRegisteredPost(){
        amtInsured = 20;
    }
    void Read(){
        RegisteredPost::read();
            cout<<"Enter AmtInsured value: ";
            cin>>amtInsured;
    }
    void Print(){
        RegisteredPost::Print();
        cout<<"AmtInsured value: "<<amtInsured<<endl;
    }
    float TotalCost(){
        return RegisteredPost::TotalCost()+amtInsured;
    }
};
int main(){
    InsuredRegisteredPost envelope;
    envelope.read();
    cout<<"\n----Post Details---\n";
    envelope.Print();
}
