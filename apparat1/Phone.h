#pragma once
#include<iostream>
#include"NetworkHardware.h"
class Phone :public NetworkHardware {
public:
	Phone(const char* name, typeDEV type, string ip, int port, int �onnector) :NetworkHardware(name, type, ip, port), Connector(�onnector) {}
	void setConnector(double �onnector) throw(int) { Connector = �onnector; };
	double getConnector()const { return Connector; };
	virtual string SubjectWrite()const {
		return "Phone";
	}
	void print()const {
		NetworkHardware::print();
		cout << "������ ��������: " << getConnector() << endl << endl;
	}
private:
	int Connector;
};



