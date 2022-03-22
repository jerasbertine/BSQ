/*
** EPITECH PROJECT, 2021
** B-CPE-110-PAR-1-1-BSQ-jeras.bertine
** File description:
** my
*/

#ifndef MY_H_
    #define MY_H_

    #include <sys/types.h>
    #include <sys/stat.h>
    #include <unistd.h>
    #include <stdio.h>
    #include <fcntl.h>
    #include <stdlib.h>

// typedef struct bsq {
//     int l;
//     int c;
//     int nb_rows;
//     int nb_cols;
//     int **tab;
//     char *buffer;
// } bsq;

int count_rows(char const *buffer);
int my_getnbr(char const *str);
int count_columns(char *str);
int **fill_tab(char *buffer);
void my_putchar(char a);
int my_put_nbr(int n);
int my_strlen(char const *str);
void bsq(char *buffer);
int kinder(int z, int l, int index, char *buffer);

#endif /* !my_h */
