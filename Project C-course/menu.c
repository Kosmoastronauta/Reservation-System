#include <gtk/gtk.h>
#include "menu_functions.h"
#include "menu_functions.c"
//#include "date_functions.c"
#include "menu.h"
//Mateusz Gil
void show_my_menu(int argc, char *argv[])
{
    gtk_init(&argc, &argv);
    GtkWidget *window, *label, *button_reserv, *button_add, *button_remove, *button_history, *button_exit, *button_week, *button_booked_week;
    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(window), "System rezerwacji sprzetu");
    gtk_window_set_default_size(GTK_WINDOW(window), (gint)100, (gint)300);
    g_signal_connect(window, "delete_event", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget *grid;
    grid = gtk_grid_new();
    gtk_grid_set_row_spacing(GTK_GRID(grid), 20);
    gtk_grid_set_row_homogeneous(GTK_GRID(grid), TRUE);
    gtk_grid_set_column_spacing(GTK_GRID(grid), 30);
    gtk_grid_set_column_homogeneous(GTK_GRID(grid), TRUE);

    label = gtk_label_new("Menu");
    button_reserv = gtk_button_new_with_label("Rezerwacja");
    button_add = gtk_button_new_with_label("Dodaj urzadzenie");
    button_remove = gtk_button_new_with_label("Usun urzadzenie");
    button_history = gtk_button_new_with_label("Historia rezerwacji");
    button_week = gtk_button_new_with_label("Wolne urzadzenia");
    button_exit = gtk_button_new_with_label("Wyjscie");
    button_booked_week = gtk_button_new_with_label("Plan tydzien");

    gtk_grid_attach(GTK_GRID(grid), label, 1, 1, 3, 1);
    gtk_grid_attach(GTK_GRID(grid), button_reserv, 2, 6, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_add, 2, 7, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_remove, 2, 8, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_history, 2, 9, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_week, 2, 10, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_booked_week, 2, 11, 1, 1);
    gtk_grid_attach(GTK_GRID(grid), button_exit, 2, 12, 1, 1);

    g_signal_connect(button_reserv, "clicked", G_CALLBACK(button_reserv_clicked),NULL);
    g_signal_connect(button_add, "clicked", G_CALLBACK(button_add_clicked), NULL);
    g_signal_connect(button_remove, "clicked", G_CALLBACK(button_remove_clicked), NULL);
    g_signal_connect(button_history, "clicked", G_CALLBACK(button_history_clicked), NULL);
    g_signal_connect(button_week, "clicked", G_CALLBACK(button_week_clicked), NULL);
    g_signal_connect(button_booked_week, "clicked", G_CALLBACK(button_week_booked_clicked), NULL);
    g_signal_connect(button_exit, "clicked", G_CALLBACK(gtk_main_quit), NULL);


    gtk_container_add(GTK_CONTAINER(window), grid);

    gtk_container_set_border_width(GTK_CONTAINER(window), 15);

    gtk_widget_show_all(window);
    gtk_main();
   
}
