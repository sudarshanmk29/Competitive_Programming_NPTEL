/**
 * Problem Statement:
 *  Reverse Sort: It is essentially a sorting algorithm designed to sort a list of distinct integers in ascending order. At the heart of the algorithm is the so-called reverse operation, which essentially takes a sub-array and reverses it completely.
 * The algorithm works as follows:
 * 1. Find the position of the minimum element in the list.
 * 2. Reverse the list from the first element to the position of the minimum element.
 * 3. Repeat the process for the remaining list.
 *
 * @author Sudarshan M K
 **/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

 /**
  * Function to find the minimum element in the sub array
  * arr[][in]: array of integers
  * start[in]: starting index of the sub array
  * arr_size[in]: size of the array
  * return[out]: index of the minimum element
 **/
uint32_t MIN(int32_t arr[], uint32_t start, uint32_t arr_size)
{
	int32_t min = arr[start];
	int index = 0;
	for (int j = start; j < arr_size; j++)
	{
		if (min > arr[j])
		{
			min = arr[j];
			index = j;
		}
	}
	if (index)
		return index;
	else
		return start;
}

/**
 * Function to swap the elements in the sub array
 * arr[][in]: array of integers
 * start[in]: starting index of the sub array
 * end[in]: ending index of the sub array
**/
void swap(int32_t arr[], uint32_t start, uint32_t end)
{
	arr[start] = arr[start] ^ arr[end];
	arr[end] = arr[start] ^ arr[end];
	arr[start] = arr[start] ^ arr[end];
}

/**
 * Recursive function to reverse the sub array
 * arr[][in]: array of integers
 * start[in]: starting index of the sub array
 * end[in]: ending index of the sub array
**/
void reverse(int32_t arr[], uint32_t start, uint32_t end)
{
	if (start >= end)
		return;
	else
	{
		swap(arr, start, end);
		reverse(arr, start + 1, end - 1);
	}
}

/**
 * Function to perform Reverse Sort algorithm
 * arr[][in]: array of integers
 * arr_size[in]: size of the array
**/
uint32_t reverse_sort(int32_t arr[], uint32_t arr_size)
{
	uint32_t cost = 0;
	for (int i = 0; i < arr_size - 1; i++)
	{
		uint32_t min_index = MIN(arr, i, arr_size);
		reverse(arr, i, min_index);
		cost += min_index - i + 1;
	}
	return cost;
}

int main()
{
	uint32_t test_cases = 0;
	scanf("%d", &test_cases);
	for (int i = 1; i <= test_cases; i++)
	{
	uint32_t arr_size = 0;
	scanf("%d", &arr_size);
	int32_t arr[arr_size];
	for (int j = 0; j < arr_size; j++)
	{
	 	scanf("%d", &arr[j]);
	}
	uint32_t cost = reverse_sort(arr, arr_size);
	printf("Case #%d: %d\n", i, cost);
	}
	return 0;
}