#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Vehicle {
protected:
    string licensePlate;
    string manufacturer;
    double carriageSizeLimit;

public:
    Vehicle(string licensePlate, string manufacturer, double carriageSizeLimit)
        : licensePlate(licensePlate), manufacturer(manufacturer), carriageSizeLimit(carriageSizeLimit) {}

    virtual void performMaintenance() = 0;
    virtual double calculateFuelConsumption(double distance) = 0;
    double getCarriageSizeLimit() const { 
        return carriageSizeLimit; 
    }
};

class GasolineVehicle : public Vehicle {
protected:
    double fuelTankCapacity;
    string fuelType;

public:
    GasolineVehicle(string licensePlate, string manufacturer, double carriageSizeLimit,
                    double fuelTankCapacity, string fuelType)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit), fuelTankCapacity(fuelTankCapacity), fuelType(fuelType) {}

    virtual double calculateFuelConsumption(double distance) = 0;

    void performMaintenance() override {
        cout << "Gasoline vehicle maintenance for " << manufacturer << " " << licensePlate << endl;
    }
};

class ElectricVehicle : public Vehicle {
protected:
    double batteryCapacity;
    double chargingTime;

public:
    ElectricVehicle(string licensePlate, string manufacturer, double carriageSizeLimit,
                    double batteryCapacity, double chargingTime)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit), batteryCapacity(batteryCapacity), chargingTime(chargingTime) {}

    virtual double electricityConsumption(double distance) = 0;

    void performMaintenance() override {
        cout << "Electric vehicle maintenance for " << manufacturer << " " << licensePlate << endl;
    }
};

class Motorcycle : public GasolineVehicle {
public:
    Motorcycle(string licensePlate, string manufacturer, double carriageSizeLimit,
               double fuelTankCapacity, string fuelType)
        : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType) {}

    double calculateFuelConsumption(double distance) override {
        return (5.0 * distance) / 100;
    }

    void performMaintenance() override {
        cout << "Motorcycle - maintenance" << endl;
    }
};

class Car : public GasolineVehicle {
protected:
    int passengerCapacity;

public:
    Car(string licensePlate, string manufacturer, double carriageSizeLimit,
        double fuelTankCapacity, string fuelType, int passengerCapacity)
        : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType), passengerCapacity(passengerCapacity) {}

    double calculateFuelConsumption(double distance) override {
        return (6.0 * distance) / 100;
    }

     void performMaintenance() override {
        cout << "Car - maintenance" << endl;
    }
};

class Truck : public GasolineVehicle {
protected:
    double cargoCapacity;

public:
    Truck(string licensePlate, string manufacturer, double carriageSizeLimit,
          double fuelTankCapacity, string fuelType, double cargoCapacity)
        : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType), cargoCapacity(cargoCapacity) {}

    double calculateFuelConsumption(double distance) override {
        return (18.0 * distance) / 100;
    }

     void performMaintenance() override {
        cout << "Truck - maintenance" << endl;
    }
};

class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
protected:
    double energyRegenerationEfficiency;

public:
    HybridVehicle(string licensePlate, string manufacturer, double carriageSizeLimit,
                  double fuelTankCapacity, string fuelType, double batteryCapacity,
                  double chargingTime, double energyRegenerationEfficiency)
        : GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          ElectricVehicle(licensePlate, manufacturer, carriageSizeLimit, batteryCapacity, chargingTime),
          energyRegenerationEfficiency(energyRegenerationEfficiency) {}

    double calculateFuelConsumption(double distance) override {
        double fuelConsumption = (5.0 * distance) / 100;
        double electricityConsumption = (0.3 * distance) / 100;
        return fuelConsumption + electricityConsumption;
    }

    double electricityConsumption(double distance) override {
        return (0.3 * distance) / 100;
    }

     void performMaintenance() override {
        cout << "Hybrid Vehicle - maintenance" << endl;
    }
};
bool compareByCapacity(Vehicle* a, Vehicle* b) {
    return a->getCarriageSizeLimit() > b->getCarriageSizeLimit();
}

void sort_vehicles_by_capacity(Vehicle** vehicles, int n) {
    sort(vehicles, vehicles + n, compareByCapacity);
}

int main() {
    vector<Vehicle*> vehicles;

    vehicles.push_back(new Motorcycle("M-11", "RoyalEnfield", 200, 15, "Petrol"));
    vehicles.push_back(new Car("C-22", "Premio", 250, 50, "Petrol", 6));
    vehicles.push_back(new Truck("T-33", "AshokLeyland", 350, 200, "Diesel", 500));
    HybridVehicle* hybrid = new HybridVehicle("H-44", "Tesla", 30, 50, "Electric", 10, 60, 68);

    
for (int i = 0; i < vehicles.size(); ++i) {
    vehicles[i]->performMaintenance();
}

hybrid->performMaintenance();
double distance = 100;
for (int i = 0; i < vehicles.size(); ++i) {
    cout << "Fuel Consumption for " << vehicles[i]->getCarriageSizeLimit() << " size vehicle: "
         << vehicles[i]->calculateFuelConsumption(distance) << " units" << endl;
}

hybrid->calculateFuelConsumption(distance);
sort_vehicles_by_capacity(vehicles.data(), vehicles.size());
cout << "\nSorted Vehicles by Capacity:" << endl;
for (int i = 0; i < vehicles.size(); ++i) {
    cout << "Vehicle with size " << vehicles[i]->getCarriageSizeLimit() << endl;
}

for (int i = 0; i < vehicles.size(); ++i) {
    delete vehicles[i];
}

return 0;
}