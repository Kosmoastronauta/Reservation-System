#include <gtk/gtk.h>
#include <string.h>
#include "structures.h"
#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>
#include "menu_functions_actions.h"
#include "file_functions.h"
#include "date_functions.h"
#include <stdbool.h>
// Mateusz Gil
static void on_changed_month_from(GtkWidget *widget, Time *date)
{   
    
   
    strcpy(date->From_month, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget)));
    g_print("%s", date->From_month);
   
        gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_feature), 0);
    
    
   // g_print("%s", date->From_day);
   // gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_day_from),0);
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(date->combo_box_day_from));


  //  gtk_combo_box_set_model(GTK_COMBO_BOX_TEXT(date->combo_box_day_from), NULL);

   char number_of_day[2];

    if (strcmp(date->From_month, "Styczen")==0 || strcmp(date->From_month,"Marzec")==0 || strcmp(date->From_month, "Maj")==0 || strcmp(date->From_month, "Lipiec")==0 || strcmp(date->From_month, "Sierpien")==0 || strcmp(date->From_month, "Pazdziernik" )==0 || strcmp(date->From_month, "Grudzien")==0)
    {
        
        for (int i = 1; i <= 31; i++)
        {
            sprintf(number_of_day, "%d", i);
            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date->combo_box_day_from), NULL, number_of_day);
        }
        
   }

   else if(strcmp(date->From_month,"Luty")==0)
   {
       
      for (int i = 1; i <= 28; i++)
        {
            sprintf(number_of_day, "%d", i);
            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date->combo_box_day_from), NULL, number_of_day);
        } 
       
   }

   else
   {
       
       for (int i = 1; i <= 30; i++)
        {
            sprintf(number_of_day, "%d", i);
            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date->combo_box_day_from), NULL, number_of_day);
        }
        
   }

   
  // gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_day_from), 0);
 //  g_print("%s", date->From_month);
    
}

static void on_changed_day_from(GtkWidget *widget, Time *date)
{
    
        gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_feature), 0);
    
    
    if(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget))!=NULL)
    {
        strcpy(date->From_day, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget)));  // Podstawienie nowego dnia
        g_print("%s", date->From_day);
    }
        
}



static void on_changed_month_to(GtkWidget *widget, Time *date)
{   
    
    strcpy(date->To_month, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget)));
    g_print("%s", date->To_month);
   
    gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_feature), 0);
   // g_print("%s", date->From_day);
  //  gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_day_from),0);
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(date->combo_box_day_to));
 //   date->combo_box_day_from = gtk_combo_box_text_new();
    char number_of_day[2];

    if (strcmp(date->To_month, "Styczen")==0 || strcmp(date->To_month,"Marzec")==0 || strcmp(date->To_month, "Maj")==0 || strcmp(date->To_month, "Lipiec")==0 || strcmp(date->To_month, "Sierpien")==0 || strcmp(date->To_month, "Pazdziernik" )==0 || strcmp(date->To_month, "Grudzien")==0)
    {
        
        for (int i = 1; i <= 31; i++)
        {
            sprintf(number_of_day, "%d", i);
            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date->combo_box_day_to), NULL, number_of_day);
        }
        
   }

   else if(strcmp(date->To_month,"Luty")==0)
   {
       
      for (int i = 1; i <= 28; i++)
        {
            sprintf(number_of_day, "%d", i);
            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date->combo_box_day_to), NULL, number_of_day);
        } 
       
   }

   else
   {
       
       for (int i = 1; i <= 30; i++)
        {
            sprintf(number_of_day, "%d", i);
            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date->combo_box_day_to), NULL, number_of_day);
        }
        
   }
   
   gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_day_to), 0);
 //  g_print("%s", date->From_month);
   
    
}

static void on_changed_day_to(GtkWidget *widget, Time *date)        // Podstawienie nowego dnia
{
    if(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(date->combo_box_day_to))!=NULL)
    {
    
         strcpy(date->To_day, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(date->combo_box_day_to)));
         g_print("%s", date->To_day);
         gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_feature), 0);

    }
}

static void on_changed_hour_from(GtkWidget *widget, Time *date)
{
     strcpy(date->From_hour, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget)));
     g_print("%s", date->From_hour);
     gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_feature), 0);
}

static void on_changed_hour_to(GtkWidget *widget, Time *date)
{
    strcpy(date->To_hour, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget)));
    g_print("%s", date->To_hour);
    gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_feature), 0);


    
}

static void on_changed_type(GtkWidget *widget, Time *date)
{
    strcpy(date->type, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget)));
    g_print("%s\n", date->type);

    char features[30][30];
    int number_of_features = read_object(date->type, features);
 //   g_print("%d\n", number_of_features);

    int i = 0; 
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(date->combo_box_feature));
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(date->combo_box_model));
    while(i<number_of_features)
    {
        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date->combo_box_feature), NULL, features[i]);
        i++;
    }

    gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_feature), 0);

}


static void on_changed_feature(GtkWidget *widget, Time *date)
{
    if(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget))!=NULL)
    {
        strcpy(date->feature, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget)));  // Podstawienie nowego dnia
        g_print("%s", date->feature);
    }

    char name_of_file[70];
    char avaliable[30][30];
    int number_of_avaliable = 0;
    int row_of_avaliable = 0;
    int number_From_month = month_number(date->From_month);
    int number_To_month = month_number(date->To_month);
    int number_of_day_from = atoi(date->From_day);
    int number_of_day_to = atoi(date->To_day);

    int start_reservation = 31*number_From_month +  number_of_day_from;
    int end_reservation = 31*number_To_month +  number_of_day_to;
    date->start_reservation = start_reservation;
    date->end_reservation = end_reservation;
    char models[30][30];

    sprintf(name_of_file, "%s-%s.txt", date->type, date->feature);
    g_print("\n%s\n", name_of_file);

    if(date->cyclic)    // W przypadku rezerwacji cyklicznej konflikt dat dziala inaczej dni pomiedzy moga być, więc na końcu jest sprawdzana poprawność
    {
        row_of_avaliable = read_objects_with_type(name_of_file, avaliable, start_reservation, end_reservation,true,models);
    }

    else    //wyswietlane sa tylko mozliwe do zarezerwowania w danym terminie obiekty w rezerwacji standardowej
    {
        row_of_avaliable = read_objects_with_type(name_of_file, avaliable, start_reservation, end_reservation, false, models);
    }
    g_print("\n Ilosc wierszy: %d\n", row_of_avaliable);
   // g_print("nJuz mam wiersze\n");

   // gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(date->combo_box_model));
    
    g_print("\n %d\n", row_of_avaliable);

    if (row_of_avaliable > 0)
    {
        for (int i = 0; i < row_of_avaliable; i++)
        {
            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date->combo_box_model), NULL, avaliable[i]);
        }
        gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_model), 0);
    }

   
}

static void on_changed_name(GtkWidget *widget, Time *date)
{
    strcpy(date->name, gtk_entry_get_text(GTK_ENTRY(widget)));
    g_print("%s", date->name);
}

static void on_changed_last_name(GtkWidget *widget, Time *date)
{
    strcpy(date->last_name, gtk_entry_get_text(GTK_ENTRY(widget)));
    g_print("%s", date->last_name);
}

static void on_changed_email(GtkWidget *widget, Time *date)
{
    strcpy(date->email, gtk_entry_get_text(GTK_ENTRY(widget)));
    g_print("%s", date->email);
}

static void on_changed_comment(GtkWidget *widget, Time *date)
{
    GtkWidget *popup;
    int response;
    if (gtk_entry_get_text_length(GTK_ENTRY(widget)) == 100)
    {
        popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Komentarz przekracza 100 znakow!");
        response = gtk_dialog_run(GTK_DIALOG(popup));
        gtk_widget_destroy(popup);
        gtk_entry_set_text(GTK_ENTRY(widget), "");
    }
    else
    {
        strcpy(date->comment, gtk_entry_get_text(GTK_ENTRY(widget)));
        g_print("%s", date->comment);
    }
}

static void on_changed_model(GtkWidget *widget, Time *date)
{
    if(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget))!=NULL)
    {
        strcpy(date->model, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget)));  // Podstawienie nowego dnia
        g_print("%s", date->model);
    }
}

static void button_save_clicked(GtkWidget *widget, Time *date)
{
   // g_print("Clicked save");
   GtkWidget *popup;
   char name_of_file[80];
   int temp;
   int response;
   
   sprintf(name_of_file, "%s-%s.txt", date->type, date->feature);


   // int temp_reserv = 0;
   
   if(strlen(date->name) <1)
   {
       popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Pole imie jest puste!");
       response = gtk_dialog_run(GTK_DIALOG(popup));
       gtk_widget_destroy(popup);
       //return;
   }

   else if (strlen(date->last_name) <1)
   {
       popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Pole nazwisko jest puste!");
       response = gtk_dialog_run(GTK_DIALOG(popup));
       gtk_widget_destroy(popup);
      // return;
   }

   else if (strlen(date->email) <1)
   {
       popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Pole e-mail jest puste!");
       response = gtk_dialog_run(GTK_DIALOG(popup));
       gtk_widget_destroy(popup);
       //return;
   }

   else
   {

    //  g_print("%s",name_of_file);
        if (!date->cyclic)
        {
            temp = save_reservation(date->From_month, date->From_day, date->To_month, date->To_day, date->type, name_of_file, date->model, date->start_reservation, date->end_reservation, date->comment, date->name, date->last_name, date->email, false);    
        }

        else
            {
                bool possible = true;
                int number_of_reservations = 0;
                int from[30];
                int to[30];

                number_of_reservations = file_get_dates_of_model(date->type, date->model, date->feature, from, to);
                g_print("Liczba rezerwacji jakie ma: %d\n", number_of_reservations);

                char check_month[30];
                char check_day[30];
                int check_start;
                strcpy(check_month, date->From_month);
                strcpy(check_day, date->To_day);

                char temp_month[30];
                char temp_day[30];
                int temp_start;
                int number_of_day;

                strcpy(temp_month, date->From_month);
                strcpy(temp_day, date->To_day);


                int start, end;
                int distance = 0;
                end = (month_number(date->To_month) * 31 + atoi(date->To_day));
                start = (month_number(date->From_month) * 31 + atoi(date->From_day));
                temp_start = start;
                check_start = start;

                if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(date->check_button_monthly))) // raz na miesiac
                {

                    while (check_start <= end)
                    {
                        possible = date_avaliable(check_start, check_start, from, to, number_of_reservations);
                        if(!possible)
                        {
                            break;
                        }
                        date_name_of_month_from_number(month_number(check_month) + 1, check_month);
                        check_start = month_number(check_month) * 31 + atoi(check_day);
                    }

                    if(possible)
                    {
                        while(temp_start<=end)
                        {
                            temp = save_reservation(temp_month, temp_day, temp_month, temp_day, date->type, name_of_file, date->model, temp_start, temp_start, date->comment, date->name, date->last_name, date->email, false);
                            date_name_of_month_from_number(month_number(temp_month) + 1, temp_month);
                            temp_start = month_number(temp_month) * 31 + atoi(temp_day);
                        }

                        popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Przedmiot zostal zarezerwowany");
                        response = gtk_dialog_run(GTK_DIALOG(popup));
                        gtk_widget_destroy(popup);
                    }
                }

                else //(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(date->check_button_weekly))) // raz na tydzien
                {

                    while(check_start<=end)
                        {
                            number_of_day = atoi(check_day);
                            possible = date_avaliable(check_start, check_start, from, to, number_of_reservations);
                            if (!possible)
                            {
                                break;
                            }

                            
                            if (number_of_day + 7 > date_days_in_month(check_month) && strcmp("Grudzien",check_month)!=0)
                            {
                                distance = date_days_in_month(check_month) - number_of_day;
                                number_of_day = 7 - distance;
                                date_name_of_month_from_number(month_number(check_month)+1, check_month);
                            }
                            
                            else
                            {
                                number_of_day += 7;
                            }
                            //number_of_day = atoi(check_day);
                            g_print("Jestem sprawdzanie\n");
                            //date_next_week(check_month, check_day);      // aktualizacja miesiaca i dnia w przesunieciu o tydzien
                            sprintf(check_day, "%d", number_of_day);
                            check_start = month_number(check_month) * 31 + atoi(check_day);
                        }

                        if(possible)
                        {
                            while(temp_start<=end)
                            {   number_of_day = atoi(temp_day);
                                  temp = save_reservation(temp_month, temp_day, temp_month, temp_day, date->type, name_of_file, date->model, temp_start, temp_start, date->comment, date->name, date->last_name, date->email, false);
                                  
                                  //date_next_week(temp_month, temp_day); // aktualizacja miesiaca i dnia w przesunieciu o tydzien
    
                                  number_of_day = atoi(temp_day);
                              if (number_of_day + 7 > date_days_in_month(temp_month) && strcmp("Grudzien",temp_month)!=0)
                              {
                                  distance = date_days_in_month(temp_month) - number_of_day;
                                  number_of_day = 7 - distance;
                                  date_name_of_month_from_number(month_number(temp_month)+1, temp_month);
                              }
    
                              else
                              {
                                  number_of_day += 7;
                              }
                              //  g_print("Jestem zapisywanie\n");
                              sprintf(temp_day, "%d", number_of_day);
                              temp_start = month_number(temp_month) * 31 + atoi(temp_day);
                            }

                            popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Przedmiot zostal zarezerwowany");
                            response = gtk_dialog_run(GTK_DIALOG(popup));
                            gtk_widget_destroy(popup);
                        }
            
                }

                if(!possible)
                {
                    popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Niestety nie mozna zarezerwowac przedmiotu w tym terminie");
                    response = gtk_dialog_run(GTK_DIALOG(popup));
                    gtk_widget_destroy(popup);
                }
            
            }
        
    }
}

    static void check_button_type_toggled(GtkWidget *widget, Add *date)
    {

        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(widget)))
        {
            
            gtk_editable_set_editable (GTK_EDITABLE (date->entry_type),true);
            gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(date->check_button_feature),true);
        }

        else
        {
            char features[30][30];

            if(!gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(date->check_button_type)))
            {
                int number_of_features = read_object(date->type, features);

                for (int i = 0; i < number_of_features; i++)
                {

                    gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date->combo_box_feature), NULL, features[i]);
                    i++;
                }

                gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_feature), 0);
            }

            gtk_entry_set_text(GTK_ENTRY(date->entry_type),"");
            gtk_editable_set_editable (GTK_EDITABLE (date->entry_type),false);
    }
                               
}

static void check_button_feature_toggled(GtkWidget *widget, Add *date)
{
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(date->check_button_feature)))
    {
        gtk_editable_set_editable (GTK_EDITABLE (date->entry_feature),true);
        gtk_editable_set_editable (GTK_EDITABLE (date->entry_kind_of_feature),true);
    }

    else
    {
         gtk_entry_set_text(GTK_ENTRY(date->entry_feature),"");
         gtk_editable_set_editable (GTK_EDITABLE (date->entry_feature),false);
          gtk_entry_set_text(GTK_ENTRY(date->entry_kind_of_feature),"");
         gtk_editable_set_editable (GTK_EDITABLE (date->entry_kind_of_feature),false);
    }
    
   
}

static void on_changed_add_existing_type(GtkWidget *widget, Add *date)
{
    strcpy(date->type, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(date->combo_box_existing_types)));

    char features[30][30];
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(date->combo_box_feature));
     int number_of_features = read_object(date->type, features);
     g_print("%d", number_of_features);

     for (int i = 0; i < number_of_features; i++)
     {

         gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date->combo_box_feature), NULL, features[i]);
    }

            gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_feature), 0);
}

static void button_add_save_clicked(GtkWidget *widget, Add *date)
{

    int temp;
    GtkWidget *popup;
    int response;
    if (!gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(date->check_button_type))) // z istniejacym rodzajem
    {
        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(date->check_button_feature)))     // Z nowa cecha
        {

            if(gtk_entry_get_text_length(GTK_ENTRY(date->entry_feature)) == 0)
            {
                g_print("A Cecha?");
                popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Brak cechy!");
                response = gtk_dialog_run(GTK_DIALOG(popup));
                gtk_widget_destroy(popup);
            }
    /*
            else if(gtk_entry_get_text_length(GTK_ENTRY(date->entry_kind_of_feature)) == 0)
            {
                g_print("A Nazwa Cechy?");
            }

    */
            if(gtk_entry_get_text_length(GTK_ENTRY(date->entry_model)) == 0)
            {
                g_print("A Model?");
                popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Brak modelu!");
                response = gtk_dialog_run(GTK_DIALOG(popup));
                gtk_widget_destroy(popup);
            }


            else
            {
                 strcpy(date->type, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(date->combo_box_existing_types)));
                 strcpy(date->feature, gtk_entry_get_text(GTK_ENTRY(date->entry_feature)));
                 strcpy(date->model, gtk_entry_get_text(GTK_ENTRY(date->entry_model)));

                 g_print("\nNazwa rodzaju: %s\n", date->type);
                 g_print("Nazwa cechy: %s\n", date->feature);
                 g_print("Nazwa modeli: %s\n", date->model);
                
                 add_with_existing_type_new_feature(date->type, date->feature, date->model);
                 popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Urzadzenie zostalo dodane!");
            }
        }

        else  // Z istniejaca cecha
        {
       
            if(gtk_entry_get_text_length(GTK_ENTRY(date->entry_model))==0)
            {
                g_print("A Model?");
                popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Brak modelu!");
                response = gtk_dialog_run(GTK_DIALOG(popup));
                gtk_widget_destroy(popup);
            }

            else
            {
                
                strcpy(date->type, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(date->combo_box_existing_types)));
                strcpy(date->feature, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(date->combo_box_feature)));
                strcpy(date->model, gtk_entry_get_text(GTK_ENTRY(date->entry_model)));

                g_print("\nNazwa rodzaju: %s\n", date->type);
                g_print("Nazwa cechy: %s\n", date->feature);
                g_print("Nazwa modeli: %s\n", date->model);

                temp=add_with_existing_type_existing_feature(date->type, date->feature, date->model);

                if(temp)
                {
                     popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Taki przedmiot juz istnieje!");
                     response = gtk_dialog_run(GTK_DIALOG(popup));
                     gtk_widget_destroy(popup);
                }

                else
                {
                    popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Przedmiot zostal dodany!");
                    response = gtk_dialog_run(GTK_DIALOG(popup));
                    gtk_widget_destroy(popup);
                }
                
                
                response = gtk_dialog_run(GTK_DIALOG(popup));
                gtk_widget_destroy(popup);
            }
        
        }
      
    }

     else       // Z nowym rodzajem
    {
        g_print("Ej jestem\n");

        if (gtk_entry_get_text_length(GTK_ENTRY(date->entry_type)) == 0)
        {
            g_print("A Rodzaj?");
            popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Brak rodzaju!");
            response = gtk_dialog_run(GTK_DIALOG(popup));
                gtk_widget_destroy(popup);
        }

        if(gtk_entry_get_text_length(GTK_ENTRY(date->entry_model))==0)
        {
            g_print("A Model?");
            popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Brak modelu!");
            response = gtk_dialog_run(GTK_DIALOG(popup));
                gtk_widget_destroy(popup);
        }

        if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(date->check_button_feature)))  /// Wymagana nowa cecha
        {
            if(gtk_entry_get_text_length(GTK_ENTRY(date->entry_feature))==0)
            {
                g_print("A Cecha?");
                popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Brak cechy!");
                response = gtk_dialog_run(GTK_DIALOG(popup));
                gtk_widget_destroy(popup);
            }

              if(gtk_entry_get_text_length(GTK_ENTRY(date->entry_kind_of_feature)) == 0)
            {
                g_print("A Nazwa Cechy?");
                popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Brak nazwy cechy!");
                response = gtk_dialog_run(GTK_DIALOG(popup));
                gtk_widget_destroy(popup);
            }

            else
            {
                strcpy(date->type, gtk_entry_get_text(GTK_ENTRY(date->entry_type)));
                strcpy(date->feature, gtk_entry_get_text(GTK_ENTRY(date->entry_feature)));
                strcpy(date->model, gtk_entry_get_text(GTK_ENTRY(date->entry_model)));
                strcpy(date->kind_of_feature, gtk_entry_get_text(GTK_ENTRY(date->entry_kind_of_feature)));
    
                g_print("\nNazwa rodzaju: %s\n", date->type);
                g_print("Nazwa cechy: %s\n", date->feature);
                g_print("Nazwa rodzaju cechy: %s\n", date->kind_of_feature);
                g_print("Nazwa modeli: %s\n", date->model);
                add_with_new_type(date->type, date->feature, date->model, date->kind_of_feature);
                g_print("\ndadaje\n");
                popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Urzadzenie zostalo dodane!");
                response = gtk_dialog_run(GTK_DIALOG(popup));
                gtk_widget_destroy(popup);
            }
            
        }

       

        else
         {
             
            strcpy(date->type, gtk_entry_get_text(GTK_ENTRY(date->entry_type)));
            strcpy(date->feature, gtk_entry_get_text(GTK_ENTRY(date->entry_feature)));
            strcpy(date->model, gtk_entry_get_text(GTK_ENTRY(date->entry_model)));
            strcpy(date->kind_of_feature, gtk_entry_get_text(GTK_ENTRY(date->entry_kind_of_feature)));

            g_print("\nNazwa rodzaju: %s\n", date->type);
            g_print("Nazwa cechy: %s\n", date->feature);
            g_print("Nazwa rodzaju cechy: %s\n", date->kind_of_feature);
            g_print("Nazwa modeli: %s\n", date->model);
            add_with_new_type(date->type, date->feature, date->model, date->kind_of_feature);
            g_print("\ndadaje\n");
            popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Urzadzenie zostalo dodane!");
            response = gtk_dialog_run(GTK_DIALOG(popup));
            gtk_widget_destroy(popup);
         }
    }

    
}


static void history_on_changed_feature(GtkWidget *widget, Time *date)
{

     if(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget))!=NULL)
    {
        strcpy(date->feature, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget)));  // Podstawienie nowego dnia
        g_print("%s", date->feature);
    }

    char name_of_file[70];
    char avaliable[30][30];
    int number_of_avaliable = 0;
    int row_of_avaliable = 0;
    int number_From_month = month_number(date->From_month);
    int number_To_month = month_number(date->To_month);
    int number_of_day_from = atoi(date->From_day);
    int number_of_day_to = atoi(date->To_day);

    int start_reservation = 31*number_From_month +  number_of_day_from;
    int end_reservation = 31*number_To_month +  number_of_day_to;
    date->start_reservation = start_reservation;
    date->end_reservation = end_reservation;
    char models[30][30];
    int number_of_models = 0;
    int row_of_avaliabe;

    sprintf(name_of_file, "%s-%s.txt", date->type, date->feature);

    number_of_models = read_objects_with_type(name_of_file, avaliable, start_reservation, end_reservation,TRUE,models);

    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(date->combo_box_model));
    g_print("\n Ilosc: %d\n", number_of_models);
    
    if (number_of_models > 0)
    {
        for (int i = 0; i < number_of_models; i++)
        {
            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date->combo_box_model), NULL, models[i]);
        }
        gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_model), 0);
    }   

}

static void history_button_show_clicked(GtkWidget *window, Time *date)
{
    char info[200][101];
    int number_of_lines = 0;
    char name_of_file[80];
    //GtkTextIter end;

    GtkTextIter iter;
    GtkTextIter end;
    GtkTextMark *cursor;

    gtk_text_buffer_get_iter_at_offset(date->text_buffer, &iter, 0);
    strcpy(date->model, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(date->combo_box_model)));
    sprintf(name_of_file, "%s-%s.txt", date->type, date->model);

    number_of_lines = read_info(info, name_of_file); 
    g_print("\nLiczba lini: %d\n", number_of_lines);

    gtk_text_buffer_set_text (GTK_TEXT_BUFFER(date->text_buffer),"",-1);
    for (int i = 0; i < number_of_lines; i++)
    {
       
        gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer), &iter, info[i], -1);
        gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer), &iter, "\n", -1);

    }
}


static void remove_button_clicked(GtkWidget *widget, Time *date)
{
    int number_of_reservations = 0;
    char name_of_file[80];
    char message[60];
    GtkWidget *popup;
    int temp;

    sprintf(name_of_file, "%s-%s.txt", date->type, date->feature);
    strcpy(date->model, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(date->combo_box_model)));
  
    number_of_reservations = file_number_of_reservations(date->type, date->feature, date->model);

    if(number_of_reservations>-1)
    {
        if(!date->remove_popup_showed)
        {
            sprintf(message, "Liczba rezerwacji dla tego przedmiotu to: %d", number_of_reservations);
            popup = gtk_message_dialog_new(NULL, GTK_DIALOG_MODAL, GTK_MESSAGE_INFO, GTK_BUTTONS_OK, "Liczba rezerwacji dla tego przedmiotu to: %d",number_of_reservations);
            int response = gtk_dialog_run(GTK_DIALOG(popup));
            gtk_widget_destroy(popup);
            date->remove_popup_showed = true;
        }

        else
        {
            temp = remove_object(date->type, date->feature, date->model);
        }
    }
}

static void week_on_changed_month(GtkWidget *widget, Time *date)
{
    strcpy(date->From_month, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget)));
    g_print("%s", date->From_month);
    gtk_combo_box_text_remove_all(GTK_COMBO_BOX_TEXT(date->combo_box_day_from));

    char number_of_day[4];
    char mondays[5][3];
    int number_of_weeks = weeks(date->From_month, mondays);

    for (int i = 0; i < number_of_weeks; i++)
    {
        strcpy(number_of_day, mondays[i]);
        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date->combo_box_day_from), NULL, number_of_day);
    }



}

static void week_on_changed_day(GtkWidget *widget, Time *date)
{
    if(gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget))!=NULL) // Jezeli nie jest pusty (Bez tego przy zmianie miesiaca jest pusty i segvf)
    {
        strcpy(date->From_day, gtk_combo_box_text_get_active_text(GTK_COMBO_BOX_TEXT(widget)));  // Podstawienie nowego dnia
        g_print("%s", date->From_day);
    }

    
}

static void week_button_show_clicked(GtkWidget *widget, Time *date)
{

    GtkTextIter iter[7], itera;
    GtkTextIter end;
    GtkTextMark *cursor;

    char avaliable_monday[70][60];
    char avaliable_thuesday[70][60];
    char avaliable_wednesday[70][60];
    char avaliable_thursday[70][60];    
    char avaliable_friday[70][60];
    char avaliable_sathurday[70][60];
    char avaliable_sunday[70][60];
    int number_of_day_from = atoi(date->From_day);
    int number_of_day;
    int number_of_month;
    int start = (month_number(date->From_month) * 31 + number_of_day_from);
    int jump = 1;
    char prem_month[30];
    strcpy(prem_month, date->From_month);
    int lines = 0;

    
    for (int i = 0; i < 7; i++)
    {   
         gtk_text_buffer_set_text (GTK_TEXT_BUFFER(date->text_buffer_day[i]),"",-1);  // Czyszczenie pola dla kazdego dnia tygodnia
    }
    number_of_day = atoi(date->From_day);

    if (number_of_day > date_days_in_month(prem_month))
    {
        number_of_day = 1;
        date_name_of_month_from_number(month_number(prem_month) + 1, prem_month);
        
     }

        
        start = (month_number(prem_month) * 31 + number_of_day);

        gtk_text_buffer_get_iter_at_offset(date->text_buffer_day[0], &iter[0], 0);
        gtk_text_buffer_set_text(GTK_TEXT_BUFFER(date->text_buffer_day[0]), "", -1);
        lines = file_week_avaliable(date->From_month, date->From_day, avaliable_monday, start, start);

        for (int p = 0; p < lines; p++)
        {
            gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer_day[0]), &iter[0], avaliable_monday[p], -1);
            gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer_day[0]), &iter[0], "\n\n", -1);
        }
        
        number_of_day++;

         if(number_of_day>date_days_in_month(prem_month))
        {
            number_of_day = 1;
            date_name_of_month_from_number(month_number(prem_month) + 1, prem_month);
        }
        start = (month_number(prem_month) * 31 + number_of_day);
    
        gtk_text_buffer_get_iter_at_offset(date->text_buffer_day[1], &iter[1], 0);
        gtk_text_buffer_set_text(GTK_TEXT_BUFFER(date->text_buffer_day[1]), "", -1);
        lines = file_week_avaliable(date->From_month, date->From_day, avaliable_thuesday, start, start);
        for (int p = 0; p < lines; p++)
        {
            gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer_day[1]), &iter[1], avaliable_thuesday[p], -1);  // Uwaga
            gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer_day[1]), &iter[1], "\n\n", -1);
        }
        
        number_of_day++;

         if(number_of_day>date_days_in_month(prem_month))
        {
            number_of_day = 1;
            date_name_of_month_from_number(month_number(prem_month) + 1, prem_month);
        }
        start = (month_number(prem_month) * 31 + number_of_day);

        gtk_text_buffer_get_iter_at_offset(date->text_buffer_day[2], &iter[2], 0);
        gtk_text_buffer_set_text(GTK_TEXT_BUFFER(date->text_buffer_day[2]), "", -1);
        lines = file_week_avaliable(date->From_month, date->From_day, avaliable_wednesday, start, start);
        for (int p = 0; p < lines; p++)
        {
            gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer_day[2]), &iter[2], avaliable_wednesday[p], -1);
            gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer_day[2]), &iter[2], "\n\n", -1);
        }
        
        number_of_day++;

         if(number_of_day>date_days_in_month(prem_month))
        {
            number_of_day = 1;
            date_name_of_month_from_number(month_number(prem_month) + 1, prem_month);
            
        }
        start = (month_number(prem_month) * 31 + number_of_day);

        gtk_text_buffer_get_iter_at_offset(date->text_buffer_day[3], &iter[3], 0);
        gtk_text_buffer_set_text(GTK_TEXT_BUFFER(date->text_buffer_day[3]), "", -1);
        lines = file_week_avaliable(date->From_month, date->From_day, avaliable_thursday, start, start);
        for (int p = 0; p < lines; p++)
        {
            gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer_day[3]), &iter[3], avaliable_thursday[p], -1);
            gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer_day[3]), &iter[3], "\n\n", -1);
        }

        number_of_day++;

         if(number_of_day>date_days_in_month(prem_month))
        {
            number_of_day = 1;
            date_name_of_month_from_number(month_number(prem_month) + 1, prem_month);
        }
        start = (month_number(prem_month) * 31 + number_of_day);

        gtk_text_buffer_get_iter_at_offset(date->text_buffer_day[4], &iter[4], 0);
        gtk_text_buffer_set_text(GTK_TEXT_BUFFER(date->text_buffer_day[4]), "", -1);
        lines = file_week_avaliable(date->From_month, date->From_day, avaliable_friday, start, start);
        for (int p = 0; p < lines; p++)
        {
            gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer_day[4]), &iter[4], avaliable_friday[p], -1);
            gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer_day[4]), &iter[4], "\n\n", -1);
        }

        number_of_day++;

         if(number_of_day>date_days_in_month(prem_month))
        {
            number_of_day = 1;
            date_name_of_month_from_number(month_number(prem_month) + 1, prem_month);
        }
        start = (month_number(prem_month) * 31 + number_of_day);

        gtk_text_buffer_get_iter_at_offset(date->text_buffer_day[5], &iter[5], 0);
        gtk_text_buffer_set_text(GTK_TEXT_BUFFER(date->text_buffer_day[5]), "", -1);
        lines = file_week_avaliable(date->From_month, date->From_day, avaliable_sathurday, start, start);
        for (int p = 0; p < lines; p++)
        {
            gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer_day[5]), &iter[5], avaliable_sathurday[p], -1);
            gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer_day[5]), &iter[5], "\n\n", -1);
        }

        number_of_day++;

        if(number_of_day>date_days_in_month(prem_month))
        {
            number_of_day = 1;
            date_name_of_month_from_number(month_number(prem_month) + 1, prem_month);
        }
        start = (month_number(prem_month) * 31 + number_of_day);

        gtk_text_buffer_get_iter_at_offset(date->text_buffer_day[6], &iter[6], 0);
        gtk_text_buffer_set_text(GTK_TEXT_BUFFER(date->text_buffer_day[6]), "", -1);
        lines = file_week_avaliable(date->From_month, date->From_day, avaliable_sunday, start, start);
        for (int p = 0; p < lines; p++)
        {
            gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer_day[6]), &iter[6], avaliable_sunday[p], -1);
            gtk_text_buffer_insert(GTK_TEXT_BUFFER(date->text_buffer_day[6]), &iter[6], "\n\n", -1);
        }
    
       

}

static void check_button_monthly_toggled(GtkWidget *widget, Time *date)
{
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(date->check_button_weekly)))
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(date->check_button_weekly),false);
    }
    else
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(date->check_button_monthly),true);
    }
    

    
}

static void check_button_weekly_toggled(GtkWidget *widget, Time *date)
{
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(date->check_button_monthly)))
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(date->check_button_monthly),false);
    }
    else
    {
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(date->check_button_weekly),true);
    }
    
    
}

static void check_button_cyclic_toggled(GtkWidget *widget, Time *date)
{
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(date->check_button_cyclic)))
    {
        date->cyclic = true;
        gtk_combo_box_set_active(GTK_COMBO_BOX(date->combo_box_feature), 0);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(date->check_button_monthly),true);
        g_print("Jest cykliczna\n");
    }

    else
    {
        date->cyclic = false;
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(date->check_button_weekly),false);
        gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(date->check_button_monthly),false);
        g_print("Nie jest cykliczna\n");
    }
        
    
}