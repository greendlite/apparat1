#pragma once
#include <iostream>
using namespace std;

class INetworkHardware
{
public:// сеттеры

	virtual void setdeviceName(const char* name)=0; // Сеттер поля имени
	virtual void setdeviceType(typeDEV type) = 0;// Сеттер поля типа
	virtual void setipAddress(string ip) = 0;// Сеттер поля адреса
	virtual void setportNumber(int port) = 0;// Сеттер поля порта

	virtual const char* getDeviceName()const = 0;
	virtual typeDEV getDeviceType()const = 0;
	virtual string getIpAddress()const = 0;
	virtual int getPortNumber()const = 0;

	virtual void print()const = 0;//Вывод
};

