#include <iostream>

#include <conio.h>//used to read in key movements obtained from https://www.youtube.com/watch?v=v3MiuCVTMvE  using the _getch() function
#include "Functions.h"//all functions used in the program
#include "Maze.h"
//any use of system functions was done from seeing various instances of people using it
using namespace std;

int main() {

	cout << "Welcome" << endl;//welcome message
	int Games_Played = 0, Points = 0;//sets score and number of games played to 0
	while (1) {//constantly goes in a loop for users
		//the menu system mimics one that was present in an earlier programming practical.
		cout << "Select and option" << endl << "1)Start Game" << endl << "2) check scores" << endl << "3) Rules" << endl << "4) Exit" << endl;//menu displaying all options available
		try {
			char options = _getch();// uses the key input of the user to select menu option _getch function obtained from https://www.youtube.com/watch?v=v3MiuCVTMvE although never using the direction key buttons
			if ((options != '1') && (options != '2') && (options != '3') && (options != '4'))//exception handling so that if it is not one of the options throw an exception
				throw options;
			if (options == '1') {
				Games_Played++;
				Points = Points + 100;//increases the numbers of games played
				Maze stage;//constructor for the maze asking user for maze choice
				stage.Play();//playing the maze


			}



			if (options == '2') {
				system("cls");//clears screen then displays the score of the user
				Scores(Games_Played, Points);//takes number of points and number of games played. If user has not played any games doesnt display a score
				system("pause");
			}
			if (options == '3') {
				system("cls");
				Rules();//outputs the rules from the function
			}
			if (options == '4') {
				break;//exits the menu
			}
		}
		catch (char options) {//catching the exception from menu options
			system("cls");
			cout << "Invalid input: Select an option from the available" << endl;//tells the users they must input a valid optoin
			system("pause");
		}
		system("cls");//clears the screen so that it does not output the menu again below the earlier output
	}
	system("pause");//keeps the debugger open


}
