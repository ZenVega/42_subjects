#include <stdlib.h>
#include <stdio.h>

char  *ft_strdup(char *src)
{
  int   i;
  char  *dest;
  i = 0;
  while(src[i])
    i++;
  dest = (char *)malloc(sizeof(char) * (i + 1));
  if (!dest)
  {
    printf("Error");
    return NULL;
  }
  i = 0;
  while(*src)
  {
    dest[i] = *src;
    src++;
    i++;
  }
  dest[i] = '\0';
  return (dest);
}

int main()
{
  char  *str = "Hello World!";
  char  *dest;
  dest = ft_strdup(str);
  printf("%s", dest);
  free(dest);
}