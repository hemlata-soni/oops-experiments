#include <iostream>
using namespace std;
class Account
{
    double balance;

public:
    Account(double b)
    {
        balance = b;
    }
    friend void transfer(Account &A1, Account &A2);
    void printBalance()
    {
        cout << "Balance: " << balance << endl;
    }
};

void transfer(Account &A1, Account &A2)
{
    A2.balance += A1.balance;
    A1.balance = 0.0;
}

int main()
{
    Account A1(1000);
    Account A2(2000);

    cout << "Before transfer:" << endl;
    A1.printBalance();
    A2.printBalance();

    transfer(A1, A2);

    cout << "\nAfter transfer:" << endl;
    A1.printBalance();
    A2.printBalance();

    return 0;
}