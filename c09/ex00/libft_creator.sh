#!/bin/sh -e
# for the subject it's not really necessary but it will make sure the library will be in the same directory no matter from where it's executed
SCRIPT_DIR="$(dirname "$0")"
#cc -Wall -Wextra -Werror -c $SCRIPT_DIR/*.c
# This would be the easiest way, however we are not supposed to use wildcards. therefore i will put all the files in variables
FT_STRCMP=ft_strcmp
FT_STRLEN=ft_strlen
FT_SWAP=ft_swap
FT_PUTCHAR=ft_putchar
FT_PUTSTR=ft_putstr

cc -Wall -Wextra -Werror -c \
  $SCRIPT_DIR/$FT_STRCMP.c \
  $SCRIPT_DIR/$FT_STRLEN.c \
  $SCRIPT_DIR/$FT_SWAP.c \
  $SCRIPT_DIR/$FT_PUTCHAR.c \
  $SCRIPT_DIR/$FT_PUTSTR.c 

# ar creates (modifies) archives
# c creates new archive or overwrites
# r checks replaces *.o files to use with more recent ones
ar cr $SCRIPT_DIR/libft.a \
  $FT_STRCMP.o \
  $FT_STRLEN.o \
  $FT_SWAP.o \
  $FT_PUTCHAR.o \
  $FT_PUTSTR.o

  rm \
  $FT_STRCMP.o \
  $FT_STRLEN.o \
  $FT_SWAP.o \
  $FT_PUTCHAR.o \
  $FT_PUTSTR.o