#include <iostream>

using namespace std;

void PrintArr(char a[3][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl << endl;
	}
}

int main() {
	setlocale(LC_ALL, "");


	char a[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	char X = 'x', O = '0';



	for (int i = 0; i < 9; i++) {
		int x, y;
		cout << "Введите номер строки: ";
		cin >> x;
		cout << "Введите номер столбца: ";
		cin >> y;
		cout << endl;
		a[x - 1][y - 1] = (i % 2 == 0) ? X : O;
		PrintArr(a);

	}



	return 0;
}