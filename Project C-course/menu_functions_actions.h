#ifndef MENU_FUNCTIONS_ACTIONS_H
#define MENU_FUNCTIONS_ACTIONS_H
#include <gtk/gtk.h>
#include <string.h>
#include "structures.h"
#include <stdbool.h>

// Mateusz Gil

static void on_changed_month_from(GtkWidget *widget, Time *date);

static void on_changed_day_from(GtkWidget *widget, Time *date);

static void on_changed_month_to(GtkWidget *widget, Time *date);

static void on_changed_day_to(GtkWidget *widget, Time *date);

static void on_changed_hour_to(GtkWidget *widget, Time *date);

static void on_changed_hour_from(GtkWidget *widget, Time *date);

static void on_changed_type(GtkWidget *widget, Time *date);

static void on_changed_feature(GtkWidget *widget, Time *date);

static void button_save_clicked(GtkWidget *widget, Time *date);

static void on_changed_model(GtkWidget *widget, Time *date);

static void on_changed_name(GtkWidget *widget, Time *date);

static void on_changed_last_name(GtkWidget *widget, Time *date);

static void on_changed_email(GtkWidget *widget, Time *date);

static void on_changed_comment(GtkWidget *widget, Time *date);

static void check_button_type_toggled(GtkWidget *widget, Add *date);

static void button_add_save_clicked(GtkWidget *widget, Add *date);

static void check_button_feature_toggled(GtkWidget *widget, Add *date);

static void on_changed_add_existing_type(GtkWidget *widget, Add *date);

static void history_on_changed_feature(GtkWidget *widget, Time *date);

static void history_button_show_clicked(GtkWidget *window, Time *date);

static void remove_button_clicked(GtkWidget *widget, Time *date);

static void week_on_changed_month(GtkWidget *widget, Time *date);

static void week_on_changed_day(GtkWidget *widget, Time *date);

static void week_button_show_clicked(GtkWidget *widget, Time *date);

static void check_button_weekly_toggled(GtkWidget *widget, Time *date);

static void check_button_monthly_toggled(GtkWidget *widget, Time *date);

static void check_button_cyclic_toggled(GtkWidget *widget, Time *date);
#endif