#include <stdio.h>

void swap(int *, int *);
void print(int *);
void bubble_sort(int *);

int main() {
  int arr[10] = {5, 4, 3, 2, 1};

  // 5 4 3 2 1
  print(arr);

  bubble_sort(arr);

  // 1 2 3 4 5
  print(arr);

  return 0;
}

void swap(int *num1, int *num2) {
  *num1 = *num1 + *num2;
  *num2 = *num1 - *num2;
  *num1 = *num1 - *num2;
}

void bubble_sort(int *arr) {
  // bubble sort logic
  int i, j;
  for (i = 0; i < 5; i++) {
    for (j = 0; j < 5 - i - 1; j++) {
      if (arr[j] > arr[j + 1])
        swap(&arr[j], &arr[j + 1]);
    }
  }
}

void print(int *arr) {
  int i;
  for (i = 0; i < 5; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}
