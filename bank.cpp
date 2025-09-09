#include <iostream>
#include <string>
using namespace std;

// ---------------- Customer ----------------
class Customer {
private:
    string Name;
    int Age;
    string DOB;
    string Pan_card_no;
    int Credit_Score;
    string Aadhar_card_Number;

public:
    Customer(string name, int age, string dob, string pan, int score, string aadhar)
        : Name(name), Age(age), DOB(dob), Pan_card_no(pan),
          Credit_Score(score), Aadhar_card_Number(aadhar) {}

    void Get_Balance() {
        cout << "[Customer] " << Name << " checking balance..." << endl;
    }

    string getName() { return Name; }
};

// ---------------- Account ----------------
class Account {
protected:
    string Account_Holder_Name;
    int Account_Number;
    string Password;

public:
    Account(string holder, int number, string pwd)
        : Account_Holder_Name(holder), Account_Number(number), Password(pwd) {}

    bool Check_Password(string input) {  // fixed typo here
        cout << "[Account] Checking password..." << endl;
        return input == Password;
    }

    void Change_Password(string newPwd) {
        Password = newPwd;
        cout << "[Account] Password changed successfully." << endl;
    }

    string getHolderName() { return Account_Holder_Name; }
};

// ---------------- Savings ----------------
class Savings : public Account {
private:
    double Balance;

public:
    Savings(string holder, int number, string pwd, double bal)
        : Account(holder, number, pwd), Balance(bal) {}

    void Add_Balance(double amt) {  // fixed typo here
        Balance += amt;
        cout << "[Savings] Added " << amt << ". New balance: " << Balance << endl;
    }

    void Reduce_Balance(double amt) {
        if (amt <= Balance) {
            Balance -= amt;
            cout << "[Savings] Reduced " << amt << ". New balance: " << Balance << endl;
        } else {
            cout << "[Savings] Insufficient funds!" << endl;
        }
    }
};

// ---------------- Credit Account ----------------
class CreditAccount : public Account {  // renamed class for consistency
private:
    int Credit_Score;

public:
    CreditAccount(string holder, int number, string pwd, int score)
        : Account(holder, number, pwd), Credit_Score(score) {}

    void Get_Amount(double amt) {
        cout << "[Credit Account] Credit of " << amt << " granted." << endl;
    }

    void Fill_Debts(double amt) {
        cout << "[Credit Account] Debt of " << amt << " paid." << endl;
    }
};

// ---------------- Admin ----------------
class Admin {
private:
    int Id_No;
    string Position;
    string DOB;
    string Password;

public:
    Admin(int id, string pos, string dob, string pwd)
        : Id_No(id), Position(pos), DOB(dob), Password(pwd) {}

    bool Check_Password(string input) {
        cout << "[Admin] Checking admin password..." << endl;
        return input == Password;
    }

    void Change_Password(string newPwd) {
        Password = newPwd;
        cout << "[Admin] Admin password changed successfully." << endl;
    }
};

// ---------------- DEMO ----------------
int main() {
    cout << "=== Banking System Demo ===" << endl;

    // Create customer
    Customer c1("Alice", 30, "1994-01-01", "PAN123", 750, "AADHAR1234");
    c1.Get_Balance();

    // Create accounts (Savings + Credit) for the customer
    Savings s1("Alice", 1001, "pass123", 5000);
    CreditAccount ca1("Alice", 2001, "cred123", 700);

    // Savings operations
    s1.Add_Balance(1500);
    s1.Reduce_Balance(2000);

    // Credit operations
    ca1.Get_Amount(10000);
    ca1.Fill_Debts(2000);

    // Account password change
    s1.Check_Password("pass123");
    s1.Change_Password("newpass");

    // Admin
    Admin admin1(1, "Manager", "1980-05-05", "adminpwd");
    admin1.Check_Password("adminpwd");
    admin1.Change_Password("newadminpwd");

    cout << "=== Demo Complete ===" << endl;
    return 0;
}
