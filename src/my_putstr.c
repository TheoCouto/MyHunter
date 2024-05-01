/*
** EPITECH PROJECT, 2023
** my_putstr
** File description:
** prints a string
*/

#include "../include/my.h"
#include <unistd.h>

int my_putchar(char c)
{
    write(1, &c, 1);
}

int my_putstr(char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        my_putchar(str[i]);
    }
    return 0;
}
