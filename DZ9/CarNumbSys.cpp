#include "Header.h"
//� == -64     � == -33
//������������� ������� ������ ������� ����� ��, ���, ��, ���, ���, 
//��, ���, ���, ��, ��, ��, ��, ���, ���, ���, ���, ���, ��, ���


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
		cout << "0 - ��������� ������" << endl;
		cout << "1 - ������� ��������� �������� �����" << endl;
		cout << "2 - �������� �������� ����" << endl;
		cout << "3 - ���������� �������� ������ �������" << endl;
		cout << "4 - ������������� ������ ������� (������ ���������� ����� ��������� ����� �������� ������)" << endl;
		cout << "10 - ������� �����" << endl;
		cin >> menu;
		switch (menu)
		{
		case 1: {
			this->showinfo();
			break;
		}
		case 2: {
			cout << "������ ���������� ����� ������� ��� ��������� �����" << endl;
			cin >> chose;
			if (chose < 11 && chose > 0) {
				this->getcarnumber(chose);
			}
			else cout << "�������� ���� �� �������������� �������(�� 1 �� 10)" << endl;
			break;
		}
		case 3: {
			while (chose != 0)
			{
				cout << "0 - �����" << endl;
				cout << "1 - ���������� ����� ������" << endl;
				cout << "2 - ���������� 1-� ����� ������" << endl;
				cout << "3 - ���������� 2-� ����� ������" << endl;
				cin >> chose;
				if (chose == 0)
				{
					break;
				}
				else if (chose == 1) {
					cout << "������ �������� ����� �����" << endl;
					cin >> chosech;
					cout << chosech << endl;
					this->setnumber(chosech);
				}
				else if (chose == 2) {
					cout << "������ ������ ����� ��������� ����� (������� ����� ������ ���������� ������� ��������)" << endl <<
						"���������� ����� �ɻ, �ֻ, �û, �ػ, �ٻ, �ǻ, �Ի, �ۻ, �ϻ, �˻, �Ļ, �ƻ, �ݻ, �߻, �׻, �ܻ, �ڻ, ���, �޻" << endl;
					cin >> chosech;
					this->setch1(chosech);
				}
				else if (chose == 3) {
					cout << "������ ������ ����� ��������� ����� (������� ����� ������ ���������� ������� ��������)" << endl <<
						"���������� ����� �ɻ, �ֻ, �û, �ػ, �ٻ, �ǻ, �Ի, �ۻ, �ϻ, �˻, �Ļ, �ƻ, �ݻ, �߻, �׻, �ܻ, �ڻ, ���, �޻" << endl;
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