#include <stdio.h>
#include <stdlib.h>
#include <assert.h>


size_t my_strlen (const char *str)
{
    assert(str != NULL);
    size_t num = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
       num++;
    }
    return num;
}

char *my_strcpy (char *destination, const char *source)
{
    assert(source != NULL);
    assert(destination != NULL);
    int i = 0;
    for( ; i < (my_strlen(source) + 1); i++)
    {
        destination[i] = source[i];
    }
    destination[i] = '\0';
    return destination;
}

char *my_strchr (char *str, char ch)
{
    assert(str != NULL);
    for( ; *str != '\0'; str++)
    {
        if(*str == ch)
        {
            return str;
        }
    }
    return NULL;
}

char *my_strdup(const char *str)
{
    assert(str != NULL);
    char *dup_str = (char *) malloc(my_strlen(str) + 1);
    if (dup_str == NULL)
    {
        return NULL;
    }
    for(int i = 0; i < (my_strlen(str) + 1); dup_str[i] = str[i], i++){};
    return dup_str;
}

char *my_strstr(char *strB, const char *strA)
{
    assert(strA != NULL);
    assert(strB != NULL);
    for (int i = 0; i < my_strlen(strB); i++)
    {
        if  (strB[i] == *strA && (my_strlen(strB) - i) >= my_strlen(strA))
        {
            int j = 0;
            for  ( ; j < my_strlen(strA); j++)
            {
               if (strB[i+j] != strA[j])
               {
                   break;
               }
            }
            if (j == my_strlen(strA))
            {
                return strB+i;
            }
            else
            {
                i += j - 1;
            }
        }
    }
    return NULL;
}

void *my_memchr (void *arr, char c, size_t n)
{
    assert(arr != NULL);
     if (n > my_strlen((char*)arr))
    {
        n = my_strlen((char*)arr);
    }
    for(int i = 0; i < n; i++)
    {
        if(((char *)arr)[i] == c)
        {
            return (((char *)arr) + i);
        }
       (char *)arr == (char *)arr + 1; //?
    }
    return NULL;
}

void *my_memset (void *destination, char c, size_t n)
{
    assert(destination != NULL);
    if (n > my_strlen((char*)destination))
    {
        n = my_strlen((char*)destination);
    }
    for (int i = 0; i < n; i++)
    {
        ((char *)destination)[i] = c;
    }
    return destination;
}

void *my_memcpy (void *destination, const void *source, size_t n)
{
    assert(source != NULL);
    assert (destination != NULL);
    if (n > my_strlen((char*)destination))
    {
        n = my_strlen(((char*) source));
    }
    for(int i = 0; i < n; i++)
    {
        ((char*)destination)[i] = ((char*)source)[i];
    }
    return destination;
}