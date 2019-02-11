#ifndef FILE_FUNCTIONS_H
#define FILE_FUNCTIONS_H
#include "structures.h"
#include "date_functions.h"
#include <stdbool.h>
//Mateusz Gil
int read_types_of_objects(char types_of_objects[][30]);

int read_object(char type[30], char features[][30]);

int read_objects_with_type(char name_of_file[30], char avaliable[][30], double start_of_reservation, double end_of_reservation, bool history, char models[30][30], bool booked);

int save_reservation(char month_from[30], char day_from[30], char hour_from[5],char month_to[30], char day_to[30], char hour_to[5] ,char name_of_type[30], char name_of_file[80], char name_of_reserved[30], double start_of_reservation, double end_of_reservation, char comment[100], char name[30], char lastname[30], char mail[30],bool remove);

void existing_types(GtkWidget *widget);

void add_with_new_type(char name_of_type[30], char name_of_feature[30], char name_of_model[30], char name_of_kind_of_feature[30]);

void add_with_existing_type_new_feature(char name_of_type[30], char name_of_feature[30], char name_of_model[30]);

int add_with_existing_type_existing_feature(char name_of_type[30], char name_of_feature[30], char name_of_model[30]);

int read_info(char info[200][101],char name_of_file[80]);

int remove_object(char type[30], char feature[30], char model[30]);

int file_number_of_reservations(char name_of_type[30], char name_of_feature[30], char name_of_model[30]);

int file_week_avaliable(char month[20], char day[2], char avaliable_on_day[70][60], double start_of_reservation, double end_of_reservation);

int file_get_dates_of_model(char type[30], char model[30], char feature[30], double from[30], double to[30]);

int file_week_hour_booked(char month[20], char day[2], char avaliable_on_hour[70][60], double start_of_reservation, double end_of_reservation);

#endif