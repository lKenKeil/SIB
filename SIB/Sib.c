#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%2d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int size) {
    int comparisons = 0;
    int moves = 0;

    for (int i = 0; i < size - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < size; j++) {
            comparisons++;
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        moves++;

        printf("Number of comparisons: %d\n", comparisons);
        printf("Number of moves: %d\n", moves);
        printf("Output: ");
        printArray(arr, size);
        printf("\n");
    }
}

void insertionSort(int arr[], int size) {
    int comparisons = 0;
    int moves = 0;

    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            comparisons++;
            arr[j + 1] = arr[j];
            j--;
            moves++;
        }
        arr[j + 1] = key;
        moves++;

        printf("Number of comparisons: %d\n", comparisons);
        printf("Number of moves: %d\n", moves);
        printf("Output: ");
        printArray(arr, size);
        printf("\n");
    }
}

void bubbleSort(int arr[], int size) {
    int comparisons = 0;
    int moves = 0;

    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                // swap temp and arr[i]
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                moves++;
            }
        }

        printf("Number of comparisons: %d\n", comparisons);
        printf("Number of moves: %d\n", moves);
        printf("Output: ");
        printArray(arr, size);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int numbers[SIZE];

    printf("Original array: ");
    for (int i = 0; i < SIZE; i++) {
        numbers[i] = rand() % 100; // Generate random numbers between 0 and 99
        printf("%2d ", numbers[i]);
    }
    printf("\n\n");

    printf("Selection Sort:\n");
    selectionSort(numbers, SIZE);

    printf("\nInsertion Sort:\n");
    insertionSort(numbers, SIZE);

    printf("\nBubble Sort:\n");
    bubbleSort(numbers, SIZE);

    return 0;
}