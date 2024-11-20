/*
 * Name: Jonathan Tucker
 * Date Submitted: 10/09/24
 * Lab Section: 006
 * Assignment Name: Lab 4: Searching and Sorting
 */

#pragma once

#include <vector>
#include <cstdlib>

template <class T>
std::vector<T> merge(std::vector<T> left, std::vector<T> right)
{
	std::vector<T> result;
	int i = 0;
	int k = 0;

	while (i < left.size() && k < right.size())
	{
		if (left[i] < right[k])
		{
			result.push_back(left[i]);
			i++;
		}
		else
		{
			result.push_back(right[k]);
			k++;
		}
	}

	while (i < left.size())
	{
		result.push_back(left[i]);
		i++;
	}

	while (k < right.size())
	{
		result.push_back(right[k]);
		k++;
	}

	return result;
}
	
template <class T>
std::vector<T> mergeSort(std::vector<T> lst)
{
	if (lst.size() <= 1)
	{
		return lst;
	}

	int central = lst.size() / 2;

	std::vector<T> left, right;

	for (int i = 0; i < central; i++)
	{
		left.push_back(lst[i]);
	}

	for (int i = central; i < lst.size(); i++)
	{
		right.push_back(lst[i]);
	}

	left = mergeSort(left);
	right = mergeSort(right);

	return merge(left, right);
}

template <class T>
std::vector<T> quickSortPivot(std::vector<T> lst, int right, int left)
{
	if (left < right)
	{
		int pIndex = rand() % (right - left + 1) + left;
		T pValue = lst[pIndex];

		std::swap(lst[pIndex], lst[right]);

		int storeIndex = left;

		for (int x = left; x < right; x++)
		{
			if (lst[x] < pValue)
			{
				std::swap(lst[x]. lst[storeIndex]);
				storeIndex++;
			}
		}

		std::swap(lst[storeIndex], lst[right]);

		quickSortPivot(lst, left, storeIndex - 1);
		quickSortPivot(lst, storeIndex + 1, right);
	}
}


template <class T>
std::vector<T> quickSort(std::vector<T> lst)
{
	quickSortPivot(lst, 0, lst.size() - 1);
	return lst;
}

