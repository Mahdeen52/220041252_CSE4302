#include <iostream>
#include <string>
#include <ctime>
#include <algorithm>

using namespace std;

class Employee {
private:
    string name;
    tm dateOfBirth; 
    double salary;
public:

Employee() : name("John Doe"), salary(10000) {
        dateOfBirth.tm_year = 102;
        dateOfBirth.tm_mon = 0;
        dateOfBirth.tm_mday = 1;
    }
    
    int calculateAge(const tm& currentDate) const {
        int age = currentDate.tm_year - dateOfBirth.tm_year;
        if ((currentDate.tm_mon < dateOfBirth.tm_mon) || 
            (currentDate.tm_mon == dateOfBirth.tm_mon && currentDate.tm_mday < dateOfBirth.tm_mday)) {
            age--;
        }
        return age;
    }


    void setName(const string& newName) {
        if (newName.length() > 2) {
            name = newName;
        } else {
            name = "John Doe";
        }
    }

    void setDateOfBirth(int year, int month, int day) {
        tm now;
        time_t t = time(nullptr);
        localtime_r(&t, &now);

        int age = now.tm_year + 1900 - year;
        if (age > 18) {
            dateOfBirth.tm_year = year - 1900; 
            dateOfBirth.tm_mon = month - 1;
            dateOfBirth.tm_mday = day;
        } 
        
        else {
            dateOfBirth.tm_year = 102;
            dateOfBirth.tm_mon = 0;
            dateOfBirth.tm_mday = 1;
        }
    }

    void setSalary(double newSalary) {
        if (newSalary >= 10000 && newSalary <= 100000) {
            salary = newSalary;
        } else {
            salary = 10000;
        }
    }

    string getName() const { 
        return name; 
        
    }
    tm getDateOfBirth() const { 
        return dateOfBirth; 
        
    }
    double getSalary() const { 
        return salary;
        
    }

    int getAge() const {
        tm now;
        time_t t = time(nullptr);
        localtime_r(&t, &now);
        return calculateAge(now);
    }

    void setInfo(const string& newName, int year, int month, int day, double newSalary) {
        setName(newName);
        setDateOfBirth(year, month, day);
        setSalary(newSalary);
    }

    void getInfo() const {
        cout << "Name: " << name << endl;
        cout << "Date of Birth: " << dateOfBirth.tm_mday << "/"
             << dateOfBirth.tm_mon + 1 << "/" << dateOfBirth.tm_year + 1900 << endl;
        cout << "Salary: BDT " << salary << endl;
        cout << "Age: " << getAge() << " years" << endl;
    }

   const Employee& compareAge(const Employee& e) const {
    if (this->getAge() > e.getAge()) {
        return *this;
    } 
    else {
        return e;
    }
}
};

void generateInformationRandom(Employee& e) {
    string names[] = {"Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah"};
    string name = names[rand() % 8];

    int year = 1980 + rand() % 24;
    int month = 1 + rand() % 12;
    int day = 1 + rand() % 28;

    double salary = 10000 + (rand() % 91) * 1000;

    e.setInfo(name, year, month, day, salary);
}

void ShowBasedOnAge(Employee ar[], int size) {
    sort(ar, ar + size, [](const Employee& e1, const Employee& e2) {
        return e1.getAge() < e2.getAge();
    });

    for (int i = 0; i < size; i++) {
        cout << "Name: " << ar[i].getName() << ", Age: " << ar[i].getAge() << " years" << endl;
    }
}

int main() {
    const int numEmployees = 100;
    Employee employees[numEmployees];

    srand(time(nullptr));

    for (int i = 0; i < numEmployees; i++) {
        generateInformationRandom(employees[i]);
    }

    ShowBasedOnAge(employees, numEmployees);

    return 0;
}
