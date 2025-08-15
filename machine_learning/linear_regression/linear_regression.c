#include <math.h>
#include <stdio.h>

float arithmetic_mean(float[], float);
float covariance(float[], float[]);
float variance(float[]);
float calculate_slope(float[], float[]);
float calculate_intercept(float[], float[], float);

int main() {
  float x[10] = {0.1, 1.3, 2.6, 3.0, 4.4, 5.5, 6.1, 7.2, 8.5, 9.8};
  float y[10] = {3.35,  5.98,  8.72,  9.15,  11.89,
                 14.03, 15.20, 17.61, 20.34, 22.98};
  float slope, intercept;
  float input;
  float prediction;

  slope = calculate_slope(x, y);
  if (slope == INFINITY) {
    printf("Error: Slope is INFINITY\n");
    return 0;
  } else {

    intercept = calculate_intercept(x, y, slope);

    prediction = slope * input + intercept;
    printf("%f\n", slope);
    printf("%f\n", intercept);
  }
}

// slope = covariance(x,y)/variance(x)
float calculate_slope(float x[], float y[]) {
  float slope;
  float cov_x_y, var_x;
  cov_x_y = covariance(x, y);
  var_x = variance(x);

  // Check for divide by 0 error as well
  if (var_x == 0)
    return INFINITY;
  slope = cov_x_y / var_x;

  return slope;
}

float calculate_intercept(float x[], float y[], float slope) {
  float size_of_arr = 10.0;
  float x_mean = arithmetic_mean(x, size_of_arr);
  float y_mean = arithmetic_mean(y, size_of_arr);

  float intercept = y_mean - (slope * x_mean);
  return intercept;
}

float covariance(float x[], float y[]) {
  float size_of_arr = 10;
  float x_mean = arithmetic_mean(x, size_of_arr);
  float y_mean = arithmetic_mean(y, size_of_arr);

  float cov_x_y;
  float sum = 0.0;
  for (int i = 0; i < size_of_arr; i++) {
    sum += (y[i] - y_mean) * (x[i] - x_mean);
  }
  cov_x_y = sum / size_of_arr;
  return cov_x_y;
}

float variance(float x[]) {
  float size_of_arr = 10;
  float x_mean = arithmetic_mean(x, size_of_arr);
  float sum_of_square_difference_x = 0;
  float var_x;
  int i;
  for (i = 0; i < size_of_arr; i++) {
    sum_of_square_difference_x += ((x[i] - x_mean) * (x[i] - x_mean));
  }
  var_x = sum_of_square_difference_x / size_of_arr;
  return var_x;
}

float arithmetic_mean(float arr[], float n) {
  float sum_n = 0.0;
  int i = 0;
  float a_mean = 0.0;
  for (i = 0; i < n; i++) {
    sum_n = sum_n + arr[i];
  }
  a_mean = sum_n / n;
  return a_mean;
}
