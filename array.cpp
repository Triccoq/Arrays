#include "array.h"
#include <iostream>
#include <conio.h>
#include <fstream>


using namespace std;
void displayArray(DynamicArray *array)
{
    cout<<"Array (Size: "<<array->size<<" Capacity: "<<array->capacity<<")"<<endl<<endl;
    for (int i = 0; i < array->size; i++) {
        cout<<array->data[i]<<" ";
    }
   cout<<endl;
}

int findMaximumValue(DynamicArray *array)
{
    if (array->size == 0) {
        cout<<"Array is empty."<<endl;
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
        cout<<"Array is empty."<<endl;
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
        cout<<"Array is empty."<<endl;
        return 0;
    }
    int sum = 0;
    for (int i = 0; i < array->size; i++) {
        sum += array->data[i];
    }
    return ((float)sum / array->size);
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
    ofstream zapis("array.txt");
        for (int i = 0; i < array->size; i++) {
            zapis<<array->data[i]<<" ";
        }
        zapis.close();
        cout<<"Data saved to file successfully."<<endl;
}

void restoreDataFromFile (DynamicArray *array)
{
        int value;
        ifstream odczyt("array.txt");
        while (odczyt >> value) {
            enterValueIntoArray(array,value);
    }
        }


void printDataFromFile (DynamicArray *array)
{
    ifstream odczyt("array.txt");
    string fileLine;
    while (getline(odczyt, fileLine)) {
        cout << fileLine << endl;
    }
    odczyt.close();
    cout<<"Data printed from file successfully."<<endl;
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
            cout<<"Error: Memory reallocation failed."<<endl;
            return;
        }
        array->data = (int *) temp;
    }
    array->data[array->size++] = toAdd;
}


void deleteValueFromArray(DynamicArray *array, int index)
{
    if (index < 0 || index >= array->size) {
        cout<<"Invalid index"<<endl;
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
    cout<<"The board has been wiped clean"<<endl;
}