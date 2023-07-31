#include "sort.h"

void shuffle(int array[], size_t size) {
    srand(time(NULL)); // initialize random seed
    for (size_t i = size - 1; i > 0; i--) {
        size_t j = rand() % (i + 1); // pick a random index between 0 and i
        int tmp = array[i]; // swap arr[i] with arr[j]
        array[i] = array[j];
        array[j] = tmp;
    }
}

void shuffle_sort(int array[], size_t size) {
    shuffle(array, size); // shuffle the array first
    for (size_t i = 1; i < size; i++) {
        int key = array[i];
        size_t j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = key;
    }
}

