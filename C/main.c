// Libraries
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// General Functions
double rand_double();
void print_array(int array[], int size);
void ord_array(int array[], int size);
void rand_array(int array[], int size);
int choice(int array[], int size);
void insert(int array[], int current, int target);
int get_min_index(int array[], int size, int start);

// Search Functions
int linear_search(int array[], int size, int target);
int recursive_linear_search(int array[], int size, int target, int index);
int binary_search(int array[], int size, int target);
int recursive_binary_search(int array[], int size, int target, int low, int high);

// Sort Functions
void bubble_sort(int array[], int size);
void recursive_bubble_sort(int array[], int size, int i, int sorted);
void insertion_sort(int array[], int size);
void recursive_insertion_sort(int array[], int size, int index);
void selection_sort(int array[], int size);
void recursive_selection_sort(int array[], int size, int index);
void merge_sort();

// Main Method
int main(void) {
    const int SIZE = 100;
    int array[SIZE];
    int target;
    int result;
    clock_t start;
    clock_t end;
    double delta_time;

    printf("Linear Search\n");
    rand_array(array, SIZE);
    print_array(array, SIZE);
    target = choice(array, SIZE);
    printf("target: %d\n", target);
    start = clock();
    result = linear_search(array, SIZE, target);
    end = clock();
    delta_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("output: %d\n", result);
    printf("time: %lf\n", delta_time);
    printf("Recursive Linear Search\n");
    start = clock();
    result = recursive_linear_search(array, SIZE, target, 0);
    end = clock();
    delta_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("output: %d\n", result);
    printf("time: %lf\n\n\n\n", delta_time);

    printf("Binary Search\n");
    ord_array(array, SIZE);
    print_array(array, SIZE);
    target = choice(array, SIZE);
    printf("target: %d\n", target);
    start = clock();
    result = binary_search(array, SIZE, target);
    end = clock();
    delta_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("output: %d\n", result);
    printf("time: %lf\n", delta_time);
    printf("Recursive Binary Search\n");
    start = clock();
    result = recursive_binary_search(array, SIZE, target, 0, SIZE-1);
    end = clock();
    delta_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("output: %d\n", result);
    printf("time: %lf\n\n\n\n", delta_time);

    printf("Bubble Sort\n");
    rand_array(array, SIZE);
    print_array(array, SIZE);
    start = clock();
    bubble_sort(array, SIZE);
    end = clock();
    delta_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    print_array(array, SIZE);
    printf("time: %lf\n", delta_time);
    printf("Recursive Bubble Sort\n");
    rand_array(array, SIZE);
    print_array(array, SIZE);
    start = clock();
    recursive_bubble_sort(array, SIZE, 0, 1);
    end = clock();
    delta_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    print_array(array, SIZE);
    printf("time: %lf\n", delta_time);
    printf("\n\n\n");

    printf("Insertion Sort\n");
    rand_array(array, SIZE);
    print_array(array, SIZE);
    start = clock();
    insertion_sort(array, SIZE);
    end = clock();
    delta_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    print_array(array, SIZE);
    printf("time: %lf\n", delta_time);
    printf("Recursive Insertion Sort\n");
    rand_array(array, SIZE);
    print_array(array, SIZE);
    start = clock();
    recursive_insertion_sort(array, SIZE, 0);
    end = clock();
    delta_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    print_array(array, SIZE);
    printf("time: %lf\n", delta_time);
    printf("\n\n\n");

    printf("Selection Sort\n");
    rand_array(array, SIZE);
    print_array(array, SIZE);
    start = clock();
    selection_sort(array, SIZE);
    end = clock();
    delta_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    print_array(array, SIZE);
    printf("time: %lf\n", delta_time);
    printf("Recursive Selection Sort\n");
    rand_array(array, SIZE);
    print_array(array, SIZE);
    start = clock();
    recursive_selection_sort(array, SIZE, 0);
    end = clock();
    delta_time = ((double) (end - start)) / CLOCKS_PER_SEC;
    print_array(array, SIZE);
    printf("time: %lf\n", delta_time);
    printf("\n\n\n");

    return 0;
}


// **** General Functions ****

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

void insert(int array[], int current, int target) {
    int i;
    int temp = array[current];
    for (i = current; i >  target; i--) {
        array[i] = array[i - 1];
    }
    array[target] = temp;
}

int get_min_index(int array[], int size, int start) {
    int i;
    int output = start;
    for (i = start; i < size; i++) {
        if (array[i] < array[output]) {
            output = i;
        }
    }
    return output;
}


// **** Search Functions ****

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


// **** Sort Functions ****

void bubble_sort(int array[], int size) {
    int i;
    int j;
    int temp;
    int sorted = 0;
    for (i = 0; i < size && !sorted; i++) {
        sorted = 1;
        for (j = 1; j < size; j++) {
            if (array[j - 1] > array[j]) {
                temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                sorted = 0;
            }
        }
    }
}

void recursive_bubble_sort(int array[], int size, int i, int sorted) {
    int temp;
    if (i % size == size - 1) {
        if (!sorted) {
            recursive_bubble_sort(array, size, i+1, 1);
        }
    } else {
        if (array[i % size] > array[i % size + 1]) {
            temp = array[i % size];
            array[i % size] = array[i % size + 1];
            array[i % size + 1] = temp;
            recursive_bubble_sort(array, size, i+1, 0);
        } else {
            recursive_bubble_sort(array, size, i+1, sorted);
        }
    }
}

void insertion_sort(int array[], int size) {
    int index = 1;
    int i;
    while (index < size) {
        i = 0;
        while (array[i] < array[index]) {
            i++;
        }
        insert(array, index, i);
        index++;
    }
}

void recursive_insertion_sort(int array[], int size, int index) {
    int i = 0;
    while (array[i] < array[index]) {
        i++;
    }
    insert(array, index, i);
    if (index < size - 1) {
        recursive_insertion_sort(array, size, index + 1);
    }
}

void selection_sort(int array[], int size) {
    int i;
    int temp;
    int min_index;
    for (i = 0; i < size; i++) {
        min_index = get_min_index(array, size, i);
        temp = array[i];
        array[i] = array[min_index];
        array[min_index] = temp;
    }
}

void recursive_selection_sort(int array[], int size, int index) {
    int min_index = get_min_index(array, size, index);
    int temp = array[min_index];
    array[min_index] = array[index];
    array[index] = temp;
    if (index < size - 1) {
        recursive_selection_sort(array, size, index + 1);
    }
}
