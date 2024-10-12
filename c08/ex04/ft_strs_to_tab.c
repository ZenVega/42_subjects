#include <stdlib.h>
#include <unistd.h>
#include "ft_stock_str.h"

#include <stdio.h>

int ft_str_len(char *str)
{
  int i;
  i = 0;
  while (str[i])
    i++;
  return i;
}

char *ft_str_copy(char *str)
{
  int length;
  int i;
  char *str_cpy;
  length = ft_str_len(str);
  str_cpy = (char *)malloc(sizeof(char) * (length + 1));
  if (!str_cpy)
    return NULL;
  i = 0;
  while (i < length)
  {
    str_cpy[i] = str[i];
    i++;
  }
  str_cpy[i] = '\0';
  return (str_cpy);
}

void clean_all(t_stock_str *struct_arr, int iterations)
{
  while (iterations)
  {
    free(struct_arr[iterations - 1].copy);
    iterations--;
  }
  free(struct_arr);
}

struct s_stock_str *ft_strs_to_tab(int ac, char **av)
{
  t_stock_str *struct_arr;
  int i;
  i = 0;
  struct_arr = (t_stock_str *)malloc(sizeof(t_stock_str) * (ac + 1));
  if (!struct_arr)
    return NULL;
  while (i < ac)
  {
    int length;
    length = ft_str_len(av[i]);
    struct_arr[i].size = length;
    struct_arr[i].str = av[i];
    struct_arr[i].copy = ft_str_copy(av[i]);
    if (!struct_arr[i].copy)
    {
      clean_all(struct_arr, i);
      return NULL;
    }
    i++;
  }
  struct_arr[i].str = 0;
  return struct_arr;
}