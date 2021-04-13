
#ifndef Maze_H
#define Maze_H

#include <string>
#include <map>
#include <iostream>
#include <algorithm>//used to swap the array position. The way to use it was obtained from https://stackoverflow.com/questions/8196037/c-string-swap-character-places however was adapted to make it work within the game scenario
#include <conio.h>//used to read in key movements obtained from https://www.youtube.com/watch?v=v3MiuCVTMvE  using the _getch() function
#include <fstream>//the fstream library was used to read in mazes from txt files. These include use of IFstreams and getline. The documentation was obtained from http://www.cplusplus.com/reference/fstream/fstream/ and the changed to fit my purpose.
#include <vector>
//#include <filesystem>

using namespace std;

enum class movement {
	up = 0,
	down = 1,
	left = 2,
	right = 3
};

struct coord {
	int x;
	int y;
	coord operator+(coord rhs)
	{
		return coord{ this->x + rhs.x, this->y + rhs.y };
	}
};



static std::map<movement, coord> moves = {
	{ movement::up,		{ 0, 1 } },
	{ movement::down,	{ 0,-1} },
	{ movement::left,	{-1, 0} },
	{ movement::right,	{ 1, 0} },
};	


class Maze {

	int height;
	int width;
	coord begin;
	coord Exit;
	bool inBounds(const coord& c);
	std::vector<std::vector<char>> board;
	bool valid_maze(coord start);
	coord RandCoord();
public:
	Maze(const char* file);
	Maze(int h, int w);
	//void Play();//plays the game where the user navigates the stage
	bool complete(const coord& player);//if true player wins the game
	void GenRandom(int h, int w);
	int getWidth();
	int getHeight();
	char at(int x, int y);


protected:
	std::string Stage;//maze the user navigates
	int Player_position;//where the player starts on the maze, it will change after each movement
	int Win_Position;//position that is where the user must reach to win the game
	
};
#endif

