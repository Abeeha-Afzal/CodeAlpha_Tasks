#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
using namespace std;

void Register_User() {
    system("color 0A"); // Green

    string username, password;

    cout << "\n--- Registration ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ofstream file("users.txt", ios::app);
    file << username << " " << password << endl;
    file.close();

    cout << "Registration Successful!\n";
}

void login_User() {
    system("color 0B"); // Blue

    string username, password;
    string fileUser, filePass;
    bool found = false;

    cout << "\n--- Login ---\n";
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("users.txt");
    while (file >> fileUser >> filePass) {
        if (fileUser == username && filePass == password) {
            found = true;
            break;
        }
    }
    file.close();
    if (found) {
        system("color 0A"); // Green
        cout << "Login Successful!\n";
    } else {
        system("color 0C"); // Red
        cout << "Invalid Username or Password!\n";
        system("pause");
        system("color 07"); // Back to default
    }
}

int main() {
    int choice;
    do {
        system("color 07"); // Default color
        cout << "\n===== MENU =====\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        if (choice == 1) {
            Register_User();
        }
        else if (choice == 2) {
            login_User();
        }
        else if (choice == 3) {
            cout << "Goodbye!\n";
        }
        else {
            system("color 0C"); // Red
            cout << "Invalid choice!\n";
            system("pause"); 
            system("color 07"); // Reset
        }
    } while (choice != 3);

    return 0;
} 