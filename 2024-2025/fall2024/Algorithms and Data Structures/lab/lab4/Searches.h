/*
 * Name: Jonathan Tucker
 * Date Submitted: 10/09/24
 * Lab Section: 006
 * Assignment Name: Lab 4: Searching and Sorting
 */

#pragma once

#include <vector>

template <class T>
int linearSearch(std::vector<T> data, T target)
{
	for (int i = 0; i < data.size(); i++)
	{
		if (target == data[i])
		{
			return i;
		}
	}
	
	return -1;
}


template <class T>
int binarySearch(std::vector<T> data, T target)
{
	int high = data.size();
	int low = 0;
	int central = (high - low) / 2 + low;

	for (int i = 0; i < data.size() / 2; i++)
	{
		if (data[central] == target)
		{
			return central;
		}

		if (data[central] > target)
		{
			high = central - 1;
		}

		if (data[central] < target)
		{
			low = central + 1;
		}

		central = low + (high - low) / 2;
	}

	return -1;
}

