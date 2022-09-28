//
//  main.c
//  Here Comes The Fudge
//
//  Created by Hunter Snyder on 3/1/22.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

FILE *fp;
/* FILE *fp is used here to open a text file */

int main()
{
    int totalGallonsOrdered = 0 ;
    int totalGallonsInOz ;
    int fiftyFiveGallonInOz = 7040;
    int totalFiftyFiveOunce ;
    int gallonRemainderFiftyFive ;
    
    int twentyGallonInOz = 2560;
    int totalTwentyOunce ;
    int gallonRemainderTwenty ;
    
    int tenGallonInOz = 1280;
    int totalTenOunce ;
    int gallonRemainderTen ;

    int fiveGallonInOz = 640;
    int totalFiveOunce ;
    int gallonRemainderFive ;
    
    int oneGallonInOz = 128;
    int totalOneOunce ;
    int gallonRemainderOne ;
    /*Created and defined variables for each size container using int*/
    fp = fopen("Here Comes The Fudge.txt", "w");
    /* this tells the computer the name of the file to store the text in*/
    
    printf("Gallons of fudge ordered: ");
    fprintf(fp, "Gallons of fudge ordered: ");
    scanf("%d", &totalGallonsOrdered);
    totalGallonsInOz = (totalGallonsOrdered * 128);
    /* scanf is used to store the input data within a variable*/
    /* printf is used here to display text in the output*/
    /* fprint(fp) is used to send the print code to a txt file*/

    totalFiftyFiveOunce = totalGallonsInOz / fiftyFiveGallonInOz;
    printf("The number of 55 gallon drums is: %d \n", totalFiftyFiveOunce);
    fprintf(fp, "The number of 55 gallon drums is: %d \n", totalFiftyFiveOunce);
    gallonRemainderFiftyFive = totalGallonsInOz % fiftyFiveGallonInOz;
    /*I took the total ounce ammount and divided it by the container size in Oz. Then printed total and found the remainder by dividing the total remaining gallon ammount by the container size in Oz. */
    
    totalTwentyOunce = gallonRemainderFiftyFive / twentyGallonInOz;
    printf("The number of 20 gallon drums is: %d \n", totalTwentyOunce);
    fprintf(fp,"The number of 20 gallon drums is: %d \n", totalTwentyOunce);
    gallonRemainderTwenty = gallonRemainderFiftyFive % twentyGallonInOz;
    
    totalTenOunce = gallonRemainderTwenty / tenGallonInOz;
    printf("The number of 10 gallon drums is: %d \n", totalTenOunce);
    fprintf(fp, "The number of 10 gallon drums is: %d \n", totalTenOunce);
    gallonRemainderTen = gallonRemainderTwenty % tenGallonInOz;
    
    totalFiveOunce = gallonRemainderTen / fiveGallonInOz;
    printf("The number of 5 gallon drums is: %d \n", totalFiveOunce);
    fprintf(fp,"The number of 5 gallon drums is: %d \n", totalFiveOunce);
    gallonRemainderFive = gallonRemainderTen % fiveGallonInOz;
    
    totalOneOunce = gallonRemainderFive / oneGallonInOz;
    printf("The number of 1 gallon drums is: %d \n", totalOneOunce);
    fprintf(fp, "The number of 1 gallon drums is: %d \n", totalOneOunce);
    gallonRemainderOne = gallonRemainderFive % oneGallonInOz;
    
    fclose(fp);
    return 0;
}
