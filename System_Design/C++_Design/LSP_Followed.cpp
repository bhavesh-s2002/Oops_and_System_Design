// Description: This code demonstrates the Liskov Substitution Principle (LSP) being followed in a banking system. The FixedDepositAccount class inherits from the NonWithdrawablwAccount class that does not support the withdraw operation, which is expected from an Account class. So, now every subclass can be substituted in place of its parent class and LSP is followed.

#include <bits/stdc++.h>
using namespace std;

class NonWithdrawableAccount{
    public:
        string name;
        double Balance;
        NonWithdrawableAccount(string n, double b){
            name = n; Balance = b;
        }
        void getDetails(){
            cout <<"Account Holder: "<<name<<", Balance: $"<<Balance<<endl;
        }
        virtual void deposit(double amount)=0;
};
class Account : public NonWithdrawableAccount{
    public:
        Account(string n, double b) : NonWithdrawableAccount(n, b) {}
        virtual void withdraw(double amount)=0; // Pure Virtual Function
        void deposit(double amount) override {
            Balance += amount;
            cout <<"Deposited $"<<amount<<" to "<<name<<"'s account. New Balance: $"<<Balance<<endl;
        }
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
class FixedDepositAccount : public NonWithdrawableAccount{ // Follows LSP as it only provides the functionality that it's designed for.
    public:
        FixedDepositAccount(string n, double b) : NonWithdrawableAccount(n, b) {}
        void deposit(double amount) {
            Balance += amount;
            cout <<"Deposited $"<<amount<<" to "<<name<<"'s account. New Balance: $"<<Balance<<endl;
        }
};
class BankClients{
    vector<NonWithdrawableAccount*> nonWithdrawableAccounts;
    vector<Account*> Accounts;
    public:
        BankClients(vector<Account*> accs, vector<NonWithdrawableAccount*> nonWithdrawableAccs){
            Accounts = accs;
            nonWithdrawableAccounts = nonWithdrawableAccs;
        }
        void addAccount(Account* account){
            Accounts.push_back(account);
        }
        void addNonWithdrawableAccount(NonWithdrawableAccount* account){
            nonWithdrawableAccounts.push_back(account);
         }
        void performTransactions(){
            for(auto acc : Accounts){
                acc->getDetails();
                acc->deposit(1000);
                acc->withdraw(500);
            }
            for(auto acc : nonWithdrawableAccounts){
                acc->getDetails();
                acc->deposit(1000);
            }
        }
};

int main(){
    Account* acc1 = new SavingsAccount("Alice", 5000);
    Account* acc2 = new CurrentAccount("Bob", 3000);
    NonWithdrawableAccount* acc3 = new FixedDepositAccount("Charlie", 10000);
    vector<Account*> accounts = {acc1, acc2};
    vector<NonWithdrawableAccount*> nonWithdrawableAccounts = {acc3};
    BankClients clients(accounts, nonWithdrawableAccounts);
    clients.performTransactions();
    return 0;
}