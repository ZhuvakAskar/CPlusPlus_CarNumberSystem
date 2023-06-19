#include "Header.h"
//А == -64     Я == -33
//автомобильных номерах нельзя увидеть буквы «й», «ц», «г», «ш», «щ», 
//«з», «ф», «ы», «п», «л», «д», «ж», «э», «я», «ч», «ь», «ъ», «б», «ю»


CarNumbSys::CarNumbSys() {
	this->setcarnumbers();
}

CarNumbSys::CarNumbSys(int num, char ch1, char ch2)
{
	carnumber = num;
	this->ch1 = ch1;
	this->ch2 = ch2;
}

CarNumbSys::~CarNumbSys()
{}

string CarNumbSys::tostring(bool end)
{
	string s[10];
	char c1 = ch1;
	char c2 = ch2;
	if (carnumber < 10 && carnumber >= 0) {
		s->append("000" + to_string(carnumber) + c1 + c2);
	}
	else if (carnumber < 100 && carnumber >= 10) {
		s->append("00" + to_string(carnumber) + c1 + c2);
	}
	else if (carnumber < 1000 && carnumber >= 100) {
		s->append("0" + to_string(carnumber) + c1 + c2);
	}
	else {
		s->append(to_string(carnumber) + c1 + c2);
	}
	if(end == true) return *s;
	else return s->append(" | ");
}

void CarNumbSys::numberplus()
{
	carnumber++;
	if (carnumber > 9999) {
		while (true)
		{
			ch1--;
			if (ch1 > -43) {
				ch1 = -64;
				ch2--;
				while (true) {
					if (ch1 > -43) {
						break;
					}
					else if ((ch1 <= -43 && ch1 >= -64) && (ch1 != -63 || ch1 != -61 || ch1 != -60 || ch1 != -58 || ch1 != -57 || ch1 != -55, -53, -49, -44, -42, -41, -40, -39, -38, -37, -36, -35, -34, -33)) {
						break;
					}
					else ch2--;
				}
				break;
			}
			else if ((ch1 <= -43 && ch1 >= -64) && (ch1 != -63 || ch1 != -61 || ch1 != -60 || ch1 != -58 || ch1 != -57 || ch1 != -55, -53, -49, -44, -42, -41, -40, -39, -38, -37, -36, -35, -34, -33)) {
				break;
			}
			else ch1--;
	}
	}
}

void CarNumbSys::setcarnumbers() {
	for (int i = 0; i < 10; i++) {
		if (i == 9) {
			carnumbrs.append(this->tostring(true));
		}
		else carnumbrs.append(this->tostring(false));
		this->numberplus();
	}
}

void CarNumbSys::refullcarnumbers()
{
	this->carnumbrs.resize(0);
	this->setcarnumbers();
}

void CarNumbSys::getcarnumber(int num)
{
	if (num == 10) {
		this->carnumbrs.resize(79);
	}
	else {
		num = (num - 1) * 9;
		for (int i = num; i < 79; i++) {
			this->carnumbrs[i] = this->carnumbrs[i + 9];
		}
		this->carnumbrs.resize(79);
	}
		this->carnumbrs.append("| " + this->tostring(true));
		this->numberplus();
}

void CarNumbSys::showinfo()const {
	cout << this->carnumbrs << endl;
	//for (int i = 0; i < 10; i++) {
	//	cout << this->tostring() << endl;
	//	this->numberplus();
	//}
}

void CarNumbSys::SYSTEMUP() {

	while (true)
	{
		int menu = -1, chose = -1;
		char chosech;
		cout << "0 - завершить работу" << endl;
		cout << "1 - вывести доступные номерные знаки" << endl;
		cout << "2 - получить номерной знак" << endl;
		cout << "3 - установить значение отчёта номеров" << endl;
		cout << "4 - перезаполнить список номеров (обычно используют после установки новых значений номера)" << endl;
		cout << "10 - отчисть экран" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1: {
			this->showinfo();
			break;
		}
		case 2: {
			cout << "Ведите порядковый номер нужного вам номерного знака" << endl;
			cin >> chose;
			if (chose < 11 && chose > 0) {
				this->getcarnumber(chose);
			}
			else cout << "Выберете один из представленных номеров(от 1 до 10)" << endl;
			break;
		}
		case 3: {
			while (chose != 0)
			{
				cout << "0 - назад" << endl;
				cout << "1 - установить число номера" << endl;
				cout << "2 - установить 1-ю букву номера" << endl;
				cout << "3 - установить 2-ю букву номера" << endl;
				cin >> chose;
				if (chose == 0)
				{
					break;
				}
				else if (chose == 1) {
					cout << "Ведите цифровой номер знака" << endl;
					cin >> chosech;
					cout << chosech << endl;
					this->setnumber(chosech);
				}
				else if (chose == 2) {
					cout << "Ведите первую букву номерного знака (Ввидить можно только заглавными буквами кирилицы)" << endl <<
						"Запрещёные буквы «Й», «Ц», «Г», «Ш», «Щ», «З», «Ф», «Ы», «П», «Л», «Д», «Ж», «Э», «Я», «Ч», «Ь», «Ъ», «Б», «Ю»" << endl;
					cin >> chosech;
					this->setch1(chosech);
				}
				else if (chose == 3) {
					cout << "Ведите вторую букву номерного знака (Ввидить можно только заглавными буквами кирилицы)" << endl <<
						"Запрещёные буквы «Й», «Ц», «Г», «Ш», «Щ», «З», «Ф», «Ы», «П», «Л», «Д», «Ж», «Э», «Я», «Ч», «Ь», «Ъ», «Б», «Ю»" << endl;
					cin >> chosech;
					this->setch2(chosech);
				}
			}
			break;
		}
		case 4: {

		}
		case 10:
		{
			system("cls");
		}
		default: {
			break;
		}
			   chose = -1;
		}
		if (menu == 0) {
			break;
		}
	}
	this->~CarNumbSys();
}