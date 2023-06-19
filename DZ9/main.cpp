#include "Header.h"

int CarNumbSys::carnumber = 1, CarNumbSys::ch1 = -64, CarNumbSys::ch2 = -64;

void main() {
	setlocale(0, "");	
	CarNumbSys sys/*(1,"À","À")*/;

	sys.SYSTEMUP();
	
	system("pause");
}

//void main() {
//	setlocale(0, "");
//	char a = 'q';
//	for (int i = -64; i < -32; i++) {
//		cout << (char)i << " ";
//		if (i == -80 || i == -40) { cout << endl; }
//	}
//	while (a != '+')
//	{
//		cin >> a;
//		cout << (int)a << endl;
//	}
//	system("pause");
//}