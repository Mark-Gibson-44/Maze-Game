#include "Maze.h";



bool Maze::inBounds(const coord& c)
{
	return (c.x < width && c.x > -1) && (c.y < height && c.y > -1);
}
std::map<std::pair<int, int>, int> visited;
bool Maze::valid_maze(coord start)
{
	if (visited[std::make_pair(start.x, start.y)] == 1)
		return false;
	visited[std::make_pair(start.x, start.y)]++;
	if (start.x < 0 || start.x > width - 1 || start.y < 0 || start.y > height - 1)
		return false;
	if (start.x == Exit.x && start.y == Exit.y)
		return true;
	if (board[start.x][start.y] == 'X')
		return false;

	return valid_maze(start + moves[movement::up]) || valid_maze(start + moves[movement::down]) || valid_maze(start + moves[movement::left]) || valid_maze(start + moves[movement::right]);
}

Maze::Maze(const char* file){
	std::fstream f;

	f.open(file);
	if (!f.is_open())
	{
		std::cout << "Invalid File, exiting";
		return;
	}
	char buff;
	while (f.get(buff))
	{
		std::vector<char> line;
		if (buff == '\n')
		{
			this->board.emplace_back(line);
			this->width = line.size();
		}
		if (buff == '0')
		{
			this->Exit.x = line.size() - 1;
			this->Exit.y = board.size() - 1;

		}
		line.emplace_back(buff);
	}
	this->height = board.size();

}

Maze::Maze(int h, int w)
{
	height = h;
	width = w;
	//generate random maze
	std::cout << "Generating Random Maze" << std::endl;
	this->GenRandom(h, w);
	coord test = { rand() % h-1, rand() % w-1 };
	this->Exit = coord{ rand() % h, rand() % w };
	/*while (!this->valid_maze(test))
	{
		std::cout << "Invalid Maze regenerating Maze" << std::endl;
		this->board.clear();
		this->GenRandom(h, w);
	}*/
	board[test.x][test.y] = '0';
	model_board[test.x][test.y] = entity::player;
	board[Exit.x][Exit.y] = '+';
	model_board[Exit.x][Exit.y] = entity::exit;
	std::string res = (this->valid_maze(test)) ? "Valid" : "invalid";
	std::cout << res << std::endl;
	this->begin = test;
}

/*
Maze::Maze() {
	char Maze_Selection;

	ifstream Maze1;//file stream for the mazes. Formatting was obtained from http://www.cplusplus.com/reference/fstream/ifstream/ then adapted to suit the maze format
	string Maze1_Segment[7];
	string Maze2_Segment[7];
	string Maze3_Segment[10];
	int i = 0;
	ifstream Maze2;
	ifstream Maze3;

	cout << "What maze is should be played, 1, 2, or 3?" << endl;//gives users the option of which maze to select
	try {
		cin >> Maze_Selection;
		//Maze_Selection = _getch();//user inputs character responding to maze
		if (Maze_Selection != '1' && Maze_Selection != '2' && Maze_Selection != '3' && Maze_Selection != '4')//if the key is not one of the options throws an exception,
			throw Maze_Selection;
	}

	catch (char Maze_Selection)
	{
		cout << "Invalid choice" << endl;//takes invalid arguments as exceptions and sets the stage to the default.
		system("pause");
	}

	switch (Maze_Selection) {//switch statement to go through each option
	case '1': {
		Maze1.open("Maze1.txt");
		if (Maze1.is_open() != true) {//if the file does not open
			cout << "canot find file" << endl;
			Stage = "XXXXXXXXXX\nXOXX XXX X\nX     X  X\nXXX XXX XX\nX    X   X\nX       #X\nXXXXXXXXXX";
			Player_position = 12;
			Win_Position = 63;
			width = 11;
			break;

		}
		else {
			width = 51;//relevant values for Maze1
			Player_position = 55;
			Win_Position = 299;
			while (Maze1.eof() != true) {//whilst the file is open
				getline(Maze1, Maze1_Segment[i]);//get the first line of the string and put it into the first index of a string array
				Maze1_Segment[i] = Maze1_Segment[i] + "\n";//add a \n to the array so that it is consistent with the other mazes
				Stage = Stage + Maze1_Segment[i];//add that string to the overall stage string meaning once finished the entire maze will be contructed
				i++;// do for all lines in the file

			}




		}

		break;
	}
	case '2': {	Maze2.open("Maze2.txt");
		if (Maze2.is_open()) {

			while (Maze2.eof() != true) {//whilst the file is open
				getline(Maze2, Maze2_Segment[i]);//get the first line of the string and put it into the first index of a string array
				Maze2_Segment[i] = Maze2_Segment[i] + "\n"; //add \n for maze format consistency

				Stage = Stage + Maze2_Segment[i];//add the segment to the overall stage creating the full stage
				i++;//do for all lines in the file
			}
			Win_Position = 75;
			width = 26;
			Player_position = 105;
		}
		else {
			cout << "canot find file" << endl;//if the maze cannot be found they use the default maze
			Stage = "XXXXXXXXXX\nXOXX XXX X\nX     X  X\nXXX XXX XX\nX    X   X\nX       #X\nXXXXXXXXXX";
			Player_position = 12;//data for the default maze
			Win_Position = 63;
			width = 11;
		} break; }
	case '3': { Maze3.open("Maze3.txt");
		if (Maze3.is_open()) {

			while (Maze3.eof() != true) {
				getline(Maze3, Maze3_Segment[i]);
				Maze3_Segment[i] = Maze3_Segment[i] + "\n";
				Stage = Stage + Maze3_Segment[i];
				i++;
			}
			width = 9;
			Player_position = 10;
			Win_Position = 78;

		}
		else {
			cout << "canot find file" << endl;//if the maze cannot be found they use the default maze
			Stage = "XXXXXXXXXX\nXOXX XXX X\nX     X  X\nXXX XXX XX\nX    X   X\nX       #X\nXXXXXXXXXX";
			Player_position = 12;
			Win_Position = 63;
			width = 11;
			break;

		}
		break;
	}
	default://if the key input is not one which corresponds to an option give the player the default maze
		Player_position = 12;
		Win_Position = 63;
		width = 11;
		Stage = "XXXXXXXXXX\nXOXX XXX X\nX     X  X\nXXX XXX XX\nX    X   X\nX       #X\nXXXXXXXXXX";
		break;

	}




}
*/
coord Maze::getStart() noexcept
{
	return this->begin;
}

bool Maze::complete(const coord& player)
{
	return player.x == this->Exit.x && player.y == this->Exit.y;
}

void Maze::GenRandom(int h, int w)
{
	for (int i = 0; i < h; i++)
	{
		std::vector<char> line;
		std::vector<entity> temp;
		for (int j = 0; j < w; j++)
		{
			if (i == 0 || i == h - 1)
			{
				line.emplace_back('X');
				temp.emplace_back(entity::wall);
			}
			else if (j == 0 || j == w - 1)
			{
				line.emplace_back('X');
				temp.emplace_back(entity::wall);
			}
			else {
				line.emplace_back((rand() % 3) ? ' ' : 'X');
				temp.emplace_back((rand() % 3) ? entity::empty : entity::wall);
			}
			
		}
		
		this->board.push_back(line);
		this->model_board.push_back(temp);
		
	}
	
}

int Maze::getWidth()
{
	return this->width;
}

int Maze::getHeight()
{
	return this->height;
}

char Maze::at(int x, int y)
{
	return board[x][y];
}

entity& Maze::operator[](coord c)
{
	return this->model_board[c.x][c.y];
}

void Maze::setStart(coord c)
{
	this->model_board[begin.x][begin.y] = entity::empty;
	begin = c;
	this->model_board[begin.x][begin.y] = entity::player;
}





