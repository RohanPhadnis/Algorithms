// Libraries
#include <stdio.h>
#include <stdlib.h>

// General Functions
double rand_double();
void print_array(int array[], int size);
void ord_array(int array[], int size);
void rand_array(int array[], int size);
int choice(int array[], int size);

// Search Functions
int linear_search(int array[], int size, int target);
int recursive_linear_search(int array[], int size, int target, int index);
int binary_search(int array[], int size, int target);
int recursive_binary_search(int array[], int size, int target, int low, int high);

// Sort Functions
void bubble_sort(int array[], int size);

// Main Method
int main(void) {
    const int SIZE = 100;
    int array[SIZE];
    int target;

    printf("Linear Search\n");
    rand_array(array, SIZE);
    print_array(array, SIZE);
    target = choice(array, SIZE);
    printf("target: %d\n", target);
    printf("output: %d\n", linear_search(array, SIZE, target));
    printf("Recursive Linear Search\n");
    printf("output: %d\n\n\n", recursive_linear_search(array, SIZE, target, 0));

    printf("Binary Search\n");
    ord_array(array, SIZE);
    print_array(array, SIZE);
    target = choice(array, SIZE);
    printf("target: %d\n", target);
    printf("output: %d\n", binary_search(array, SIZE, target));
    printf("Recursive Binary Search\n");
    printf("output: %d\n\n\n", recursive_binary_search(array, SIZE, target, 0, SIZE-1));

    return 0;
}

double rand_double() {
    double output = 1. * rand() / RAND_MAX;
    return output;
}

void print_array(int array[], int size) {
    int i;
    printf("[");
    for (i = 0; i < size - 1; i++) {
        printf("%d, ", array[i]);
    }
    printf("%d]\n", array[size - 1]);
}

void ord_array(int array[], int size) {
    int i;
    int multiply = rand_double() * size + 1;
    int add = rand_double() * size;
    printf("%d \t %d \n", multiply, add);
    for (i = 0; i < size; i++) {
        array[i] = multiply * i + add;
    }
}

void rand_array(int array[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        array[i] = rand_double() * size * 10;
    }
}

int choice(int array[], int size) {
    int index = rand_double() * size;
    return array[index];
}

int linear_search(int array[], int size, int target) {
    int i;
    for (i = 0; i < size; i++) {
        if (array[i] == target) {
            return i;
        }
    }
    return -1;
}

int recursive_linear_search(int array[], int size, int target, int index) {
    if (index < size) {
        if (array[index] == target) {
            return index;
        } else {
            return recursive_linear_search(array, size, target, index + 1);
        }
    } else {
        return -1;
    }
}

int binary_search(int array[], int size, int target) {
    int low = 0;
    int high = size - 1;
    int avg;
    while (low != high) {
        avg = (high + low) / 2;
        if (array[avg] == target) {
            return avg;
        } else if (array[avg] > target) {
            high = avg;
        } else {
            low = avg;
        }
    }
    if (array[avg] == target) {
        return avg;
    } else {
        return -1;
    }
}

int recursive_binary_search(int array[], int size, int target, int low, int high) {
    int avg = (low + high) / 2;
    if (array[avg] == target) {
        return avg;
    } else if (high == low) {
        return -1;
    } else if (array[avg] > target) {
        return recursive_binary_search(array, size, target, low, avg);
    } else {
        return recursive_binary_search(array, size, target, avg, high);
    }
}
