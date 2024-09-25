#include <iostream>
#include <cmath>
using namespace std;

class Calculator {
private:
 
    float currentAngle;  
    float previousAngle; 
    
    float getAngle() {
        return currentAngle;
    }

    void setAngle(float angle) {
        previousAngle = currentAngle; 
        currentAngle = angle;
    }
    
    float intoRadian(float degrees)  {
        return degrees * (3.1416 / (float) 180);
    }

public:
   
    Calculator() {
        currentAngle = 0;
        previousAngle = 0;
    }

    Calculator(float angle) {
        currentAngle = angle;
        previousAngle = 0; 
    }

    float calculateSine() {
        return sin(intoRadian(currentAngle));
    }

    float calculateCosine() {
        return cos(intoRadian(currentAngle));
    }

    float calculateTangent() {
        if ((int)(currentAngle) % 180 == 90) {
            cout << "Invalid operation: undefined result." << endl;
            currentAngle = previousAngle; 
         
        }
        return tan(intoRadian(currentAngle));
    }

    float calculateArcSine() {
        float radianAngle = intoRadian(currentAngle);
        cout << "Angle in radians: " << radianAngle << endl;
        return asin(radianAngle);
    }

    float calculateArcCosine() {
        return acos(intoRadian(currentAngle));
    }

    float calculateArcTangent() {
        return atan(intoRadian(currentAngle));
    }

    void calculateForAngle(float paramAngle) {
        cout << "Sine of " << paramAngle << ": " << sin(intoRadian(paramAngle)) << endl;
        cout << "Cosine of " << paramAngle << ": " << cos(intoRadian(paramAngle)) << endl;
        
        if ((int)(paramAngle) % 180 == 90) {
            cout << "Tangent of " << paramAngle << ": Invalid operation: undefined result." << endl;
        } 
        else {
            cout << "Tangent of " << paramAngle << ": " << tan(intoRadian(paramAngle)) << endl;
        }
    }

    void clear() {
        setAngle(0);
    }

    void display() {
        cout << "Calculator display: " << currentAngle << endl;
    }

    ~Calculator() {
        cout << "Calculator display: " << currentAngle << endl;
        cout << "Destructor of the Calculator object is called." << endl;
    }
};


int main() {
    Calculator calc(30);  
    calc.display();
    cout << "Sine: " << calc.calculateSine() << endl;     
    cout << "Cosine: " << calc.calculateCosine() << endl;  
    cout << "Tangent: " << calc.calculateTangent() << endl; 
    
    cout<<endl;
     
    cout<<"Displaying the arcs"<<endl;
    cout << "Sine: " << calc.calculateArcSine() << endl;     
    cout << "Cosine: " << calc.calculateArcCosine() << endl;  
    cout << "Tangent: " << calc.calculateArcTangent() << endl; 
    
    
    cout<<endl;
    
    cout<<"Displaying For Given angle: "<<endl;
    calc.calculateForAngle(45);
    calc.clear();
    
    cout<<endl;
    
    return 0;  
}
