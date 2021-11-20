#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "str_function.h"



int compar  (const void * p1, const void* p2)
{
    return (strcmp(*((char **)p1),*((char **)p2)));
}

int num_str (char * str)
{
    int number_of_string = 0;
    for (int i = 0; i < my_strlen(str); i++)
    {
        if (str[i] == '\n') 
        {
            number_of_string++;
        }
    }
    return number_of_string;
}


int main () {
    FILE * read = fopen("EvgeniyOnegin.txt", "rb");
    fseek (read, 0, SEEK_END);
    size_t file_butes_size = ftell(read);
    fseek (read, 0, SEEK_SET);
    char * very_long_string = (char *) calloc(sizeof(char), file_butes_size);
    if (NULL == very_long_string)
    {
        printf ("too long file");
        return 0;
    }
    fread(very_long_string, sizeof(char), file_butes_size, read);
    char** mas_strings = (char **) calloc(sizeof(char *), num_str(very_long_string));
    if (NULL == mas_strings)
    {
        printf ("too many strings");
        return 0;
    }
    int num_of_str = 0;
    mas_strings[num_of_str] = (&(very_long_string[0]));
    num_of_str++;
    for (int i = 1; i < file_butes_size-1; i++)
    {
        if (very_long_string[i-1] == '\n')
        {
            very_long_string[i-1] = '\0';
            mas_strings[num_of_str] = (&(very_long_string[i]));
            num_of_str++;
        }
    }
    qsort(mas_strings, num_of_str, sizeof(char*), compar);
    FILE * write = fopen("SortedEvgeniyOnegin.txt", "w");
    for (int i = 0; i < num_of_str; i++)
    {
        fprintf(write, "%s", mas_strings[i]);
    }
    
    fclose(write);
    fclose(read);
    free(very_long_string);
    free(mas_strings);
    return 0;
}
