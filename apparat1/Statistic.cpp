#include "Statistic.h"

double Statistic::SumGadget(INetworkHardware* gadget)
{
	Gadgetsum += gadget->getPortNumber();
	Stats[gadget]++;
	return Gadgetsum;
}

double  Statistic::SumGadget(TemplateTree< INetworkHardware>* gadget)
{
	for (int i = gadget->Get_count() - 1; i > 0; i--) {
		SumGadget(gadget->getitem(i));
	}
	return Gadgetsum;
}

void Statistic::print()
{
	cout << "Сумма портов во всех гаджетах: " << Gadgetsum << endl;
	for (auto it = Stats.begin(); it != Stats.end(); ++it)
	{
		cout << it->first->getDeviceName() << " " << it->second << endl;
	}
	cout << Gadgetsum << endl;
}

