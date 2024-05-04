#pragma once
#include<iostream>
#include"NetworkHardware.h"
class Router :public NetworkHardware{
public:
	Router(const char* name, typeDEV type, string ip, int port, int speed) :NetworkHardware(name, type, ip, port), Speed(speed) {}
	void setSpeed(double speed) throw(int) {
		if (Speed > 20000)throw overflow_error("Невозможная скорость работы роутера");
		Speed = speed;
	};
	int getSpeed()const { return Speed; };
	virtual string SubjectWrite()const {
		return "Router";
	}
	void print()const {
		NetworkHardware::print();
		cout << "Скорость работы роутера: " << getSpeed() << endl << endl;
	}
private:
	int Speed;
};

