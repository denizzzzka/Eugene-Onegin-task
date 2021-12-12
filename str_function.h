/**
 * @file str_function.h
 * @author Dan
 * @version 2.0
 * @date 2021-12-12 
 */
#include <stdio.h>

/**
 * calculate the length of a string
 * @param str pointer to string
 * @return he number of bytes in the string pointed to 
 */
size_t my_strlen (const char *str);

/**
 * copy a string
 * @param destination where copy
 * @param source what copy
 * @return functions return a pointer to the destination string
 * @warning If there is no null byte among the first n bytes of src, the string placed in dest will not be null-terminated
 */
char *my_strcpy (char *destination, const char *source);

/**
 * locate character in string
 * @param str where search 
 * @param ch what search
 * @return functions return a pointer to the matched character or NULL if the character is not found
 */
char *my_strchr (char *str, int ch);

/**
 * duplicate a string
 * @param str what duplicate
 * @return a pointer to the duplicated string. It returns NULL if insufficient memory was available 
 */
char *my_strdup(const char *str);

/**
 *  locate a substring
 * @param strB what search
 * @param strA string where search
 * @return a pointer to the beginning of the located substring, or NULL if the substring is not found
 */
char *my_strstr(char *strB, const char *strA);

/**
 * scan memory for a character
 * @param arr string that is scanning 
 * @param c what is search
 * @param n number of scanning bytes
 * @return a pointer to the matching byte or NULL if the character does not occur in the given memory area
 */
void *my_memchr (void *arr, char c, size_t n);

/**
 * fill memory with a constant byte
 * @param destination pointer to string which will be filled 
 * @param c with what will be filled
 * @param n how many cells will be filled
 * @return a pointer to the memory area s.
 */
void *my_memset (void *destination, char c, size_t n);

/**
 * copy memory area
 * @param destination pointer where copy
 * @param source pointer to string from which copy 
 * @param n how many cells copy
 * @return returns a pointer to dest.* 
 */
void *my_memcpy (void *destination, const void *source, size_t n);

