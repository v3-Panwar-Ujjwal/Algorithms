#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 8

void swap(int *, int *);
int partition(int *, int, int);
int randomize_partition(int *, int, int);
void quick_sort(int *, int, int);
void print(int *, int);

int main() {
  int arr[ARR_SIZE] = {4, 5, 1, 2, 0, 7, 6, 3};
  int start = 0, end = ARR_SIZE - 1;

  // 4 5 1 2 0 7 6 3
  print(arr, ARR_SIZE);

  quick_sort(arr, start, end);

  // 0 1 2 3 4 5 6 7
  print(arr, ARR_SIZE);
}

void quick_sort(int *arr, int start, int end) {
  if (start < end) {
    int partition_index = partition(arr, start, end);
    quick_sort(arr, start, partition_index - 1);
    quick_sort(arr, partition_index + 1, end);
  }
}

int randomize_partition(int *arr, int start, int end) {
  // Seed random function with current time;
  srand(time(NULL));

  // generate random number between start and end
  int random_pivot = (rand() % end) + start;
  swap(&arr[end], &arr[random_pivot]);
  partition(arr, start, end);
  return random_pivot;
}
int partition(int *arr, int start, int end) {
  int pivot = arr[end];
  int partition_index = start;
  int i;

  for (i = start; i < end; i++) {
    if (arr[i] <= pivot) {
      swap(&arr[i], &arr[partition_index]);
      partition_index++;
    }
  }
  swap(&arr[partition_index], &arr[end]);
  return partition_index;
}

void swap(int *num1, int *num2) {
  int temp;
  temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

void print(int *arr, int size_of_arr) {
  int i;
  for (i = 0; i < size_of_arr; i++)
    printf("%d ", arr[i]);
  printf("\n");
}
