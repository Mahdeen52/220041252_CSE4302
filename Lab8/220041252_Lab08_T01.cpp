#include <iostream>
#include <string>
using namespace std;

class Account {
protected:
    string accountNo;
    string accountName;
    float balance;

public:
    Account(const string& Name, float OpeningBalance) : accountName(Name), balance(OpeningBalance) {}

    string getAccountNo() const { 
        return accountNo; 
    }
    void setAccountNo(const string& accNo) { 
        accountNo = accNo;
     }

    string getAccountName() const { 
        return accountName;
     }
    void setAccountName(const string& name) { 
        accountName = name; 
    }

    float getBalance() const { 
        return balance; 
    }
    void setBalance(float amount) { 
        balance = amount;
     }
};


class CurrentAccount : public Account {
    private:
    const static int serviceCharge = 100;
    const static int accountPrefix = 100;
    static int nextAccount;
public:
    CurrentAccount(const string& name, float OpeningBalance) : Account(name, OpeningBalance) {
        setAccountNo(to_string(accountPrefix) + "-" + to_string(nextAccount++));
    }

    static int getServiceCharge() { 
        return serviceCharge;
     }

    static int getaccountPrefix() {
        return  accountPrefix;

    }

    static int getNextAccountNo() { 
        return nextAccount;
     }
    static void setNextAccountNo(int next_no) { 
        nextAccount = next_no;
     }
};

int CurrentAccount::nextAccount = 1;


class SavingsAccount : public Account {
    private:
    float interestRate;
    float monthlyDepositAmount;
    const static int accountPrefix=200;
    static int nextAccount;

    public:
    SavingsAccount(const string& name, float initialBalance, float interest, float monthlyDeposit)
        : Account(name, initialBalance), interestRate(interest), monthlyDepositAmount(monthlyDeposit) {
        setAccountNo(to_string(accountPrefix) + "-" + to_string(nextAccount++));
    }

    float getInterestRate() const { 
        return interestRate;
     }

     void setInterestRate(float rate) { 
        interestRate = rate;
     }

    float getMonthlyDepositAmount() const { 
        return monthlyDepositAmount; 
    }

    void setMonthlyDepositAmount(float amount) { 
        monthlyDepositAmount = amount;
     }

    static int getNextAccountNo() { 
        return nextAccount; 
    }

    static void setNextAccountNo(int next_no) { 
        nextAccount = next_no;
     }
};

int SavingsAccount::nextAccount = 1;


class MonthlyDepositScheme: public Account {
private:
    float interestRate;
    float monthlyDepositAmount;
    const static int accountPrefix=300;
    static int nextAccount;

    public:
    MonthlyDepositScheme(const string& name, float initialBalance) : Account(name, initialBalance) {
        setAccountNo(to_string(accountPrefix) + "-" + to_string(nextAccount++));
    }

    static int getNextAccountNo() { 
        return nextAccount; 
    }
    static void setNextAccountNo(int nextNo) { 
        nextAccount = nextNo; 
    }
};

int MonthlyDepositScheme::nextAccount = 1;

class LoanAccount : public Account {
private:
    float monthlyDepositAmount;
    float interestRate;
    const static int accountPrefix = 900;
    static int nextAccount;

public:
    LoanAccount(const string& name, float initialBalance, float amount, float interest)
        : Account(name, initialBalance), monthlyDepositAmount(amount), interestRate(interest) {
        setAccountNo(to_string(accountPrefix) + "-" + to_string(nextAccount++));
    }

    float getmonthlyDepositAmount() const { 
        return monthlyDepositAmount; 
    }
    void setmonthlyDepositAmount(float amount) { 
        monthlyDepositAmount = amount;
     }

    float getInterestRate() const { 
        return interestRate;
     }
    void setInterestRate(float rate) { 
        interestRate = rate;
     }

    static int getNextAccountNo() { 
        return nextAccount; 
    }
    static void setNextAccountNo(int nextNo) { 
        nextAccount = nextNo; 
    }
};

int LoanAccount::nextAccount = 1;

class TwoYearMDS: public MonthlyDepositScheme{
    private: 
    float maximuminterest;

    public: TwoYearMDS(const string& Name, float initialBalance, float maxInterest) 
    : MonthlyDepositScheme(Name,initialBalance),maximuminterest(maxInterest) {}


    float getMaximumInterest() const {
        return maximuminterest;
    }

    void setMaximumInterest(float maxInterest) {
        maximuminterest = maxInterest;
    }
};

class FiveYearMDS: public MonthlyDepositScheme{
    private: float maximuminterest;

    public: FiveYearMDS(const string& Name, float initialBalance, float maxInterest) 
    : MonthlyDepositScheme(Name,initialBalance),maximuminterest(maxInterest) {}


    float getMaximumInterest() const {
        return maximuminterest;
    }

    void setMaximumInterest(float maxInterest) {
        maximuminterest = maxInterest;
    }
};


class InitialDepositMDS: public MonthlyDepositScheme{
    private: float maximuminterest;
             float initialDepositAmount;

    public: InitialDepositMDS(const string& Name, float initialBalance, float maxInterest, float iniAmount) 
    : MonthlyDepositScheme(Name,initialBalance),maximuminterest(maxInterest), initialDepositAmount(iniAmount)  {}


    float getMaximumInterest() const {
        return maximuminterest;
    }

    void setMaximumInterest(float maxInterest) {
        maximuminterest = maxInterest;
    }
    
    float getinitialDepositAmount() const{
        return initialDepositAmount;
    }
};


int main() {
    CurrentAccount current("Rahim", 500);
    SavingsAccount savings("Karim", 1000, 3.5, 100);
    MonthlyDepositScheme mds("Jabbar", 2000);
    LoanAccount loan("Iqbal", 1500, 5000, 5);

    TwoYearMDS twoYearAccount("Shafiq", 2500, 5.0f);
    FiveYearMDS fiveYearAccount("Shahbaz", 3000, 6.5f);
    InitialDepositMDS initialDepositAccount("Nadeem", 3500, 4.0f, 500);

    cout << "Current Account Details:"<<endl;
    cout << "Account No: " << current.getAccountNo() <<endl;
    cout << "Account Name: " << current.getAccountName() <<endl;
    cout << "Balance: " << current.getBalance()<<endl;
    cout << "Service Charge: " << current.getServiceCharge() <<endl;
    cout<<endl;

    cout << "Savings Account Details:"<<endl;
    cout << "Account No: " << savings.getAccountNo()<<endl;
    cout << "Account Name: " << savings.getAccountName() <<endl;
    cout << "Balance: " << savings.getBalance() <<endl;
    cout << "Interest Rate: " << savings.getInterestRate() <<"%"<<endl;
    cout << "Monthly Deposit:" << savings.getMonthlyDepositAmount() <<endl;
    cout<<endl;

    cout << "Monthly Deposit Scheme Details:"<<endl;
    cout << "Account No: " << mds.getAccountNo() <<endl;
    cout << "Account Name: " << mds.getAccountName() <<endl;
    cout << "Balance: " << mds.getBalance() <<endl;
    cout<<endl;

    cout << "Loan Account Details:"<<endl;
    cout << "Account No: " << loan.getAccountNo() <<endl;
    cout << "Account Name: " << loan.getAccountName() <<endl;
    cout << "Balance: " << loan.getBalance() <<endl;
    cout << "Loan Amount: " << loan.getmonthlyDepositAmount()<<endl;
    cout << "Interest Rate: " << loan.getInterestRate() << "%"<<endl;
    cout<<endl;

    cout << "Two-Year MDS Account Details:"<<endl;
    cout << "Account No: " << twoYearAccount.getAccountNo() <<endl;
    cout << "Account Name: " << twoYearAccount.getAccountName() <<endl;
    cout << "Balance: " << twoYearAccount.getBalance() <<endl;
    cout << "Maximum Interest: " << twoYearAccount.getMaximumInterest() << "%"<<endl;
    cout<<endl;

    cout << "Five-Year MDS Account Details:"<<endl;
    cout << "Account No: " << fiveYearAccount.getAccountNo() <<endl;
    cout << "Account Name: " << fiveYearAccount.getAccountName() <<endl;
    cout << "Balance: " << fiveYearAccount.getBalance() <<endl;
    cout << "Maximum Interest: " << fiveYearAccount.getMaximumInterest() << "%"<<endl;
    cout<<endl;

    cout << "Initial Deposit MDS Account Details:"<<endl;
    cout << "Account No: " << initialDepositAccount.getAccountNo() <<endl;
    cout << "Account Name: " << initialDepositAccount.getAccountName() <<endl;
    cout << "Balance: " << initialDepositAccount.getBalance() <<endl;
    cout << "Maximum Interest: " << initialDepositAccount.getMaximumInterest() << "%"<<endl;
    cout << "Initial Deposit Amount: $" << initialDepositAccount.getinitialDepositAmount() <<endl;

    return 0;
}





