#include "date_functions.h"
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
// Mateusz Gil

char mondays[5][2];

int date_days_in_month(char month[20]) 
{
    if (strcmp(month, "Styczen")==0 || strcmp(month,"Marzec")==0 || strcmp(month, "Maj")==0 || strcmp(month, "Lipiec")==0 || strcmp(month, "Sierpien")==0 || strcmp(month, "Pazdziernik" )==0 || strcmp(month, "Grudzien")==0)
    {
        return 31;
    }

    else if(strcmp(month,"Luty")==0)
    {

       return 28;
    }

    else
    {

       return 30;
    }
   
}

void date_name_of_month_from_number(int number_of_month,char month[20])
{
    if(number_of_month==1)
    {
        strcpy(month, "Styczen");
    }

    if(number_of_month==2)
    {
        strcpy(month, "Luty");
    }

    if(number_of_month==3)
    {
        strcpy(month, "Marzec");
    }

    if(number_of_month==4)
    {
        strcpy(month, "Kwiecien");
    }

     if(number_of_month==5)
    {
        strcpy(month, "Maj");
    }

     if(number_of_month==6)
    {
        strcpy(month, "Czerwiec");
    }

     if(number_of_month==7)
    {
        strcpy(month, "Lipiec");
    }

     if(number_of_month==8)
    {
        strcpy(month, "Sierpien");
    }

     if(number_of_month==9)
    {
        strcpy(month, "Wrzesien");
    }

     if(number_of_month==10)
    {
        strcpy(month, "Pazdziernik");
    }

     if(number_of_month==11)
    {
        strcpy(month, "Listopad");
    }

     if(number_of_month==12)
    {
        strcpy(month, "Grudzien");
    }

    
}

int month_number(char month[20])
{
    if(strcmp(month,"Styczen")==0)
    {
        return 1;
    }

    if(strcmp(month,"Luty")==0)
    {
        return 2;
    }

    if(strcmp(month,"Marzec")==0)
    {
        return 3;
    }

    if(strcmp(month,"Kwiecien")==0)
    {
        return 4;
    }

    if(strcmp(month,"Maj")==0)
    {
        return 5;
    }

    if(strcmp(month,"Czerwiec")==0)
    {
        return 6;
    }

    if(strcmp(month,"Lipiec")==0)
    {
        return 7;
    }

    if(strcmp(month,"Sierpien")==0)
    {
        return 8;
    }

    if(strcmp(month,"Wrzesien")==0)
    {
        return 9;
    }

    if(strcmp(month,"Pazdziernik")==0)
    {
        return 10;
    }

    if(strcmp(month,"Listopad")==0)
    {
        return 11;
    }

    if(strcmp(month,"Grudzien")==0)
    {
        return 12;
    }
}

int weeks(char month[20], char mondays[5][3])
{
    if(strcmp(month,"Styczen")==0)
    {
        strcpy(mondays[0], "7");
        strcpy(mondays[1], "14");
        strcpy(mondays[2], "21");
        strcpy(mondays[3], "28");
        return 4;
    }

    if(strcmp(month,"Luty")==0)
    {
        strcpy(mondays[0], "4");
        strcpy(mondays[1], "11");
        strcpy(mondays[2], "18");
        strcpy(mondays[3], "25");
        return 4;
    }

    if(strcmp(month,"Marzec")==0)
    {
        strcpy(mondays[0], "4");
        strcpy(mondays[1], "11");
        strcpy(mondays[2], "18");
        strcpy(mondays[3], "25");
        return 4;
    }

    if(strcmp(month,"Kwiecien")==0)
    {
        strcpy(mondays[0], "1");
        strcpy(mondays[1], "8");
        strcpy(mondays[2], "15");
        strcpy(mondays[3], "22");
        strcpy(mondays[4], "29");
        return 5;
    }

    if(strcmp(month,"Maj")==0)
    {
        strcpy(mondays[0], "6");
        strcpy(mondays[1], "13");
        strcpy(mondays[2], "20");
        strcpy(mondays[3], "27");
        return 4;
    }

    if(strcmp(month,"Czerwiec")==0)
    {
        strcpy(mondays[0], "3");
        strcpy(mondays[1], "10");
        strcpy(mondays[2], "17");
        strcpy(mondays[3], "24");
        return 4;
    }

    if(strcmp(month,"Lipiec")==0)
    {
        strcpy(mondays[0], "1");
        strcpy(mondays[1], "8");
        strcpy(mondays[2], "15");
        strcpy(mondays[3], "22");
        strcpy(mondays[4], "29");
        return 5;   
    }

    if(strcmp(month,"Sierpien")==0)
    {
        strcpy(mondays[0], "5");
        strcpy(mondays[1], "12");
        strcpy(mondays[2], "19");
        strcpy(mondays[3], "26");
        return 4;
    }

    if(strcmp(month,"Wrzesien")==0)
    {
        strcpy(mondays[0], "2");
        strcpy(mondays[1], "9");
        strcpy(mondays[2], "16");
        strcpy(mondays[3], "23");
        strcpy(mondays[4], "30");
        return 5;
    }

    if(strcmp(month,"Pazdziernik")==0)
    {
        strcpy(mondays[0], "7");
        strcpy(mondays[1], "14");
        strcpy(mondays[2], "21");
        strcpy(mondays[3], "28");
        return 4;
    }

    if(strcmp(month,"Listopad")==0)
    {
        strcpy(mondays[0], "4");
        strcpy(mondays[1], "11");
        strcpy(mondays[2], "18");
        strcpy(mondays[3], "25");
        return 4;
    }

    if(strcmp(month,"Grudzien")==0)
    {
        strcpy(mondays[0], "2");
        strcpy(mondays[1], "9");
        strcpy(mondays[2], "16");
        strcpy(mondays[3], "23");
        strcpy(mondays[4], "30");
        return 5;
    }
}

bool date_avaliable(double start, double end, double from[30], double to[30], int number_of_reservations)
{

    bool possible = true;

    for (int i = 0; i < number_of_reservations; i++)
    {
        if((from[i] >= start && from[i] <=end) || (to[i] >= start && to[i] <= end) || (from[i] <= start && to[i] >= end))
        {
            possible = false;
            return possible;
        }
    }

    return possible;
}

void date_next_week(char month[20], char day[2])
{
    int number_of_day;
    int distance = 0;
    int new_month_number;
    char temp_month[20];

    number_of_day = atoi(day);
    if(number_of_day+7<=date_days_in_month(month)) // gdy aktualny dzien +7 dni miesci sie w tym samym miesiacu
        sprintf(day, "%d", number_of_day + 7);

    else
    {
        if(month!="Grudzien")
        {
             distance = (date_days_in_month(month) - number_of_day);
             
             number_of_day = (7 - distance); // dni od poczatku
             //g_print("W nowym miesiacu: %d", number_of_day);
             new_month_number = month_number(month);
             new_month_number++;
             date_name_of_month_from_number(new_month_number, temp_month); // kolejny miesiac
             strcpy(month, temp_month);
        }
    }
    

}

int date_number_of_hour(char hour[5])
{
    char temp[2];
    if(hour[0]=='0')
        return (int)hour[1]-'0';

    else
    {
        temp[0] = hour[0];
        temp[1] = hour[1];
        return atoi(temp);
    }

}