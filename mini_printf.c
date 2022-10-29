/*
** EPITECH PROJECT, 2022
** mini_printf
** File description:
** mini_printf
*/
#include <stdarg.h>
#include <stdio.h>
#include "include/my.h"

int condit(va_list list,const char *format,int i)
{
    if (format[i] == 's') {
        my_putstr(va_arg(list, char *));
    }
    if (format[i] == 'c') {
        my_putchar(va_arg(list, char));
    }
    if (format[i] == 'i' || format[i] == 'd') {
        my_putnbr(va_arg(list, int));
    }
    if (format[i] == '%') {
        my_putchar('%');
    }
}

int mini_printf(const char * format , ...)
{
    va_list list;
    va_start(list, format);
    int length = my_strlen(format);
    int i = 0;
    int compteur = 0;
    while (format[i] != '\0') {
        if (format[i] == '%') {
            i++;
            condit(list, format ,i);
            i++;
        }else {
            my_putchar(format[i]);
            i++;
        }
    }
    while (compteur != format[i]) {
        compteur = compteur + my_strlen(va_arg(list, char *));
        compteur++;
    }
    return (compteur);
    va_end(list);
}
