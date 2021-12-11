#include "sort.h"

/**
 * recur_bitonic - recursive function for bitonic element swap
 * @arr: array to be sorted
 * @len: size of array
 * @lowi: start of the index in the main array
 * @seglen: size of the array segments
 * @flag: array seg merging direction flag, 1 for ascending, 0 for descending
 */
void recur_bitonic(int *arr, int len, int lowi, int seglen, int flag)
{
	int i, halfseg = seglen / 2, tmp;

	if (seglen < 2)
		return;
	for (i = lowi; i < lowi + halfseg; i++)
	{
		if ((flag && arr[i] > arr[i + halfseg]) ||
		    (flag == 0 && arr[i] < arr[i + halfseg]))
			tmp = arr[i], arr[i] = arr[i + halfseg], arr[i + halfseg] = tmp;
	}
	recur_bitonic(arr, len, lowi, halfseg, flag);
	recur_bitonic(arr, len, lowi + halfseg, halfseg, flag);
}

/**
 * seg_merge - recursive function to merge array segments and print
 * @arr: array to be sorted
 * @len: size of array
 * @lowi: start of the index in the main array
 * @seglen: size of the array segments
 * @flag: array seg merging direction flag, 1 for ascending, 0 for descending
 */
void seg_merge(int *arr, int len, int lowi, int seglen, int flag)
{
	int halfseg = seglen / 2;

	if (seglen < 2)
		return;
	printf("Merging [%d/%d]", seglen, len);
	if (flag)
		printf(" (UP):\n");
	else
		printf(" (DOWN):\n");
	print_array(arr + lowi, seglen);
	seg_merge(arr, len, lowi, halfseg, 1);
	seg_merge(arr, len, lowi + halfseg, halfseg, 0);
	recur_bitonic(arr, len, lowi, seglen, flag);
	printf("Result [%d/%d]", seglen, len);
	if (flag)
		printf(" (UP):\n");
	else
		printf(" (DOWN):\n");
	print_array(arr + lowi, seglen);
}

/**
 * bitonic_sort - algorithm to sort numbers with bitonic sort method
 * @array: unsorted array
 * @size: size of array, will be equal to 2^k, where k >= 0
 */
void bitonic_sort(int *array, size_t size)
{
	int len = (int)size;

	if (!array || len <= 1)
		return;
	/* recursive method, not exactly time complexity of O(log(n)) */
	seg_merge(array, len, 0, len, 1);
}
