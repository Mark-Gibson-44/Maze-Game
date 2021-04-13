#ifndef GAME_H
#define GAME_H


#include <map>




class Game {

	short games_played, Points;
	//coord current_position;
	//Maze current;
	void init();

	void play();//Loop of execution
	void print_board();
};



#endif