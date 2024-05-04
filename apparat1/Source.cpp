#include "NetworkHardware.h" // Header
#include "typeDEV.h"
#include "Hybrid.h"
#include "Computer.h"
#include "Phone.h"
#include "Router.h"
#include <iostream>
#include "TemplateTree.h"
#include "Statistic.h"
using namespace std;

int main() {
    setlocale(LC_ALL, "RU");
    // Создание объекта класса NetworkHardware
    Router router("Роутер", typeDEV::Wired, "192.168.0.1", 8080,90000);

    Phone phone("Телефон", typeDEV::Wireless, "132.138.0.1", 9090, 3);

    Computer computer("Компьютер", typeDEV::Wired, "132.128.3.4", 1010,12);

    Hybrid hybrid("Компьютер", typeDEV::Wired, "132.128.3.4", 1010, 12, 3,98);


    TemplateTree<INetworkHardware> tr;

	try {
		/*hdd.set_costSD(-1.0);*/
		router.setSpeed(20000);
	}
	catch (double port) {
		cout << "Порт: " << port << "Меньше 0" << endl;
	}
	catch (const overflow_error& err) {
		cout << err.what() << endl;
	}
	catch (const exception& err) {
		cout << err.what() << endl;
	}
	catch (...) {
		cout << "ошибка" << endl;
	}

	tr.Add(&router);
	tr.Add(&phone);
	tr.Add(&computer);
	tr.Add(&hybrid);
	tr.Show();

	Statistic st1;
	st1.SumGadget(&hybrid);
	st1.SumGadget(&tr);
	st1.print();
	system("pause");
    return 0;
}