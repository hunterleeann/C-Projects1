//
//  main.c
//  Wages
//
//  Created by Hunter Snyder on 4/14/22.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void initialStash(double bet, double* stash, double *payoff, double *startingStash);
void printReportHeader(void);
void addToStash(double bet, double* stash, double* payoff, int* numWon, double* amtWon);
void lossFromStash(double bet, double* stash, double* payoff, int* numLost, double* amtLost);
void printReportFooter(int numWon, double amtWon, int numLost, double amtLost, double startingStash, double payoff, double endingStash);

FILE *fp;
FILE *csit;

int main()
{
   // set up variables
    char code;
    double bet, payoff, stash, amtWon, amtLost, startingStash, endingStash;
    int numWon, numLost;
    
   // test and open input file and output file.
   if (!(fp = fopen("wagers.txt", "r"))) {
        printf("wagers.txt could not be opened for input.");
        exit(1); }
   if (!(csit = fopen("csit.txt", "w"))) {
    printf("csit.txt could not be opened for output.");
    exit(1); }
    
   //initialize variable values
   bet = payoff = stash = amtWon = amtLost = startingStash = endingStash = 0.0;
   numWon = numLost = 0;
    
   // print out report header
   printReportHeader();
 
   // loop through file
   while (!feof(fp)) {
    fscanf(fp, "%c %lf\n", &code, &bet);
    if (code == 'D') // initial deposit
     initialStash(bet, &stash, &payoff, &startingStash);
    else if (code == 'W') // a win
     addToStash(bet, &stash, &payoff, &numWon, &amtWon);
    else // must have been a loss
        lossFromStash(bet, &stash, &payoff, &numLost, &amtLost); }
 
   // final calculation of profit or loss
   endingStash = stash - payoff;
    
   // print out summary
   printReportFooter(numWon, amtWon, numLost, amtLost, startingStash, payoff,
 endingStash);
    
   // close data and output file
   fclose(csit);
   fclose(fp);
   return 0;
}

/*Function prototype outputs to file and screen*/
void printReportHeader()
{

/* File *fp is to let the program know a text file needs to be opened */

printf("%5s%-15s%15s%15s%15s"," ","WAGER","WON","LOSS","STASH");
fprintf(csit,"%5s%-15s%15s%15s%15s"," ","WAGER","WON","LOSS","STASH");
printf("\n%5s%-15s%15s%15s%15s"," ","------","-----","-----","------");
fprintf(csit,"\n%5s%-15s%15s%15s%15s"," ","------","-----","-----","------");
}

void initialStash(double bet, double* stash, double *payoff, double *startingStash)

{
    *stash = bet; /*Sets the stash value equal to bet*/
    *payoff = 0; /*Sets the payoff equal to zero as it is not defined*/
    *startingStash = bet; /*Sets starting Stash e*/
    
    printf("\n%-20s%15s%15s%15.2f","Starting Stash","","",*startingStash);
    fprintf(csit,"\n%-20s%15s%15s%15.2f","Starting Stash","","",*startingStash);

}

void addToStash(double bet, double* stash, double* payoff, int* numWon, double* amtWon)
{
    *stash += bet;
    *payoff += 0.10*bet;
    (*numWon)++;
    *amtWon += bet;
    
    printf("\n%-20s%15.2f%15s%15.2f","Won!",bet,"",*stash);
    fprintf(csit,"\n%-20s%15.2f%15s%15.2f","Won!",bet,"",*stash);
    /* printf used to print output to terminal*/
    /*fprintf is to copy the text to the open text file */
}

void lossFromStash(double bet, double* stash, double* payoff, int* numLost, double* amtLost)
{
    *stash -= bet;
    *payoff += 0.05*bet;
    (*numLost)++;
    *amtLost += bet;
    
    printf("\n%-20s%15s%15.2f%15.2f","Lost!","",bet,*stash);
    fprintf(csit,"\n%-20s%15s%15.2f%15.2f","Lost!","",bet,*stash);
}

void printReportFooter(int numWon, double amtWon, int numLost, double amtLost, double startingStash, double payoff, double endingStash)
{
    printf("\n\nTotal number Wins: %d",numWon);
    fprintf(csit,"\n\nTotal number Wins: %d",numWon);
    printf("\nTotal amount Wins: %.2f",amtWon);
    fprintf(csit,"\nTotal amount Wins: %.2f",amtWon);
    printf("\nTotal number Losses: %d",numLost);
    fprintf(csit,"\nTotal number Losses: %d",numLost);
    printf("\nTotal amount Losses: %.2f",amtLost);
    fprintf(csit,"\nTotal amount Losses: %.2f",amtLost);
    printf("\n\nStarting Stash: %.2f",startingStash);
    fprintf(csit,"\n\nStarting Stash: %.2f",startingStash);
    printf("\nTotal payoff charge: %.2f",payoff);
    fprintf(csit,"\nTotal payoff charge: %.2f",payoff);
    printf("\nClosing Stash: %.2f",endingStash);
    fprintf(csit,"\nClosing Stash: %.2f",endingStash);
}
