#include "Functions.h"


void Rules() {//outputs the rules of the game. Made into a function so that if the rules change simply have to change function.
	cout << "You must navigate through the maze, You are represented by the 0 character, the walls are the X character and cannot be moved onto You must reach the #" << endl;
	cout << "X:		Walls" << endl << "0:	Player character" << endl << "#:	Goal" << endl;
	system("pause");
}
void Scores(int games, int score) {
	if (games == 0) {//identifies if you have played any games and if not does not display any score
		cout << "You Have Not Played Any Games Yet" << endl;
	}
	else {
		cout << "You have a score of... " << score << endl;// outputs the score
	}
}
