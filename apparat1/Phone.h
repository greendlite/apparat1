#pragma once
#include<iostream>
#include"NetworkHardware.h"
class Phone :public NetworkHardware {
public:
	Phone(const char* name, typeDEV type, string ip, int port, int ñonnector) :NetworkHardware(name, type, ip, port), Connector(ñonnector) {}
	void setConnector(double ñonnector) throw(int) { Connector = ñonnector; };
	double getConnector()const { return Connector; };
	virtual string SubjectWrite()const {
		return "Phone";
	}
	void print()const {
		NetworkHardware::print();
		cout << "Ðàçúåì òåëåôîíà: " << getConnector() << endl << endl;
	}
private:
	int Connector;
};



