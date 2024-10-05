#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <ctime>
using namespace std;

void rowtodel(int ar[4][4], int& rows, int& cols, int rowdel) {
	for (int i = rowdel; i < rows - 1; i++) {
		for (int j = 0; j < cols; j++) {
			ar[i][j] = ar[i+1][j];
		}
	}
	rows--;
}
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(0));

	int cols = 4;
	int rows = 4;
	int ar[4][4];
	

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			ar[i][j] = rand() % 100;
			cout << ar[i][j]<< ' ';
		}
		cout << endl;
	}

	int rowdel;
	cout << "Введіть рядок який ви хочете видалити" << endl;
	cin >> rowdel;
	rowdel--;
	rowtodel(ar, rows, cols, rowdel);

	for (int i = 0; i < rows; i++) {
		for (int j = 0; j < cols; j++) {
			cout << ar[i][j] << ' ';
		}
		cout << endl;
	}

}

