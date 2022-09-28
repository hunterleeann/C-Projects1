//
//  main.c
//  TrainMaker4
//
//  Created by Hunter Snyder on 5/15/22.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
//#include "traindata-1.txt" = trainMaker

#define LOCOMOTIVE_HORSEPOWER 1000.0

//defines the structure
typedef struct {
char trainCarName[30];
char cargoType;
double carWeight;
int carLength;
int horsePower;
int totalNumOfCars;
}TrainMaker;

//Funtion prototype definition before main statement
int loadTrainInformation(TrainMaker trainMaker[]);
int calculateTotalCars(TrainMaker trainMaker[], int totalMakers);
int calculateHorsePower(TrainMaker trainMaker[], int totalMakers);
int calculateLength(TrainMaker trainMaker[], int totalMakers);
int calculateLocomotives(TrainMaker trainMaker[], int totalMakers);
void displayTrainInformation(int trainMaker, int totalTrainMakers);
void displayInformation(TrainMaker trainMaker[], int totalTrainMakers);
void displayInfo(TrainMaker trainMaker[], int totalTrainMakers);



//void foo(TrainMaker trainMaker[]);
            
int main() {
    TrainMaker trainMaker[50];
    int totalTrainMakers= loadTrainInformation(trainMaker);
    void displayTrainInformation(int trainMaker, int totalTrainMakers);
    void displayInfo(TrainMaker trainMaker[], int totalTrainMakers);

}
//opens file for data use
int loadTrainInformation(TrainMaker trainMaker[]){
    FILE *fp;
    int index = 0;
    int i;
    fp = fopen("traindata-1.txt", "r");
    if (fp == NULL)  {
        printf("File could not be opened. \n");
        exit(1);
    
    //int i;
    while (!feof(fp))
    //substr[i] = TrainMaker[index + i];
        //imports file data and sets values to their variable
    (fscanf(fp, "%s %c %lf %d %d %d\n", trainMaker[index + 1].trainCarName,
    &trainMaker[index + i].cargoType, &trainMaker[index + 1].carWeight,
    &trainMaker[index + i].carLength, &trainMaker[index + 1].horsePower,
            &trainMaker[index + i].totalNumOfCars));
        index++;
    }
    return index;
}
//calculates the total car number. returns total number of the cars
int calculateTotalCars(TrainMaker trainMaker[], int totalMakers) {
    int totalNumOfCars = 0;
for (int index = 0; index < totalMakers; index++) {
    totalNumOfCars += trainMaker[index].totalNumOfCars;
}
    return totalNumOfCars;
}
//calculates total horsepower and returns data
int calculateHorsePower(TrainMaker trainMaker[], int totalMakers) {
    int totalHorsePower = 0;
for (int index = 0; index < totalMakers; index++) {
    totalHorsePower += trainMaker[index].horsePower * trainMaker[index].totalNumOfCars;
}
    return totalHorsePower;
}
//calculates the train length and returns data
int calculateLength(TrainMaker trainMaker[], int totalMakers) {
    int fullTrainLength = 0;
    for(int index = 0; index < totalMakers; index++) {
        fullTrainLength += trainMaker[index].carLength * trainMaker[index].totalNumOfCars;
    }
    return fullTrainLength;
}
//calculates the total horse power
int calculateLocomotives(TrainMaker trainMaker[], int totalMakers) {

    int totalHorsePower = calculateHorsePower(trainMaker, totalMakers);
    return (int)(ceil(totalHorsePower / LOCOMOTIVE_HORSEPOWER));
    
    //ceil used to round a double number
}
//prints information and displays on screen
    void displayInformation(TrainMaker trainMaker[], int totalTrainMakers){
    printf("Current Train Cars: \n");
    for (int index = 0; index < totalTrainMakers; index++) {
    printf("Type: %s Weight: %c Length: %.2lf HorsePower: %d Number in Train: %d\n",
    trainMaker[index].trainCarName, trainMaker[index].cargoType, trainMaker[index].carWeight,
    trainMaker[index].carLength, trainMaker[index].horsePower, trainMaker[index].totalNumOfCars);
}
}
//displays information specifics. total car num, total length, total horsepower
void displayInfo(TrainMaker trainMaker[], int totalTrainMakers) {

    void displayTrainInformation(int trainMaker, int totalTrainMakers);
    int totalCars = calculateTotalCars(trainMaker, totalTrainMakers);
    int totalHorsePower = calculateHorsePower(trainMaker, totalTrainMakers);
    int totalTrainLength = calculateLength(trainMaker, totalTrainMakers);

    int locomotives = calculateLocomotives(trainMaker, totalTrainMakers);
    printf("There are %d cars in the train\n", totalCars);
    printf("The total length of train is: %d\n", totalTrainLength);
    printf("The total horsepower needed to pull this train is: %d\n", totalHorsePower);
    printf("The number of engines needed to pull the train is: %d\n", locomotives);
}
