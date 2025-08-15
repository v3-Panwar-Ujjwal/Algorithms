#include <math.h>
#include <stdio.h>

// Tolerance for float comparison
#define TOLERANCE 1e-10

float arithmetic_mean(float[], int);
float covariance(float[], float[], int);
float variance(float[], int);
float calculate_slope(float[], float[], int);
float calculate_intercept(float[], float[], float, int);

int main() {
  float x[10] = {0.1, 1.3, 2.6, 3.0, 4.4, 5.5, 6.1, 7.2, 8.5, 9.8};
  float y[10] = {3.35,  5.98,  8.72,  9.15,  11.89,
                 14.03, 15.20, 17.61, 20.34, 22.98};
  // Calculating only for x as both will be equal size ideally
  int size_of_arr = sizeof(x) / sizeof(x[0]);

  if (sizeof(x) / sizeof(x[0]) != sizeof(y) / sizeof(y[0])) {
    printf("Error: Array sizes are not equal");
    return 1;
  }

  float slope, intercept;

  slope = calculate_slope(x, y, size_of_arr);
  if (isinf(slope)) {
    printf("Error: Slope is INFINITY\n");
    return 1;
  }

  intercept = calculate_intercept(x, y, slope, size_of_arr);

  if (isinf(intercept)) {
    printf("Error: Intercept is INFINITY\n");
    return 1;
  }

  printf("Slope : %f\n", slope);
  printf("Intercept : %f\n", intercept);

  // Prediction example
  float input = 5.0; // Example input
  float prediction = slope * input + intercept;
  printf("Predicted y for x = %.1f: %f\n", input, prediction);

  return 0;
}

// slope = covariance(x,y)/variance(x)
float calculate_slope(float x[], float y[], int size_of_arr) {
  if (x == NULL || y == NULL || size_of_arr <= 0) {
    printf("Error: Invalid input in calculate_slope");
    return INFINITY;
  }
  float cov_x_y, var_x;
  cov_x_y = covariance(x, y, size_of_arr);
  var_x = variance(x, size_of_arr);

  /*
   * Check for divide by 0 error as well by making sure var_x is greater than
   * TOLERANCE. As var_x is float direct comparison won't work
   */
  if (isinf(var_x) || isinf(cov_x_y) || fabs(var_x) < TOLERANCE)
    return INFINITY;

  return cov_x_y / var_x;
}

float calculate_intercept(float x[], float y[], float slope, int size_of_arr) {
  if (x == NULL || y == NULL || size_of_arr <= 0) {
    printf("Error: Invalid input in calculate_intercept");
    return INFINITY;
  }

  float x_mean = arithmetic_mean(x, size_of_arr);
  float y_mean = arithmetic_mean(y, size_of_arr);

  if (isinf(x_mean) || isinf(y_mean))
    return INFINITY;

  return y_mean - (slope * x_mean);
}

float covariance(float x[], float y[], int size_of_arr) {
  if (x == NULL || y == NULL || size_of_arr <= 0) {
    printf("Error: Invalid input in covariance");
    return INFINITY;
  }
  float x_mean = arithmetic_mean(x, size_of_arr);
  float y_mean = arithmetic_mean(y, size_of_arr);

  if (isinf(x_mean) || isinf(y_mean))
    return INFINITY;

  float sum = 0.0;
  for (int i = 0; i < size_of_arr; i++) {
    sum += (y[i] - y_mean) * (x[i] - x_mean);
  }
  return sum / (float)size_of_arr;
}

float variance(float x[], int size_of_arr) {
  if (x == NULL || size_of_arr <= 0) {
    printf("Error: Invalid input in variance");
    return INFINITY;
  }

  float x_mean = arithmetic_mean(x, size_of_arr);
  float sum_of_square_difference_x = 0;
  int i;

  if (isinf(x_mean))
    return INFINITY;

  for (i = 0; i < size_of_arr; i++) {
    sum_of_square_difference_x += ((x[i] - x_mean) * (x[i] - x_mean));
  }
  return sum_of_square_difference_x / (float)size_of_arr;
}

float arithmetic_mean(float arr[], int n) {
  if (arr == NULL || n <= 0) {
    printf("Error: Invalid input in arithmetic_mean");
    return INFINITY;
  }
  float sum_n = 0.0;
  int i = 0;
  for (i = 0; i < n; i++) {
    sum_n = sum_n + arr[i];
  }
  return sum_n / (float)n;
}
