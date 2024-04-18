#include <iostream>
#include <cstdlib>
#include "array.h"

FILE *fptr;
int array[SIZE] = {1, 2, 3, 50, -5, 6, 7, 8, 9, 10};

void menu(void) {
    printf("\n");
    printf("1- Display Array\n");
    printf("2- Enter Data Into Array\n");
    printf("3- Maximum Value in Array\n");
    printf("4- Minimum Value in Array\n");
    printf("5- Average Value in Array\n");
    printf("6- Median Value in Array \n");
    printf("7- Save data into Array \n");
    printf("0-EXIT\n");
    printf("Select an option:  ");
}

int main() {
    fptr=fopen("array.txt", "w");
    int option=0;
    do{
        menu();
        scanf("%d", &option);
        printf(" \n");
        switch (option) {
            case 0:
                break;
            case 1:
                displayArray(array);
                break;

            case 2:
                enterDataIntoArray(array);
                break;

            case 3:
                printf("Maximum value = %d \n", findMaximumValue(array));
                break;

            case 4:
                printf("Minimum value = %d \n", findMinimumValue(array));
                break;

            case 5:
                printf("Average value = %f \n", calculateAverage(array));
                break;
            case 6:
                printf("Median value = %d \n", findMedianValue(array));
                break;
            case 7:
                saveData(array);
                if(fptr!=0) {
                    printf("Array saved to the file \n \n");
                }
                else {
                    printf("Something went wrong... \n \n");
                }
                break;

        }

    }while (option!=0);
    printf("THE END");
    return 1;

}