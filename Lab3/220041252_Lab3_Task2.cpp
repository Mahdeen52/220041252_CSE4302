#include <iostream>
using namespace std;

class RationalNumber {
    
    private: int num,den,temp;
             float fraction;
    public: 
            void assign(int numerator, int denominator) {
            num=numerator;
            den=denominator;
    }
    
        float convert() {
             fraction=(float)num/den;
             return fraction;
        }
        
        void invert() {
            if(den==0) {
            cout<<"You can not assign 0 as denominator.Inversion failed"<<endl;
        }
         
            else {
                temp=num;
                num=den;
                den=temp;
            }
            
        }
        
        void print() {
            if(den!=1) {
            cout<<"The Rational number is "<<num<<"/"<<den<<endl;
        }
            else cout<<"The Rational number is "<<num<<endl;
     }
        
};
            


int main() {
    RationalNumber r1;
    r1.assign(1,6);
    r1.print();
    r1.invert();
    r1.print();

    return 0;
}