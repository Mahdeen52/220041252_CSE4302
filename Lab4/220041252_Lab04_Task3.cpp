#include <iostream>
#include<string>
using namespace std;

class Employee{

private: string EmpName;
         int ID,Age;
         float Salary;
         string getStatus() {

            if(Age<=25) {
                if(Salary>20000) {
                 
                    return "Moderate Salaried Person";
                }

                else if(Salary<=20000) {
                   
                    return "Low Salaried Person";
                }
                else return "Invalid";

            }

            if(Age>25) {
                if(Salary<=21000) {
                  
                    return "Low Salaried Person";
                }

                else if(Salary>21000 && Salary <=60000) {
                  
                    return "Moderate Salaried Person";
                }

                else if (Salary>60000) {
                  
                    return "High Salaried Person";
                }

                else return "Invalid";

            }
        }

public: void FeedInfo() {

        cout<<"Enter Employee Name: ";
        cin>>EmpName;
        cout<<endl;

        cout<<"Enter Employee ID: ";
        cin>>ID;
        cout<<endl;

        cout<<"Enter Employee Salary: ";
        cin>>Salary;
        cout<<endl;
}


   void ShowInfo() {
            cout << "Employee Name: " << EmpName << endl;
            cout << "Employee ID: " << ID << endl;
            cout << "Employee Age: " << Age << endl;
            cout << "Employee Salary: " << Salary << endl;
            cout << "Employee Status: " << getStatus() << endl;
        }


    };



int main() {
    Employee emp;
    emp.FeedInfo(); 
    emp.ShowInfo();  
    return 0;
}