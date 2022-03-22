/*
** EPITECH PROJECT, 2021
** B-CPE-110-PAR-1-1-BSQ-jeras.bertine
** File description:
** my_putchar
*/

#include <unistd.h>

void my_putchar(char a)
{
    write(1, &a, 1);
}
