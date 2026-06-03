// Description:  This code demonstrates the four fundamental principles of Object-Oriented Programming (OOP) in C++: Encapsulation, Inheritance, Polymorphism, and Abstraction. It defines a base class `Car` with common attributes and methods, and two derived classes `ManualCar` and `ElectricCar` that inherit from `Car` and implement specific behaviors. The code also showcases both runtime polymorphism (using virtual functions) and static polymorphism (using function overloading). Finally, it abstracts the complexity of car operations through simple method calls in the `main` function.

#include <bits/stdc++.h>
using namespace std;

class Car{       //--------------------------------------------> Encapsulation
    public:
        string brand;
        string model;
        int year;
        int speed;
        bool isEngineOn;
        Car(string b, string m, int y){
            brand = b;
            model = m;
            year = y;
            speed = 0;
            isEngineOn = false;
        }
        void startEngine(){
            isEngineOn = true;
            cout <<this->brand<<" "<<this->model<<" "<<"Engine started!" << endl;
        }
        void stopEngine(){
            isEngineOn = false; speed=0;
            cout <<this->brand<<" "<<this->model<<" "<<"Engine stopped!" << endl;
        }
        void getSpeed(){
            cout <<this->brand<<" "<<this->model<<" "<<"Current speed: "<<speed<<" km/h"<<endl;
        }
        virtual void accelerate()=0; // ------------------------------>(Runtime Polymorphism)
        virtual void brake()=0;
};
class ManualCar : public Car{    // -------------------------------------------> Inheritance
    int gear; float fuelCapacity;
    public:
        ManualCar(string b, string m, int y): Car(b,m,y){
            gear = 0; fuelCapacity = 50.0;
        }
        void getGear(){
            cout <<this->brand<<" "<<this->model<<" "<<"Current gear: "<<gear<<endl;
        }
        void getFuelCapacity(){
            cout <<this->brand<<" "<<this->model<<" "<<"Fuel capacity: "<<fuelCapacity<<" liters"<<endl;
        }
        void fillFuel(float amount){
            fuelCapacity += amount;
            cout <<this->brand<<" "<<this->model<<" "<<"Filled "<<amount<<" liters of fuel. Total fuel: "<<fuelCapacity<<" liters"<<endl;
        }
        void shiftGear(int g){
            if(this->isEngineOn){
            gear += g;
            cout <<this->brand<<" "<<this->model<<" "<<"Shifted to gear "<<gear<<endl;
            }else{
                cout <<this->brand<<" "<<this->model<<" "<<"Engine is off! Can't shift gears."<<endl;
            }
        }
        void accelerate(){
            if(this->isEngineOn){
                this->speed += 10; fuelCapacity -= 0.5;
                cout <<this->brand<<" "<<this->model<<" "<<"Accelerating! Speed: "<<this->speed<<" km/h"<<endl;
            }else{
                cout <<this->brand<<" "<<this->model<<" "<<"Engine is off! Can't accelerate."<<endl;
            }
        }
        void accelerate(int increment){ // ------------------------------>Static Polymorphism
            if(this->isEngineOn){
                this->speed += increment; fuelCapacity -= 0.5*increment/10;
                cout <<this->brand<<" "<<this->model<<" "<<"Accelerating! Speed: "<<this->speed<<" km/h"<<endl;
            }else{
                cout <<this->brand<<" "<<this->model<<" "<<"Engine is off! Can't accelerate."<<endl;
            }
        }
        void brake(){
            if(this->isEngineOn){
                this->speed -= 10;
                cout <<this->brand<<" "<<this->model<<" "<<"Braking! Speed: "<<this->speed<<" km/h"<<endl;
            }else{
                cout <<this->brand<<" "<<this->model<<" "<<"Engine is off! Can't brake."<<endl;
            }
        }
};

class ElectricCar : public Car{
    int batteryLevel;
    public:
        ElectricCar(string b, string m, int y): Car(b,m,y){
            batteryLevel = 100;
        }
        void getBatteryLevel(){
            cout <<this->brand<<" "<<this->model<<" "<<"Battery level: "<<batteryLevel<<"%"<<endl;
        }
        void chargeBattery(int amount){
            batteryLevel += amount;
            if(batteryLevel > 100) batteryLevel = 100;
            cout <<this->brand<<" "<<this->model<<" "<<"Charged battery by "<<amount<<"%. Current battery level: "<<batteryLevel<<"%"<<endl;
        }
        void accelerate(){
            if(this->isEngineOn){
                this->speed += 15;
                batteryLevel -= 5;
                cout <<this->brand<<" "<<this->model<<" "<<"Accelerating! Speed: "<<this->speed<<" km/h"<<endl;
            }else{
                cout <<this->brand<<" "<<this->model<<" "<<"Engine is off! Can't accelerate."<<endl;
            }
        }
        void accelerate(int increment){
            if(this->isEngineOn){
                this->speed += increment;
                batteryLevel -= 5*increment/15;
                cout <<this->brand<<" "<<this->model<<" "<<"Accelerating! Speed: "<<this->speed<<" km/h"<<endl;
            }else{
                cout <<this->brand<<" "<<this->model<<" "<<"Engine is off! Can't accelerate."<<endl;
            }
        }
        void brake(){
            if(this->isEngineOn){
                this->speed -= 15;
                cout <<this->brand<<" "<<this->model<<" "<<"Braking! Speed: "<<this->speed<<" km/h"<<endl;
            }else{
                cout <<this->brand<<" "<<this->model<<" "<<"Engine is off! Can't brake."<<endl;
            }
        }
};

int main(){
    ManualCar*myCar1 = new ManualCar("Toyota", "Corolla", 2020);
    ElectricCar*myCar2 = new ElectricCar("Tesla", "Model 3",2022);
     
    myCar1->startEngine();   // -----------------------------------------------> Abstraction
    myCar1->accelerate();
    myCar1->accelerate(20);
    myCar1->getSpeed();
    myCar1->getFuelCapacity();
    myCar1->fillFuel(10);
    myCar1->shiftGear(1);
    myCar1->getGear();
    myCar1->brake();
    myCar1->stopEngine();

    cout<<endl;

    myCar2->startEngine();
    myCar2->accelerate();
    myCar2->accelerate(25);
    myCar2->getSpeed();
    myCar2->getBatteryLevel();
    myCar2->chargeBattery(5);
    myCar2->brake();
    myCar2->stopEngine();

    return 0;
}