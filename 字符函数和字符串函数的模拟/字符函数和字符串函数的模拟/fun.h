#ifndef _FUN_H_
#define _FUN_H_
#include <stdio.h>
#include <assert.h>
unsigned int my_strlen(const char *str);
unsigned int my_strlen1(const char *str);
char* my_strcpy(char *destination, const char* source);
char* my_strncpy(char* destination, const char* source, size_t count);
char* my_strcat(char* destination, const char* source);
char* my_strncat(char* destination, const char* source, size_t count);
int my_strcmp(const char* str1, const char* str2);
int my_strncmp(const char* str1, const char* str2, size_t count);
char* my_strstr(const char* str1, const char* str2);
void* my_memcpy(void* dest, const void* source, unsigned int count);
void* my_memmove(void* dest, const char* src, unsigned int count);
#endif