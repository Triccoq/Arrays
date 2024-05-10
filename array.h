#ifndef Array_ARRAY_H
//#define SIZE 10

typedef struct {
    int *data;
    int size;
    int capacity;
} DynamicArray;

void displayArray(DynamicArray *array);
int findMaximumValue(DynamicArray *array);
int findMinimumValue(DynamicArray *array);
float calculateAverage(DynamicArray *array);
//void enterDataIntoArray(int *array);
void enterValueIntoArray(DynamicArray *array, int element);
void deleteValueFromArray(DynamicArray *array, int index);
int findMedianValue(DynamicArray *array);
void insertionSort(DynamicArray *array);
void saveData(DynamicArray *array);
void printDataFromFile (DynamicArray *array);
void freeArray(DynamicArray *array);
void initializeArray(DynamicArray *array);
void restoreDataFromFile (DynamicArray *array);
#define Array_ARRAY_H

#endif