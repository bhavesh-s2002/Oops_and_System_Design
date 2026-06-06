// Description: This code demonstrates the Liskov Substitution Principle (LSP) being violated in a banking system. The FixedDepositAccount class inherits from the Account class but does not support the withdraw operation, which is expected from an Account class. This violates the LSP as it cannot be substituted for an Account without altering the expected behavior of the program. Ideally, we should have separate classes for different types of accounts that do not inherit from a common base class if they do not share the same behavior.

#include <bits/stdc++.h>
using namespace std;

class Account{
    public:
        string name;
        double Balance;
        Account(string n, double b){
            name = n; Balance = b;
        }
        void getDetails(){
            cout <<"Account Holder: "<<name<<", Balance: $"<<Balance<<endl;
        }
        virtual void withdraw(double amount)=0; // Pure Virtual Function
        virtual void deposit(double amount)=0;
};
class SavingsAccount : public Account{
    public:
        SavingsAccount(string n, double b) : Account(n, b) {}
        void withdraw(double amount) {
            if (amount <= Balance) {
                Balance -= amount;
                cout<<"Withdrew $"<<amount<<" from "<<name<<"'s account. New Balance: $"<<Balance<<endl;
            } else {
                cout << "Insufficient funds" << endl;
            }
        }
        void deposit(double amount) {
            Balance += amount;
            cout <<"Deposited $"<<amount<<" to "<<name<<"'s account. New Balance: $"<<Balance<<endl;
        }
};
class CurrentAccount : public Account{
    public:
        CurrentAccount(string n, double b) : Account(n, b) {}
        void withdraw(double amount) {
            if (amount <= Balance) {
                Balance -= amount;
                cout<<"Withdrew $"<<amount<<" from "<<name<<"'s account. New Balance: $"<<Balance<<endl;
            } else {
                cout << "Insufficient funds" << endl;
            }
        }
        void deposit(double amount) {
            Balance += amount;
            cout <<"Deposited $"<<amount<<" to "<<name<<"'s account. New Balance: $"<<Balance<<endl;
        }
};
class FixedDepositAccount : public Account{ // Violates LSP as it does not support withdraw operation which is expected from an Account class.
    public:
        FixedDepositAccount(string n, double b) : Account(n, b) {}
        void withdraw(double amount) {
            throw runtime_error("Withdrawals not allowed from Fixed Deposit Account");
        }
        void deposit(double amount) {
            Balance += amount;
        }
};
class BankClients{
    vector<Account*> accounts;
    public:
        BankClients(vector<Account*> accs){
            accounts = accs;
        }
        void addAccount(Account* account){
            accounts.push_back(account);
        }
        void performTransactions(){
            for(auto acc : accounts){
                acc->getDetails();
                acc->deposit(1000);
                try{
                    acc->withdraw(50);
                }catch(const exception& e){        
                    cout << e.what() << endl;
                }
            }
        }
};

int main(){
    Account* acc1 = new SavingsAccount("Alice", 5000);
    Account* acc2 = new CurrentAccount("Bob", 3000);
    Account* acc3 = new FixedDepositAccount("Charlie", 10000);
    vector<Account*> accounts = {acc1, acc2, acc3};
    BankClients clients(accounts);
    clients.performTransactions();
    return 0;
}