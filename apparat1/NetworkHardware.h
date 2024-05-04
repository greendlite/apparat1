#pragma once
#include <String>
#include <iostream>
#include "typeDEV.h"
#include "INetworkHardware.h"
using namespace std;

class NetworkHardware :public virtual INetworkHardware {

public:
    // �����������, ������� ��������� ��� ����������, ��� ����������, IP-�����, � ����� �����
    NetworkHardware(); //����������� �� ���������
    NetworkHardware(const char* name, typeDEV type, string ip, int port);
    NetworkHardware(const NetworkHardware& st) :NetworkHardware(st.deviceName, st.deviceType, st.ipAddress, st.portNumber) {// ���������� ����������� 
    }
    void setdeviceName(const char* name); // ������ ���� �����
    void setdeviceType(typeDEV type);// ������ ���� ����
    void setipAddress(string ip);// ������ ���� ������
    void setportNumber(int port);// ������ ���� �����

    const char* getDeviceName()const;
    typeDEV getDeviceType()const;
    string getIpAddress()const;
    int getPortNumber()const;


    void print()const;//�����
    ~NetworkHardware();

    bool operator<(const NetworkHardware& left);

    bool operator>(const NetworkHardware& right);

    bool operator== (int m);

    friend ostream& operator<<(ostream& os, const NetworkHardware& device);
protected:
    virtual string SubjectWrite() const = 0;
private:
    char* deviceName=NULL;
    typeDEV deviceType;
    string ipAddress;
    int portNumber;
    static int numNum;
};

