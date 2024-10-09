#include <iostream>
using namespace std;

class Fahrenheit;
class Kelvin;

class Celsius {
    double tempCelsius;

public:
    Celsius(double temp = 0) {
        if (temp >= -273.15)
            tempCelsius = temp;
        else
            tempCelsius = -273.15;
    }

    void assign(double temp) {
        if (temp >= -273.15)
            tempCelsius = temp;
        else
            tempCelsius = -273.15;
    }

    void display() const {
        cout << "The temperature is " << tempCelsius << " Celsius." << endl;
    }

    operator Fahrenheit();
    operator Kelvin();
};

class Fahrenheit {
    double tempFahrenheit;

public:
    Fahrenheit(double temp = 32) {
        if (temp >= -459.67)
            tempFahrenheit = temp;
        else
            tempFahrenheit = -459.67;
    }

    void assign(double temp) {
        if (temp >= -459.67)
            tempFahrenheit = temp;
        else
            tempFahrenheit = -459.67;
    }

    void display() const {
        cout << "The temperature is " << tempFahrenheit << " Fahrenheit." << endl;
    }

    operator Celsius();
    operator Kelvin();
};

class Kelvin {
    double tempKelvin;

public:
    Kelvin(double temp = 273.15) {
        if (temp >= 0)
            tempKelvin = temp;
        else
            tempKelvin = 0;
    }

    void assign(double temp) {
        if (temp >= 0)
            tempKelvin = temp;
        else
            tempKelvin = 0;
    }

    void display() const {
        cout << "The temperature is " << tempKelvin << " Kelvin." << endl;
    }

    operator Celsius();
    operator Fahrenheit();
};

Celsius::operator Fahrenheit() {
    return Fahrenheit(tempCelsius * 9 / 5 + 32);
}

Celsius::operator Kelvin() {
    return Kelvin(tempCelsius + 273.15);
}

Fahrenheit::operator Celsius() {
    return Celsius((tempFahrenheit - 32) * 5 / 9);
}

Fahrenheit::operator Kelvin() {
    return Kelvin((tempFahrenheit - 32) * 5 / 9 + 273.15);
}

Kelvin::operator Celsius() {
    return Celsius(tempKelvin - 273.15);
}

Kelvin::operator Fahrenheit() {
    return Fahrenheit((tempKelvin - 273.15) * 9 / 5 + 32);
}

int main() {
    int x;
    cout<<"Enter Celcius Temp"<<endl;
    cin>>x;
    Celsius Cel(x);
    Cel.display();

    Fahrenheit Far = Cel;
    Far.display();

    Kelvin Kel = Far;
    Kel.display();

    return 0;
}
