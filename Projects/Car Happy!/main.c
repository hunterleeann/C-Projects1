//
//  main.c
//  Car Happy!
//
//  Created by Hunter Snyder on 5/19/22.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

//structure for car information.
typedef struct CarHappyNode {
    char carModel[40];
    float price;
    int miles;
    struct CarHappyNode* nextCar;
} CarHappy;

//declares the function prototypes
void traversecarInfoList(struct CarHappyNode* start);
void averageCarPrice(struct CarHappyNode* start);
void calculateMilesTotal(struct CarHappyNode* start);


/*void traversecarInfoList(struct CarHappyNode* start){
    while(start!=NULL){
        printf("Car: %s Price: %f I drove it: %d \n",start->carModel,start->price,start->miles);
        start = start->nextCar;
    }
    }*/
int main(){
    //creates the nodes for each car
    struct CarHappyNode* car1 = NULL;
    struct CarHappyNode* car2 = NULL;
    struct CarHappyNode* car3 = NULL;
    struct CarHappyNode* car4 = NULL;
    
    //Uses malloc to allocate the car data memory
    car1 = (struct CarHappyNode*)malloc(sizeof(struct CarHappyNode));
    car2 = (struct CarHappyNode*)malloc(sizeof(struct CarHappyNode));
    car3 = (struct CarHappyNode*)malloc(sizeof(struct CarHappyNode));
    car4 = (struct CarHappyNode*)malloc(sizeof(struct CarHappyNode));
    
    //adds values to car1. Hard coded nodes
    strcpy(car1->carModel,"56 Ford");
    car1->price = 500.00;
    car1->miles = 23000;
    car1->nextCar = car2;
    
    //adds values to car2
    strcpy(car2->carModel,"64 Impala");
    car2->price = 1800.00;
    car2->miles = 12000;
    car2->nextCar = car3;
    
    //adds values to car3
    strcpy(car3->carModel,"57 Ford");
    car3->price = 1400.00;
    car3->miles = 22000;
    car3->nextCar = car4;
    
    //adds values to car4
    strcpy(car4->carModel,"65 Galaxy");
    car4->price = 2600.00;
    car4->miles = 48000;
    car4->nextCar = NULL;
    
    traversecarInfoList(car1);
    calculateMilesTotal(car1);
    averageCarPrice(car1);
    
    printf("Press any key to continue...\n");
    getchar();
    return 0;
}
void traversecarInfoList(struct CarHappyNode* start){
    while(start!=NULL){
        //while start has a value traverse the linked list information. Prints info.
        printf("Car: %s\tPrice: %0.2f\tI drove it: %d \n",start->carModel,start->price,start->miles);
        start = start->nextCar;
    }
}
    
void averageCarPrice(struct CarHappyNode* start){
    
    //calculates the total price then uses division to fin the average
        float priceTotal = 0.0;
    //initializes price total

        
        while(start!=NULL){
            //while start has a value add the car's price to the total count.

            priceTotal += start->price;
            start = start->nextCar;;
            
            
        }
    printf("The average price was: %0.2f \n", priceTotal/4);
    //calculates the average by finding the total and dividing by 4 (total number of cars).
    }
void calculateMilesTotal(struct CarHappyNode* start){
    //calculates the total mile count
    int milesTotal = 0;
    
    while(start!=NULL){
        //while start has a value add the car's miles to the total count.
        milesTotal += start->miles;
        start = start->nextCar;
        
    }
    printf("\nThe Total Miles: %d\n", milesTotal);
    //outputs the total mile count.
}
