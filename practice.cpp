/*
#include<iostream>
using namespace std;
class Student{
    string name;
    int roll_number;
    int marks[3];
    public:
    void set_name();
    void set_roll();
    void set_marks();
    void print_student();
};
void Student::set_name(){
    cout<<"Enter Student's name: ";
    cin>>name;
}
void Student::set_roll(){
    cout<<"Enter roll number: ";
    cin>>roll_number;
}
void Student::set_marks(){
    cout<<"Enter mark 1: ";
    cin>>marks[0];
    cout<<"Enter mark 2: ";
    cin>>marks[1];
    cout<<"Enter mark 2: ";
    cin>>marks[2];
}
void Student::print_student(){
    cout<<"Student name: <"<<name<<">"<<endl;
    cout<<"Roll Number: <"<<roll_number<<">"<<endl;
    cout<<"Marks: ";
    cout<<"Quiz 1: <"<<marks[0]<<">"<<endl;
    cout<<"Quiz 2: <"<<marks[1]<<">"<<endl;
    cout<<"Quiz 3: <"<<marks[2]<<">"<<endl;


}
int main(){
    Student s;
    s.set_name();
    s.set_roll();
    s.set_marks();
    s.print_student();
}



#include<iostream>
using namespace std;
class BankAccount{
    private:
    string name;
    int password;
    double balance;
    public:
    BankAccount(string n,int p,double b){
        name = n;
        password = p;
        balance = b;
    }
    void deposit(double amount){
        balance = balance + amount;
        cout<<"Amout deposited successfully.";

    }
    void withdraw(int p,double amount){
        if(p==password){
            if(amount<=balance){
                balance = balance - amount;
                cout<<"Amount withdrawn successfully.";
            }else{
                cout<<"Insufficient balance";
            }
        }else{
            cout<<"Wrong password";
        }
    }
    void checkbalance(int p){
        if(p==password){
            cout<<"Balance is : "<<balance<<endl;
        }else{
            cout<<"Incorrect Password";
        }
    }

};
int main(){
    BankAccount acc("Abeeha",1234,10000);
    acc.deposit(5000);
    acc.checkbalance(1234);
    
    acc.withdraw(1234,1000);
    acc.checkbalance(1234);

}


#include <iostream>
using namespace std;

class BankAccount{
private:
    string name;
    int password;
    double balance;

public:
    // Constructor
    BankAccount(string n, int p, double b){
        name = n;
        password = p;
        balance = b;
    }

    void deposit(double amount){
        balance = balance + amount;
        cout << "Amount deposited successfully." << endl;
    }

    void withdraw(int p, double amount){
        if(p == password){
            if(amount <= balance){
                balance = balance - amount;
                cout << "Amount withdrawn successfully." << endl;
            } else {
                cout << "Insufficient balance." << endl;
            }
        } else {
            cout << "Wrong password." << endl;
        }
    }

    void checkbalance(int p){
        if(p == password){
            cout << "Balance is: " << balance << endl;
        } else {
            cout << "Incorrect password." << endl;
        }
    }
};

int main(){

    string name;
    int password;
    double balance;

    // --- Account creation (user input) ---
    cout << "Enter name: ";
    cin >> name;

    cout << "Set password: ";
    cin >> password;

    cout << "Enter initial balance: ";
    cin >> balance;

    BankAccount acc(name, password, balance);

    // --- Deposit ---
    double depositAmount;
    cout << "\nEnter amount to deposit: ";
    cin >> depositAmount;
    acc.deposit(depositAmount);

    // --- Check balance ---
    int pass;
    cout << "\nEnter password to check balance: ";
    cin >> pass;
    acc.checkbalance(pass);

    // --- Withdraw ---
    double withdrawAmount;
    cout << "\nEnter password to withdraw: ";
    cin >> pass;

    cout << "Enter amount to withdraw: ";
    cin >> withdrawAmount;
    acc.withdraw(pass, withdrawAmount);

    // --- Final balance check ---
    cout << "\nEnter password to check balance again: ";
    cin >> pass;
    acc.checkbalance(pass);

    return 0;
}
*/
#include<iostream>
#include<cstring>
using namespace std;
class Balance{
    double curr_balance;
    char name[80];
    public:
    Balance(){
        curr_balance = 0;
        name[0] = '\0';
    }
    Balance(double b, char*s){
        curr_balance = b;
        strcpy(name,s);
    }
    void set_data(double n,char*s){
        curr_balance = n;
        strcpy(name,s);
    }
    ~Balance(){
        cout<<"Destructing"<<name<<endl;
    }
    void get_data(double &n, char*s){
        n=curr_balance;
        strcpy(s,name);
    }

};
int main(){
    Balance *p;
    char s[80];
    double n;
    p = new Balance[3];
    p[0].set_data(1124,"PRACHI");
    p[1].set_data(11256,"BIA");
    p[2].set_data(9000,"TAAB");
    for(int i = 0;i<3;i++){
        p[i].get_data(n,s);
        cout<<s<<"BALANCE IS: "<<n<<endl;

    }
    delete []p;
}