/*
** my_strcpy.c for my_strcpy in /home/samuel.rousseaux/Lib
** 
** Made by Samuel Rousseaux
** Login   <samuel.rousseaux@epitech.net>
** 
** Started on  Wed Nov 16 00:17:43 2016 Samuel Rousseaux
** Last update Wed Nov 16 00:17:55 2016 Samuel Rousseaux
*/

char    *my_strcpy(char *dest, char *src)
{
  int   i;

  i = 0;
  while (src[i] != '\0')
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest = '\0';
  return (0);
}
