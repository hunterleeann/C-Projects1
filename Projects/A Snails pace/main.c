//
//  main.c
//  A Snails pace
//
//  Created by Hunter Snyder on 2/14/22.
//
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#define FOOT_PER_MILE 5280
#define EARTH_MILE 24901
#define HOURS_IN_DAY 24
#define DAYS_IN_YEAR 365
#define YEARS_TO_COMPLETE 15008


FILE *fp;

int main()
{
    
    
    outcome = 5280 * 24901 * 24 * 635
    
    int totalMiles = 24901;
    int feetPerMile = 5280;
    int daysPerYear = 365;
    int hoursPerDay = 24;
    double totalFeet = 0.0;
    
    
    double outcome = totalFeet;
    
    int totalHours = totalFeet / hoursPerDay;
    double yearsToComplete = totalHours / daysPerYear;
    
    
    
    totalFeet = totalMiles * feetPerMile;
    scanf("%1d %1d", &totalMiles, &feetPerMile);
    scanf("%1lf", &totalFeet);
    scanf("%d", &hoursPerDay);
    outcome = (double)totalFeet / (double)hoursPerDay;
    scanf("%1d", &totalHours);
    scanf("%1d", &daysPerYear);
    scanf("%1lf",&yearsToComplete);
    yearsToComplete = totalHours / daysPerYear;
    printf("It will take %d years for Sam to crawl around the world. \n", YEARS_TO_COMPLETE);
}


