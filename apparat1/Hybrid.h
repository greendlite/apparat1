#pragma once
#include "NetworkHardware.h"
#include "Router.h"
#include "Phone.h"

class Hybrid : public Router, public Phone {
public:
	Hybrid(const char* name, typeDEV type, string ip, int port, double speed, double connector, double energy) :Router(name, type, ip, port, speed), Phone(name, type, ip, port, connector), Energy(energy) {}
	void setEnergy(double E) { Energy = E; };
	double getEnergy()const { return Energy; };
	virtual string SubjectWrite() const {
		return "Hybrid Phone";
	};
	void print()const {
		NetworkHardware::print();
		cout << "Скорость работы роутера: " << getSpeed() << endl;
		cout << "Разъем: " << getConnector() << endl;
		cout << "Энергопотребление: " << getEnergy() << endl;
	}
private:
	double Energy;
};


