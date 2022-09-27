#include <iostream>
using namespace std;

int main()
{
	//Задание 1

	setlocale(LC_ALL, "Russian");
	cout << "Задание 1 \n\n";
	cout << "Под int отводится " \
		<< sizeof(int) << " байта \n";
	cout << "Под short int отводится " \
		<< sizeof(short int) << " байта \n";
	cout << "Под long int отводится " \
		<< sizeof(long int) << " байта \n";
	cout << "Под float отводится " \
		<< sizeof(float) << " байта \n";
	cout << "Под double отводится " \
		<< sizeof(double) << " байт \n";
	cout << "Под long double отводится " \
		<< sizeof(long double) << " байт \n";
	cout << "Под char отводится " \
		<< sizeof(char) << " байт \n";
	cout << "Под bool отводится " \
		<< sizeof(bool) << " байт \n\n";

	//Задание 2

	int chislo, i;
	unsigned int kol_razryadov = sizeof(chislo) * 8;
	unsigned int maska = 1 << (kol_razryadov - 1);
	cout << "Задание 2 \n\n";
	cout << "Введите число int: ";
	cin >> chislo;
	cout << "\n" << "Двоичное представление числа " << chislo << " : \n";
	for (i = kol_razryadov - 1; i >= 0; i -= 1)
	{
		putchar(chislo & maska ? '1' : '0');
		maska >>= 1;
		if (i % 8 == 0)
			putchar(' ');
		if (i % (kol_razryadov - 1) == 0)
			putchar(' ');
	}

	//Задание 3

	cout << "\n\n" << "Задание 3" << "\n\n";
	cout << "Введите число float: ";
	union
	{
		float chislo_float;
		int chislo_3;
	};
	cin >> chislo_float;

	cout << "\n" << "Двоичное представление числа " << chislo_float << " : \n";
	kol_razryadov = sizeof(chislo_float) * 8; // Обновляем количество разрядов
	maska = 1 << kol_razryadov - 1; // Обновляем маску
	cout << "\n" << "  |<--------Мантисса------->|<Порядок>|\n";
	for (i = 0; i < kol_razryadov-1; i += 1)
	{
		putchar(chislo_3 & maska ? '1' : '0');
		chislo_3 <<= 1;
		if (i % 8 == 0)
			putchar(' ');
		
	}

	//Задание 4

	cout << "\n\n" << "Задание 4" << "\n\n";
	cout << "Введите число double: ";
	union {
		double chislo_double;
		int chislo_4[2];
	};

	cin >> chislo_double;

	kol_razryadov = sizeof(double) * 8; //Обновляем количество разрядов для работы
	maska = 1 << kol_razryadov-1; // Обновялем маску
	cout << "\n" << "  |<-Порядок>|<------------------------Мантисса------------------------>|\n";
	for (int i = 0; i < kol_razryadov/2; i++)
	{
		putchar(chislo_4[1] & maska ? '1' : '0');
		chislo_4[1] <<= 1;
		if (i % 8 == 0 || i == 12)
			putchar(' ');
	} // Работает с первыми 4 битами

	for (int i = 0; i < kol_razryadov/2; i++) {
		if (i % 8 == 0)
			putchar(' ');
		putchar(chislo_4[0] & maska ? '1' : '0');
		chislo_4[0] <<= 1;
	} // Работает со вторыми 4 битами
}
