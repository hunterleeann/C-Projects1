//
//  main.c
//  Speedy
//
//  Created by Hunter Snyder on 3/8/22.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

FILE *fp;
/* File *fp is to let the program know a text file needs to be opened */
int main() {
 
    int speedLimit = 0 ;
    int clockedSpeed ;
    int numOfTicketsRecived ;
    /*number of tickets recieved within one year*/
    int speedDifference;
    /* int here is used to define the needed variables */
    
    fp = fopen("Speedy.txt", "w");
    /*fp = fopen opens and names a text file */
    
    printf("Enter the speed limit: ");
    fprintf(fp, "Enter the speed limit: ");
    scanf("%d", &speedLimit);
    printf("Enter the clocked speed: ");
    fprintf(fp, "Enter the clocked speed: ");
    scanf("%d", &clockedSpeed);
    printf("How many tickets have you received in the last year? ");
    fprintf(fp,"How many tickets have you received in the last year? ");
    scanf("%d", &numOfTicketsRecived);
    printf("\n \n");
    fprintf(fp,"\n \n");
    /* printf with \n \n is to allow for spacing in the output */
    /* printf and scanf are used to ask and interpret input */
    /*fprintf is to copy the text to the open text file */
    
    speedDifference = clockedSpeed - speedLimit;
    /* speedDifference is calculated by taking the clocked speed and subtracting the speed limit*/
    
    if(speedDifference <= 15 && speedDifference >= 0) {
        printf("You are fined: 238.00 \n");
        fprintf(fp, "You are fined: 238.00 \n");
    }
    else if(speedDifference <= 25 && speedDifference >= 16) {
        printf("You are fined: 367.00 \n");
        fprintf(fp, "You are fined: 367.00 \n");
    }
    else if(speedDifference <= 100 && speedDifference >= 26) {
        printf("You are fined: 490.00 \n");
        fprintf(fp, "You are fined: 490.00 \n");
    }
    else if(speedDifference > 100) {
        printf("You are fined: 900.00 \n");
        fprintf(fp, "You are fined: 900.00 \n");
    }
    
    if(numOfTicketsRecived > 1 && speedDifference >= 0 && speedDifference <= 25) {
        printf("Your license is suspended for 6 months. \n");
        fprintf(fp, "Your license is suspended for 6 months. \n");
    }
    else if(numOfTicketsRecived > 1 && speedDifference >= 26 && speedDifference < 100) {
        printf("Your license is suspended for 6 months. \n");
    }
    else if(numOfTicketsRecived < 1 && speedDifference >= 0 && speedDifference <= 25) {
        printf("Your license is not suspended. \n");
    }
    else if(numOfTicketsRecived < 1 && speedDifference >= 26 && speedDifference < 100) {
        printf("Your license is not suspended. \n");
    }
    /* if and else if statements are used here to provide a different outcome based on the input */
    
    fclose(fp);
    /* fclose closes the text file */
    
    return 0;
}
