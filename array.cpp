#include <cstdio>
#include "array.h"
#include <cstdlib>

void displayArray(DynamicArray *array)
{
    printf("Array (Size: %d, Capacity: %d): ", array->size, array->capacity);
    for (int i = 0; i < array->size; i++) {
        printf("%d ", array->data[i]);
    }
    printf("\n");
}

int findMaximumValue(DynamicArray *array)
{
    if (array->size == 0) {
        printf("Array is empty.\n");
        return 0;
    }
    int max = array->data[0];
    for (int i = 1; i < array->size; i++) {
        if (array->data[i] > max) {
            max = array->data[i];
        }
    }
    return max;
}


int findMinimumValue(DynamicArray *array)
{
    if (array->size == 0) {
        printf("Array is empty.\n");
        return 0;
    }
    int min = array->data[0];
    for (int i = 1; i < array->size; i++) {
        if (array->data[i] < min) {
            min = array->data[i];
        }
    }
    return min;
}

float calculateAverage(DynamicArray *array)
{
    if (array->size == 0) {
        printf("Array is empty.\n");
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < array->size; i++) {
        sum += array->data[i];
    }
    return (float)sum / array->size;
}


/*void enterDataIntoArray(int *array)
{
    printf("Enter data into array \n");
    for(int i = 0; i < SIZE; i++){
        printf("array[%d]= ", i);
        scanf("%d", (array + i));
    }
}
*/
int findMedianValue(DynamicArray *array)
{

    if (array->size % 2 == 0) {
        return (array->data[array->size / 2] + array->data[array->size / 2 - 1]) / 2;
    } else {
        return array->data[array->size / 2];
    }
}
    //int median=(((*(array+(middle-1)))+(*(array+middle)))/2);
    //return median;


void insertionSort(DynamicArray *array) {
    if (array->size <= 1) {
        return; // No need to sort
    }

    for (int i = 1; i < array->size; i++) {
        int key = array->data[i];
        int j = i - 1;

        while (j >= 0 && array->data[j] > key) {
            array->data[j + 1] = array->data[j];
            j = j - 1;
        }
        array->data[j + 1] = key;
    }
}

void saveData(DynamicArray *array)
{
    fptr = fopen("array.txt", "w");
    if (fptr != 0) {
        for (int i = 0; i < array->size; i++) {
            fprintf(fptr, "%d\n", array->data[i]);
        }
        fclose(fptr);
        printf("Data saved to file successfully.\n");
    } else {
        printf("Error opening file!\n");
    }
}



void restoreDataFromFile (DynamicArray *array)
{
    fptr = fopen("array.txt", "r");
    if (fptr != NULL) {
        char fileLine[50];
        while (fgets(fileLine, sizeof(fileLine), fptr) != 0) {
            printf("%s", fileLine);
        }
        fclose(fptr);
        printf("Data restored from file successfully.\n");
    } else {
        printf("Error opening file!\n");
    }
}

void enterValueIntoArray(DynamicArray *array, int toAdd)
{
    if (array->size >= array->capacity) {
        if (array->capacity == 0) {
            array->capacity = 1;
        } else {
            array->capacity *= 2;
        }
        void *temp = realloc(array->data, array->capacity * sizeof(int));
        if (temp == NULL) {
            printf("Error: Memory reallocation failed.\n");
            return;
        }
        array->data = (int *) temp;
    }
    array->data[array->size++] = toAdd;
}


void deleteValueFromArray(DynamicArray *array, int index)
{
    if (index < 0 || index >= array->size) {
        printf("Invalid index\n");
        return;
    }
    for (int i = index; i < array->size - 1; i++) {
        array->data[i] = array->data[i + 1];
    }
    array->size--;
}


void initializeArray(DynamicArray *array) {
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
}

void freeArray(DynamicArray *array) {
    free(array->data);
    array->data = NULL;
    array->size = 0;
    array->capacity = 0;
    printf("The board has been wiped clean\n");
}