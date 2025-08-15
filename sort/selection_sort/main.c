#include <stdio.h>

// Sort the integer array in increasing order
void selection_sort(int *, int);
void print(int *, int);
void swap(int *, int *);

int main() {
  int arr[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  int size_of_arr = sizeof(arr) / sizeof(arr[0]);

  /*
   * Before sorting 10 9 8 7 6 5 4 3 2 1
   */
  print(arr, size_of_arr);

  selection_sort(arr, size_of_arr);

  /*
   * After sorting 1 2 3 4 5 6 7 8 9 10
   */
  print(arr, size_of_arr);
  return 0;
}

void selection_sort(int *arr, int size_of_arr) {
  if (arr == NULL || size_of_arr <= 0) {
    printf("Error: Invalid array or size\n");
    return;
  }
  int i, j, min_index;
  for (i = 0; i < size_of_arr - 2; i++) {
    min_index = i;
    j = i + 1;
    while (j < size_of_arr) {
      if (arr[j] < arr[min_index])
        min_index = j;
      j++;
    }
    swap(&arr[i], &arr[min_index]);
  }
}

// Function to print the array
void print(int *arr, int size_of_arr) {
  if (arr == NULL || size_of_arr <= 0) {
    printf("Error: Invalid array or size\n");
    return;
  }
  int i = 0;
  for (i = 0; i < size_of_arr; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void swap(int *num1, int *num2) {
  if (num1 == NULL || num2 == NULL) {
    printf("Error: NULL pointer in swap\n");
    return;
  }
  // Use temp to avoid bit overflows
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}
