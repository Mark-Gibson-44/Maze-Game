#ifndef GAME_H
#define GAME_H

#include "Maze.h"
#include <map>




class Game {
	const char* menu = "1: Play Maze\n"\
		"2: Check Score\n"\
		"3: Games Played\n"\
		"4: Quit\n";
	short games_played, Points;
	coord start;
	Maze board;
	
	//coord current_position;
	bool validMove(coord m);
	void init();

	void play();//Loop of execution
	void print_board();
public:
	Game(Maze m);
};



#endif