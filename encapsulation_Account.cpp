#include<iostream>
using namespace std;

class Account{
    private:
    int id;
    string name;
    int balance;
    public:
    // constructor
    Account(int id, string name){
        this->id = id;
        this->name = name;
    }
    Account(int id, string name, int balance){
        this->id = id;
        this->name = name;
        this->balance = balance;
    }
    // set and information customer
    int getId(){
        return id;
    }
    void setName(string name){
        this->name = name;
    }
    string getName(){
        return name;
    }
    int getBalance(){
        return balance;
    }
    //  method is used to deposit an amount of money
    void deposit(int amount){
        balance += amount;
    }   
    //method used to withdraw an amound of money 
    void withdraw(int amount){
        if(balance < amount){
            cout << "That amount exceeds your current balnce." << endl;
        }
        else{
            balance -= amount;
        }
    }
    // method is used to show the account information 
    void display(){
        cout << "Id: " << id << endl;
        cout << "Name: " << name << endl;
        cout << "Balance: " << balance << endl;
    }
};

// the program is used to test Account class
int main(){
    Account account1(1000, "Tuan", 2000);
    account1.display();
    account1.withdraw(2200);
    account1.deposit(600);
    cout << "Balance: " << account1.getBalance() << endl;
    account1.withdraw(2100);
    cout << "Balance: " << account1.getBalance() << endl;
    return 0;
}