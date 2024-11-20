/*
 * Name: Jonathan Tucker
 * Date Submitted: 10/28/24
 * Lab Section: 006
 * Assignment Name: Lab 6: Finding the Closest Pair of Points
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    	double x;
    	double y;
};

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/
double closestPair(string filename);

/*
int main()
{
    	double min;
    	string filename;
    	cout << "File with list of points within unit square: ";
    	cin >> filename;
    	min = closestPair(filename);
    	cout << setprecision(16);
    	cout << "Distance between closest pair of points: " << min << endl;
    	return 0;
}
*/

double getMinDistance(const int g, const vector<point>& curCell, vector<point>& juxCell, double min)
{
        for (size_t i = 0; i < juxCell.size(); i++)
        {
                if (i >= g && curCell[g].x == juxCell[i].x && curCell[g].y == juxCell[i].y)
                {
                        break;
                }

                double distance = sqrt(pow(curCell[g].x - juxCell[i].x, 2) + pow(curCell[g].y - juxCell[i].y, 2));

                if (distance < min)
                {
                        min = distance;
                }
        }

        return min;
}

double closestPair(string filename)
{
	ifstream inputFile(filename);

	if (!inputFile.is_open())
	{
		return 0;
	}

	int nPoints;
	inputFile >> nPoints;

	const int nCells = static_cast<int>(std::sqrt(nPoints));

	vector<vector<vector<point>>> cellTable(nCells, vector<vector<point>>(nCells));

	for (int x = 0; x < nPoints; x++)
	{
		point p;
		inputFile >> p.y >> p.x;
		cellTable[static_cast<int>(p.y * nCells)][static_cast<int>(p.x * nCells)].push_back(p);
	}

	inputFile.close();

	double min = sqrt(2);

	for (size_t i = 0; i < nCells; i++)
	{
		for (size_t k = 0; k < nCells; k++)
		{
			vector<point>& curCell = cellTable[i][k];

			for (size_t x = 0; x < curCell.size(); x++)
			{
				min = getMinDistance(x, curCell, curCell, min);

				if (k + 1 < nCells)
				{
					min = getMinDistance(x, curCell, cellTable[i][k + 1], min);
				}

				if (i + 1 < nCells)
                                {
                                        min = getMinDistance(x, curCell, cellTable[i + 1][k], min);
                                }

				if (i + 1 < nCells && k + 1 < nCells)
                                {
                                        min = getMinDistance(x, curCell, cellTable[i + 1][k + 1], min);
                                }

				if (i + 1 < nCells && k > 0)
                                {
                                        min = getMinDistance(x, curCell, cellTable[i + 1][k - 1], min);
                                }
			}
		}
	}

	return min;
}


