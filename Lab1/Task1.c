#include <iostream>
using namespace std;


int main() {
    int num1, num2, den1, den2,num_frac,den_frac;
    char slash='/';
    cout<<"Enter numerator of first fraction: "<<endl;
    cin>>num1;
    cout<<"Enter denominator of first fraction: "<<endl;
    cin>>den1;
    cout<<"Enter numerator of second fraction: "<<endl;
    cin>>num2;
    cout<<"Enter denominator of second fraction: "<<endl;
    cin>>den2;

    cout<<"The fractions are: "<<num1<<slash<<den1<<"  "<<"and" <<"  "<<num2<<slash<<den2<<endl;

    num_frac=(num1*den2)+(num2*den1);
    den_frac=(den1*den2);

    cout<<"The sum is: "<<num_frac<<slash<<den_frac<<endl;



    return 0;
}
