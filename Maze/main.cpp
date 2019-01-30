#include "maze.h"

ostream& operator<< (ostream& os, Position& p) {
	os << p.x+1 << ',' << p.y+1;

	return os;
}

int main() {
	MazeSolution maze;
	Position goal(19, 18);

	maze.Initiailize();
	while (1) {
		if (maze.Search()) {
			maze.step();
			if ((maze.currentPosition.x == goal.x )&& (maze.currentPosition.y == goal.y)) {
				break;
			}
		}
		else {
			maze.back();
		}
	}
	maze.gotoxy(Position(0,20));
	cout << maze.currentPosition << endl;
	return 0;
}