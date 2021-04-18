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
	std::vector<char> line;
	std::vector<entity> temp;
	height = 0;
	while (f.get(buff))
	{
		
		
		if (buff == '\n')
		{

			this->board.emplace_back(line);
			
			this->model_board.push_back(temp);
			this->width = line.size() - 1;
			line.clear();
			temp.clear();
			height++;
		}
		else if (buff == '0')
		{
			this->begin.x = line.size() - 1;
			this->begin.y = height;
			temp.emplace_back(entity::player);
		}
		else if (buff == '+')
		{
			
			this->Exit.x = line.size() - 1;
			this->Exit.y = height;  
			temp.emplace_back(entity::exit);
		}
		else {
			
			temp.emplace_back(buff == 'X' ? entity::wall : entity::empty);
		}
		line.emplace_back(buff);
		
		//this->height = temp.size() - 1;

	}
	this->model_board.push_back(temp);
	height++;

	
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





