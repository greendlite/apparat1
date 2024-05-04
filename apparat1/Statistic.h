#pragma once
#include <map>
#include <iostream>
#include "TemplateTree.h"
#include "NetworkHardware.h"
class Statistic
{
public:
	double SumGadget(INetworkHardware* gadget);
	double SumGadget(TemplateTree<INetworkHardware>*gadget);
	void print();
private:
	map<INetworkHardware*, int> Stats;
	double Gadgetsum;
};

