#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * bubble_sort - this function sort the integer
 * in desending order
 * @array: Array of unsorted integers
 * @size: maximum size
 * Return: nothing
 */
void bubble_sort(int *array, size_t size)
{
	int i, j, temp;
	int res = size;
	int check_swap = 0;

	if (array == NULL || size < 2)
		return;
	for (j = 0; j < res; j++)
	{
		for (i = 0; i < res - 1 - j; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				check_swap = 1;
			}
		}
		if (check_swap == 0)
			break;
	}
}
