#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Vehicle {
protected:
    string licensePlate;
    string manufacturer;
    double carriageSizeLimit;

public:
    Vehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit)
        : licensePlate(licensePlate), manufacturer(manufacturer), carriageSizeLimit(carriageSizeLimit) {}
    virtual ~Vehicle() = default;
    virtual void maintenance() const = 0;
};

class GasolineVehicle : virtual public Vehicle {
protected:
    double fuelTankCapacity;
    string fuelType;

public:
    GasolineVehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
                    double fuelTankCapacity, const string& fuelType)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
          fuelTankCapacity(fuelTankCapacity), fuelType(fuelType) {}
    virtual void maintenance() const override {
        cout << "GasolineVehicle - maintenance" << endl;
    }
};

class ElectricVehicle : virtual public Vehicle {
protected:
    double batteryCapacity;
    int chargingTime;

public:
    ElectricVehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
                    double batteryCapacity, int chargingTime)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
          batteryCapacity(batteryCapacity), chargingTime(chargingTime) {}
    virtual void maintenance() const override {
        cout << "ElectricVehicle - maintenance" << endl;
    }
};

class HybridVehicle : public GasolineVehicle, public ElectricVehicle {
private:
    double energyRegenerationEfficiency;

public:
    HybridVehicle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
                  double fuelTankCapacity, const string& fuelType, double batteryCapacity, int chargingTime,
                  double energyRegenerationEfficiency)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
          GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          ElectricVehicle(licensePlate, manufacturer, carriageSizeLimit, batteryCapacity, chargingTime),
          energyRegenerationEfficiency(energyRegenerationEfficiency) {}
    virtual void maintenance() const override {
        cout << "HybridVehicle - maintenance" << endl;
    }
};

class Motorcycle : public GasolineVehicle {
public:
    Motorcycle(const string& licensePlate, const string& manufacturer, double carriageSizeLimit,
               double fuelTankCapacity, const string& fuelType)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
          GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType) {}
    virtual void maintenance() const override {
        cout << "Motorcycle - maintenance" << endl;
    }
};

class Car : public GasolineVehicle {
private:
    int passengerCapacity;

public:
    Car(const string& licensePlate, const string& manufacturer, double carriageSizeLimit, double fuelTankCapacity,
        const string& fuelType, int passengerCapacity)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
          GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          passengerCapacity(passengerCapacity) {}
    virtual void maintenance() const override {
        cout << "Car - maintenance" << endl;
    }
};

class Truck : public GasolineVehicle {
private:
    double cargoCapacity;

public:
    Truck(const string& licensePlate, const string& manufacturer, double carriageSizeLimit, double fuelTankCapacity,
          const string& fuelType, double cargoCapacity)
        : Vehicle(licensePlate, manufacturer, carriageSizeLimit),
          GasolineVehicle(licensePlate, manufacturer, carriageSizeLimit, fuelTankCapacity, fuelType),
          cargoCapacity(cargoCapacity) {}
    virtual void maintenance() const override {
        cout << "Truck - maintenance" << endl;
    }
};

class Employee {
protected:
    string name;
    int id;

public:
    Employee(const string& name, int id) : name(name), id(id) {}
    virtual ~Employee() = default;
    virtual void introduce() const = 0;
};

class Manager : public Employee {
public:
    Manager(const string& name, int id) : Employee(name, id) {}
    virtual void introduce() const override {
        cout << "Mr. " << name << endl;
    }
};

class Driver : public Employee {
public:
    Driver(const string& name, int id) : Employee(name, id) {}
    virtual void introduce() const override {
        cout << "Driver " << name << endl;
    }
};

class Branch {
private:
    vector<Vehicle*> vehicles;
    vector<Employee*> employees;

public:
    ~Branch() {
        for (auto v : vehicles) delete v;
        for (auto e : employees) delete e;
    }
    void addVehicle(Vehicle* v) {
        vehicles.push_back(v);
    }
    void addEmployee(Employee* e) {
        employees.push_back(e);
    }
    void maintenance_all_vehicle() const {
        for (const auto& v : vehicles) {
            v->maintenance();
        }
    }
    void introduceEmployees() const {
        for (const auto& e : employees) {
            e->introduce();
        }
    }
};

int main() {
    Branch branch;
    branch.addVehicle(new Car("ABC123", "Toyota", 500, 50, "Petrol", 5));
    branch.addVehicle(new Motorcycle("XYZ789", "Honda", 100, 15, "Petrol"));
    branch.addVehicle(new ElectricVehicle("ELEC456", "Tesla", 400, 75, 120));
    branch.addEmployee(new Manager("Alice", 1));
    branch.addEmployee(new Driver("Bob", 2));
    branch.maintenance_all_vehicle();
    branch.introduceEmployees();
    return 0;
}

