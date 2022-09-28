//
//  main.c
//  Fore 2
//
//  Created by Hunter Snyder on 4/23/22.
//

#include <stdio.h>
#include <stdlib.h>

void askForScores(int holeScore[]); //declares the function before use at the start of the code.

int holeNum[9] = {1,2,3,4,5,6,7,8,9}; // declares the variable holeNum using an array. Array set to values of 1-9.




int main()
{
    int holeScore[9]; //declares holeScore variable inside main function.
    
    askForScores(holeScore); //calling the askForScores function.
    
    printf("\n\n"); //allows for spacing between output lines.
    
    int parValue[9] = {4,5,4,5,4,3,4,3,4}; // value of par for each hole hard coded into an array.
    int parTotal = 36; // for this course, parTotal will always be 36.
    int scoreTotal = 0; //Score total used in function, not yet assigned a value.
    int par = 0,birdie = 0, bogey = 0; // declares par, birdie, and bogey.
    

    for (int i = 0 ; i < 9; i++) //for loop to delare and set parameters for "i".
    {
        if(holeScore[i] == parValue[i]) //par - if statement - if holeScore is equal to parValue out put is a par.
        {
            printf("The score on hole # %d was: %d Par is %d - Par\n", holeNum[i], holeScore[i], parValue[i]);
            par ++;
        }
        else if(holeScore[i] < parValue[i]) //birdie - if statement - if holeScore is less than to parValue out put is a birdie.
        {
            printf("The score on hole # %d was: %d Par is %d - Birdie!\n", holeNum[i], holeScore[i], parValue[i]);
            birdie++;
        }
        else //bogie - if statement - if holeScore is more than to parValue out put is a bogey.
        {
            printf("The score on hole # %d was: %d Par is %d - Bogey!\n", holeNum[i], holeScore[i], parValue[i]);
            bogey++;
        }
        
        //add score to the score total
        scoreTotal += holeScore[i];

    }
    printf("\nPar is: %d - total score was: %d \n", parTotal, scoreTotal); //print total score for parTotal and print score for scoreTotal.
    printf("\nNumber of pars: %d \nNumber of birdies: %d \nNumber of bogeys: %d \n", par,birdie,bogey); //determinnes how many pars, birdies, and bogeys based on user input.
}

void askForScores(int holeScore[]){ //function to accept user input and asssign input to holeScore array. 
    for( int i = 0 ; i < 9; i = i + 1) {
        printf("Enter score on hole: %d  ", holeNum[i]);
        scanf(" %d", &holeScore[i]);
    }
}


    
