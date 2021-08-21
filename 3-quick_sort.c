#include "sort.h"

/**
 * quick_sort - algorithm to sort numbers with quick sort method
 * @array: unsorted array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	int i, j;
	/* if declare as size_t, problems on j=size-1 for going to junk val 0*/

	if (array == NULL || size <= 1)
		return;
	i = 0, j = size - 1;
	p_tree(array, i, j, size);
}

/**
 * p_tree - generate pivot tree, print array at each time a branch is created
 * @array: unsorted array
 * @low_p: designated lower point in the array
 * @high_p: designated higher point in the array
 * @size: size of array
 */
void p_tree(int *array, int low_p, int high_p, size_t size)
{
	int party;

	if (low_p < high_p)
	{
		/* main branch of pivot tree */
		party = lomuto(array, low_p, high_p, size);
		/* left branches generated in recursion */
		p_tree(array, low_p, party - 1, size);
		/* right branches generated in recursion */
		p_tree(array, party + 1, high_p, size);
	}
}

/**
 * lomuto - Lomuto partition, sorting array and then return new array section
 * @array: unsorted array
 * @low_p: designated lower point in the array
 * @high_p: designated higher point in the array
 * @size: size of array
 * Return: next pivot, the index for splitting
 */
size_t lomuto(int *array, int low_p, int high_p, size_t size)
{
	int i, j, tmp, pivot;

	pivot = array[high_p];
	i = low_p - 1; /* can not be size_t, or case i=-1 not defined */
	for (j = low_p; j < high_p; j++)
	{
		if (array[j] <= pivot)
		{
			i++;
			tmp = array[j];
			array[j] = array[i];
			array[i] = tmp;
			if (i != j)
				print_array(array, size);
		}
	}
	i++;
	tmp = array[high_p];
	array[high_p] = array[i];
	array[i] = tmp;
	if (i != high_p)
		print_array(array, size);
	return (i);
}
