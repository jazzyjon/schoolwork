/*
 * Name: Jonathan Tucker
 * Date Submitted: 10/21/24
 * Lab Section: 006
 * Assignment Name: Lab 5: Spell Checker Using a Hash Table
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    	return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    	return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    	return size;
}

void Stringset::insert(string word)
{
    	//Implement this function
	
	hash<string> stringHash;

	if (num_elems == size)
	{
		size *= 2;

		vector<list<string>> newTable(size);

		for (int i = 0; i < size / 2; i++)
		{
			for (auto ix = table[i].begin(); ix != table[i].end(); ix++)
			{
				int index = stringHash(*ix) % size;

				newTable[index].push_back(*ix);
			}
		}

		vector<list<string>>().swap(table);

		table = newTable;
	}

	int index = stringHash(word) % size;

	if (!find(word))
	{
		table[index].push_back(word);

		num_elems++;
	}
}

bool Stringset::find(string word) const
{
    	//Implement this function
	hash<string> stringHash;

	int checkLoc = stringHash(word) % table.size();

	list<string> tempList = table[checkLoc];

	if (tempList.size() == 0)
	{
		return false;
	}

	for (auto ix = tempList.cbegin(); ix != tempList.cend(); ix++)
	{
		if (*ix == word)
		{
			return true;
		}
	}

	return false;
}

void Stringset::remove(string word)
{
    	//Implement this function
	hash<string> stringHash;

	int index = stringHash(word) % size;

	for (auto ix = table[index].begin(); ix != table[index].end(); ix++)
	{
		if (*ix == word)
		{
			table[index].erase(ix);

			num_elems--;

			break;
		}
	}	
}
