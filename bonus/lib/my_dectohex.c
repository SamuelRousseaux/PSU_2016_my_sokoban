/*
** my_dectohex.c for my_dectohex.c in /home/samuel.rousseaux/Lib
** 
** Made by Samuel Rousseaux
** Login   <samuel.rousseaux@epitech.net>
** 
** Started on  Wed Nov 16 00:08:13 2016 Samuel Rousseaux
** Last update Wed Nov 16 00:14:45 2016 Samuel Rousseaux
*/

#include <stdlib.h>

int     my_dectohex(int nb, char str)
{
  char  *final;
  int   i;
  int   save;

  i = 0;
  final = malloc(sizeof(char));
  if (final == '\0')
    return (84);
  while (nb > 0)
    {
      if ((nb % 16) >= 10)
	{
	  if (str == 'x')
	    final[i] = (nb % 16) + 87;
	  else
	    final[i] = (nb % 16) + 55;
	}
      else
	final[i] = (nb % 16) + 48;
      nb = nb / 16;
      i++;
    }
  final[i] = '\0';
  my_putstr(my_revstr(final));
  return (0);
}
