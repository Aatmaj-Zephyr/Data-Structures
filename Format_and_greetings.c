#include<stdio.h>
int main()
{
    int time;
    printf("Enter the time (1-24): ");
    scanf("%d", &time);
    printf("\n");
    if(time>0 && time<=3)
        printf("Good Night");
    else if(time>3 && time<12)
        printf("Good Morning");
    else if(time==12)
        printf("Good Noon");
    else if(time>12 && time<=15)
        printf("Good AfterNoon");
    else if(time>15 && time<20)
        printf("Good Evening");
    else if(time>=20 && time<=24)
        printf("Good Night");
    else
        printf("Unknown time!");
    return 0;
}
