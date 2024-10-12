#include <stdlib.h>
#include "../ex04/ft_stock_str.h"

struct s_stock_str *ft_strs_to_tab(int ac, char **av);
void ft_show_tab(struct s_stock_str *par);

// Remember to include all files from ex04 to the compiler -> cc ex05/main.c ex04/ft_stock_str.h ex04/ft_strs_to_tab.c ex05/ft_show_tab.c
int main(void)
{
  t_stock_str *struct_arr;
  char *str_1 = "Hello ";
  char *str_2 = "World ";
  char *str_3 = "!";
  char *arr[3];
  arr[0] = str_1;
  arr[1] = str_2;
  arr[2] = str_3;
  int i = 0;
  struct_arr = ft_strs_to_tab(3, arr);
  ft_show_tab(struct_arr);
  while (struct_arr[i].str)
  {
    free(struct_arr[i].copy);
    i++;
  }
  free(struct_arr);
}