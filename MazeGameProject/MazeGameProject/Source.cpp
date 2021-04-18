#include <iostream>

#include <conio.h>//used to read in key movements obtained from https://www.youtube.com/watch?v=v3MiuCVTMvE  using the _getch() function
#include "Functions.h"//all functions used in the program
//#include "Maze.h"

#include "Game.h"

#ifdef __unix__         

#define clear "clear"

#elif defined(_WIN32) || defined(WIN32) 

#define clear "cls"

#endif


//any use of system functions was done from seeing various instances of people using it


int main()
{
	/*Maze r(8, 8);
	for (int i = 0; i < r.getHeight(); i++)
	{
		for (int j = 0; j < r.getWidth(); j++)
		{
			std::cout << pieces[r.model_board[i][j]];//r.at(i, j);
		}
		std::cout << std::endl;
	}*/

	Maze r(5, 5);
	
	Maze m("../MazeGameProject/Maze1.txt");
	
	Game g(m);
	
}

