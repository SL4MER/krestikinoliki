#include <iostream>

using namespace std;

bool Draw(int* i) {
	if (*i == 8)
		return 1;
	return 0;
}


bool Win(char a[3][3]) {
	for (int i = 0; i < 3; i++) {
		if (a[i][0] == a[i][1] && a[i][1] == a[i][2] && a[i][0] != ' ')
			return true;
	}
	for (int j = 0; j < 3; j++) {
		if (a[0][j] == a[1][j] && a[1][j] == a[2][j] && a[0][j] != ' ')
			return true;
	}
	if (a[0][0] == a[1][1] && a[1][1] == a[2][2])
		return true;
	if (a[0][2] == a[1][1] && a[1][1] == a[2][0])
		return true;
	return false;
}

void Rules() {
	cout << "Правила:\nа. Игроки играют поочерёдно. \n";
	cout << "b. Один играет крестиками, другой - ноликами. \n";
	cout << "c. Игрок не может сделать ход вне своего хода. \n \n";
}


int Inputcorrectness(char a, int* i) {
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

	bool restart;

	do {
		Rules();

		char a[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
		char X = 'x', O = '0';



		for (int i = 0; i < 9; i++) {
			int x, y;
			cout << "Введите номер строки: ";
			cin >> x;
			cout << "Введите номер столбца: ";
			cin >> y;
			Inputcorrectness(a[x - 1][y - 1], &i);
			cout << endl;
			a[x - 1][y - 1] = (i % 2 == 0) ? X : O;
			PrintArr(a);
			if (i > 3) {
				if (Win(a) == true) {
					cout << "ПОБЕДИЛ ИГРОК " << (i) % 2 + 1 << endl;
					break;
				}
			}
			if (Draw(&i)) cout << "НИЧЬЯ \n";
		}

		cout << "\nХотите сыграть еще раз? (1 - да, 0 - нет): ";
		cin >> restart;
		cout << endl;

	} while (restart);

	cout << "Спасибо за игру!" << endl;

	return 0;
}