//
//  main.c
//  Cars two
//
//  Created by Hunter Snyder on 2/24/22.
//

#include <stdio.h>
/*Used the following 5 lines of code to define the appreciation rate as a constant for each car*/
#define APP_RATE_CHALLENGER 3.02
#define APP_RATE_PLYMOUTH 2.91
#define APP_RATE_FORD 2.01
#define APP_RATE_PONTIAC 2.51
#define APP_RATE_CHEVY 3.35
/*FILE *fp here is used to open a disk file*/
FILE *fp;

int main()
{
    /*lines 21-25 and 27-31 are defining the needed variables for each car and the given years*/
    float challenger04 = 44200;
    float plymouthCuda04 = 7400;
    float mustang04 = 55000;
    float pontiacG04 = 29000;
    float chevyNova04 = 2500;
    
    float challenger08 = (APP_RATE_CHALLENGER * challenger04) + challenger04;
    float plymouthCuda08 = (APP_RATE_PLYMOUTH * plymouthCuda04) + plymouthCuda04;
    float mustang08 = (APP_RATE_FORD * mustang04) + mustang04;
    float pontiacG08 = (APP_RATE_PONTIAC * pontiacG04) + pontiacG04;
    float chevyNova08 = (APP_RATE_CHEVY * chevyNova04) + chevyNova04;
    
    /*fp= open is naming the file the text will be saved under*/
    fp = fopen("Cars For Sale.txt", "w");
    
    /*printf and fprintf are used to display the output in the output box and the disk file*/
    printf("%4s %18s %14s\n", "Car", "2004 Value", "2008 Value");
    fprintf(fp, "%4s %18s %14s\n", "Car", "2004 Value", "2008 Value");
    printf("%5s\n", "---------------------------------------");
    fprintf(fp, "%5s\n", "---------------------------------------");
    printf("%5s %7s %9.2f %3s %10.2f\n", "Nova", ":", chevyNova04,":", chevyNova08);
    fprintf(fp, "%5s %7s %9.2f %3s %10.2f\n", "Nova", ":", chevyNova04,":", chevyNova08);
    printf("%11s %1s %9.2f %3s %10.2f\n", "Challenger",":", challenger04,":", challenger08);
    fprintf(fp,"%11s %1s %9.2f %3s %10.2f\n", "Challenger",":", challenger04,":", challenger08);
    printf("%5s %7s %9.2f %3s %10.2f\n", "Cuda",":", plymouthCuda04,":", plymouthCuda08);
    fprintf(fp, "%5s %7s %9.2f %3s %10.2f\n", "Cuda",":", plymouthCuda04,":", plymouthCuda08);
    printf("%8s %4s %9.2f %3s %10.2f\n", "Mustang",":", mustang04,":", mustang08);
    fprintf(fp,"%8s %4s %9.2f %3s %10.2f\n", "Mustang",":", mustang04,":", mustang08);
    printf("%4s %8s %9.2f %3s %10.2f\n", "GTO",":", pontiacG04,":", pontiacG08);
    fprintf(fp, "%4s %8s %9.2f %3s %10.2f\n", "GTO",":", pontiacG04,":", pontiacG08);
    
    /*fclose closes the disk file*/
    fclose(fp);
    return 0;
}
