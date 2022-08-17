#include "sort.h"
/**
 * selection_sort - sorts an array of integers
 * @array: array of integers
 * @size: size of array
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
	int i;
	int j;
	int siz = size;
	int min, temp;


	for (i = 0; i < siz; i++)
	{
		min = i;
		for (j = i + 1; j < siz; j++)
		{
			if (array[j] < array[min])
				min = j;
		}
		if (min != i)
		{
			temp = array[min];
			array[min] = array[i];
			array[i] = temp;
			print_array(array, size);
		}
	}
}
