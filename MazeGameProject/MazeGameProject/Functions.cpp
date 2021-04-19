#include "Functions.h"


void Rules() {//outputs the rules of the game. Made into a function so that if the rules change simply have to change function.
	std::cout << "You must navigate through the maze, You are represented by the 0 character, the walls are the X character and cannot be moved onto You must reach the #" << std::endl;
	std::cout << "X:		Walls\n0:	Player character\n#:	Goal" << std::endl;
	system("pause");
}
void Scores(int games, int score) {
	if (games == 0) {//identifies if you have played any games and if not does not display any score
		std::cout << "You Have Not Played Any Games Yet" << std::endl;
	}
	else {
		std::cout << "You have a score of... " << score << std::endl;// outputs the score
	}
}
