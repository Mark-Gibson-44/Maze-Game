#include "Maze.h";

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

void Maze::Move_Up() {//all movement functoins were created from scratch
	if (Stage[Player_position - width] == 'X') {//makes sure that the player cannnot move through a wall
		cout << "invalid Move" << endl;
		system("pause");
	}
	else {
		swap(Stage[Player_position], Stage[Player_position - width]);//due to Stages being in a string it swaps the characters in the string making it seem like it has moved
		Player_position = Player_position - width;//changing the value for where the player position is
	}
}
void Maze::Move_Down() {//moving down
	if (Stage[Player_position + width] == 'X') {
		cout << "invalid Move" << endl;
		system("pause");
	}
	else {
		swap(Stage[Player_position], Stage[Player_position + width]);//due to Stages being in a string it swaps the characters in the string making it seem like it has moved
		Player_position = Player_position + width;//changing position of player
	}
}
void Maze::Move_Left() {
	if (Stage[Player_position - 1] == 'X') {
		cout << "invalid Move" << endl;
		system("pause");
	}
	else {
		swap(Stage[Player_position], Stage[Player_position - 1]);
		Player_position = Player_position - 1;
	}
}
void Maze::Move_Right() {
	if (Stage[Player_position + 1] == 'X') {//prevents players moving through what is meant to be the walls of the map
		cout << "invalid Move" << endl;
		system("pause");
	}
	else {
		swap(Stage[Player_position], Stage[Player_position + 1]);// if it is a valid move swap position in the string to show the player character moving
		Player_position = Player_position + 1;//edit the player position so that they are not only allowed to move once in the game
	}
}
bool Maze::Win_Stage() {//boolean function to determine whether the game has been completed
	if (Stage[Player_position] == Stage[Win_Position]) {//sets to true if the position of the player is the end point
		return true;
	}
	else {
		return false;//if they didnt get onto the winning spot they havent won
	}
}

void Maze::Play() {//constructor that creates the Maze
	system("cls");
	cout << Stage << endl;
	while (1) {

		int i = 1;

		char key = _getch();

		int Key_Value = key;


		if (Key_Value == 's' || Key_Value == 'S') {//determines direction of movement
			Move_Down();
		}

		if (Key_Value == 'w' || Key_Value == 'W') {//determines direction of movement
			Move_Up();
		}
		if (Key_Value == 'd' || Key_Value == 'D') {//determines direction of movement
			Move_Right();
		}
		if (Key_Value == 'a' || Key_Value == 'A') {//determines direction of movement
			Move_Left();
		}

		if (Win_Stage() == true)//identifies if the player has one
		{
			system("CLS");
			cout << "Well done, You win" << endl;//congratulates them

			_getch();

			// adds 100 Points once the game has been completed
			break;
		}

		system("CLS");//clears the screen then outputs the new maze that should have changed due to some elements swapping from player movement
		cout << Stage << endl;

	}
}