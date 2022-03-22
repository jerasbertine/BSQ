/*
** EPITECH PROJECT, 2021
** B-CPE-110-PAR-1-1-BSQ-jeras.bertine
** File description:
** first_columns
*/

#include "../include/my.h"

int count_columns(char *str)
{
    int i = 0;

    for (; str[i] != '\n'; i++);
    return (i);
}
