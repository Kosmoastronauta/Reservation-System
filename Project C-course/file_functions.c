#include <stdio.h>
#include <gtk/gtk.h>
#include <string.h>
#include <stdlib.h>
#include "file_functions.h"
#include "structures.h"
#include "date_functions.h"
#include <stdbool.h>
// Mateusz Gil

int read_types_of_objects( char types[][30])
{

    FILE *file_pointer;
    int number_of_types = 0;
    file_pointer = fopen("types_of_objects.txt", "r");
    if (file_pointer == NULL)
    {
        fprintf(stderr, "Nie udalo sie w odczytac pliku ");
    }
    
    else
        {
            int i = 0;
            int j = 0;
            char temp;

            

            while(!feof(file_pointer))
            {
                temp = fgetc(file_pointer);
                if(temp!='\n')
                {
                    types[i][j] = temp;
                    j++;
                }
                else
                {
                    types[i][j] = '\0';
                    i++;
                    j = 0;
                    number_of_types++;
                }
            }

        

            
            return number_of_types;

        }
        fclose(file_pointer);
        return number_of_types;
}

int read_object(char type[30], char features[][30])
{
    char name_of_file[40];
    sprintf(name_of_file, "%s-feature.txt", type);
    FILE *file_pointer;

    file_pointer = fopen(name_of_file, "r");
   
    if (file_pointer == NULL)
    {
        fprintf(stderr, "Nie udalo sie w odczytac pliku ");
    }

     else
     {
        int i = 0;
        int j = 0;
        char temp;

        int number_of_features = -1;

            while(!feof(file_pointer))
            {
                temp = fgetc(file_pointer);
                if(temp!='\n')
                {
                    features[i][j] = temp;
                    j++;
                }
                else
                {
                    features[i][j] = '\0';
                    i++;
                    j = 0;
                    number_of_features++;
                }
            }

            
            return number_of_features+1;

     }
    fclose(file_pointer);

}


int read_objects_with_type(char name_of_file[30], char avaliable[][30], int start_of_reservation, int end_of_reservation, bool history, char models[30][30])
{
    int row_of_avaliable = 0;
    int number_of_models = 0;
    FILE *file_pointer;
    file_pointer = fopen(name_of_file, "r");

    if (file_pointer == NULL)
    {
        fprintf(stderr, "Nie udalo sie w odczytac pliku ");
    }

    else
    {
      //  fprintf(stderr, "Yolo jestem");
        int i = 0;
        int j = 0;
        int line = 1;
        
        int number_of_reservations = 0;
        int temp_start = 0;
        int temp_end = 0;
        bool possible = 1;
        char temp = 'a';
        char temp2;
        char name_of_object[30][30];
        

        while (!feof(file_pointer))
        {
         
        //   temp = fgetc(file_pointer);
               while(temp!='\n')
               {
                    temp = fgetc(file_pointer);
                    if(feof(file_pointer))
                    {
                        fclose(file_pointer);
                        return row_of_avaliable;
                    }

                    if (temp != '\n')
                    {
                        name_of_object[i][j] = temp;
                        j++;
                    }
                        else
                        {
                            name_of_object[i][j] = '\0';
                            i++;
                            j = 0;
                        }
               }
        
               
                fscanf(file_pointer, "%d", &number_of_reservations);
                if(number_of_reservations==0)
                {   


                    while(temp2!='\n')
                    {
                        temp2 = fgetc(file_pointer);
                    }
                     //temp2 = 'a';
                    //fscanf(file_pointer, "%c", &temp2);
                    //fscanf(file_pointer, "%c", &temp2);
                    possible = true;

                    
                    
                    
                }

                else
                {   

                    while(temp2!='\n')
                    {
                        temp2 = fgetc(file_pointer);
                    }
                    //temp2 = 'a';

                    possible = true;

                    if(name_of_object[i-1][0]>='A' && name_of_object[i-1][0]<='z')
                    {
                        for (int p = 0; p < number_of_reservations; p ++)
                        {
                            fscanf(file_pointer, "%d", &temp_start);
                            fscanf(file_pointer, "%d", &temp_end);
                            g_print("%s\n", name_of_object[i - 1]);
                            g_print("start: %d \n", temp_start);
                            g_print("end: %d\n", temp_end);

                            if((temp_start>=start_of_reservation && temp_start<=end_of_reservation) || (temp_end>=start_of_reservation && temp_end<=end_of_reservation) || (temp_start<=start_of_reservation && temp_end>=end_of_reservation))
                            {
                                possible = false;
                                //g_print("%s\n", name_of_object[i - 1]);
                                //g_print("start: %d \n", temp_start);
                                //g_print("end: %d\n", temp_end);
                            }
                            //temp_start 
                        }
                    }

                   
                    
                }

                 if(possible)
                    {
                        if(name_of_object[i-1][0]>='A' && name_of_object[i-1][0]<='z')
                        {
                        sprintf(avaliable[row_of_avaliable], "%s", name_of_object[i - 1]);
                        row_of_avaliable++;
                        g_print("\n\n");
                        g_print("Dostepny: %s\n", name_of_object[i - 1]);
                        g_print("\n\n");
                        }
                        
                    }

                    if(history)
                    {
                        if(name_of_object[i-1][0]>='A' && name_of_object[i-1][0]<='z')
                            {
                                sprintf(models[number_of_models], "%s", name_of_object[i - 1]);
                                number_of_models++;

                                g_print("Models: %s\n",models[number_of_models-1]);
                            }
                    }
                

                
           // }

          //  line++;
               temp = 'a';
        }
        fclose(file_pointer);
    }
    

          //fclose(file_pointer);
          //rewind(file_pointer);
          if (history)
              return number_of_models;

          else
          {
              return row_of_avaliable;
          }
            
        
}

int save_reservation(char month_from[30], char day_from[30], char month_to[30], char day_to[30], char name_of_type[30], char name_of_file[80], char name_of_reserved[30], int start_of_reservation, int end_of_reservation, char comment[100], char name[30], char lastname[30], char mail[30],bool remove)
{

    FILE *fp;
    fp = fopen(name_of_file, "r+");

    if(fp==NULL)
    {
        fprintf(stderr, "Nie udalo sie w odczytac pliku ");
    }
    else
    {
       

            int i = 0;
            int j = 0;
            char temp;
            int temp1, temp2;
            char types[15][30];
            char spaces[3];
            spaces[0]='a';
            spaces[1]='a';
            spaces[2]='a';
            long int position;
            int number_of_types = 0;
            int number_of_reservations=0;
            int start, end;
            int reserv[50];
            bool done = false;
            // int k;

            while(!feof(fp))
            {
                temp = fgetc(fp);
                if(temp!='\n')
                {
                    types[i][j] = temp;int number_of_types = 0;
                    j++;
                }
                else
                {
                    types[i][j] = '\0';
                    if(!strcmp(name_of_reserved,types[i]))
                    {
                        fscanf(fp,"%d",&number_of_reservations);

                        if(number_of_reservations==0)
                        {
                            fseek(fp,-1,1);
                            fprintf(fp,"%d\n",number_of_reservations+1);

                            fprintf(fp, "%d %d", start_of_reservation, end_of_reservation);

                            done = true;
                        }

                        if(number_of_reservations>9)
                        {
                           fseek(fp,-2,1);
                            fprintf(fp,"%d\n",number_of_reservations+1);
                           // fprintf(fp,"\n");
                        }

                        if(number_of_reservations<10 && number_of_reservations>0)
                        {
                            fseek(fp,-1,1);
                            fprintf(fp,"%d\n",number_of_reservations+1);
                           // fprintf(fp,"\n");
                        }

                        if(!done)
                        {
                            // fseek(fp,2,1);
                            temp = 'a';
                            position=ftell(fp);
                            //  fprintf(fp,"moja");
                            spaces[0]='a';
                            spaces[1]='a';

                            for (int k = 0; k < number_of_reservations; k++)
                            {
                                fscanf(fp, "%d %d", &temp1, &temp2);
                                
                            }
                            //fseek(fp, -1, 1);
                            fprintf(fp, " %d %d", start_of_reservation, end_of_reservation);
                            g_print("%d %d", start_of_reservation, end_of_reservation);

                        }
                        break;


                    }

                    i++;
                    j = 0;
                    number_of_types++;
                }
            }




   fclose(fp);

    FILE *file_info, *file_email;
    char info_file_name[60];
    sprintf(info_file_name, "%s-%s.txt", name_of_type, name_of_reserved);
    file_info = fopen(info_file_name, "a+");

    if(file_info==NULL)
    {
            fprintf(stderr, "Nie udalo sie w odczytac pliku ");
    }

    fprintf(file_info, "Od: %s, %s Do: %s,%s\n", month_from, day_from, month_to, day_to);
    fprintf(file_info, "Imie: %s, Nazwisko: %s\n", name, lastname);
    fprintf(file_info, "Email: %s\n", mail);
    fprintf(file_info, "Komentarz: %s\n\n", comment);

    fclose(file_info);
    /*
    file_email = fopen("email.txt", "w");
    fprintf(file_email, "Subject: Reservation\n\n");
    fprintf(file_email, "Przedmiot: %s, %s", name_of_type, name_of_reserved);
    */
    }

    return 0;
}

void existing_types(GtkWidget *widget)
{
    FILE *file_pointer;
    file_pointer = fopen("types_of_objects.txt", "r");
    
    if(file_pointer==NULL)
    {
        fprintf(stderr, "Nie udalo sie w odczytac pliku ");
    }

    else
    {
                int i = 0;
                int j = 0;
                char temp;
                char types[15][30];

                int number_of_types = 0;

                while(!feof(file_pointer))
                {
                    temp = fgetc(file_pointer);
                    if(temp!='\n')
                    {
                        types[i][j] = temp;
                        j++;
                    }
                    else
                    {
                        types[i][j] = '\0';
                        gtk_combo_box_text_append(GTK_COMBO_BOX_TEXT(widget), NULL, types[i]);
                        i++;
                        j = 0;
                        number_of_types++;
                    }
                }

             gtk_combo_box_set_active(GTK_COMBO_BOX(widget), 0);

             fclose(file_pointer);
    }

    
}

void add_with_new_type(char name_of_type[30], char name_of_feature[30], char name_of_model[30], char name_of_kind_of_feature[30])
{
    FILE *file_types_of_objects, *file_type, *file_features, *file_model;
    file_types_of_objects = fopen("types_of_objects.txt", "a");
    char name_of_file_types[60];
    char name_of_file_features[60];

    if(file_types_of_objects==NULL)
    {
        fprintf(stderr, "Nie udalo sie w odczytac pliku ");
    }

    else
    {   // Dopisanie rodzaju przedmiotu do wszystkich rodzajow
        fprintf(file_types_of_objects, "%s\n", name_of_type);
        g_print("nDopisuje rodzaj\n");
    }

    // Plik typ-features zawierajacy cechy dla rodzaju
    sprintf(name_of_file_features, "%s-feature.txt", name_of_type);         
    file_features = fopen(name_of_file_features, "ab+");
    fprintf(file_features, "%s\n", name_of_kind_of_feature);
    fprintf(file_features, "%s\n", name_of_feature);
    // fprintf(file_features, "\n");

    // Plik typ-nazwarodzaju zawierajacy modele z ta cecha
    sprintf(name_of_file_types, "%s-%s.txt", name_of_type, name_of_feature);
    file_model = fopen(name_of_file_types, "ab+");
    fprintf(file_model, "%s\n", name_of_model);
    fprintf(file_model, "0\n");
    for (int i = 0; i < 70; i++)
    {
        fprintf(file_model, " ");
    }
    fprintf(file_model, "\n");
    

    fclose(file_types_of_objects);
    fclose(file_features);
    fclose(file_model);
    
}  

void add_with_existing_type_new_feature(char name_of_type[30], char name_of_feature[30], char name_of_model[30])
{
    FILE *file_features, *file_model;
    char name_of_file_features[60];
    char name_of_file_types[60];
    sprintf(name_of_file_features, "%s-feature.txt", name_of_type);         
    file_features = fopen(name_of_file_features, "a");
    fprintf(file_features, "%s\n", name_of_feature);

    // Plik typ-nazwarodzaju zawierajacy modele z ta cecha
    sprintf(name_of_file_types, "%s-%s.txt", name_of_type, name_of_feature);
    file_model = fopen(name_of_file_types, "ab+");
    fprintf(file_model, "%s\n", name_of_model);
    fprintf(file_model, "0\n");
    for (int i = 0; i < 70; i++)
    {
        fprintf(file_model, " ");
    }
    fprintf(file_model, "\n");

    fclose(file_features);
    fclose(file_model);
}


int add_with_existing_type_existing_feature(char name_of_type[30], char name_of_feature[30], char name_of_model[30])
{


                                
            int i = 0;
            int j = 0;
            char temp;
            char models[15][30];
            int number_of_types = 0;
            bool exists = 0;
            char name_of_file_model[30];

            sprintf(name_of_file_model, "%s-%s.txt", name_of_type, name_of_feature);
            g_print("typ: %s cecha: %s", name_of_type, name_of_feature);
            FILE *file_model;
            file_model = fopen(name_of_file_model, "r");

            if(file_model==NULL)
             {
                 fprintf(stderr, "Nie udalo sie w odczytac pliku ");
             }

             else
             {
                    
                
                

                // Sprawdzenie czy taki przedmiot juz nie istnieje
                while (!feof(file_model))
                {
                    temp = fgetc(file_model);
                    if(temp!='\n')
                    {
                        models[i][j] = temp;
                        j++;
                    }
                    else
                    {
                        models[i][j] = '\0';
                        if(strcmp(models[i],name_of_model)==0)
                        {
                            exists = 1;
                            break;
                        }
                        i++;
                        j = 0;
                        number_of_types++;
                    }
                }

                if(exists)
                {
                    g_print("Juz taki sprzet istnieje");
                    fclose(file_model);
                    return 1;
                }

                else
                {
                   // g_print("Zapisuje");
                    fclose(file_model);
                    file_model = fopen(name_of_file_model, "a");

                    if(file_model==NULL)
                    {
                        fprintf(stderr, "Nie udalo sie w odczytac pliku przy zapisie");
                    }
                    else
                    {
                        g_print("Zapisuje do: %s",name_of_file_model);
                    fprintf(file_model, "%s\n", name_of_model);
                    fprintf(file_model, "0\n");
                    for (int i = 0; i < 70; i++)
                    {
                        fprintf(file_model, " ");
                    }
                    fprintf(file_model, "\n");
                    fprintf(file_model, "\n");
                    }
                }

             }

             fclose(file_model);

             return 0;
}

int read_info(char info[200][101], char name_of_file[80])
{
    FILE *fp;
    fp = fopen(name_of_file, "r");
    g_print("%s", name_of_file);
    int i = 0;
    int j = 0;
    char temp = 'a';
    if (fp == NULL)
    {
        fprintf(stderr, "Nie udalo sie w odczytac pliku ");
        return 0;
    }

    else
    {
        while(!feof(fp))
        {
            //g_print("jestem");
            while (temp != '\n')
            {
                
                
                temp = fgetc(fp);

                if(feof(fp))
                {
                    return i;
                }

                if(temp!='\n')
                {
                    info[i][j] = temp;
                    j++;
                }

                else
                {
                    info[i][j] = '\0';
                    g_print("%s\n", info[i]);
                    temp = 'a';
                    i++;
                    j = 0;
                }
            }
        }
        return i;

        fclose(fp);
    }

    // fclose(fp);  Tutaj bylo tylko to
    
}

int remove_object(char type[30], char feature[30], char model[30])
{
    char name_of_file[80];
    char name_of_file2[80];
    sprintf(name_of_file, "%s-%s.txt", type, feature);
    FILE *fp;
    FILE *fp2;
    fp = fopen(name_of_file, "r");
    int del_info;
    char info_file[30];
    sprintf(info_file, "%s-%s.txt", type, model);

    sprintf(name_of_file2, "%s-%s2.txt", type, feature);

    fp2 = fopen(name_of_file2, "w+");
    int new_lines = 0;
    int i = 0, j = 0;

   

    if(fp==NULL)
    {
        fprintf(stderr, "Nie udalo sie w odczytac pliku ");
    }

    else
    {

        
        char temp='a';
        char object[30][200];
        while (!feof(fp))
        {
             temp = 'a';
            g_print("jestem");
             if(feof(fp))
                {
                    fclose(fp);
                    fclose(fp2);
                    del_info = remove(name_of_file);
                    del_info = rename(name_of_file2, name_of_file);
                    del_info = remove(info_file);
                    return 0;
                }

            while (temp != '\n')    // Czytanie linii
            {
                if(feof(fp))
                {
                    fclose(fp);
                    fclose(fp2);
                    del_info = remove(name_of_file);
                    del_info = rename(name_of_file2, name_of_file);
                    return 0;
                }

                temp = fgetc(fp);
                if(temp!='\n')
                {
                    object[i][j] = temp;
                    j++;
                }

                else
                {
                    object[i][j] = '\0';
                    i++;
                    j = 0;
                }
            }
                // Wczytano nowa linie

                if(feof(fp))
                {
                    fclose(fp);
                    fclose(fp2);
                    del_info = remove(name_of_file);
                    del_info = rename(name_of_file2, name_of_file);
                    return 0;
                }

                if(strcmp(object[i-1],model)==0) // Czy napotkalem na obiekt do usuniecia
                {
                    
                    temp = 'a';

                    while(new_lines<2) 
                    {
                        temp = fgetc(fp);
                        if(temp=='\n')
                        {
                            new_lines++;
                            temp = 'a';

                        }
                    }

                   
                }

                else
                {
                    g_print("\nmam %s",object[i-1]);
                    fprintf(fp2, "%s\n", object[i-1]);
                   // fprintf(fp2, "asdasdsadas\n");
                }

                 if(feof(fp))
                {
                    
                    fclose(fp);
                    fclose(fp2);
                    del_info = remove(name_of_file);
                    del_info = rename(name_of_file2, name_of_file);
                    return 0;
                }
        }
        
    }

    fclose(fp);
    fclose(fp2);
    del_info = remove(name_of_file);
    del_info = rename(name_of_file2, name_of_file);

    return 0;
}

int file_number_of_reservations(char name_of_type[30], char name_of_feature[30], char name_of_model[30])
{
    char name_of_file[60];
    sprintf(name_of_file, "%s-%s.txt", name_of_type, name_of_feature);
    char info[30][200];

    FILE *fp;
    fp = fopen(name_of_file, "r");
    int i = 0, j = 0;
    char temp = 'a';
    int number_of_reservations = 0;
    int temp2;
    if (fp == NULL)
    {
         fprintf(stderr, "Nie udalo sie w odczytac pliku ");
    }

    else
    {
       
        while (!feof(fp))
        {
            //g_print("jestem");
            temp = 'a';
            while (temp != '\n')
            {
                temp = fgetc(fp);
                if(temp!='\n')
                {
                    info[i][j] = temp;
                    j++;
                }

                else
                {
                    info[i][j] = '\0';
                    i++;
                    j = 0;
                }
            }   
            

            if(strcmp(name_of_model,info[i-1])==0)
            {
                fscanf(fp, "%d", &number_of_reservations);
                fclose(fp);
                return number_of_reservations;
            }

           
        }
    }

    fclose(fp);
    return -1;
}

int file_week_avaliable(char month[20], char day[2], char avaliable_on_day[70][60], int start_of_reservation, int end_of_reservation)
{
    char types[30][30];
    int number_of_types = 0;
    FILE *fp;
    fp = fopen("types_of_objects.txt", "r");
    int i = 0, j = 0;
    char temp = 'a';
    char name_of_file_features[30];
    char name_of_file_models[30];
    char features[30][30];
    int number_of_features;
    char temp_models[30][30];
    char temp_models2[30][30];
    int temp_number_of_avaliable_models = 0;
    int number_of_avaliable = 0;

    if(fp==NULL)
    {
        fprintf(stderr, "Nie udalo sie otworzyc pliku ");
    }

    else
    {
        //g_print("Jestem");
        while (!feof(fp)) // czytanie rodzaji obiektow
        {
            
            while(temp!='\n')
            {
                temp = fgetc(fp);

                if(temp!='\n')
                {
                    if(feof(fp))
                        break;

                    types[i][j] = temp;
                    j++;
                }

                else
                {
                    
                    types[i][j] = '\0';
                    i++;
                    j = 0;
                    number_of_types++;
                    g_print("%s\n", types[i - 1]);
                }
                temp = 'a';
                
            }
        }
        fclose(fp);

        for (int p = 0; p < number_of_types; p++)   // Dla kazdego rodzaju sprzetu
        {
          //  sprintf(name_of_file_features, "%s-%s.txt", types[p]);

            number_of_features = read_object(types[p], features);  // Liczba cech dla tego rodzaju sprzetu

            for (int q = 0; q < number_of_features; q++)    // Dla kazdej cechy
            {
                sprintf(name_of_file_features, "%s-%s.txt", types[p], features[q]);

                // Dla kazdego modelu z ta cecha dodaje jezeli jest dostepny w tym dniu
                temp_number_of_avaliable_models = read_objects_with_type(name_of_file_features, temp_models, start_of_reservation, end_of_reservation, false, temp_models2);

                                                    // Przepisanie do docolewej tablicy dostepnych sprzetu
                for (int s = 0; s < temp_number_of_avaliable_models; s++)
                {
                    sprintf(avaliable_on_day[number_of_avaliable], "%s:\n %s", types[p], temp_models[s]);
                    g_print("%s\n", avaliable_on_day[number_of_avaliable]);
                    number_of_avaliable++;
                }
            }
        }

        
    }

    return number_of_avaliable;
}

int file_get_dates_of_model(char type[30], char model[30], char feature[30], int from[30], int to[30])
{
    FILE *fp;
    char name_of_file[60];
    sprintf(name_of_file, "%s-%s.txt", type, feature);
    fp = fopen(name_of_file, "r");

    char line[200];
    int j = 0;
    char temp = 'a';
    int number_of_reservations = 0;

    if(fp==NULL)
    {
        fprintf(stderr, "Nie udalo sie w odczytac pliku ");
    }

    else
    {
        while(!feof(fp))
        {   
                 temp = 'a';

                 while (temp != '\n')
                 {
                    if(feof(fp))
                     {
                          fclose(fp);
                            return number_of_reservations;
                     }

                     temp = fgetc(fp);

                     if (temp != '\n')
                     {
                         line[j] = temp;
                         j++;
                     }
                     else
                     {
                         line[j] = '\0';
                         j = 0;
                     }
                 }

                     if (strcmp(line, model) == 0)
                     {
                         fscanf(fp, "%d", &number_of_reservations);
                         g_print("\n%d\n", number_of_reservations);

                         if(number_of_reservations==0)
                         {
                             fclose(fp);
                            return number_of_reservations;
                         }

                         for (int i = 0; i < number_of_reservations; i++)
                            {
                                fscanf(fp, "%d %d", &from[i], &to[i]);
                                //fscanf(fp, "%d", &to[i]);

                               // g_print("%d %d\n", from[i], to[i]);
                          
                            }

                            fclose(fp);
                            return number_of_reservations;
                     }

                     if(feof(fp))
                     {
                         fclose(fp);
                         return number_of_reservations;
                     }
                
                
        }
    }

    fclose(fp);
    return number_of_reservations;
}