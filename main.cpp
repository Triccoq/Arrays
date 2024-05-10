#include <iostream>
#include <stdio.h>
#include "array.h"


FILE *fptr;
//int array[SIZE] = {1, 2, 3, 50, -5, 6, 7, 8, 9, 10};

using namespace std;


void menu(void) {
    cout<<endl;
    cout<<"1- Display Array"<<endl;
    cout<<"2- Enter 1 Value Into Array"<<endl;
    cout<<"3- Maximum Value in Array"<<endl;
    cout<<"4- Minimum Value in Array"<<endl;
    cout<<"5- Average Value in Array"<<endl;
    cout<<"6- Median Value in Array "<<endl;
    cout<<"7- Save data into Array "<<endl;
    cout<<"8- Restore data from Array "<<endl;
    cout<<"9- Delete 1 value from Array "<<endl;
    cout<<"10- Free data in Array "<<endl;
    cout<<"11- Restore data to array from file"<<endl;
    cout<<"0-EXIT"<<endl;
    cout<<"Select an option:  ";
}

int main() {
    DynamicArray array;
    initializeArray(&array);
    fptr=fopen("array.txt", "w");
    int option=0;
    do{
        menu();
       cin>>option;
        cout<<endl;
        switch (option) {
            case 0:
                break;
            case 1:
                displayArray(&array);
                break;

            case 2:
                int toAdd;
                cout<<"Which element to add?"<<endl;
                cin>>toAdd;
                enterValueIntoArray(&array, toAdd );
                break;

            case 3:
                cout<<"Maximum value = "<< findMaximumValue(&array)<<endl;
                break;

            case 4:
                cout<<"Minimum value = "<< findMinimumValue(&array)<<endl;
                break;

            case 5:
                cout<<"Average value = " << calculateAverage(&array)<<endl;
                break;
            case 6:
                cout<<"Median value = " << findMedianValue(&array)<<endl;
                break;
            case 7:
                saveData(&array);
                break;
            case 8:
                printDataFromFile(&array);
                break;
            case 9:
                int toDelete;
                cout<<"Which element to remove?"<<endl;
                cin>>toDelete;
                deleteValueFromArray(&array, toDelete);
                break;
            case 10:
                freeArray(&array);
                break;
            case 11:
                restoreDataFromFile(&array);
                break;
        }

    }while (option!=0);
    cout<<"THE END"<<endl;
    freeArray(&array);
    return 1;

}