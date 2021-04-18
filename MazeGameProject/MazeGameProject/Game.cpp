#include "Game.h"

Game::Game(Maze m) : board(m)
{
	start = board.getStart();
	games_played = 0;
	Points = 0;
	/*std::cout << "Select a Maze to navigate\n";
	std::cout << "1: Maze 1\n";
	std::cout << "2: Maze 2\n";
	std::cout << "3: Maze 3\n";
	std::cout << "4: Generate Random Maze\n";
	*/
	
	/*start = m.getStart();
	while (!m.complete(start))
	{
		//play game.
	}*/
	std::cout << menu;

	int option;
	//option = std::cin.get();
	play();
	/*
	switch (option)
	{
		case 1:
			
			play(); break;
		case 2: 
			std::cout << this->Points << std::endl; break;
		case 3:
			std::cout << this->games_played << std::endl; break;
		case 4:
			break;

		
	}
	*/
}

bool Game::validMove(coord m)
{
	
	return this->board[(m)] != entity::wall;//start + moves[m];
}

void Game::play()
{
	while (!board.complete(start))
	{
		print_board();
		int selected_move;
		selected_move = cin.get();
		auto move = moves[movement(selected_move - 48)];
		if (validMove(start + move))
			start = start + move;
		
		board.setStart(start);
	}
}

void Game::print_board()
{
	for (int a = 0; a < board.getHeight(); a++)
	{
		for (int b = 0; b < board.getWidth(); b++)
		{
			std::cout << pieces[board.model_board[a][b]];
		}
		std::cout << std::endl;
	}
}
