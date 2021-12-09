#include "sort.h"

int main(void)
{
        int len = 20;
	int i, left = 0, right = len - 1;
	int temp, arr[] = {79, 47, 68, 87, 84, 91, 21, 32, 34, 2, 95, 31, 20, 22, 98, 39, 92, 41, 62, 1};
	while (left < right) {
		for (i = left; i < right; i++)
			if (arr[i] > arr[i + 1]) {
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				print_array(arr, len);
			}
		right--;
		for (i = right; i > left; i--)
			if (arr[i - 1] > arr[i]) {
				temp = arr[i];
				arr[i] = arr[i - 1];
				arr[i - 1] = temp;
				print_array(arr, len);
			}
		left++;
	}
        print_array(arr, len);
        return (0);
}