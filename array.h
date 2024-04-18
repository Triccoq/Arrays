#ifndef Array_ARRAY_H
#define SIZE 10
extern FILE *fptr;
void displayArray(int *array);
int findMaximumValue(int *array);
int findMinimumValue(int *array);
float calculateAverage(int *array);
void enterDataIntoArray(int *array);
int findMedianValue(int *array);
void insertionSort(int *array);
void saveData(int *array);
void restoreDataFromFile (int *array);
#define Array_ARRAY_H

#endif