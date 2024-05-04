#pragma once
#include <String>
#include <iostream>
#include "typeDEV.h"
#include "INetworkHardware.h"
using namespace std;

class NetworkHardware :public virtual INetworkHardware {

public:
    // Конструктор, который принимает имя устройства, тип устройства, IP-адрес, и номер порта
    NetworkHardware(); //Конструктор по умолчанию
    NetworkHardware(const char* name, typeDEV type, string ip, int port);
    NetworkHardware(const NetworkHardware& st) :NetworkHardware(st.deviceName, st.deviceType, st.ipAddress, st.portNumber) {// копирующий конструктор 
    }
    void setdeviceName(const char* name); // Сеттер поля имени
    void setdeviceType(typeDEV type);// Сеттер поля типа
    void setipAddress(string ip);// Сеттер поля адреса
    void setportNumber(int port);// Сеттер поля порта

    const char* getDeviceName()const;
    typeDEV getDeviceType()const;
    string getIpAddress()const;
    int getPortNumber()const;


    void print()const;//Вывод
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

