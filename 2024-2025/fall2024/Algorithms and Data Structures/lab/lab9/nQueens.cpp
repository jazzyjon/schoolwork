/*
 * Name: Jonathan Tucker
 * Date Submitted: 11/18/24
 * Lab Section: 006
 * Assignment Name: Lab 9: Using Recursion to Solve the N-Queens Problem
 */

#include <iostream>
#include <vector>

using namespace std;

//Determines whether a queen can be placed at a given row and column 
//on the chessboard without conflicting with previously placed queens.
bool queenPotential(const vector<int>& setQueens, int r, int c)
{
	for (int i = 0; i < c; i++)
	{
		if (setQueens[i] == r || abs(setQueens[i] - r) == abs(i - c))
		{
			return false;
		}
	}

	return true;
}

//Recursively calculates all possible solutions 
//for placing n queens on an n x n chessboard.
void potentialSolutions(vector<int>& setQueens, int c, int& result, int n)
{
	if (c == n)
	{
		result++;
		return;
	}

	for (int r = 0; r < n; r++)
	{
		if (queenPotential(setQueens, r, c))
		{
			setQueens[c] = r;
			potentialSolutions(setQueens, c + 1, result, n);
		}
	}
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    	//Implement int nQueens(int n)
    	//Feel free to implement any recursive helper functions
	
	vector<int> setQueens(n, -1);
	int amount = 0;

	potentialSolutions(setQueens, 0, amount, n);

	return amount;
}

/*
int main()
{
    	cout << "1: " << nQueens(1) << endl;
    	cout << "2: " << nQueens(2) << endl;
    	cout << "3: " << nQueens(3) << endl;
    	cout << "4: " << nQueens(4) << endl;
    	cout << "5: " << nQueens(5) << endl;
    	cout << "6: " << nQueens(6) << endl;
    	cout << "7: " << nQueens(7) << endl;
    	cout << "8: " << nQueens(8) << endl;
    	cout << "9: " << nQueens(9) << endl;
   	cout << "10: " << nQueens(10) << endl;
    	cout << "11: " << nQueens(11) << endl;
    	cout << "12: " << nQueens(12) << endl;
    	return 0;
}
*/
