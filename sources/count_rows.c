/*
** EPITECH PROJECT, 2021
** rows
** File description:
** function that displays the first line
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include "../include/my.h"

int count_rows(char const *buffer)
{
    int a;
    a = my_getnbr(buffer);
    return (a);
}
