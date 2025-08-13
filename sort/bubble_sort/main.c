#include <stdio.h>

#define ARR_SIZE 5

void swap(int *, int *);
void print(int *, int);
void bubble_sort(int *, int);

int main() {
  int arr[ARR_SIZE] = {5, 4, 3, 2, 1};

  // 5 4 3 2 1
  print(arr, ARR_SIZE);

  bubble_sort(arr, ARR_SIZE);

  // 1 2 3 4 5
  print(arr, ARR_SIZE);

  return 0;
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

void bubble_sort(int *arr, int size) {
  if (arr == NULL || size <= 0) {
    printf("Error: Invalid array or size\n");
    return;
  }
  int i, j;
  int swapped; // Flag to track the swaps in loop
  for (i = 0; i < size; i++) {
    swapped = 0;
    for (j = 0; j < size - i - 1; j++) {
      if (arr[j] > arr[j + 1]) {
        swap(&arr[j], &arr[j + 1]);
        swapped = 1;
      }
    }
    // If no swaps occured break
    if (swapped == 0)
      break;
  }
}

void print(int *arr, int size) {
  if (arr == NULL || size <= 0) {
    printf("Error: Invalid array or size\n");
    return;
  }
  int i;
  for (i = 0; i < size; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
