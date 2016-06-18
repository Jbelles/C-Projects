#include <iostream>
using namespace std;

// main() is where program execution begins.


void isMagic(int size, int a[4][4]) 
{
	int total = 0;
	int limit = (size* ((size*size) + 1)) / 2;
	int currLoc = 0;

	int dupes[8];
	for (int i = 0; i < sizeof(dupes) / sizeof(*dupes); i++)
		dupes[i] = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			if (dupes[a[i][j]] != 0) {
				cout << "The grid has duplicate numbers, please try again" << endl;
				return;
			}
			else
				dupes[a[i][j]] = a[i][j];	
		}
	}
	//Check all vertical/horizontal directions
	for (int currLoc = 0; currLoc < size; currLoc++) { 
		for (int i = 0; i < size; i++) {//vertical
			total += a[currLoc][i];
			cout << a[currLoc][i];
		}
		if (total != limit) return;
		total = 0;
		cout << endl;
		for (int j = 0; j < size; j++) {//horizontal
			total += a[j][currLoc];
			cout << a[j][currLoc];
		}
		if (total != limit) return;
		total = 0;
		cout << endl;
			
	}

	for (int k = 0; k < size; k++) {//check increasing diagonal
		total += a[k][k];
		cout << a[k][k];
	}
	if (total != limit) return;
	total = 0;
	cout << endl;

	for (int l = 0; l < size; l++) {//check decreasing diagonal
		total += a[size - (1 + 1)][l];
		cout << a[size - (l + 1)][l];
	}
	if (total != limit) return;
	total = 0;
	cout << endl;

	cout << "This is a magic square!" << endl;

}

int main()
{
	int grid[4][4];//predefined size
	//test cases

	//= { { 8, 1, 6 },
	//{ 3, 5, 7 },
	//{ 4, 9, 2 } };

	//{{14, 1, 12, 7},
	//{11, 8, 13, 2},
	//{5, 10, 3, 16},
	//{4, 15, 6, 9}};

	int num = 0;

	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			cout << "Please enter a 4x4 grid in order" << endl;
			cin >> num;
			while (!cin) // or if(cin.fail())
			{// user didn't input a number
				cout << "Please enter an integer value." << endl;
				cin.clear(); // reset failbit
				cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //skip bad input
				cin >> num;
			}	
			grid[i][j] = num;
		}
	}
	isMagic(4, grid);
	return 0;
}