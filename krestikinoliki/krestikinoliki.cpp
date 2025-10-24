#include <iostream>

using namespace std;

void Rules() {
	cout << "Правила:\nа. Игроки играют поочерёдно. \n";
	cout << "b. Один играет крестиками, другой - ноликами. \n";
	cout << "c. Игрок не может сделать ход вне своего хода. \n \n";
}


int Inputcorrectness(char a, int* i, int x, int y) {
	if (a == 'x' || a == '0'){
		cout << "\nПРЕДУПРЕЖДЕНИЕ: Данное поле уже занято, выберите другое\n";
		return (*i)--;
	}
}

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
	
	Rules();

	char a[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	char X = 'x', O = '0';



	for (int i = 0; i < 9; i++) {
		int x, y;
		cout << "Введите номер строки: ";
		cin >> x;
		cout << "Введите номер столбца: ";
		cin >> y;
		Inputcorrectness(a[x - 1][y - 1], &i, x, y);
		cout << endl;
		a[x - 1][y - 1] = (i % 2 == 0) ? X : O;
		PrintArr(a);

	}



	return 0;
}