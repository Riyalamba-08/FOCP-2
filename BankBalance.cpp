#include<iostream>
using namespace std;

class Bank {
private:
    int accBalance[1001];
    bool isPresent[1001];

public:
    Bank() {
        for (int idx = 0; idx <= 1000; idx++) {
            accBalance[idx] = 0;
            isPresent[idx] = false;
        }
    }

    bool CREATE(int uid, int amt) {
        if (!isPresent[uid]) {
            isPresent[uid] = true;
            accBalance[uid] = amt;
            return true;
        } else {
            accBalance[uid] += amt;
            return false;
        }
    }

    bool DEBIT(int uid, int amt) {
        if (!isPresent[uid] || accBalance[uid] < amt) {
            return false;
        }
        accBalance[uid] -= amt;
        return true;
    }

    bool CREDIT(int uid, int amt) {
        if (!isPresent[uid]) {
            return false;
        }
        accBalance[uid] += amt;
        return true;
    }

    int BALANCE(int uid) {
        if (!isPresent[uid]) {
            return -1;
        }
        return accBalance[uid];
    }
};

int main() {
    int queries;
    cout << "Enter number of queries: ";
    cin >> queries;

    Bank obj;

    for (int i = 0; i < queries; i++) {
        int option;
        cout << "\nChoose operation:\n";
        cout << "1. CREATE\n2. DEBIT\n3. CREDIT\n4. BALANCE\n";
        cout << "Enter choice: ";
        cin >> option;

        if (option == 1) {
            int user, value;
            cout << "Enter User ID and Initial Balance: ";
            cin >> user >> value;

            if (obj.CREATE(user, value))
                cout << "Account created (true)" << endl;
            else
                cout << "User exists, amount added (false)" << endl;
        }
        else if (option == 2) {
            int user, value;
            cout << "Enter User ID and Amount: ";
            cin >> user >> value;

            if (obj.DEBIT(user, value))
                cout << "Debit successful (true)" << endl;
            else
                cout << "Debit failed (false)" << endl;
        }
        else if (option == 3) {
            int user, value;
            cout << "Enter User ID and Amount: ";
            cin >> user >> value;

            if (obj.CREDIT(user, value))
                cout << "Credit successful (true)" << endl;
            else
                cout << "Credit failed (false)" << endl;
        }
        else if (option == 4) {
            int user;
            cout << "Enter User ID: ";
            cin >> user;

            int res = obj.BALANCE(user);
            if (res == -1)
                cout << "User not found (-1)" << endl;
            else
                cout << "Balance: " << res << endl;
        }
        else {
            cout << "Invalid choice!" << endl;
        }
    }
    return 0;
}
