//
//  main.c
//  Keep Your Cool!
//
//  Created by Hunter Snyder on 2/15/22.
//

#include <stdio.h>

FILE *fp;
/* FILE *fp is used here to open a text file */

int main()
{
    int currentTempRamonaInC;
    int startingAltitudeR;
    int finalAltitudeBB;
    int differenceInAltitude;
    double tempAfterConversion;
    double changeInTemp;
    double changeInTempPerFoot = 5.38 / 1000;
    float finalTemp;
    /*all variables defined above as integers, doubles, or floats*/

    fp = fopen("KeepYourCool.txt", "w");
    /* this tells the computer the name of the file to store the text in*/

    printf("Please enter the tempurature in celsius: ");
    fprintf(fp, "Please enter the tempurature in celsius: ");
    scanf("%d", &currentTempRamonaInC);
    printf("Please enter the inital altitude: ");
    fprintf(fp, "Please enter the inital altitude: ");
    scanf("%d", &startingAltitudeR);
    printf("Please enter the final altitude: ");
    fprintf(fp, "Please enter the final altitude: ");
    scanf("%d", &finalAltitudeBB);
    /* printf is used here to display text in the output*/
    /* scanf is used to store the input data within a variable*/
    /* fprint(fp) is used to send the print code to a txt file*/
    
    tempAfterConversion = (currentTempRamonaInC * 1.8) + 32;
    differenceInAltitude = finalAltitudeBB - startingAltitudeR;
    changeInTemp = (differenceInAltitude * changeInTempPerFoot);
    finalTemp = tempAfterConversion - changeInTemp;
    /* I used math equations to convert C to F and preform the needed opperations*/
    
    printf("The tempurature in fahrenheit at %d feet is: %.1f \n" , finalAltitudeBB, finalTemp);
    fprintf(fp, "The tempurature in fahrenheit at %d feet is: %.1f \n" , finalAltitudeBB,
            finalTemp);

    fclose(fp);
    return 0;
}
