#include <math.h>
#include <stdio.h>

float arithmetic_mean(float[], int);
float covariance(float[], float[], int);
float variance(float[], int);
float calculate_slope(float[], float[], int);
float calculate_intercept(float[], float[], float, int);

int main() {
  float x[10] = {0.1, 1.3, 2.6, 3.0, 4.4, 5.5, 6.1, 7.2, 8.5, 9.8};
  float y[10] = {3.35,  5.98,  8.72,  9.15,  11.89,
                 14.03, 15.20, 17.61, 20.34, 22.98};
  // Calculating only for x as both will be equal size
  int size_of_arr = sizeof(x) / sizeof(x[0]);

  float slope, intercept;
  slope = calculate_slope(x, y, size_of_arr);
  if (slope == INFINITY) {
    printf("Error: Slope is INFINITY\n");
    return 0;
  }

  intercept = calculate_intercept(x, y, slope, size_of_arr);

  if (intercept == INFINITY) {
    printf("Error: Intercept is INFINITY\n");
    return 0;
  }

  printf("Slope : %f\n", slope);
  printf("Intercept : %f\n", intercept);
}

// slope = covariance(x,y)/variance(x)
float calculate_slope(float x[], float y[], int size_of_arr) {
  if (x == NULL || y == NULL) {
    printf("Error: x and y are NULL in calculate_slope");
    return INFINITY;
  }
  float slope;
  float cov_x_y, var_x;
  cov_x_y = covariance(x, y, size_of_arr);
  var_x = variance(x, size_of_arr);

  if (var_x == INFINITY || cov_x_y == INFINITY)
    return INFINITY;

  // Check for divide by 0 error as well
  if (var_x == 0)
    return INFINITY;
  slope = cov_x_y / var_x;

  return slope;
}

float calculate_intercept(float x[], float y[], float slope, int size_of_arr) {
  if (x == NULL || y == NULL) {
    printf("Error: x and y are NULL in calculate_intercept");
    return INFINITY;
  }

  float x_mean = arithmetic_mean(x, size_of_arr);
  float y_mean = arithmetic_mean(y, size_of_arr);

  if (x_mean == INFINITY || y_mean == INFINITY)
    return INFINITY;

  return y_mean - (slope * x_mean);
}

float covariance(float x[], float y[], int size_of_arr) {
  if (x == NULL || y == NULL) {
    printf("Error: x and y are NULL in covariance");
    return INFINITY;
  }
  float x_mean = arithmetic_mean(x, size_of_arr);
  float y_mean = arithmetic_mean(y, size_of_arr);

  if (x_mean == INFINITY || y_mean == INFINITY)
    return INFINITY;

  float sum = 0.0;
  for (int i = 0; i < size_of_arr; i++) {
    sum += (y[i] - y_mean) * (x[i] - x_mean);
  }
  return sum / (float)size_of_arr;
}

float variance(float x[], int size_of_arr) {
  if (x == NULL) {
    printf("Error: x is NULL in variance");
    return INFINITY;
  }
  float x_mean = arithmetic_mean(x, size_of_arr);
  float sum_of_square_difference_x = 0;
  int i;
  if (x_mean == INFINITY)
    return INFINITY;

  for (i = 0; i < size_of_arr; i++) {
    sum_of_square_difference_x += ((x[i] - x_mean) * (x[i] - x_mean));
  }
  return sum_of_square_difference_x / (float)size_of_arr;
}

float arithmetic_mean(float arr[], int n) {
  if (arr == NULL) {
    printf("Error: arr is NULL in arithmetic_mean");
    return INFINITY;
  }
  float sum_n = 0.0;
  int i = 0;
  for (i = 0; i < n; i++) {
    sum_n = sum_n + arr[i];
  }
  return sum_n / (float)n;
}
