//
//  main.c
//  Paul Bunyan
//
//  Created by Hunter Snyder on 3/16/22.
//

#include <stdio.h>

FILE *fp;
/* File *fp is to let the program know a text file needs to be opened */

int main()
{
    int numberOfTrees = 1000;
    float paulsCutRate = 0.13;
    int yearsTill50Trees = 0;
    int treesPlanted = 0;
    /*int and float are used to define variables used in he program*/
    fp = fopen("PaulBunyan.txt", "w");
    
    printf("How many trees do you want planted per year: ");
    fprintf(fp, "How many trees do you want planted per year: ");
    scanf("%d", &treesPlanted);
    /* printf and scanf are used to ask and interpret input */
    /*fprintf is to copy the text to the open text file */
    
    while (numberOfTrees > 50)
    {
        numberOfTrees = numberOfTrees - (paulsCutRate * numberOfTrees) + treesPlanted;
        printf("Number of remaining trees: %d \n", numberOfTrees);
        fprintf(fp, "Number of remaining trees: %d \n", numberOfTrees);
        yearsTill50Trees++;
        /*Add a year to the end value*/
    }
    /*While is used to confirm if the statement is true or false. While the number of trees is above 50 run the loop*/
    
    printf("Years passed: %d\n", yearsTill50Trees);
    fprintf(fp, "Years passed: %d\n", yearsTill50Trees);

    fclose(fp);
    /* fclose closes the text file */
    
    return 0;
/*The answer is 5 trees per day*/
}
