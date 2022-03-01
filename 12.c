#include <stdio.h>

void sort_custom(int arr[], int n) {
	int i, j, temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int main() {
	int i, n, target, arr[100];
	printf("Enter number of elements : \n");
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}
	sort_custom(arr, n);
	printf("Array after sorting : \n");
	for (i = 0; i < n ; i++) {
		printf("%d ", arr[i]);
	}
	printf("Enter value to find : \n");
	scanf("%d", &target);

	// bs
	int low = 0;
	int high = n - 1;
	while (low <= high) {
		int mid = (low + high) / 2;
		if (arr[mid] == target) {
			printf("%d found at position : %d \n", target, mid);
			break;
		}
		else if (arr[mid] < target) {
			low = mid + 1;
		}
		else {
			high = mid -1;
		}
	}
	return -1; // if not found
}