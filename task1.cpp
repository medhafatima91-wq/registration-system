#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;
string hashPassword(const string& password) {
    unsigned long hash = 5381;
    for (char c : password) {
        hash = ((hash << 5) + hash) + c;
        }
    return to_string(hash);
}
bool isUsernameTaken(const string& username) {
    ifstream file("database.txt");
    if (!file.is_open()) {
        return false; 
        }

    string fileUser, filePass;
    
    while (file >> fileUser >> filePass) {
        if (fileUser == username) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}
void registerUser() {
    string username, password;

    cout << "\n--- REGISTRATION ---" << endl;
    cout << "Enter a new username (no spaces): ";
    cin >> username;

    if (isUsernameTaken(username)) {
        cout << "Error: Username already exists! Please try a different one." << endl;
        return;
    }

    cout << "Enter a password (no spaces): ";
    cin >> password;

    
    ofstream file("database.txt", ios::app);
    if (!file.is_open()) {
        cout << " Error: Could not open the database file." << endl;
        return;
    }

    string hashedPassword = hashPassword(password);
    file << username << " " << hashedPassword << endl;
    file.close();

    cout << " Success: Registration completed successfully!" << endl;
}

void loginUser() {
    string username, password;

    cout << "\n--- LOGIN ---" << endl;
    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream file("database.txt");
    if (!file.is_open()) {
        cout << "Error: No registered users found in the system yet." << endl;
        return;
    }

    string fileUser, filePass;
    string hashedInputPassword = hashPassword(password);
    bool loginSuccess = false;

    while (file >> fileUser >> filePass) {
        if (fileUser == username && filePass == hashedInputPassword) {
            loginSuccess = true;
            break;
        }
    }
    file.close();

    if (loginSuccess) {
        cout << "Success: Login successful! Welcome back, " << username << "." << endl;
    } else {
        cout << " Error: Invalid username or password." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << "\n===============================" << endl;
        cout << "  LOGIN & REGISTRATION SYSTEM  " << endl;
        cout << "===============================" << endl;
        cout << "1. Register" << endl;
        cout << "2. Login" << endl;
        cout << "3. Exit" << endl;
        cout << "Enter your choice (1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                registerUser();
                break;
            case 2:
                loginUser();
                break;
            case 3:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << " Invalid choice! Please enter a number between 1 and 3." << endl;
        }
    }

    return 0;
}