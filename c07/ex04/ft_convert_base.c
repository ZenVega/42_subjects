#include <stdio.h>
#include <stdlib.h>

struct convert_base
  {
    char *nbr;
    char *base_from;
    char *base_to;
    int base_from_len;
    int base_to_len;
  } typedef cb_obj;

int validate_base(char *base)
{
  int i;
  int j;
  i = 0;
  while (base[i])
  {
    j = 0;
    if(base[i] <= '!' || base[i] >= '~' || base[i] == '-' || base[i] == '+')
      return (0);
    while (j < i)
    {
      if(base[i] == base[j])
        return (0);
      j++;
    }
    i++;
  }
  return (1);
}

int get_str_length(char* str)
{
  int i;
  i = 0;
  while (str[i])
    i++;
  return i;
}

int get_base(char *base)
{
  if(!validate_base(base))
    return (-1);
  int i;
  i = 0;
  while(base[i])
    i++;
  if (i >= 2 )
    return (i);
  return 0;
}

int base_val_to_int(char value, char* base)
{
  int i;
  i = 0;
  while (base[i])
  {
    if (base[i] == value)
      return (i);
    i++;
  }
  return (-1);
}

int to_base_ten(cb_obj cb_object)
{
  int res;
  int i = 0;
  int val_in_base;
  res = 0;
  while (cb_object.nbr[i])
    {
      val_in_base = base_val_to_int(cb_object.nbr[i], cb_object.base_from);
      if (val_in_base == -1)
        return (-1);
      res = res * cb_object.base_from_len + val_in_base;
      i++;
    }
  return (res);
}

char  *to_dest_base(int base_ten, cb_obj cb_object, int neg)
{
  int i;
  int div;
  int res_length;
  char  *res;
  div = base_ten;
  res_length = 0;
  while (div > 0)
  {
    div /= cb_object.base_to_len;
    res_length++;
  }
  res = (char *)malloc(sizeof(char) * (res_length + 1 + neg));
  if(!res)
    return NULL;
  div = base_ten;
  i = 0;
  while (div > 0)
  {
    res[i] = cb_object.base_to[div % cb_object.base_to_len];
    div /= cb_object.base_to_len;
    i++;
  }
  if (neg)
    res[i++] = '-';
  res[i] = '\0';
  return (res);
}

char  *convert_to_dest_base(cb_obj cb_object)
{
  int   base_ten;
  int   i;
  char  buffer;
  char  *dest_base;
  int   str_len;
  int neg;
  neg = 0;
  if(*cb_object.nbr == '+' || *cb_object.nbr == '-')
  {
    if(*cb_object.nbr == '-')
      neg = 1;
    cb_object.nbr++;
  }
  base_ten = to_base_ten(cb_object);
  if (base_ten == -1)
    return NULL;
  dest_base = to_dest_base(base_ten, cb_object, neg);
  str_len = get_str_length(dest_base);
  i = 0;
  while (i < str_len / 2)
{
    buffer = dest_base[i];
    dest_base[i] = dest_base[str_len - 1 - i];
    dest_base[str_len - 1 - i] = buffer;
    i++;
}
  return (dest_base);
}

char  *ft_convert_base(char *nbr, char *base_from, char *base_to)
{
  char  *res;
  cb_obj cb_object;
  cb_object.nbr = nbr;
  cb_object.base_from = base_from;
  cb_object.base_to = base_to;
  cb_object.base_from_len = get_base(base_from);
  cb_object.base_to_len = get_base(base_to);
  if(cb_object.base_from_len == -1 || cb_object.base_to_len == -1)
    return NULL;
  res = convert_to_dest_base(cb_object);
  if (res == NULL)
    return (NULL);
  return res;
}

int main(void)
{
  char  *nbr = "-FFF42D";
  char  *base_from = "0123456789ABCDEF";
  char  *base_to = "012";
  char  *converted_number = ft_convert_base(nbr, base_from, base_to);
  if(converted_number == NULL)
    printf("Invalid Input");
  else
    printf("%s in base: %s\nConverted to base: %s\nIs: %s\n", nbr, base_from, base_to, converted_number);
  free(converted_number);
}