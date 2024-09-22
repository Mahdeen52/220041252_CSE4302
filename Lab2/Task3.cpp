#include <iostream>
using namespace std;

struct fraction {
    int numerator,denominator;

};


int main() {
    fraction f1,f2;
    char slash='/';
    cout<<"Enter numerator of first fraction: "<<endl;
    cin>>f1.numerator;
    cout<<"Enter denominator of first fraction: "<<endl;
    cin>>f1.denominator;
    cout<<"Enter numerator of second fraction: "<<endl;
    cin>>f2.numerator;
    cout<<"Enter denominator of second fraction: "<<endl;
    cin>>f2.denominator;

    cout<<"The fractions are: "<<f1.numerator<<slash<<f1.denominator<<"  "<<"and" <<"  "<<f2.numerator<<slash<<f2.denominator<<endl;

    int sum_num=(f1.numerator*f2.denominator)+(f2.numerator*f1.denominator);
    int sum_den=(f1.denominator*f2.denominator);

    cout<<"The sum is: "<<sum_num<<slash<<sum_den<<endl;



    return 0;
}
