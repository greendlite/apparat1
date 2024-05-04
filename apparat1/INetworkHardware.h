#pragma once
#include <iostream>
using namespace std;

class INetworkHardware
{
public:// �������

	virtual void setdeviceName(const char* name)=0; // ������ ���� �����
	virtual void setdeviceType(typeDEV type) = 0;// ������ ���� ����
	virtual void setipAddress(string ip) = 0;// ������ ���� ������
	virtual void setportNumber(int port) = 0;// ������ ���� �����

	virtual const char* getDeviceName()const = 0;
	virtual typeDEV getDeviceType()const = 0;
	virtual string getIpAddress()const = 0;
	virtual int getPortNumber()const = 0;

	virtual void print()const = 0;//�����
};

