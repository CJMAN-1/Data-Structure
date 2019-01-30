#include "maze.h"

void MazeSolution::Initiailize() {
	currentPosition.x = 1;
	currentPosition.y = 0;
	PrintBoard();

	maze[0][1] = 2;
	gotoxy(Position(0, 1));
	cout << '0';
}

void MazeSolution::PrintBoard() {
	for (int j = 0; j < SIZE; j++) {
		for (int i = 0; i < SIZE; i++) {
			if (maze[i][j] == 0) {
				cout << tile[EMPTY];
			}
			else if (maze[i][j] == 1){
				cout << tile[WALL];
			}
			else if (maze[i][j] == 2) {
				cout << tile[WENT];
			}
		}//inner
		cout << endl;
	}//outter
}

void MazeSolution::gotoxy(Position p)//지정한 위치로 커서 이동
{
	COORD pos = { p.x*2,p.y };

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

bool MazeSolution::Search() {
	for (int i = 0; i < 4; i++) {
		try {
			switch (i) {
			case 0:
				if (currentPosition.x-1 < 0)
					throw i;

				if (maze[currentPosition.x-1][currentPosition.y] == 0) {
					nextPosition.x = currentPosition.x-1;
					nextPosition.y = currentPosition.y;
					return true;
				}
			

			case 1:
				if (currentPosition.y+1 > 19)
					throw i;

				if (maze[currentPosition.x][currentPosition.y+1] == 0) {
					nextPosition.x = currentPosition.x;
					nextPosition.y = currentPosition.y+1;
					return true;
				}
			

			case 2:
				if (currentPosition.x+1 > 19)
					throw i;

				if (maze[currentPosition.x+1][currentPosition.y] == 0) {
					nextPosition.x = currentPosition.x + 1;
					nextPosition.y = currentPosition.y;
					return true;
				}
			

			case 3:
				if (currentPosition.y-1 < 0)
					throw i;

				if (maze[currentPosition.x][currentPosition.y-1] == 0) {
					nextPosition.x = currentPosition.x;
					nextPosition.y = currentPosition.y-1;
					return true;
				}
			

			default:
				return false;
			}
		}
		catch (int i) {}
	}
	
}

void MazeSolution::step() {
	way.insert_top(currentPosition);
	currentPosition = nextPosition;
	maze[currentPosition.x][currentPosition.y] = 2;
	gotoxy(currentPosition);
	cout << '0';
	return;
}

void MazeSolution::back() {
	gotoxy(currentPosition);
	cout << tile[EMPTY];
	currentPosition = way.pop_top();

	return;
}
