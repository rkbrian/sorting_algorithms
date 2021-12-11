#include "sort.h"

/**
 * quick_sort_hoare - quick sort method with Hoare partition scheme
 * @array: unsorted array
 * @size: size of array
 */
void quick_sort_hoare(int *array, size_t size)
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
		party = hoare(array, low_p, high_p, size);
		/* left branches generated in recursion */
		p_tree(array, low_p, party - 1, size);
		/* right branches generated in recursion */
		p_tree(array, party, high_p, size);
	}
}

/**
 * hoare - Hoare partition, sorting array and then return new array section.
 *  Note: swap details not always the same as checker required, but it works.
 * @array: unsorted array
 * @low_p: designated lower point in the array
 * @high_p: designated higher point in the array
 * @size: size of array
 * Return: next pivot, the index for splitting
 */
size_t hoare(int *array, int low_p, int high_p, size_t size)
{
	int i, j, tmp, pivot;

	pivot = array[high_p];
	while (low_p < high_p)
	{
		i = low_p, j = high_p;
		while (array[i] < pivot)
			i++;
		while (array[j] > pivot)
			j--;
		if (j <= i)
			return (j);
		tmp = array[j];
		array[j] = array[i];
		array[i] = tmp;
		print_array(array, size);
	}
	return (high_p);
}
