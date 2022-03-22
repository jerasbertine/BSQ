/*
** EPITECH PROJECT, 2021
** B-CPE-110-PAR-1-1-BSQ-jeras.bertine
** File description:
** fill_tab
*/

#include "../include/my.h"

int **fill_tab(char *buffer)
{
    int nb_rows = my_getnbr(buffer);
    int **tab;
    int i = 0;
    while (buffer[i] != '\n')
        i++;
    buffer += i + 1;

    tab = malloc(sizeof(int*) * (nb_rows + 1));
    for (int l = 0, i = 0; l != nb_rows; l++, i++) {
        tab[l] = malloc(sizeof(int) * (count_columns(buffer) + 1));
        for (int c = 0; buffer[i] != '\n'; i++, c++)
            tab[l][c] = (buffer[i] == '.') ? 1 : 0;
    }
    return (tab);
}

int demin_inv(int l, int c, int **tab)
{
    int min = tab[l][c - 1];

    if (tab[l][c] == 0)
        return (0);
    if (min > tab[l - 1][c])
        min = tab[l - 1][c];
    if (min > tab[l - 1][c - 1])
        min = tab[l - 1][c - 1];
    return (min + 1);
}

void bsq(char *buffer)
{
    int m = 0;
    int n = 0;
    int nb_rows = my_getnbr(buffer);
    int **tab = fill_tab(buffer);
    int i = 0;
    int index = 0;
    while (buffer[i] != '\n')
        i++;
    buffer += i + 1;
    for (int z = 1; z < nb_rows; z++) {
        for (int l = 1; l < count_columns(buffer); l++) {
            tab[z][l] = demin_inv(z, l, tab);
            if (tab[z][l] > index) {
                index = tab[z][l];
                m = z;
                n = l;
            }
        }
    }
    kinder(m, n, index, buffer);
}

int kinder(int z, int l, int index, char *buffer)
{
    int tmp = index;
    int pos = z * count_columns(buffer) + z + l;
    buffer[pos] = 'x';
    for (int j = 0; j != index; j++) {
        for (int i = 0; i != index; i++)
            buffer[pos - i] = 'x';
        pos = pos - (count_columns(buffer) + 1);
    }
    write (1, buffer, my_strlen(buffer));
}

int main (int ac, char **av)
{
    struct stat bytes;
    int fd = open (av[1], O_RDONLY);
    if (stat(av[1], &bytes) == -1)
        return (84);
    char *buffer;
    stat(av[1], &bytes);
    int a = bytes.st_size;
    buffer = malloc(sizeof(char) * (a + 1));
    read(fd, buffer, a);
    buffer[a] = '\0';
    bsq(buffer);
    free(buffer);
}
