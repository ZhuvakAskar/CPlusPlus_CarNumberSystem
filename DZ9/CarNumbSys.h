#pragma once
class CarNumbSys
{
	//А == -64     Я == -33
//автомобильных номерах нельзя увидеть буквы «й», «ц», «г», «ш», «щ», «з», «ф», «ы», 
//«п», «л», «д», «ж», «э», «я», «ч», «ь», «ъ», «б», «ю»
//ИНФОРМАЦИЯ ПРО БУКВЫ В НОМЕРНЫХ ЗНАКАХ ВЗЯТА С САЙТА:
//   https://www.avtovzglyad.ru/gai/pdd/2018-06-20-pochemu-na-nomerah-mashin-net-bukv-zh-p-ili-y/


	static int carnumber, ch1, ch2;
	string carnumbrs;
public:
	CarNumbSys();
	CarNumbSys(int num,char ch1,char ch2);
	~CarNumbSys();

	static void setnumber(int num) {
		if (num < 10000 && num > -1) {
			carnumber = num;
		}
		else cout << "Ошибка ввода! (область ввода от 0 до 9999)" << endl;
	}
	static void setch1(int ch) {
		ch += 64;
		if ((ch <= -33 && ch >= -64) && (ch != -63 || ch != -61 || ch != -60 || ch != -58 || ch != -57 || ch != -55, -53, -49, -44, -42, -41, -40, -39, -38, -37, -36, -35, -34, -33)) {
			ch1 = ch;
		}
		else cout << "Ошибка ввода!" << endl << "В номерном знаке не допустимы следущие символы: Б  Г  Д  Ж  З  Й  Л  П  Ф  Ц  Ч  Ш  Щ  Ъ  Ы  Ь  Э  Ю  Я" << endl << "Так-же убедитесь что вводите букву в заглавном регистре" << endl;

	}
	static void setch2(int ch) {
		ch += 64;
		if ((ch <= -33 && ch >= -64) && (ch != -63 || ch != -61 || ch != -60 || ch != -58 || ch != -57 || ch != -55, -53, -49, -44, -42, -41, -40, -39, -38, -37, -36, -35, -34, -33)) {
			ch2 = ch;
		}
		else cout << "Ошибка ввода!" << endl << "В номерном знаке не допустимы следущие символы: Б  Г  Д  Ж  З  Й  Л  П  Ф  Ц  Ч  Ш  Щ  Ъ  Ы  Ь  Э  Ю  Я" << endl << "Так-же убедитесь что вводите букву в заглавном регистре" << endl;
	};

	int shownumber()const { return carnumber; };
	char showch1()const { return ch1; };
	char showch2()const { return ch2; };

	static void numberplus();
	static string tostring(bool end);

	void setcarnumbers();

	void refullcarnumbers();

	void getcarnumber(int num);

	void showinfo()const;

	void SYSTEMUP();
};

