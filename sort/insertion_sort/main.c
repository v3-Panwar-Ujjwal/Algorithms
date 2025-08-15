#include <stdio.h>

#define ARR_SIZE 5

void insertion_sort(int *, int);
void print(int *, int);
void swap(int *, int *);

int main() {
  int arr[ARR_SIZE] = {5, 4, 3, 2, 1};

  // Output 5 4 3 2 1
  print(arr, ARR_SIZE);

  insertion_sort(arr, ARR_SIZE);

  // Output 1 2 3 4 5
  print(arr, ARR_SIZE);
}

void swap(int *num1, int *num2) {
  int temp = *num1;
  *num1 = *num2;
  *num2 = temp;
}

void print(int *arr, int size_of_arr) {
  int i;
  for (i = 0; i < size_of_arr; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insertion_sort(int *arr, int size_of_arr) {
  int i, hole, curr_value;
  for (int i = 1; i < size_of_arr; i++) {
    curr_value = arr[i];
    hole = i;
    while (hole > 0 && arr[hole - 1] > curr_value) {
      arr[hole] = arr[hole - 1];
      hole--;
    }
    arr[hole] = curr_value;
  }
}
