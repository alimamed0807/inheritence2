#include <iostream>
#include <string>

using namespace std;

template <typename T>
class Stack {
private:
    T* arr;
    int capacity;
    int topIndex;

public:
    Stack(int cap = 100) {
        capacity = cap;
        arr = new T[capacity];
        topIndex = -1;
    }

    ~Stack() {
        delete[] arr;
    }

    void push(T val) {
        if (topIndex < capacity - 1) {
            arr[++topIndex] = val;
        }
    }

    bool isEmpty() const {
        return topIndex == -1;
    }

    int size() const {
        return topIndex + 1;
    }

    T get(int index) const {
        return arr[index];
    }
};

class Engine {
public:
    string engine_no;
    string company;
    double volume;

    Engine() : engine_no(""), company(""), volume(0.0) {}
    Engine(string no, string comp, double vol) : engine_no(no), company(comp), volume(vol) {}

    void show() const {
        cout << "Engine No: " << engine_no << ", Company: " << company << ", Volume: " << volume << "L";
    }
};

class Vehicle {
protected:
    int id;
    string model;
    string vendor;
    Engine engine;

public:
    Vehicle() : id(0), model(""), vendor(""), engine() {}
    Vehicle(int _id, string _model, string _vendor, Engine _engine) 
        : id(_id), model(_model), vendor(_vendor), engine(_engine) {}

    virtual void show() const {
        cout << "ID: " << id << " | Vendor: " << vendor << " | Model: " << model << " | ";
        engine.show();
    }
};

class Car : public Vehicle {
private:
    bool hasSpoiler;

public:
    Car() : Vehicle(), hasSpoiler(false) {}
    Car(int _id, string _model, string _vendor, Engine _engine, bool _hasSpoiler)
        : Vehicle(_id, _model, _vendor, _engine), hasSpoiler(_hasSpoiler) {}

    void show() const override {
        Vehicle::show();
        cout << " | Has Spoiler: " << (hasSpoiler ? "Yes" : "No") << endl;
    }
};

class Ship : public Vehicle {
private:
    bool hasSail;

public:
    Ship() : Vehicle(), hasSail(false) {}
    Ship(int _id, string _model, string _vendor, Engine _engine, bool _hasSail)
        : Vehicle(_id, _model, _vendor, _engine), hasSail(_hasSail) {}

    void show() const override {
        Vehicle::show();
        cout << " | Has Sail: " << (hasSail ? "Yes" : "No") << endl;
    }
};

class Airplane : public Vehicle {
private:
    int engineCount;
    int passengersCapacity;

public:
    Airplane() : Vehicle(), engineCount(0), passengersCapacity(0) {}
    Airplane(int _id, string _model, string _vendor, Engine _engine, int _engCount, int _passCap)
        : Vehicle(_id, _model, _vendor, _engine), engineCount(_engCount), passengersCapacity(_passCap) {}

    void show() const override {
        Vehicle::show();
        cout << " | Engine Count: " << engineCount << " | Passenger Capacity: " << passengersCapacity << endl;
    }
};

class VehicleDepo {
public:
    Stack<Car> cars;
    Stack<Ship> ships;
    Stack<Airplane> airplanes;

    void showAllVehicle() {
        cout << "=== DEPO CARS ===" << endl;
        for (int i = 0; i < cars.size(); i++) {
            cars.get(i).show();
        }

        cout << "\n=== DEPO SHIPS ===" << endl;
        for (int i = 0; i < ships.size(); i++) {
            ships.get(i).show();
        }

        cout << "\n=== DEPO AIRPLANES ===" << endl;
        for (int i = 0; i < airplanes.size(); i++) {
            airplanes.get(i).show();
        }
    }
};

int main() {
    Engine carEngine("V8-XYZ", "BMW_Engines", 4.4);
    Engine shipEngine("MAR-99", "Yamaha", 6.0);
    Engine planeEngine("TURBO-77", "Rolls-Royce", 12.5);

    Car c1(1, "M5", "BMW", carEngine, true);
    Ship s1(2, "Yacht-X", "Benetti", shipEngine, false);
    Airplane a1(3, "747", "Boeing", planeEngine, 4, 416);

    VehicleDepo depo;
    depo.cars.push(c1);
    depo.ships.push(s1);
    depo.airplanes.push(a1);

    depo.showAllVehicle();

    return 0;
}
