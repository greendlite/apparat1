#pragma once
#include<iostream>
#include"NetworkHardware.h"
class Computer :public NetworkHardware {
public:
	Computer(const char* name, typeDEV type, string ip, int port, int numberConnectors) :NetworkHardware(name, type, ip, port), NumberConnectors(numberConnectors) {}
	void setNumberConnectors(double numberConnectors) throw(int) { NumberConnectors = numberConnectors; };
	int getNumberConnectors()const { return NumberConnectors; };
	virtual string SubjectWrite()const {
		return "Computer";
	}
	void print()const {
		NetworkHardware::print();
		cout << "Количество разъемов: " << getNumberConnectors() << endl << endl;
	}
private:
	int NumberConnectors;
};



