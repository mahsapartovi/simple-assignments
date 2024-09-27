//Assignment: Expand your program to include classes Truck and Motorcycle. All three will have members year and color,
//<< and >> operators, and function getDescription().
//All three classes will be derived from an abstract class Vehicle. 

#include <iostream>
#include <string>

// Base class for vehicles
class Vehicle {
protected:
    int year;
    std::string color;

public:
    // Constructor
    Vehicle() : year(0), color("Unknown") {}
    
    // Virtual destructor for cleanup
    virtual ~Vehicle() {}

    // Pure virtual function to describe the vehicle
    virtual std::string getDescription() const = 0;

    // Friends for input/output operators
    friend std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle);
    friend std::istream& operator>>(std::istream& is, Vehicle& vehicle);
};

// Truck class derived from Vehicle
class Truck : public Vehicle {
public:
    // Constructor
    Truck() {}

    // Provide description of Truck
    std::string getDescription() const override {
        return "Truck - Year: " + std::to_string(year) + ", Color: " + color;
    }

    // Friend functions for input/output operators
    friend std::ostream& operator<<(std::ostream& os, const Truck& truck);
    friend std::istream& operator>>(std::istream& is, Truck& truck);
};

// Motorcycle class derived from Vehicle
class Motorcycle : public Vehicle {
public:
    Motorcycle() {}

    std::string getDescription() const override {
        return "Motorcycle - Year: " + std::to_string(year) + ", Color: " + color;
    }

    friend std::ostream& operator<<(std::ostream& os, const Motorcycle& motorcycle);
    friend std::istream& operator>>(std::istream& is, Motorcycle& motorcycle);
};

// Car class derived from Vehicle
class Car : public Vehicle {
public:
    Car() {}

    std::string getDescription() const override {
        return "Car - Year: " + std::to_string(year) + ", Color: " + color;
    }

    friend std::ostream& operator<<(std::ostream& os, const Car& car);
    friend std::istream& operator>>(std::istream& is, Car& car);
};

// Input/output operators for Vehicle
std::ostream& operator<<(std::ostream& os, const Vehicle& vehicle) {
    os << vehicle.getDescription();
    return os;
}

std::istream& operator>>(std::istream& is, Vehicle& vehicle) {
    std::cout << "Enter year: ";
    is >> vehicle.year;
    std::cout << "Enter color: ";
    is >> vehicle.color;
    return is;
}

// Overload << for Truck
std::ostream& operator<<(std::ostream& os, const Truck& truck) {
    os << truck.getDescription();
    return os;
}

// Overload >> for Truck
std::istream& operator>>(std::istream& is, Truck& truck) {
    std::cout << "Enter year for the truck: ";
    is >> truck.year;
    std::cout << "Enter color for the truck: ";
    is >> truck.color;
    return is;
}

// Overload << for Motorcycle
std::ostream& operator<<(std::ostream& os, const Motorcycle& motorcycle) {
    os << motorcycle.getDescription();
    return os;
}

// Overload >> for Motorcycle
std::istream& operator>>(std::istream& is, Motorcycle& motorcycle) {
    std::cout << "Enter year for the motorcycle: ";
    is >> motorcycle.year;
    std::cout << "Enter color for the motorcycle: ";
    is >> motorcycle.color;
    return is;
}

// Overload << for Car
std::ostream& operator<<(std::ostream& os, const Car& car) {
    os << car.getDescription();
    return os;
}

// Overload >> for Car
std::istream& operator>>(std::istream& is, Car& car) {
    std::cout << "Enter year for the car: ";
    is >> car.year;
    std::cout << "Enter color for the car: ";
    is >> car.color;
    return is;
}

// Main function
int main() {
    Truck truck;
    Motorcycle motorcycle;
    Car car;

    std::cout << "Enter details for the truck:\n";
    std::cin >> truck;

    std::cout << "Enter details for the motorcycle:\n";
    std::cin >> motorcycle;

    std::cout << "Enter details for the car:\n";
    std::cin >> car;

    std::cout << "\nVehicle Descriptions:\n";
    std::cout << truck << std::endl;
    std::cout << motorcycle << std::endl;
    std::cout << car << std::endl;

    return 0;
}
