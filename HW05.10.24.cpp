//#include <iostream>
//#include <Windows.h>
//#include <cstdlib>
//#include <ctime>
//using namespace std;
//
//void rowtodel(int ar[4][4], int& rows, int& cols, int rowdel) {
//	for (int i = rowdel; i < rows - 1; i++) {
//		for (int j = 0; j < cols; j++) {
//			ar[i][j] = ar[i+1][j];
//		}
//	}
//	rows--;
//}
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	srand(time(0));
//
//	int cols = 4;
//	int rows = 4;
//	int ar[4][4];
//	
//
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			ar[i][j] = rand() % 100;
//			cout << ar[i][j]<< ' ';
//		}
//		cout << endl;
//	}
//
//	int rowdel;
//	cout << "Введіть рядок який ви хочете видалити" << endl;
//	cin >> rowdel;
//	rowdel--;
//	rowtodel(ar, rows, cols, rowdel);
//
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			cout << ar[i][j] << ' ';
//		}
//		cout << endl;
//	}
//
//}
//
//#include <iostream>
//#include <Windows.h>
//#include <cstdlib>
//#include <ctime>
//using namespace std;
//
//void transport(int ar[4][4], int ar2[4][4], int rows, int cols) {
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			ar2[j][i] = ar[i][j];
//		}
//	}
//}
//int main()
//{
//	SetConsoleCP(1251);
//	SetConsoleOutputCP(1251);
//	srand(time(0));
//
//	int cols = 4;
//	int rows = 4;
//	int ar[4][4];
//	
//
//	for (int i = 0; i < rows; i++) {
//		for (int j = 0; j < cols; j++) {
//			ar[i][j] = rand() % 100;
//			cout << ar[i][j]<< ' ';
//		}
//		cout << endl;
//	}
//
//	int ar2[4][4];
//	transport(ar, ar2, rows, cols);
//	cout << "Перевернута матриця" << endl;
//	for (int i = 0; i < cols; i++) {
//		for (int j = 0; j < rows; j++) {
//			cout << ar2[i][j] << ' ';
//		}
//		cout << endl;
//	}
//	return 0;
//}

#include <iostream>
#include <Windows.h>
#include <cstring>
using namespace std;

void name(char** data, int count) {
	char name[100];
	cout << "Введіть ім'я" << endl;
	cin >> name;

	for (int i = 0; i < count; i++) {
		if (strcmp(data[i * 2], name) == 0) {
			cout << "Знайдено " << data[i * 2] << " - " << data[i * 2 + 1] << endl;
			return;
		}
	}
	cout << "Ім'я не знайдено";
}

void tel(char** data, int count) {
	char tel[100];
	cout << "Введіть номер телефону" << endl;
	cin >> tel;

	for (int i = 0; i < count; i++) {
		if (strcmp(data[i * 2+1], tel) == 0) {
			cout << "Знайдено " << data[i * 2] << " - " << data[i * 2 + 1] << endl;
			return;
		}
	}
	cout << "Номер телефону не знайдено";
}
void change(char** data, int count) {
	char name[100];
	cout << "Введіть ім'я для зміни телефону" << endl;
	cin >> name;

	for (int i = 0; i < count; i++) {
		if (strcmp(data[i * 2], name) == 0) {
			cout << "Введіть новий телефон" << endl;
			cin >> data[i * 2+1];
			cout << "Дані оновлено"<<endl;
			return;
		}
	}
	cout << "Ім'я не знайдено";
}


int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int count = 0;

	char** data = new char* [100 * 2];
	for (int i = 0; i < 100 * 2; i++) {
		data[i] = new char[100];
	}
	while (true) {
		cout << "Введіть ім'я(0 для виходу з циклу" << endl;
		cin >> data[count * 2];
		if (strcmp(data[count * 2], "0") == 0) break;
		cout << "Введіть телефон" << endl;
		cin >> data[count * 2 + 1];
		count++;

	}

	while (true) {
		cout << "Оберіть наступну функцію"<<endl;
		cout << "1. Пошук за ім'ям"<<endl;
		cout << "2. Пошук за телефоном "<<endl;
		cout << "3. Заміна даих"<<endl;
		cout << "0. Вихід ";
		int num;
		cout << endl;
		cin >> num;

		switch (num) {
		case 1:
			name(data, count);
			break;
		case 2:
			tel(data, count);
			break;
		case 3:
			change(data, count);
			break;
		case 0:
			for (int i = 0; i < 100 * 2; i++) {
				delete[] data;
			}
			delete[] data;
			return 0;

		}
	}
}
		
