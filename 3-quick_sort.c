#include "sort.h"

/**
 * quick_sort - algorithm to sort numbers with quick sort method
 * @array: unsorted array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	size_t i, j;

	if (array == NULL || size <= 1)
		return;
	i = 0, j = size - 1;
	p_tree(array, i, j, size);
}

/**
 * p_tree - generate pivot tree, print array at each time a branch is created
 */
void p_tree(int *array, size_t low_p, size_t high_p, size_t size)
{
	size_t party;

	if (low_p < high_p)
	{
		/* main branch of pivot tree */
		party = lomuto(array, low_p, high_p, size);
		/* left branches generated in recursion */
		p_tree(array, low_p, party - 1, size);
		print_array(array, size);
		/* right branches generated in recursion */
		p_tree(array, party + 1, high_p, size);
		print_array(array, size);
	}
}

/**
 * lomuto - Lomuto partition, sorting array and then return new array section
 * @array: unsorted array
 * @low_p: designated lower point in the array
 * @high_p: designated higher point in the array
 * @size: size of array
 */
size_t lomuto(int *array, size_t low_p, size_t high_p, size_t size)
{
	size_t i, j;
	int tmp, pivot;

	pivot = array[high_p];
	i = low_p;
	for (j = low_p; j < high_p; j++)
	{
		if (array[j] <= pivot)
		{
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			i++;
		}
	}
	tmp = array[high_p];
	array[high_p] = array[i];
	array[i] = tmp;
	(void)size;
	return (i);
}
