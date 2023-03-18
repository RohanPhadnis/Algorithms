//
// Created by Rohan on 3/18/23.
//

#include <stdlib.h>
#include <stdio.h>
#include <time.h>


#define SIZE 10


void print_array(int* array, int size);
int randint();
int* generate_array(int size);
int* merge_sort(int* array, int size);
int* merge(int* array1, int size1, int* array2, int size2);


int main(void) {
    srand((unsigned ) time(NULL));
    int* array = generate_array(SIZE);
    print_array(array, SIZE);
    int* sorted_array = merge_sort(array, SIZE);
    print_array(sorted_array, SIZE);
    return 0;
}


void print_array(int* array, int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d\t", array[i]);
    }
    printf("\n");
}


int randint() {
    return (int) (((double) (rand()) / RAND_MAX) * 100);
}


int* generate_array(int size) {
    int* array = malloc(sizeof(int) * size);
    int i;
    for (i = 0; i < size; i++) {
        array[i] = randint();
    }
    return array;
}


int* merge_sort(int* array, int size) {
    if (size <= 1) {
        return array;
    }
    int split = size / 2;
    int* array1 = malloc(sizeof(int) * split);
    int* array2 = malloc(sizeof(int) * (size - split));
    int i;
    for (i = 0; i < size; i++) {
        if (i < split) {
            array1[i] = array[i];
        } else {
            array2[i - split] = array[i];
        }
    }
    return merge(merge_sort(array1, split), split, merge_sort(array2, size-split), size-split);
}


int* merge(int* array1, int size1, int* array2, int size2) {
    int index1 = 0;
    int index2 = 0;
    int* output = malloc(sizeof(int) * (size1 + size2));
    while (index1 < size1 && index2 < size2) {
        if (array1[index1] <= array2[index2]) {
            output[index1 + index2] = array1[index1];
            index1++;
        } else {
            output[index1 + index2] = array2[index2];
            index2++;
        }
    }
    while (index1 < size1) {
        output[index1 + size2] = array1[index1];
        index1++;
    }
    while (index2 < size2) {
        output[index2 + size1] = array2[index2];
        index2++;
    }
    return output;
}
