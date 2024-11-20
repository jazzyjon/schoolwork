/*
 * Name: Jonathan Tucker
 * Date Submitted: 10/01/24
 * Lab Section: 006
 * Assignment Name: Lab 3 - Finding Groups Using Recursion
 */

#include "Grouping.h"

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Implement the (parameterized) constructor and findGroup functions below

Grouping::Grouping(string fileN)
{
	fstream file(fileN);
	string line;
	int r = 0;

	while (getline(file, line))
	{
		for (unsigned i = 0; i < line.length(); i++)
		{
			if (line[i] == 'X')
			{
				grid[r][i] = 1;
			}
			else
			{
				grid[r][i] = 0;
			}
		}

		cout << endl;
		r++;
	}

	for (int i = 0; i < 10; i++)
	{
		for (int x = 0; x < 10; x++)
		{
			if (grid[i][x] == 1)
			{
				vector <GridSquare> newG;
				findGroup(i, x, newG);
				groups.push_back(newG);
			}
		}
	}

	printGroups();
}

void Grouping::findGroup(int r, int c, vector<GridSquare> &newG)
{
	newG.push_back(GridSquare(r, c));
	grid[r][c] = 0;
	
	if (grid[r + 1][c] == 1 && (r + 1) < 10)
	{
		findGroup(r + 1, c, newG);
	}

	if (grid[r - 1][c] == 1 && (r - 1) >= 0)
	{
		findGroup(r - 1, c, newG);
	}

	if (grid[r][c + 1] == 1 && (c + 1) < 10)
	{
		findGroup(r, c + 1, newG);
	}

	if (grid[r][c - 1] == 1 && (c - 1) >= 0)
	{
		findGroup(r, c - 1, newG);
	}
}



//Simple main function to test Grouping
//Be sure to comment out main() before submitting
/* 
int main()
{
    	Grouping input1("input1.txt");
    	input1.printGroups();
    
    	return 0;
}
*/
//Do not modify anything below

GridSquare::GridSquare() : row(0), col(0) {} //Default constructor, (0,0) square

GridSquare::GridSquare(int r, int c) : row(r), col(c) {} //(r,c) square

//Compare with == operator, used in test cases
bool GridSquare::operator== (const GridSquare r) const
{
    	if ((row == r.row) && (col == r.col))
    	{
        	return true;
    	}
    	return false;
}

int GridSquare::getRow() //return row value
{
    	return row;
}

int GridSquare::getCol() //return column value
{
    	return col;
}

//Output using << operator, used in Grouping::printGroups()
//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    	os << "(" << obj.row << "," << obj.col << ")";
    	return os;
}

Grouping::Grouping() : grid{},groups() {} //Default constructor, no groups

void Grouping::printGroups() //Displays grid's groups of squares
{
    	for(int g=0; g<groups.size(); g++)
    	{
        	cout << "Group " << g+1 << ": ";
        	for(int s=0; s<groups[g].size(); s++)
        	{
            		cout << " " << groups[g][s];
        	}
        	cout << endl;
    	}
}

vector<vector<GridSquare>> Grouping::getGroups() //Needed in unit tests
{
    	return groups;
}
