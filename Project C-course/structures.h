#ifndef STRUCTURES_H
#define STRUCTURES_H
#include <gtk/gtk.h>
#include <stdbool.h>
// Mateusz Gil
typedef struct Tools
{
    int From[10];
    int To[10];

} Tool;

typedef struct Time_of_reservation
{
    GtkWidget *combo_box_month_from;
    GtkWidget *combo_box_month_to;
    GtkWidget *combo_box_day_from;
    GtkWidget *combo_box_day_to;
    GtkWidget *combo_box_model;
    GtkWidget *combo_box_feature;
    GtkWidget *combo_box_type;
    GtkWidget *scrolled_window;
    GtkTextBuffer *text_buffer;
    GtkWidget *text_view;
    GtkTextBuffer *text_buffer_day[7];
    GtkTextBuffer *text_buffer_day_booked[7][7];
    GtkWidget *text_view_day[7];
    GtkWidget *text_view_day_booked[7][7];
    GtkWidget *scrolled_window_day[7];
    GtkWidget *scrolled_window_day_booked[7][7];
    GtkWidget *check_button_monthly;
    GtkWidget *check_button_weekly;
    GtkWidget *check_button_cyclic;

    char From_month[13];
    char From_day[2];
    char From_hour[5];

    char To_month[13];
    char To_day[2];
    char To_hour[5];

    char type[30];
    char feature[30];
    char model[30];
    char serial_number[30];

    int number_From_month;
    int number_To_month;
    int number_From_day;
    int number_To_day;

    char name[30];
    char last_name[30];
    char comment[100];
    char email[30];

    double start_reservation;
    double end_reservation;

    bool remove_popup_showed;
    bool cyclic; // true jesli zaznaczona jest opcja rezerwacja cykliczna wpp false

} Time;


typedef struct Add_elements
{
    GtkWidget *combo_box_existing_types;
    GtkWidget *check_button_type;
    GtkWidget *entry_type;
    GtkWidget *entry_feature;
    GtkWidget *entry_model;
    GtkWidget *save;
    GtkWidget *combo_box_feature;
    GtkWidget *check_button_feature;
    GtkWidget *entry_kind_of_feature;

    char type[30];
    char feature[30];
    char model[30];
    char kind_of_feature[30];

} Add;

//char months[13][25]={"a","Styczen","Luty","Marzec","Kwiecien","Maj","Czerwiec","Lipiec","Sierpien","Wrzesien","Pazdziernik","Listopad","Grudzien"};
/*
char months[13][20];
months[1] = "Styczen";//31
months[2] = "Luty";//28
months[3] = "Marzec";//31
months[4] = "Kwiecien";//30
months[5] = "Maj";//31
months[6] = "Czerwiec";//30
months[7] = "Lipiec";//31
months[8] = "Sierpien";//31
months[9] = "Wrzesien";//30
months[10] = "Pazdziernik";//31
months[11] = "Listopad";//30
months[12] = "Grudzien";//31
*/
#endif