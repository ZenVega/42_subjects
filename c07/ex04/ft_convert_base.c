#include <stdio.h>

int get_base(char *base)
{
  int i;
  i = 0;
  while(base[i])
    i++;
  return (i);
}

char  *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
  int base_from_len = get_base(base_from);
  int base_to_len = get_base(base_to);
  printf("In: %d // Out: %d\n", base_from_len, base_to_len);
  return nbr;
}

int main(void)
{
  char  *nbr = "-13";
  char  *base_from = "0123456789";
  char  *base_to = "01";
  char  *converted_number = ft_convert_base(nbr, base_from, base_to);
  printf("Converted: %s\n", converted_number);
}