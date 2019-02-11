#include <gtk/gtk.h>
#include "menu_functions.h"
#include <stdio.h>
#include <stdlib.h>
#include "structures.h"
#include <string.h>
#include "menu_functions_actions.c"
#include "file_functions.h"
#include "date_functions.h"
#define MAX_NUMBER_OF_TYPES 10
// Mateusz Gil

static void button_reserv_clicked(GtkWidget *widget, gpointer data)
{
   // gtk_window_close(GTK_WINDOW(widget));
    char months[13][25]={"a","Styczen","Luty","Marzec","Kwiecien","Maj","Czerwiec","Lipiec","Sierpien","Wrzesien","Pazdziernik",
    "Listopad","Grudzien"};

     int argc;
    char **argv;
    int number_of_types;
    char types[MAX_NUMBER_OF_TYPES][30];
    
    


    gtk_init(&argc, &argv);
    GtkWidget *window, *grid, *label_type, *label_model, *combo_box_month_from, *combo_box_month_to, *combo_box_hour_from, *combo_box_type, *combo_box_model,
        *combo_box_serial_number, *combo_box_hour_to, *label_month, *combo_box_feature,
        *label_day, *label_hour, *label_main_title, *label_from, *label_to, *label_title_object, *label_feature, *entry_name, *entry_lastname, *entry_email,
        *label_name, *label_lastname, *label_email, *label_title_data, *label_comment, *entry_comment, *button_save, *check_button_monthly;

    number_of_types = read_types_of_objects(types);     // Liczba typow obiektow mozliwych do zarezerwowania

     for (int p = 0; p < number_of_types; p++)
    {
        g_print("%s\n", types[p]);
    }

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Rezerwacja");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 200);
    g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    char name_of_month[20];
    char number_of_day[2];
    char number_of_hour[6];
    Time date; //Struktura trzymająca informacje o czasie rezerwacji

    date.combo_box_month_from = gtk_combo_box_text_new();
    date.combo_box_month_to = gtk_combo_box_text_new();
    date.combo_box_day_from = gtk_combo_box_text_new();
    date.combo_box_day_to = gtk_combo_box_text_new();
    combo_box_hour_from = gtk_combo_box_text_new();
    combo_box_hour_to = gtk_combo_box_text_new();
    combo_box_type = gtk_combo_box_text_new();
    combo_box_feature = gtk_combo_box_text_new();
    combo_box_model = gtk_combo_box_text_new();
    date.combo_box_model = gtk_combo_box_text_new();
    date.combo_box_feature = gtk_combo_box_text_new();
    date.check_button_monthly = gtk_check_button_new();
    date.check_button_weekly = gtk_check_button_new();
    date.check_button_cyclic = gtk_check_button_new();

    date.cyclic = false;

    for (int i = 1; i <= 12; i++)       // wypelnienie nazwami miesiecy
        {
            strcpy(name_of_month, months[i]);
            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date.combo_box_month_from), NULL, name_of_month);
            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date.combo_box_month_to), NULL, name_of_month);
            
        }
    
    for (int i = 7; i <= 20; i++)       // Wypelnienie wartosciami godziny
     {
            if(i<10)
            {
                sprintf(number_of_hour, "0%d:00", i);
                gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo_box_hour_from), NULL, number_of_hour);
                gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo_box_hour_to), NULL, number_of_hour);
            }
            else
            {
                sprintf(number_of_hour, "%d:00", i);
                gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo_box_hour_from), NULL, number_of_hour);
                gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo_box_hour_to), NULL, number_of_hour);
            }
            
     }

     for (int i = 0; i < number_of_types; i++)
     {
         gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(combo_box_type), NULL, types[i]);
     }

     //gtk_combo_box_set_active(GTK_COMBO_BOX(combo_box_month_from), 0); // Ustawienie wartosci poczatkowych miesiecy na Styczen
     //gtk_combo_box_set_active(GTK_COMBO_BOX(combo_box_month_to), 0);
     gtk_combo_box_set_active(GTK_COMBO_BOX(date.combo_box_day_from), 0); // Ustawienie wartosci poczatkowych dni na 1
     gtk_combo_box_set_active(GTK_COMBO_BOX(date.combo_box_day_to), 0);

     grid = gtk_grid_new();
     gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
     gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
     gtk_grid_set_column_spacing(GTK_GRID(grid), 20);
     gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

     label_main_title = gtk_label_new("Rezerwacja");
     label_from = gtk_label_new("Poczatek");
     label_to = gtk_label_new("Koniec ");
     label_month = gtk_label_new("Miesiac: ");
     label_day = gtk_label_new("Dzien:");
     label_hour = gtk_label_new("Godzina:");
     label_title_object = gtk_label_new("Przedmiot");
     label_type = gtk_label_new("Rodzaj:");
     label_model = gtk_label_new("Model:");
     label_feature = gtk_label_new("Cecha:");
     label_name = gtk_label_new("Imie:");
     label_lastname = gtk_label_new("Nazwisko:");
     label_title_data = gtk_label_new("Dane Rezerwujacego");
     label_email = gtk_label_new("E-mail:");
     label_comment = gtk_label_new("Komentarz: (100 znakow)");
     date.check_button_monthly = gtk_check_button_new_with_label("Co miesiac");
     date.check_button_weekly = gtk_check_button_new_with_label("Co tydzien");
     date.check_button_cyclic = gtk_check_button_new_with_label("Cykliczna");

     button_save = gtk_button_new_with_label("Rezerwuj");

     entry_name = gtk_entry_new();
     entry_lastname = gtk_entry_new();
     entry_email = gtk_entry_new();
     entry_comment = gtk_entry_new();
     gtk_entry_set_max_length(GTK_ENTRY(entry_name), 20);
     gtk_entry_set_max_length(GTK_ENTRY(entry_lastname), 30);
     gtk_entry_set_max_length(GTK_ENTRY(entry_email), 30);
     gtk_entry_set_max_length(GTK_ENTRY(entry_comment), 100);


     //Zdarzenia

     g_signal_connect(date.combo_box_month_from, "changed", G_CALLBACK(on_changed_month_from), (gpointer)&date);  // Zdarzenie Zmiana Miesiaca poczatek
     g_signal_connect(date.combo_box_day_from, "changed", G_CALLBACK(on_changed_day_from), (gpointer)&date); // Zdarzenie Zmiana Dnia poczatek
     g_signal_connect(date.combo_box_month_to, "changed", G_CALLBACK(on_changed_month_to), (gpointer)&date);      // Zdarzenie Zmiana Miesiaca koniec
     g_signal_connect(date.combo_box_day_to, "changed", G_CALLBACK(on_changed_day_to), (gpointer)&date);     // Zdarzenie Zmiana Dnia koniec
     g_signal_connect(combo_box_hour_from, "changed", G_CALLBACK(on_changed_hour_from), (gpointer)&date);    // Zdarzenie Zmiana Godziny poczatek
     g_signal_connect(combo_box_hour_to, "changed", G_CALLBACK(on_changed_hour_to), (gpointer)&date);        // Zdarzenie Zmiana Godziny koniec
     g_signal_connect(combo_box_type, "changed", G_CALLBACK(on_changed_type), (gpointer)&date);              // Zdarzenie Zmiana Rodzaju
     g_signal_connect(date.combo_box_feature, "changed", G_CALLBACK(on_changed_feature), (gpointer)&date);   // Zdarzenie Zmiana cechy
     g_signal_connect(date.combo_box_model, "changed", G_CALLBACK(on_changed_model), (gpointer)&date);       // Zdarzenie Zmiana modelu
     g_signal_connect(entry_name, "activate", G_CALLBACK(on_changed_name), (gpointer)&date);                 // Zdarzenie Zmiana Imienia
     g_signal_connect(entry_lastname, "activate", G_CALLBACK(on_changed_last_name), (gpointer)&date);        // Zdarzenie Zmiana nazwiska
     g_signal_connect(entry_email, "activate", G_CALLBACK(on_changed_email), (gpointer)&date);               // Zdarzenie Zmiana email
     g_signal_connect(entry_comment, "activate", G_CALLBACK(on_changed_comment), (gpointer)&date);           // Zdarzenie Zmiana komentarza
     g_signal_connect(button_save, "clicked", G_CALLBACK(button_save_clicked), (gpointer)&date);             // Zdarzenie Rezerwacja
     g_signal_connect(date.check_button_monthly, "toggled", G_CALLBACK(check_button_monthly_toggled), (gpointer)&date);
     g_signal_connect(date.check_button_weekly, "toggled", G_CALLBACK(check_button_weekly_toggled), (gpointer)&date);
     g_signal_connect(date.check_button_cyclic, "toggled", G_CALLBACK(check_button_cyclic_toggled), (gpointer)&date);


     //Rozmieszczenie w Gridzie do rezerwacji wszystkich obiektow

     gtk_grid_attach(GTK_GRID(grid), label_main_title, 2, 0, 4, 1);
     gtk_grid_attach(GTK_GRID(grid), label_from, 1, 1, 3, 1);
     gtk_grid_attach(GTK_GRID(grid), label_to, 2, 1, 3, 1);
     gtk_grid_attach(GTK_GRID(grid), label_title_object, 4, 0, 3, 3);

     gtk_grid_attach(GTK_GRID(grid), label_month, 1, 3, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), date.combo_box_month_from, 2, 3, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), label_day, 1, 4, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), date.combo_box_day_from, 2, 4, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), label_to, 3, 3, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), date.combo_box_month_to, 3, 3, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), date.combo_box_day_to, 3, 4, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), label_hour, 1, 5, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), combo_box_hour_from, 2, 5, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), combo_box_hour_to, 3, 5, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), label_type, 4, 3, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), combo_box_type, 5, 3, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), label_feature, 4, 4, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), label_model, 4, 5, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), label_title_data, 2, 6, 2, 1);
     gtk_grid_attach(GTK_GRID(grid), label_name, 1, 7, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), label_lastname, 1, 8, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), entry_name, 2, 7, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), entry_lastname, 2, 8, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), label_email, 3, 7, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), entry_email, 4, 7, 2, 1);
     gtk_grid_attach(GTK_GRID(grid), label_comment, 3, 8, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), entry_comment, 4, 8, 2, 2);
     gtk_grid_attach(GTK_GRID(grid), date.combo_box_feature, 5, 4, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), date.combo_box_model, 5, 5, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), date.check_button_cyclic, 6, 2, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), date.check_button_monthly, 6, 3, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), date.check_button_weekly, 6, 4, 1, 1);
     gtk_grid_attach(GTK_GRID(grid), button_save, 6, 9, 1, 2);
     


     gtk_container_add(GTK_CONTAINER(window), grid);
     gtk_container_set_border_width(GTK_CONTAINER(window), 20);

     gtk_widget_show_all(window);

     gtk_main();
}


static void button_add_clicked(GtkWidget *widget, gpointer data)
{
    int argc;
    char **argv;

    Add date;
    gtk_init(&argc, &argv);
    GtkWidget *window, *grid, *label_existing_types, *label_title, *label_feature, *label_model, *label_new_type, *label_type, *label_existing_features, *label_kind_of_feature;

    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 20);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);



    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Dodawanie Obiektu");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 200);
    g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    label_existing_types = gtk_label_new("Rodzaj:");
    label_title = gtk_label_new("Dodawanie Nowego Urzadzenia");
    label_model = gtk_label_new("Model:");
    label_type = gtk_label_new("Nowy Rodzaj:");
    label_existing_features = gtk_label_new("Istniejace Cechy");
    label_feature = gtk_label_new("Nowa Cecha:");
    label_kind_of_feature = gtk_label_new("Nazwa Cechy:");
    date.check_button_type = gtk_check_button_new_with_label("Nowy Rodzaj");
    date.combo_box_existing_types = gtk_combo_box_text_new();
    date.entry_feature = gtk_entry_new();
    date.entry_type = gtk_entry_new();
    date.entry_model = gtk_entry_new();
    date.save = gtk_button_new_with_label("Zapisz");
    date.combo_box_feature = gtk_combo_box_text_new();
    date.check_button_feature = gtk_check_button_new_with_label("Nowa Cecha");
    date.entry_kind_of_feature = gtk_entry_new();
    // gtk_combo_box_set_active(GTK_COMBO_BOX(date.combo_box_feature), 0);

    existing_types(date.combo_box_existing_types);
    gtk_editable_set_editable (GTK_EDITABLE (date.entry_type),false);
    gtk_editable_set_editable (GTK_EDITABLE (date.entry_feature),false);
    g_signal_connect(date.check_button_type, "toggled", G_CALLBACK(check_button_type_toggled), (gpointer) &date);
    g_signal_connect(date.save, "clicked", G_CALLBACK(button_add_save_clicked), (gpointer)&date);
    g_signal_connect(date.check_button_feature, "toggled", G_CALLBACK(check_button_feature_toggled), (gpointer)&date);
    g_signal_connect(date.combo_box_existing_types, "changed", G_CALLBACK(on_changed_add_existing_type), (gpointer)&date);

    gtk_grid_attach(GTK_GRID(grid), label_title, 1, 0, 3, 1);
    gtk_grid_attach(GTK_GRID(grid), label_existing_types, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.combo_box_existing_types, 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.check_button_type, 3, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_type, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_model, 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_existing_features, 1, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.entry_type, 2, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.entry_model, 2, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.combo_box_feature, 2, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.save, 3, 6, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.check_button_feature, 3, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.entry_feature, 2, 6, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_kind_of_feature, 1, 5, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_feature, 1, 6, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.entry_kind_of_feature, 2, 5, 1, 1);

    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);

    gtk_widget_show_all(window);

     gtk_main();



}

static void button_remove_clicked(GtkWidget *widget, gpointer data)
{

 char types[MAX_NUMBER_OF_TYPES][30];
    int number_of_types;
    number_of_types = read_types_of_objects(types); // Liczba typow obiektow mozliwych do zarezerwowania

    for (int p = 0; p < number_of_types; p++)
    {
        g_print("%s\n", types[p]);
    }

    int argc;
    char **argv;
    Time date;
    GtkWidget *grid, *window, *label_type, *label_feature, *label_model, *label_title, *button_remove;
    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 20);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

    date.cyclic = false;


    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Usuwanie Sprzetu");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 200);
    g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);



    label_title = gtk_label_new("Usuwanie Sprzetu");
    label_type = gtk_label_new("Rodzaj:");
    label_feature = gtk_label_new("Cecha:");
    label_model = gtk_label_new("Model:");
    button_remove = gtk_button_new_with_label("Usun");

    date.combo_box_type = gtk_combo_box_text_new();
    date.combo_box_feature = gtk_combo_box_text_new();
    date.combo_box_model = gtk_combo_box_text_new();
    date.remove_popup_showed = false;

    for (int i = 0; i < number_of_types; i++)
    {
         gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date.combo_box_type), NULL, types[i]);
    }

     gtk_combo_box_set_active(GTK_COMBO_BOX(date.combo_box_type), 0);
     gtk_combo_box_set_active(GTK_COMBO_BOX(date.combo_box_model), 0);

    g_signal_connect(date.combo_box_type, "changed", G_CALLBACK(on_changed_type), (gpointer)&date);
    g_signal_connect(date.combo_box_feature, "changed", G_CALLBACK(history_on_changed_feature), (gpointer)&date);
    g_signal_connect(button_remove, "clicked", G_CALLBACK(remove_button_clicked), (gpointer)&date);


    gtk_grid_attach(GTK_GRID(grid), label_title, 1, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), label_type, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_feature, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_model, 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.combo_box_type, 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.combo_box_feature, 2, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.combo_box_model, 2, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_remove, 2, 4, 1, 1);


    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);

    gtk_widget_show_all(window);

    gtk_main();
    

    
}

static void button_history_clicked(GtkWidget *widget, gpointer data)
{

    char types[MAX_NUMBER_OF_TYPES][30];
    int number_of_types;
    number_of_types = read_types_of_objects(types); // Liczba typow obiektow mozliwych do zarezerwowania

    for (int p = 0; p < number_of_types; p++)
    {
        g_print("%s\n", types[p]);
    }

    int argc;
    char **argv;
    Time date;
    GtkWidget *grid, *window, *label_type, *label_feature, *label_model, *label_title, *button_show;
    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 20);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    date.cyclic = false;

    

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Historia Rezerwacji");
    gtk_window_set_default_size(GTK_WINDOW(window), 800, 200);
    g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    label_title = gtk_label_new("Historia Rezerwacji");
    label_type = gtk_label_new("Rodzaj:");
    label_feature = gtk_label_new("Cecha:");
    label_model = gtk_label_new("Model:");
    button_show = gtk_button_new_with_label("Pokaż");

    date.combo_box_type = gtk_combo_box_text_new();
    date.combo_box_feature = gtk_combo_box_text_new();
    date.combo_box_model = gtk_combo_box_text_new();
    date.scrolled_window = gtk_scrolled_window_new(0, 0);
    

    date.text_view = gtk_text_view_new();
    date.text_buffer = gtk_text_view_get_buffer(GTK_TEXT_VIEW(date.text_view));
    gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(date.text_view), GTK_WRAP_WORD);
    date.scrolled_window = gtk_scrolled_window_new (NULL, NULL);
    gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(date.scrolled_window), GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);
 

    for (int i = 0; i < number_of_types; i++)
    {
         gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date.combo_box_type), NULL, types[i]);
    }

    // gtk_combo_box_set_active(GTK_COMBO_BOX(date.combo_box_type), 0);
    // gtk_combo_box_set_active(GTK_COMBO_BOX(date.combo_box_model), 0);

     gtk_container_add (GTK_CONTAINER (date.scrolled_window), date.text_view);
     gtk_container_set_border_width (GTK_CONTAINER (date.scrolled_window), 5);
     

     
    
    
    g_signal_connect(date.combo_box_type, "changed", G_CALLBACK(on_changed_type), (gpointer)&date);
    g_signal_connect(date.combo_box_feature, "changed", G_CALLBACK(history_on_changed_feature), (gpointer)&date);
    g_signal_connect(button_show, "clicked", G_CALLBACK(history_button_show_clicked), (gpointer)&date);


    
    gtk_grid_attach(GTK_GRID(grid), label_title, 3, 0, 2, 1);
    gtk_grid_attach(GTK_GRID(grid), label_type, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_feature, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_model, 1, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.combo_box_type, 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.combo_box_feature, 2, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.combo_box_model, 2, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_show, 2, 4, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window, 3, 1, 4, 4);

    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);

    gtk_widget_show_all(window);

    gtk_main();

}

static void button_week_clicked(GtkWidget *widget, gpointer data)
{
     char months[13][25]={"a","Styczen","Luty","Marzec","Kwiecien","Maj","Czerwiec","Lipiec","Sierpien","Wrzesien","Pazdziernik",
    "Listopad","Grudzien"};

    char name_of_month[20];

    int argc;
    char **argv;
    Time date;
    GtkWidget *grid, *window, *label_month, *label_monday, *button_show, *label_day[7], *label_title;
    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 20);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    date.cyclic = false;

    

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Tygodniowy Plan");
    gtk_window_set_default_size(GTK_WINDOW(window), 1200, 300);
    g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    date.combo_box_month_from = gtk_combo_box_text_new();
    date.combo_box_day_from=gtk_combo_box_text_new();

    for (int i = 1; i <= 12; i++)       // wypelnienie nazwami miesiecy
        {
            strcpy(name_of_month, months[i]);
            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date.combo_box_month_from), NULL, name_of_month);
        }


                                                                    //Okna dla dni tygodnia
    date.scrolled_window_day[0] = gtk_scrolled_window_new(NULL, NULL);
    date.scrolled_window_day[1] = gtk_scrolled_window_new(NULL, NULL);
    date.scrolled_window_day[2] = gtk_scrolled_window_new(NULL, NULL);
    date.scrolled_window_day[3] = gtk_scrolled_window_new(NULL, NULL);
    date.scrolled_window_day[4] = gtk_scrolled_window_new(NULL, NULL);
    date.scrolled_window_day[5] = gtk_scrolled_window_new(NULL, NULL);
    date.scrolled_window_day[6] = gtk_scrolled_window_new(NULL, NULL);

    for (int i = 0; i < 7; i++)
    {
        date.text_view_day[i] = gtk_text_view_new();
        date.text_buffer_day[i] = gtk_text_view_get_buffer(GTK_TEXT_VIEW(date.text_view_day[i]));
        gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(date.text_view_day[i]), GTK_WRAP_WORD);
        date.scrolled_window_day[i] = gtk_scrolled_window_new(NULL, NULL);
        gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(date.scrolled_window_day[i]), GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);

        gtk_container_add (GTK_CONTAINER (date.scrolled_window_day[i]), date.text_view_day[i]);
        gtk_container_set_border_width (GTK_CONTAINER (date.scrolled_window_day[i]), 5);
    }

    label_title = gtk_label_new("Dostepne przedmioty");
    label_month = gtk_label_new("Miesiac:");
    label_monday = gtk_label_new("Poczatek tygodnia:");

    label_day[0] = gtk_label_new("Pon");
    label_day[1] = gtk_label_new("Wt");
    label_day[2] = gtk_label_new("Sr");
    label_day[3] = gtk_label_new("Czw");
    label_day[4] = gtk_label_new("Pt");
    label_day[5] = gtk_label_new("Sob");
    label_day[6] = gtk_label_new("Nie");
    button_show = gtk_button_new_with_label("Pokaz");

    g_signal_connect(date.combo_box_month_from, "changed", G_CALLBACK(week_on_changed_month), (gpointer)&date);
    g_signal_connect(date.combo_box_day_from, "changed", G_CALLBACK(week_on_changed_day), (gpointer)&date);
    g_signal_connect(button_show, "clicked", G_CALLBACK(week_button_show_clicked), (gpointer)&date);
    

    //Dolaczanie labeli z nazwami dni tygodnia tytulu i tytulow wyboru
    gtk_grid_attach(GTK_GRID(grid), label_title, 6, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_month, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_monday, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_day[0], 3, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_day[1], 4, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_day[2], 5, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_day[3], 6, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_day[4], 7, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_day[5], 8, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_day[6], 9, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_show, 2, 3, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), date.combo_box_month_from, 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.combo_box_day_from, 2, 2, 1, 1);

    // Dolaczanie pol widoku z przedmiotami dostepnymi w kazdym dniu
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day[0], 3, 3, 1, 7);
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day[1], 4, 3, 1, 7);
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day[2], 5, 3, 1, 7);
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day[3], 6, 3, 1, 7);
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day[4], 7, 3, 1, 7);
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day[5], 8, 3, 1, 7);
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day[6], 9, 3, 1, 7);


    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);

    gtk_widget_show_all(window);

    gtk_main();

}

static void button_week_booked_clicked(GtkWidget *widget, gpointer data)
{
     char months[13][25]={"a","Styczen","Luty","Marzec","Kwiecien","Maj","Czerwiec","Lipiec","Sierpien","Wrzesien","Pazdziernik",
    "Listopad","Grudzien"};

    char name_of_month[20];

    int argc;
    char **argv;
    Time date;
    GtkWidget *grid, *window, *label_month, *label_monday, *button_show, *label_day[7], *label_title, *label_hour[7], *label_sep[7];
    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 10);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 20);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);
    date.cyclic = false;

    

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "Tygodniowy Plan");
    gtk_window_set_default_size(GTK_WINDOW(window), 1400, 1000);
    g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    date.combo_box_month_from = gtk_combo_box_text_new();
    date.combo_box_day_from=gtk_combo_box_text_new();

    for (int i = 1; i <= 12; i++)       // wypelnienie nazwami miesiecy
        {
            strcpy(name_of_month, months[i]);
            gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(date.combo_box_month_from), NULL, name_of_month);
        }


  /*                                                                  //Okna dla dni tygodnia
    date.scrolled_window_day[0] = gtk_scrolled_window_new(NULL, NULL);
    date.scrolled_window_day[1] = gtk_scrolled_window_new(NULL, NULL);
    date.scrolled_window_day[2] = gtk_scrolled_window_new(NULL, NULL);
    date.scrolled_window_day[3] = gtk_scrolled_window_new(NULL, NULL);
    date.scrolled_window_day[4] = gtk_scrolled_window_new(NULL, NULL);
    date.scrolled_window_day[5] = gtk_scrolled_window_new(NULL, NULL);
    date.scrolled_window_day[6] = gtk_scrolled_window_new(NULL, NULL);
*/


    for (int i = 0; i < 7; i++)
    {
        label_sep[i] = gtk_label_new(" ");
        for (int j = 0; j < 7; j++)
        {

            date.scrolled_window_day_booked[i][j] = gtk_scrolled_window_new(NULL, NULL);

            date.text_view_day_booked[i][j] = gtk_text_view_new();
            date.text_buffer_day_booked[i][j] = gtk_text_view_get_buffer(GTK_TEXT_VIEW(date.text_view_day_booked[i][j]));
            gtk_text_view_set_wrap_mode(GTK_TEXT_VIEW(date.text_view_day_booked[i][j]), GTK_WRAP_WORD);
            date.scrolled_window_day_booked[i][j] = gtk_scrolled_window_new(NULL, NULL);
            gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(date.scrolled_window_day_booked[i][j]), GTK_POLICY_ALWAYS, GTK_POLICY_ALWAYS);

            gtk_container_add (GTK_CONTAINER (date.scrolled_window_day_booked[i][j]), date.text_view_day_booked[i][j]);
            gtk_container_set_border_width (GTK_CONTAINER (date.scrolled_window_day_booked[i][j]),25);
            
        }
    }

    label_title = gtk_label_new("Zarezerwowane przedmioty");
    label_month = gtk_label_new("Miesiac:");
    label_monday = gtk_label_new("Poczatek tygodnia:");

    label_day[0] = gtk_label_new("Pon");
    label_day[1] = gtk_label_new("Wt");
    label_day[2] = gtk_label_new("Sr");
    label_day[3] = gtk_label_new("Czw");
    label_day[4] = gtk_label_new("Pt");
    label_day[5] = gtk_label_new("Sob");
    label_day[6] = gtk_label_new("Nie");
    label_hour[0] = gtk_label_new("7:00 - 9:00");
    label_hour[1] = gtk_label_new("9:00 - 11:00");
    label_hour[2] = gtk_label_new("11:00 - 13:00");
    label_hour[3] = gtk_label_new("13:00 - 15:00");
    label_hour[4] = gtk_label_new("15:00 - 17:00");
    label_hour[5] = gtk_label_new("17:00 - 19:00");
    label_hour[6] = gtk_label_new("19:00 - 21:00");
    button_show = gtk_button_new_with_label("Pokaz");

    g_signal_connect(date.combo_box_month_from, "changed", G_CALLBACK(week_on_changed_month), (gpointer)&date);
    g_signal_connect(date.combo_box_day_from, "changed", G_CALLBACK(week_on_changed_day), (gpointer)&date);
    g_signal_connect(button_show, "clicked", G_CALLBACK(week_booked_button_show_clicked), (gpointer)&date);
    

    //Dolaczanie labeli z nazwami dni tygodnia tytulu i tytulow wyboru
    gtk_grid_attach(GTK_GRID(grid), label_title, 6, 0, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_month, 1, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_monday, 1, 2, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_day[0], 3, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_day[1], 4, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_day[2], 5, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_day[3], 6, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_day[4], 7, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_day[5], 8, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), label_day[6], 9, 3, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_show, 2, 3, 1, 1);

   // gtk_grid_attach(GTK_GRID(grid), label_hour[0], 1, 3, 1, 1);

    gtk_grid_attach(GTK_GRID(grid), date.combo_box_month_from, 2, 1, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), date.combo_box_day_from, 2, 2, 1, 1);

    // Dolaczanie pol widoku z przedmiotami dostepnymi w kazdym dniu
    /*
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day[0], 3, 3, 1, 7);
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day[1], 4, 3, 1, 7);
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day[2], 5, 3, 1, 7);
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day[3], 6, 3, 1, 7);
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day[4], 7, 3, 1, 7);
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day[5], 8, 3, 1, 7);
    gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day[6], 9, 3, 1, 7);
    */
  // gtk_grid_attach(GTK_GRID(grid), label_sep[0], 2, 4, 7, 5);
    int p = 0;
    // Dolaczanie okien 
    for (int i = 0; i < 7; i++)
    {
        p = 0;
        gtk_grid_attach(GTK_GRID(grid), label_hour[i], 2, 2*i+5, 1, 1);
        
        for (int j = 0; j < 7; j++)
        {

            gtk_grid_attach(GTK_GRID(grid), date.scrolled_window_day_booked[i][j], i + 3, j + 4 + p, 1, 3);
            p++;
        }

    }
   
    gtk_container_add(GTK_CONTAINER(window), grid);
    gtk_container_set_border_width(GTK_CONTAINER(window), 20);

    gtk_widget_show_all(window);

    gtk_main();



}
