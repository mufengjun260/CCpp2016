#include <iostream>
#include <conio.h>
using namespace std;
const int SIZE = 10;
int x = 1, y = 1;

char fin[SIZE][SIZE] = {
	'#','#','#','#','#','#','#','#','#','#',
	'#',' ',' ','#','#',' ',' ',' ','#','#',
	'#',' ',' ','#','#',' ','#',' ',' ','#',
	'#',' ',' ',' ','#',' ','#','#',' ','#',
	'#',' ','#',' ','#',' ','#','#',' ','#',
	'#',' ','#',' ','#',' ',' ','#',' ','#',
	'#',' ','#',' ',' ','#',' ','#',' ','#',
	'#',' ','#','#',' ','#',' ','#',' ','#',
	'#',' ',' ','#',' ',' ',' ','#','@','#',
	'#','#','#','#','#','#','#','#','#','#'
};

void MazeGene();
void GetKey();
void Move(char dir);

int main() {
	MazeGene();
	GetKey();
	system("pause");
	return 0;
}

void MazeGene() {
	system("cls");
	for (int tmpo = 0; tmpo <= 9; tmpo++) {
		for (int tmpi = 0; tmpi <= 9; tmpi++) {
			if (!(tmpi == x&&tmpo == y)) {
				cout << fin[tmpo][tmpi];
			}
			else {
				cout << '*';
			}
		}
		cout << endl;
	}

}

void GetKey() {
	char dir;
	while (1) {
		if (_kbhit() != 0) {
			dir = _getch();
			if (dir == 'w' || dir == 'a' || dir == 's' || dir == 'd') {
				Move(dir);
				MazeGene();
				if (fin[y][x] == '@') {
					cout << "you had win";
					return;
				}
			}
		}
	}
}

void Move(char dir) {
	switch (dir)
	{
	case 'a': {
		if (fin[y][x - 1] != '#') x--;
		break;
	}
	case 'd': {
		if (fin[y][x + 1] != '#') x++;
		break;
	}
	case 's': {
		if (fin[y + 1][x] != '#') y++;
		break;
	}
	case 'w': {
		if (fin[y - 1][x] != '#') y--;
		break;
	}
	}
}