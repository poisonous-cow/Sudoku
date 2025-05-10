#include <iostream>
#include <string>
//Sudoku Puzzle
using namespace std;

//The grid is declared globally as a two-dimensional array
const int Y_LIM = 9, X_LIM = 9;
int grid[Y_LIM][X_LIM];

//-----INSERT FUNCTION-------
void grid_insert(int y, int x, int value) {
	grid[y][x] = value;
}

void grid_init() {
	//-----SET ALL VAULES TO 0--------
	for (int y = 0; y < Y_LIM; y++) {
		for (int x = 0; x < X_LIM; x++) {
			grid[y][x] = 0;
		}
	}
	//----INSERT STARTING NUMBERS------
	grid_insert(0, 2, 1);
	grid_insert(0, 4, 6);
	grid_insert(0, 8, 3);
	grid_insert(1, 1, 4);
	grid_insert(1, 4, 2);
	grid_insert(1, 6, 7);
	grid_insert(1, 8, 9);
	grid_insert(2, 1, 2);
	grid_insert(2, 4, 7);
	grid_insert(2, 5, 4);
	grid_insert(3, 5, 7);
	grid_insert(3, 6, 6);
	grid_insert(3, 7, 2);
	grid_insert(4, 4, 1);
	grid_insert(5, 1, 1);
	grid_insert(5, 2, 3);
	grid_insert(5, 3, 2);
	grid_insert(6, 3, 4);
	grid_insert(6, 4, 3);
	grid_insert(6, 7, 8);
	grid_insert(7, 0, 6);
	grid_insert(7, 2, 4);
	grid_insert(7, 4, 8);
	grid_insert(7, 7, 1);
	grid_insert(8, 0, 2);
	grid_insert(8, 4, 5);
	grid_insert(8, 6, 3);
}

void grid_print() {
	int xspace = 0, yspace = 1;
	cout << " "; //Aligns the first row with the others
	//Print X Coordinates
	for (int x = 0; x < X_LIM; x++, xspace++) {
		if (xspace == 3) {
			cout << " ";
			xspace = 0;
		}
		cout << x << " ";
	}
	//Label Coordinates
	cout << "X";
	cout << endl << "                       Y\n";
	for (int y = 0; y < Y_LIM; y++, yspace++) {
		//yspace and xspace are incremented along with y and x
		for (int x = 0; x < X_LIM; x++, xspace++) {
			if (xspace == 3) {
				cout << " ";
				xspace = 0;
			}
			cout << grid[y][x] << " ";
		}
		cout << "  " << y << endl; //Print Y Coordinates
		if (yspace == 3) {
			cout << endl;
			yspace = 0;
		}
	}
}

int main() {
	int select;
	grid_init(); //Call grid_init immediately
	while (true) {
		grid_print(); //Call grid_print to display graph
		//Conditional Loop allows our menu to be re-usable
		cout << "What action would you like to do?\n";
		cout << "1: Place a Number \n2: Remove a Number \n3: Restart the Game \n4: Exit\n";
		cin >> select;
		while (select < 1 or select > 4) {
			cout << "That's not a valid answer!\n";
			cout << "1: Place a Number \n2: Remove a Number \n3: Restart the Game \n4: Exit\n";
			cin >> select;
		}
		//-----MAIN MENU-------
		switch (select) {
		case 1: {
			int x, y, submission;
			//-----INPUTS AND VALIDATION------
			cout << "Which number do you want to enter?\n";
			cin >> submission;
			while (submission < 1 or submission > 9) {
				cout << "That's not a valid submission! \nEnter a value between 1 and 9!\n";
				cin >> submission;
			}
			cout << "Enter the X and Y coordinates of your value, separated by a space\n";
			cin >> x >> y;
			while ((x < 0 or x > X_LIM) or (y < 0 or y > Y_LIM)) {
				//This validation loop actually splits the long condition into two conditions
				if (x < 0 or x > X_LIM) {
					cout << "Your X Coordinate is out of range! \nEnter a value between 0 and " << X_LIM << endl;
					cin >> x;
				}
				if (y < 0 or y > Y_LIM) {
					cout << "Your Y Coordinate is out of range! \nEnter a value between 0 and " << Y_LIM << endl;
					cin >> y;
				}
			}
			//----INSERTING THE VALUES-------
			//Insert the values by simply plugging them into function grid_insert()
			grid_insert(y, x, submission);
			break;
		}
		case 2: {
			int x, y;
			cout << "Enter the X and Y coordinates of your value, separated by a space\n";
			cin >> x >> y;
			while ((x < 0 or x > X_LIM) or (y < 0 or y > Y_LIM)) {
				//This validation loop actually splits the long condition into two conditions
				if (x < 0 or x > X_LIM) {
					cout << "Your X Coordinate is out of range! \nEnter a value between 0 and " << X_LIM << endl;
					cin >> x;
				}
				if (y < 0 or y > Y_LIM) {
					cout << "Your Y Coordinate is out of range! \nEnter a value between 0 and " << Y_LIM << endl;
					cin >> y;
				}
			}
			//---Removing Values-------
			//Remove values by simply inserting 0 into your desired position
			grid_insert(y, x, 0);
			break;
		}
		case 3: {
			grid_init();
			break;
		}
		case 4: {
			return 0;
		}
		}
		cout << "\033[2J\033[0;0H"; //Restarts the game
	}
	return 0;
}
