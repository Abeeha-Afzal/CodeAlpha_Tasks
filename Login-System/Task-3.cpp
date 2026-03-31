#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    Transaction(string t, double a) {
        type = t;
        amount = a;
    }
    void show() {
        cout << type << ": " << amount << endl;
    }
};

class Account {
private:
    int accNo;
    double balance;
    vector<Transaction> history;
public:
    Account() {
        accNo = 0;
        balance = 0;
    }
    void create(int id, double b) {
        accNo = id;
        balance = b;
    }
    int getAccNo() {
        return accNo;
    }
    void deposit(double amount) {
        balance += amount;
        history.push_back(Transaction("Deposit", amount));
    }
    void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
            history.push_back(Transaction("Withdraw", amount));
        } else {
            cout << "Insufficient Balance" << endl;
        }
    }
    void showDetails(string name) {
        cout << "Name: " << name << endl;
        cout << "Account No: " << accNo << endl;
        cout << "Balance: " << balance << endl;
    }
    void showHistory() {
        if (history.empty()) {
            cout << "No transactions" << endl;
            return;
        }
        for (int i = 0; i < (int)history.size(); i++) {
            history[i].show();
        }
    }
};

class Customer {
public:
    string name;
    Account acc;
    void createCustomer() {
        int id;
        double bal;
        cin.ignore();
        cout << "Enter Name: ";
        getline(cin, name);
        cout << "Enter Account No: ";
        cin >> id;
        cout << "Enter Initial Balance: ";
        cin >> bal;
        acc.create(id, bal);
    }
};
int findCustomer(vector<Customer>& customers, int id) {
    for (int i = 0; i < (int)customers.size(); i++) {
        if (customers[i].acc.getAccNo() == id) {
            return i;
        }
    }
    return -1;
}
int main() {
    vector<Customer> customers;
    int choice;

    do {
        cout << "\n==== Banking System ====" << endl;
        cout << "1. Create Customer" << endl;
        cout << "2. Deposit" << endl;
        cout << "3. Withdraw" << endl;
        cout << "4. Show Transactions" << endl;
        cout << "5. Show Account Info" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            Customer c;
            c.createCustomer();
            customers.push_back(c);
            cout << "Customer created successfully" << endl;
        }
        else if (choice == 2) {
            int id;
            double amt;

            cout << "Enter Account No: ";
            cin >> id;
            int index = findCustomer(customers, id);
            if (index == -1) {
                cout << "Account not found" << endl;
            } else {
                cout << "Enter Amount: ";
                cin >> amt;
                customers[index].acc.deposit(amt);
                cout << "Deposit successful" << endl;
            }
        }
        else if (choice == 3) {
            int id;
            double amt;
            cout << "Enter Account No: ";
            cin >> id;
            int index = findCustomer(customers, id);
            if (index == -1) {
                cout << "Account not found" << endl;
            } else {
                cout << "Enter Amount: ";
                cin >> amt;
                customers[index].acc.withdraw(amt);
            }
        }
        else if (choice == 4) {
            int id;
            cout << "Enter Account No: ";
            cin >> id;
            int index = findCustomer(customers, id);
            if (index == -1) {
                cout << "Account not found" << endl;
            } else {
                customers[index].acc.showHistory();
            }
        }
        else if (choice == 5) {
            int id;
            cout << "Enter Account No: ";
            cin >> id;
            int index = findCustomer(customers, id);
            if (index == -1) {
                cout << "Account not found" << endl;
            } else {
                customers[index].acc.showDetails(customers[index].name);
            }
        }
        else if (choice == 6) {
            cout << "Exiting..." << endl;
        }
        else {
            cout << "Invalid choice" << endl;
        }

    } while (choice != 6);

    return 0;
}