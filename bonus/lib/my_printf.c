/*
** my_printf.c for my_printf in /home/samuel.rousseaux/Lib
** 
** Made by Samuel Rousseaux
** Login   <samuel.rousseaux@epitech.net>
** 
** Started on  Wed Nov 16 00:11:01 2016 Samuel Rousseaux
** Last update Wed Nov 16 00:13:40 2016 Samuel Rousseaux
*/

#include <stdarg.h>
#include <unistd.h>

int     check_flags(char str, va_list ap)
{
  if (str == 'c')
    my_putchar(va_arg(ap, int));
  else if (str == 's')
    my_putstr(va_arg(ap, char *));
  else if ((str == 'd') || (str == 'i'))
    my_putnbr(va_arg(ap, int));
  else
    my_putchar('%');
  return (0);
}

void    my_printf(char *str, ...)
{
  int   i;
  va_list       ap;

  i = 0;
  va_start(ap, str);
  while (str[i])
    {
      if (str[i] != '%')
	my_putchar(str[i]);
      else
	{
	  i++;
	  check_flags(str[i], ap);
	}
      i++;
    }
  va_end(ap);
}
