#include <bits/stdc++.h>
using namespace std;

class BankAccount {
protected:
    static int totalAC;
    int MIN_HIGH = 1000;
    long long acNo;
    double acBalance;

public:
    BankAccount() : acBalance(0) {
        totalAC++;
        acNo++;
    }

    BankAccount(long long a, double acBalance) : acBalance(acBalance) {
        totalAC++;
        acNo = a;
    }

    static int getTotalAC() {
        return totalAC;
    }

    double deposit(double money) {
        acBalance += money;
        return acBalance;
    }

    double withdraw(double money) {
        if (acBalance >= money) {
            acBalance -= money;
        } else {
            cout << "Insufficient balance!" << endl;
        }
        return acBalance;
    }

    void display() {
        cout << "Total Accounts: " << getTotalAC() << endl;
        cout << "Account Number: " << acNo << endl;
        cout << "Current Balance: " << acBalance << endl;
    }

    bool isHighValueAccount() const {
        return acBalance > MIN_HIGH;
    }

    long long getAccountNumber() const {
        return acNo;
    }

    double getBalance() const {
        return acBalance;
    }
};

int BankAccount::totalAC = 0;

class Bank {
    BankAccount arr[100];
    int currentAccounts = 0;
    static long long accountNo;

public:
    void addAccount(double initialBalance) {
        if (currentAccounts < 100) {
            arr[currentAccounts] = BankAccount(accountNo, initialBalance);
            currentAccounts++;
            accountNo++;
        } else {
            cout << "Maximum account limit reached." << endl;
        }
    }

    void displayAccounts() {
        for (int i = 0; i < currentAccounts; i++) {
            arr[i].display();
        }
    }

    void searchAccount(long long accountNo) {
        for (int i = 0; i < currentAccounts; i++) {
            if (arr[i].getAccountNumber() == accountNo) {
                cout << "Account found!" << endl;
                cout << "Account Number: " << arr[i].getAccountNumber() << endl;
                cout << "Current Balance: " << arr[i].getBalance() << endl;
                return;
            }
        }
        cout << "Account not found!" << endl;
    }
};

long long Bank::accountNo = 1000001;

int main() {
    Bank bank;

    bank.addAccount(1538);
    bank.addAccount(326);
    bank.addAccount(93279);
    bank.addAccount(387);
    bank.addAccount(37482);

    cout << "\nDisplaying all accounts:\n";
    bank.displayAccounts();

    cout << "\nSearching for account number 1000005:\n";
    bank.searchAccount(1000005);

    return 0;
}


/*test topic : 
1. class/encap, const
2. static,const
3. inheritance

tets day: Monday tuesday
*/





