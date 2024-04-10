#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

// Function to calculate the mean of an array
double calculate_mean(double data[], int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += data[i];
    }
    return sum / size;
}

// Function to calculate the standard deviation of an array
double calculate_std_dev(double data[], int size) {
    double mean = calculate_mean(data, size);
    double sum_sq_diff = 0;
    for (int i = 0; i < size; i++) {
        sum_sq_diff += pow(data[i] - mean, 2);
    }
    return sqrt(sum_sq_diff / size);
}

// Function to normalize data using z-score normalization
void z_score_normalization(double data[], int size) {
    double mean = calculate_mean(data, size);
    double std_dev = calculate_std_dev(data, size);
    for (int i = 0; i < size; i++) {
        data[i] = (data[i] - mean) / std_dev;
    }
}

// Function to normalize data using min-max normalization
void min_max_normalization(double data[], int size, double min_val, double max_val) {
    double range = max_val - min_val;
    for (int i = 0; i < size; i++) {
        data[i] = (data[i] - min_val) / range;
    }
}

// Function to normalize data using decimal scaling normalization
void decimal_scaling_normalization(double data[], int size, int power) {
    double max_abs_val = 0;
    for (int i = 0; i < size; i++) {
        if (fabs(data[i]) > max_abs_val) {
            max_abs_val = fabs(data[i]);
        }
    }
    double scale = pow(10, power);
    for (int i = 0; i < size; i++) {
        data[i] = data[i] / (scale * max_abs_val);
    }
}

// Function to normalize data using mean normalization
void mean_normalization(double data[], int size) {
    double mean = calculate_mean(data, size);
    double max_val = data[0];
    double min_val = data[0];
    for (int i = 1; i < size; i++) {
        if (data[i] > max_val) {
            max_val = data[i];
        }
        if (data[i] < min_val) {
            min_val = data[i];
        }
    }
    double range = max_val - min_val;
    for (int i = 0; i < size; i++) {
        data[i] = (data[i] - mean) / range;
    }
}

// Function to normalize data using unit vector normalization
void unit_vector_normalization(double data[], int size) {
    double sum_sq = 0;
    for (int i = 0; i < size; i++) {
        sum_sq += pow(data[i], 2);
    }
    double magnitude = sqrt(sum_sq);
    for (int i = 0; i < size; i++) {
        data[i] = data[i] / magnitude;
    }
}

// Function to normalize data using softmax normalization
void softmax_normalization(double data[], int size) {
    double exp_sum = 0;
    for (int i = 0; i < size; i++) {
        exp_sum += exp(data[i]);
    }
    for (int i = 0; i < size; i++) {
        data[i] = exp(data[i]) / exp_sum;
    }
}

// Function to normalize data using robust scaling normalization
void robust_scaling_normalization(double data[], int size) {
    double sorted_data[size];
    memcpy(sorted_data, data, size * sizeof(double));
    qsort(sorted_data, size, sizeof(double), cmpfunc);
    
    double median, q1, q3, iqr;
    if (size % 2 == 0) {
        median = (sorted_data[size / 2 - 1] + sorted_data[size / 2]) / 2;
        q1 = (sorted_data[size / 4 - 1] + sorted_data[size / 4]) / 2;
        q3 = (sorted_data[size * 3 / 4 - 1] + sorted_data[size * 3 / 4]) / 2;
    } else {
        median = sorted_data[size / 2];
        q1 = sorted_data[size / 4];
        q3 = sorted_data[size * 3 / 4];
    }
    iqr = q3 - q1;
    
    for (int i = 0; i < size; i++) {
        data[i] = (data[i] - median) / iqr;
    }
}

int cmpfunc(const void *a, const void *b) {
    return (*(double *)a - *(double *)b);
}

int main() {
    double data[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    int size = sizeof(data) / sizeof(data[0]);

    // Example usage of normalization techniques
    printf("Original data:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", data[i]);
    }
    printf("\n");

    // Z-score normalization
    z_score_normalization(data, size);
    printf("After Z-score normalization:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", data[i]);
    }
    printf("\n");

    // Min-max normalization
    min_max_normalization(data, size, 0.0, 1.0);
    printf("After min-max normalization:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", data[i]);
    }
    printf("\n");

    // Decimal scaling normalization
    decimal_scaling_normalization(data, size, 3);
    printf("After decimal scaling normalization:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", data[i]);
    }
    printf("\n");

    // Mean normalization
    mean_normalization(data, size);
    printf("After mean normalization:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", data[i]);
    }
    printf("\n");

    // Unit vector normalization
    double data2[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    unit_vector_normalization(data2, size);
    printf("After unit vector normalization:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", data2[i]);
    }
    printf("\n");

    // Softmax normalization
    double data3[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    softmax_normalization(data3, size);
    printf("After softmax normalization:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", data3[i]);
    }
    printf("\n");

    // Robust scaling normalization
    double data4[] = {1.0, 2.0, 3.0, 4.0, 5.0};
    robust_scaling_normalization(data4, size);
    printf("After robust scaling normalization:\n");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", data4[i]);
    }
    printf("\n");

    return 0;
}
