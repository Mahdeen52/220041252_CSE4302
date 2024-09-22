#include <iostream>
using namespace std;

enum etype{laborer, secretary, manager,
accountant, executive, researcher};
int main() {
    etype employee;
    char letter;
    cout<<"Enter letter:"<<endl;
    cin>>letter;

    switch(letter) {
        case'l': employee=laborer;
                break;
        case's': employee=secretary;
                break;
        case'm': employee=manager;
                break;
        case'a': employee=accountant;
                break;
        case'e': employee=executive;
                break;
        case'r': employee=researcher;
                break;
        case'L': employee=laborer;
                break;
        case'S': employee=secretary;
                break;
        case'M': employee=manager;
                break;
        case'A': employee=accountant;
                break;
        case'E': employee=executive;
                break;
        case'R': employee=researcher;
                break;
        default:
            cout<<"Invalid input"<<endl;


    }

    switch(employee) {
        case 0: cout<<"Employee type is Laborer"<<endl;
                break;
        case 1: cout<<"Employee type is Secretary"<<endl;
                break;
        case 2: cout<<"Employee type is Manager"<<endl;
                break;
        case 3: cout<<"Employee type is Accountant"<<endl;
                break;
        case 4: cout<<"Employee type is Executive"<<endl;
                break;
        case 5: cout<<"Employee type is Researcher"<<endl;
                break;

    }

    return 0;
}
