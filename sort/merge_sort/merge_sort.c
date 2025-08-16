#include <stdio.h>
#include <stdlib.h>

#define ARR_SIZE 5

void merge_sort(int *, int);
void merge(int *, int *, int *, int, int);
void print(int *, int);

int main() {
  int arr[ARR_SIZE] = {5, 1, 2, 3, 4};

  // 5 1 2 3 4
  print(arr, ARR_SIZE);

  merge_sort(arr, ARR_SIZE);

  // 1 2 3 4 5
  print(arr, ARR_SIZE);

  return 0;
}

void merge_sort(int *arr, int size_of_arr) {
  if (size_of_arr < 2)
    return;
  int mid = size_of_arr / 2;
  int *left = (int *)malloc(mid * sizeof(int));
  int *right = (int *)malloc((size_of_arr - mid) * sizeof(int));

  int i;
  for (i = 0; i < mid; i++)
    left[i] = arr[i];

  for (i = 0; i < size_of_arr - mid; i++)
    right[i] = arr[i + mid];
  merge_sort(left, mid);
  merge_sort(right, size_of_arr - mid);
  merge(left, right, arr, size_of_arr, mid);
  free(left);
  free(right);
}

void merge(int *left, int *right, int *arr, int size_of_arr, int mid) {
  // i to track left index
  // j to track right index
  // k to track arr index

  int i = 0, j = 0, k = 0;
  while (i < mid && j < size_of_arr - mid) {
    if (left[i] <= right[j]) {
      arr[k] = left[i];
      i++;
    } else {
      arr[k] = right[j];
      j++;
    }
    k++;
  }
  while (i < mid) {
    arr[k] = left[i];
    i++;
    k++;
  }
  while (j < size_of_arr - mid) {
    arr[k] = right[j];
    j++;
    k++;
  }
}

void print(int *arr, int size_of_arr) {
  int i;
  for (i = 0; i < size_of_arr; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
