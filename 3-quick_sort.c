#include "sort.h"
/**
 * swap - swaps values between indices
 * @a: first object
 * @array: array of unsorted integers
 * @size: size of the intgers
 * @b: second object
 * Return: void
 */
void swap(int *array, int *a, int *b, size_t size)
{
	int t;

	t = *a;
	*a = *b;
	*b = t;
	print_array(array, size);
}

/**
 * partition - implementation of lomuto partition scheme in quick sort
 * @lower_bound: first index of the array
 * @size: size of the inegers
 * @upper_bound: last index of the array
 * @array: array of unsorted integers
 * Return: returns the index of the pivot
 */
int partition(int *array, int lower_bound, int upper_bound, size_t size)
{
	int j, pivot; /* used to traverse the array*/
	int i = lower_bound - 1; /* needed for swapping purposes*/

	pivot = array[upper_bound];
	for (j = lower_bound; j <= upper_bound - 1; j++)
	{
		if (array[j] < pivot)
		{
			i++;
			if (i != j && array[i] != array[j])
				swap(array, &array[j], &array[i], size);
		}
	}
	if (i + 1 != upper_bound && array[i + 1] != array[upper_bound])
		swap(array, &array[i + 1], &array[upper_bound], size);
	return (i + 1);
}

/**
 * recursive_call - performs recursion(necessary for partition of
 * sub-array which may be produced after the partition of the main array
 * @lower_bound: first index of the array
 * @array: the array of unsorted integers
 * @size: size of the array
 * @upper_bound: the last index of the array
 * Return: nothing
 */
void recursive_call(int *array, int lower_bound, int upper_bound, size_t size)
{
	int p_index; /* index of pivot*/

	if (lower_bound < upper_bound)
	{
		p_index = partition(array, lower_bound, upper_bound, size);
		recursive_call(array, lower_bound, p_index - 1, size);
		recursive_call(array, p_index + 1, upper_bound, size);
	}
}

/**
 * quick_sort - sorts integers in ascending order
 * @array: array of integers
 * @size: size of integers
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int upper = size - 1;

	if (array == NULL || size <= 1)
		return;
	recursive_call(array, 0, upper, size);
}
