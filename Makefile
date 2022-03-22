##
## EPITECH PROJECT, 2021
## Makefile
## File description:
## Makefile
##

SRC		=		sources/my_getnbr.c		\
				sources/count_rows.c	\
				sources/count_columns.c	\
				sources/my_putchar.c	\
				sources/fill_tab.c		\
				sources/my_strlen.c		

EXEC		=	bsq

OBJ			=	$(SRC:.c=.o)

CFLAGS 		=	-g

all:	$(OBJ)
	gcc -o $(EXEC) $(OBJ)
	rm -f a.out

clean:
	find . \( -name "*#*" -or -name "*~" -or -name "*.o" \
	-or -name "*.gcno" -or -name "*.gcda" \) -delete

fclean: clean
	rm -f $(EXEC) $(TEST)

re:	fclean all