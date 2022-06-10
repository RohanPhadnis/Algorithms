#include <stdio.h>
#include <stdlib.h>

int * ordarray(int start, int stop, int step);
int * randarray(int length);
int linear_search(int array[], int target);
int binary_search(int array[]);
int * bubble_sort(int array[]);
int * insertion_sort(int array[]);
int * selection_sort(int array[]);

int main(void) {
    int array[100];
    for (int i = 0; i < 100; i++) {
        array[i] = rand();
        printf("%d \n", array[i]);
    }
    return 0;
}


int * ordarray(int start, int stop, int step) {
    int output[(stop - start) / step];
    for (int i = start, j = 0; i < stop; i += step, j++) {
        output[j] = i;
    }
    return output;
}


int * randarray(int length) {
    int output[length];
    for (int i = 0; i < length; i++) {
        output[i] = rand();
    }
    return output;
}


int linear_search(int array[], int target) {
    int index = -1;
    for (int i = 0; i < array.length; i++) {
        if (array[i] == target) {
            index = i;
            return index;
        }
    }
    return index;
}


int binary_search(int array[], int target) {
    int low = 0;
    int high = array.length - 1;
    int avg;
    while (high - low > 1) {
        avg = (low + high) / 2;
        if (array[avg] > target) {
            high = avg;
        } else if (array[avg] < target) {
            low = avg;
        } else {
            return avg;
        }
    }
    if (array[avg] == target) {
        return avg;
    } else {
        return -1;
    }
}
