#ifndef DATE_FUNCTIONS_H
#define DATE_FUNCTIONS_H
#include <stdbool.h>
// Mateusz Gil

// zwraca numer miesiaca od 1-12
int month_number(char month[20]);

// wypelnia poniedzialki w danym miesiacu i zwraca ich ilosc 
int weeks(char month[20], char mondays[5][3]);

// zwraca true jezeli dla podanego poczatku i konca z istniejacymi poczatkami i koncami nie ma konfliktu w dacie rezerwacji
bool date_avaliable(int start, int end, int from[30], int to[30], int number_of_reservations);

//daje kolejny tydzien zmienia day i month jezeli to konieczne
void date_next_week(char month[20], char day[2]);

// zwraca ilosc dni dla danego miesiaca
int date_days_in_month(char month[20]);

// do month przypisuje nazwe miesiaca majac jego numer
void date_name_of_month_from_number(int number_of_month, char month[20]);

#endif