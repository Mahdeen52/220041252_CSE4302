#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    const int accountNumber;
    string accountHolderName;
    string accountType;  
    double currentBalance;
    const double minimumBalance;

    static int totalAccountsCreated;
    static int totalAccountsPresent;
    static double totalSourceTaxCollected;

public:
    
    BankAccount(int accNo, string holderName, string type, double balance, double minBalance)
        : accountNumber(accNo), minimumBalance(minBalance) 
    {
        accountHolderName = holderName;
        accountType = type;
        currentBalance = balance;

        totalAccountsCreated++;
        totalAccountsPresent++;
    }

   
    ~BankAccount() {
        totalAccountsPresent--;
        cout << "Account of Mr./Ms. " << accountHolderName << " with account no " << accountNumber
             << " is destroyed with a balance of BDT " << currentBalance << endl;
    }

   
    void showInfo() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder Name: " << accountHolderName << endl;
        cout << "Account Type: " << accountType << endl;
        cout << "Current Balance: BDT " << currentBalance << endl;
        cout << "Minimum Balance: BDT " << minimumBalance << endl;
    }

   
    void showBalance() const {
        cout << "Current Balance: BDT " << currentBalance << endl;
    }

   
    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Invalid deposit amount!" << endl;
            return;
        }
        currentBalance += amount;
        cout << "Deposited: BDT " << amount << endl;
        showBalance();
    }

    
    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount!" << endl;
            return;
        }
        if (currentBalance - amount < minimumBalance) {
            cout << "Insufficient balance! Minimum balance requirement not met." << endl;
            return;
        }
        currentBalance -= amount;
        cout << "Withdrew: BDT " << amount << endl;
        showBalance();
    }

    
    void giveInterest(double interestRate = 3.0) {
        double interest = (interestRate / 100) * currentBalance;
        double tax = 0.10 * interest;  
        totalSourceTaxCollected += tax;
        double netInterest = interest - tax;
        currentBalance += netInterest;
        cout << "Interest of BDT " << interest << " applied. After tax deduction: BDT " << netInterest << endl;
        showBalance();
    }

    
    static int getTotalAccountsCreated() {
        return totalAccountsCreated;
    }

    static int getTotalAccountsPresent() {
        return totalAccountsPresent;
    }

    static double getTotalSourceTaxCollected() {
        return totalSourceTaxCollected;
    }
};


int BankAccount::totalAccountsCreated = 0;
int BankAccount::totalAccountsPresent = 0;
double BankAccount::totalSourceTaxCollected = 0.0;


void display_stat() {
    cout << "Total accounts created: " << BankAccount::getTotalAccountsCreated() << endl;
    cout << "Total accounts present: " << BankAccount::getTotalAccountsPresent() << endl;
    cout << "Total source tax collected: BDT " << BankAccount::getTotalSourceTaxCollected() << endl;
}


BankAccount Larger(const BankAccount A, const BankAccount B) {
    if (A.currentBalance > B.currentBalance) {
        return A;
    }
    return B;
}

int main() {
    BankAccount acc1(101, "John Doe", "savings", 5000, 1000);
    BankAccount acc2(102, "Jane Smith", "current", 3000, 500);

    acc1.showInfo();
    acc1.deposit(1500);
    acc1.withdraw(2000);
    acc1.giveInterest();

    acc2.showInfo();
    acc2.giveInterest(5.0);  


    display_stat();

  
    BankAccount largerAccount = Larger(acc1, acc2);
    cout << "The account with the larger balance belongs to: " << endl;
    largerAccount.showInfo();

    return 0;
}
