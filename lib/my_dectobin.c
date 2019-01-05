/*
** my_dectobin.c for my_dectobin in /home/samuel.rousseaux/Lib
** 
** Made by Samuel Rousseaux
** Login   <samuel.rousseaux@epitech.net>
** 
** Started on  Wed Nov 16 00:09:14 2016 Samuel Rousseaux
** Last update Wed Nov 16 00:09:33 2016 Samuel Rousseaux
*/

long int        my_dectobin(int nb)
{
  long int      final;
  int   i;
  int   r;

  final = 0;
  i = 1;
  while (nb != 0)
    {
      r = nb % 2;
      nb = nb / 2;
      final = final + r * i;
      i = i * 10;
    }
  my_putnbr(final);
  return (0);
}
