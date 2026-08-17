#include <iostream>
using namespace std;

//Implementation
class Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    virtual ~Device() {}
};

//Concrete Implementation: TV
class TV : public Device {
public:
    void turnOn() override {
        cout << "TV is turned ON" << endl;
    }

    void turnOff() override {
        cout << "TV is turned OFF" << endl;
    }
};

//Concrete Implementation: AC
class AC : public Device {
public:
    void turnOn() override {
        cout << "AC is turned ON" << endl;
    }

    void turnOff() override {
        cout << "AC is turned OFF" << endl;
    }
};

//Concrete Implementation: Fan
class Fan : public Device {
public:
    void turnOn() override {
        cout << "Fan is turned ON" << endl;
    }

    void turnOff() override {
        cout << "Fan is turned OFF" << endl;
    }
};

//Abstraction
class Remote {
protected:
    Device* device;

public:
    Remote(Device* d) {
        device = d;
    }

    void turnOn() {
        device->turnOn();
    }

    void turnOff() {
        device->turnOff();
    }
};

//Refined Abstraction
class AdvancedRemote : public Remote {
public:
    AdvancedRemote(Device* d) : Remote(d) {}

    void mute() {
        cout << "Device is muted" << endl;
    }
};

int main() {

    //Creating devices
    TV tv;
    AC ac;
    Fan fan;

    //Connecting remotes to devices
    AdvancedRemote tvRemote(&tv);
    Remote acRemote(&ac);
    Remote fanRemote(&fan);

    //Controlling TV
    tvRemote.turnOn();      //TV is turned ON
    tvRemote.mute();        //Device is muted
    tvRemote.turnOff();     //TV is turned OFF

    cout << endl;

    //Controlling AC
    acRemote.turnOn();      //AC is turned ON
    acRemote.turnOff();     //AC is turned OFF

    cout << endl;

    //Controlling Fan using AdvancedRemote
    fanRemote.turnOn();     //Fan is turned ON
    fanRemote.turnOff();     //Fan is turned OFF

    return 0;
}
