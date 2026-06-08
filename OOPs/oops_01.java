// Description:  This code demonstrates the four fundamental principles of Object-Oriented Programming (OOP) in JAVA: Encapsulation, Inheritance, Polymorphism, and Abstraction. It defines a base class `Car` with common attributes and methods, and two derived classes `ManualCar` and `ElectricCar` that inherit from `Car` and implement specific behaviors. The code also showcases both runtime polymorphism (using abstract methods) and static polymorphism (using function overloading). Finally, it abstracts the complexity of car operations through simple method calls in the `main` function.

abstract class Car { //--------------------------------------------> Encapsulation
    String brand;
    String model;
    int year;
    int speed;
    boolean isEngineOn;

    Car(String b, String m, int y) {
        brand = b;
        model = m;
        year = y;
        speed = 0;
        isEngineOn = false;
    }

    void startEngine() {
        isEngineOn = true;
        System.out.println(brand + " " + model + " Engine started!");
    }

    void stopEngine() {
        isEngineOn = false;
        speed = 0;
        System.out.println(brand + " " + model + " Engine stopped!");
    }

    void getSpeed() {
        System.out.println(brand + " " + model + " Current speed: " + speed + " km/h");
    }

    abstract void accelerate(); // ------------------------------>(Runtime Polymorphism)
    abstract void brake();
}


class ManualCar extends Car {  // -------------------------------------------> Inheritance
    int gear;
    float fuelCapacity;

    ManualCar(String b, String m, int y) {
        super(b, m, y);
        gear = 0;
        fuelCapacity = 50.0f;
    }

    void getGear() {
        System.out.println(brand + " " + model + " Current gear: " + gear);
    }

    void getFuelCapacity() {
        System.out.println(brand + " " + model + " Fuel capacity: " + fuelCapacity + " liters");
    }

    void fillFuel(float amount) {
        fuelCapacity += amount;
        System.out.println(
            brand + " " + model + " Filled " + amount +
            " liters of fuel. Total fuel: " + fuelCapacity + " liters"
        );
    }

    void shiftGear(int g) {
        if(isEngineOn) {
            gear += g;
            System.out.println(brand + " " + model + " Shifted to gear " + gear);
        } else {
            System.out.println(brand + " " + model + " Engine is off! Can't shift gears.");
        }
    }

    @Override
    void accelerate() {
        if(isEngineOn) {
            speed += 10;
            fuelCapacity -= 0.5f;
            System.out.println(
                brand + " " + model +
                " Accelerating! Speed: " + speed + " km/h"
            );
        } else {
            System.out.println(brand + " " + model + " Engine is off! Can't accelerate.");
        }
    }

    // Method Overloading (Static Polymorphism)
    void accelerate(int increment) {
        if(isEngineOn) {
            speed += increment;
            fuelCapacity -= 0.5f * increment / 10;

            System.out.println(
                brand + " " + model +
                " Accelerating! Speed: " + speed + " km/h"
            );
        } else {
            System.out.println(brand + " " + model + " Engine is off! Can't accelerate.");
        }
    }

    @Override
    void brake() {
        if(isEngineOn) {
            speed -= 10;
            System.out.println(
                brand + " " + model +
                " Braking! Speed: " + speed + " km/h"
            );
        } else {
            System.out.println(brand + " " + model + " Engine is off! Can't brake.");
        }
    }
}


class ElectricCar extends Car {
    int batteryLevel;

    ElectricCar(String b, String m, int y) {
        super(b, m, y);
        batteryLevel = 100;
    }

    void getBatteryLevel() {
        System.out.println(
            brand + " " + model +
            " Battery level: " + batteryLevel + "%"
        );
    }

    void chargeBattery(int amount) {
        batteryLevel += amount;

        if(batteryLevel > 100)
            batteryLevel = 100;

        System.out.println(
            brand + " " + model +
            " Charged battery by " + amount +
            "%. Current battery level: " + batteryLevel + "%"
        );
    }

    @Override
    void accelerate() {
        if(isEngineOn) {
            speed += 15;
            batteryLevel -= 5;

            System.out.println(
                brand + " " + model +
                " Accelerating! Speed: " + speed + " km/h"
            );
        } else {
            System.out.println(brand + " " + model + " Engine is off! Can't accelerate.");
        }
    }

    void accelerate(int increment) {
        if(isEngineOn) {
            speed += increment;
            batteryLevel -= 5 * increment / 15;

            System.out.println(
                brand + " " + model +
                " Accelerating! Speed: " + speed + " km/h"
            );
        } else {
            System.out.println(brand + " " + model + " Engine is off! Can't accelerate.");
        }
    }

    @Override
    void brake() {
        if(isEngineOn) {
            speed -= 15;

            System.out.println(
                brand + " " + model +
                " Braking! Speed: " + speed + " km/h"
            );
        } else {
            System.out.println(brand + " " + model + " Engine is off! Can't brake.");
        }
    }
}


public class oops_01 {
    public static void main(String[] args) {

        ManualCar myCar1 = new ManualCar("Toyota", "Corolla", 2020);
        ElectricCar myCar2 = new ElectricCar("Tesla", "Model 3", 2022);

        //----------------------------------------------------> Abstraction
        myCar1.startEngine();
        myCar1.accelerate();
        myCar1.accelerate(20);
        myCar1.getSpeed();
        myCar1.getFuelCapacity();
        myCar1.fillFuel(10);
        myCar1.shiftGear(1);
        myCar1.getGear();
        myCar1.brake();
        myCar1.stopEngine();

        System.out.println();

        myCar2.startEngine();
        myCar2.accelerate();
        myCar2.accelerate(25);
        myCar2.getSpeed();
        myCar2.getBatteryLevel();
        myCar2.chargeBattery(5);
        myCar2.brake();
        myCar2.stopEngine();
    }
}