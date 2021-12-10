#include "sort.h"

/**
 * counting_sort - lgorithm to sort numbers with counting sort method
 * @array: unsorted array, minimum value 0
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr = NULL, len = (int)size, i, j, k = 0, ai = 0, zero_flag = 0;

	if (!array || len <= 1)
		return;
	for (i = 0; i < len; i++)
	{
		if (k < array[i])
			k = array[i];
		if (array[i] == 0)
			zero_flag++;
	}
	count_arr = (int *)malloc(sizeof(int) * (k + 1));
	if (count_arr == NULL)
		return;
	for (i = 0; i < k + 1; i++) /* init counting array */
		count_arr[i] = 0;
	for (i = 0; i < len; i++)
		count_arr[array[i]]++;
	printf("%d", count_arr[0]);
	for (; zero_flag > 0; zero_flag--)
		array[ai] = 0, ai++;
	for (i = 1; i < k + 1; i++)
	{
		count_arr[i] += count_arr[i - 1];
		if (i > 0)
			printf(", ");
		printf("%d", count_arr[i]);
		/* dup value changes time complexity, but it's asked */
		/* otherwise, next line would be if(count_arr[i-1]<count_arr[i]) */
		for (j = count_arr[i - 1]; j < count_arr[i]; j++)
			array[ai] = i, ai++;
	}
	printf("\n");
	if (count_arr)
		free(count_arr);
}
