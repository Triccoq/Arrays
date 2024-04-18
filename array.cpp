#include <cstdio>
#include "array.h"
#include <cstdlib>

void displayArray(int *array)
{
    for(int i = 0; i < SIZE; i++){
        printf("array[%d]= %d \n", i, *(array + i));
    }
}

int findMaximumValue(int *array)
{
    int max = *array;
    for(int i = 1; i < SIZE; i++)
    {
        if(max < *(array + i))
        {
            max = *(array + i);
        }
    }
    return max;
}

int findMinimumValue(int *array)
{
    int min = *array;
    for (int i = 1; i < SIZE; i++)
    {
        if (min > *(array + i)) {
            min = *(array + i);
        }
    }
    return min;
}

float calculateAverage(int *array)
{
    int sum = 0;
    for (int i = 0; i < SIZE; i++) {
        sum += *(array + i);
    }
    float average = (float) sum / SIZE;
    return average;
}

void enterDataIntoArray(int *array)
{
    printf("Enter data into array \n");
    for(int i = 0; i < SIZE; i++){
        printf("array[%d]= ", i);
        scanf("%d", (array + i));
    }
}

int findMedianValue(int *array)
{

    int middle=SIZE/2;
    insertionSort(array);
    int median=(*(array+middle-1));
    return median;
    //int median=(((*(array+(middle-1)))+(*(array+middle)))/2);
    //return median;

}
void insertionSort(int *array) {
    int i, key, j;
    for (i = 1; i < SIZE; i++) {
        key = *(array+i);
        j = i - 1;

        while (j >= 0 && *(array+j) > key) {
            *(array+j+1) = *(array+j);
            j = j - 1;
        }
        *(array+j+1) = key;
    }
}

void saveData(int *array)
{
    fptr = fopen("array.txt", "a");
    if (fptr == 0)
    {
        printf("Blad otwierania pliku!\n");
    }
    for(int i=0; i<SIZE; i++) {
        fprintf(fptr, "array[%d]= %d \n", i, *(array + i) );
    }
    fclose(fptr);

}

void restoreDataFromFile (int *array)
{
    fptr = fopen("array.txt", "r+");
    char fileLine[50];
    if (fptr != 0)
    {
        while (!feof(fptr))
        {
            fgets(fileLine, 50, fptr);
            if (!feof(fptr))
            {
                puts(fileLine);
            }
        }
    }
    else
    {
        printf("\nBlad otwierania pliku!\n");
    }
    fclose(fptr);
}