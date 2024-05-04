#pragma once
#include "NetworkHardware.h"
#include <iostream>
#include <string>
using namespace std;
NetworkHardware::NetworkHardware(const char* name, typeDEV type, string ip, int port) :NetworkHardware()// конструктор с параметрами
{

	setdeviceName(name); // Сеттер поля 
	setdeviceType(type);// Сеттер поля 
	setipAddress(ip);// Сеттер поля 
	setportNumber(port);// Сеттер поля 

}
NetworkHardware::NetworkHardware() { // конструктор по умолчнию
	numNum++;
}
void NetworkHardware::setdeviceName(const char* name) //сеттер
{
	delete deviceName;
	deviceName = new char[strlen(name) + 1];
	strcpy_s(deviceName, strlen(name) + 1, name);
}
void NetworkHardware::setdeviceType(typeDEV type)
{
	deviceType = type;
}
void NetworkHardware::setipAddress(string ip)
{
	ipAddress = ip;
}
void NetworkHardware::setportNumber(int port)throw(double)
{
	if (portNumber < 0) throw exception("Порт не может быть отрицательным значением");
	portNumber = port;
}
const char* NetworkHardware::getDeviceName() const
{
	return deviceName;
}
typeDEV NetworkHardware::getDeviceType() const
{
	return deviceType;
}
string NetworkHardware::getIpAddress() const
{
	return ipAddress;
}
int NetworkHardware::getPortNumber() const
{
	return portNumber;
}
void NetworkHardware::print() const
{
	cout << "Position: " << numNum << endl;
	cout << "Device Name: " << getDeviceName() << endl;
	cout << "Device Type: ";
	if (deviceType == typeDEV::Wired) cout << "Проводное устройство";
	else if (deviceType == typeDEV::Wireless) cout << "Беспроводное устройство";
	cout << endl;
	cout << "IP Address: " << getIpAddress() << endl;
	cout << "Port Number: " << getPortNumber() << endl;
	cout << endl;
}
NetworkHardware::~NetworkHardware() // диструктор
{
	delete[] deviceName;
	numNum--;
}
int NetworkHardware::numNum = 0;

//перегрузка вывода
ostream& operator<<(ostream& os, const NetworkHardware& device) {
	os << "Device Name: " << device.getDeviceName() << endl;
	os << "Device Type: ";
	if (device.deviceType == typeDEV::Wired)
		os << "Проводное устройство";
	else if (device.deviceType == typeDEV::Wireless)
		os << "Беспроводное устройство";
	os << endl;
	os << "IP Address: " << device.getIpAddress() << endl;
	os << "Port Number: " << device.getPortNumber() << endl;
	os << endl << endl;
	return os;
}
bool NetworkHardware::operator<(const NetworkHardware& left)
{
	return portNumber < left.getPortNumber();
}
bool NetworkHardware::operator>(const NetworkHardware& right)
{
	return portNumber > right.getPortNumber();
}
bool NetworkHardware::operator==(int m)
{
	return portNumber == m;
}

