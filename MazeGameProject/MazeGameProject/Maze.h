
#ifndef Maze_H
#define Maze_H

#include <string>
#include <iostream>
#include <algorithm>//used to swap the array position. The way to use it was obtained from https://stackoverflow.com/questions/8196037/c-string-swap-character-places however was adapted to make it work within the game scenario
#include <conio.h>//used to read in key movements obtained from https://www.youtube.com/watch?v=v3MiuCVTMvE  using the _getch() function
#include <fstream>//the fstream library was used to read in mazes from txt files. These include use of IFstreams and getline. The documentation was obtained from http://www.cplusplus.com/reference/fstream/fstream/ and the changed to fit my purpose.

//#include <filesystem>

using namespace std;

class Maze {
public:


	Maze();

	void Play();//plays the game where the user navigates the stage
	bool Win_Stage();//if true player wins the game
	void Move_Up();//moving upwards
	void Move_Down();//moving downwards
	void Move_Left();//moving left
	void Move_Right();//moving right
protected:
	std::string Stage;//maze the user navigates
	int Player_position;//where the player starts on the maze, it will change after each movement
	int Win_Position;//position that is where the user must reach to win the game
	int width;// how wide the stage is, this is used to determine what positions must be swapped for moving up or down.
};
#endif

