/*
** my_putnbr.c for my_putnbr in /home/samuel.rousseaux/Lib
** 
** Made by Samuel Rousseaux
** Login   <samuel.rousseaux@epitech.net>
** 
** Started on  Tue Nov 15 00:45:32 2016 Samuel Rousseaux
** Last update Tue Nov 15 00:46:09 2016 Samuel Rousseaux
*/

void    my_putnbr(int nb)
{
  int   div;

  div = 1;
  if (nb < 0)
    {
      my_putchar('-');
      nb = -nb;
    }
  while ((nb / div) >= 10)
    div *= 10;
  while (div > 0)
    {
      my_putchar((nb / div) % 10 + '0');
      div /= 10;
    }
}
