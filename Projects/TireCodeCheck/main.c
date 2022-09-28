//
//  main.c
//  Rubber 2
//
//  Created by Hunter Snyder on 4/27/22.
//
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main()
{
    printf("Enter the tire code: ");
    char str1[30],str2[30]; //establishes string
    gets(str1); //calls string
    int valid = 1; //validates the integer - helps determine if statment is true or false.
    if(str1[0]!='P') //entered variable is true if P is entered -- if false user will be notified entry is invalid
{
    printf("Invalid intended use of the tire\n");
    valid = 0;
}

    strncpy(str2,str1+1,3);
    str2[3]='\0';
    int i = atoi(str2); // converts string to an integer
    if(i<155 || i>305) // if entered value is in between these values statement is true.
{
    printf("Invalid tire width\n");
    valid = 0;
}
    strncpy(str2,str1+5,2);
    str2[2]='\0';
    i = atoi(str2);
    if(i<30 || i>70)
{
    printf("Invalid sidewall height ratio to width\n");
    valid = 0;
}

    if(str1[7]!='R'&&str1[7]!='B')
{
    printf("Invalid tire construction\n");
    valid = 0;
}
    strncpy(str2,str1+8,2);
    str2[2] = '\0';
    i = atoi(str2);
    if(i<14||i>22)
{
    printf("Invalid rim diameter\n");
    valid = 0;
}

    strncpy(str2,str1+11,2);
    str2[2]='\0';
    i = atoi(str2);
    if(i<50||i>99)
{
    printf("Invalid load index\n");
    valid = 0;
}
    int validCheck = strlen(str1) - 1;
    if(str1[validCheck]!='S'&&str1[validCheck]!='T'&&str1[validCheck]!='U'&&str1[validCheck]!='H'&&str1[validCheck]!='V')
{
    printf("Invalid speed rating\n");
    valid = 0;
}

    if(valid)
{
    printf("The tire code is valid!");
}
    return 0;
}
