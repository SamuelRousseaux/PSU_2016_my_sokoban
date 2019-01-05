/*
** my_getnbr.c for my_getnbr in /home/samuel.rousseaux/Lib/lib/my
** 
** Made by Samuel Rousseaux
** Login   <samuel.rousseaux@epitech.net>
** 
** Started on  Wed Nov 23 16:33:52 2016 Samuel Rousseaux
** Last update Wed Nov 23 17:05:16 2016 Samuel Rousseaux
*/

int	my_getnbr(char *str)
{
  int	nbr;
  int	i;
  int	neg;
  int	c;
  int	lel;

  i = 1;
  nbr = 0;
  neg = 1;
  c = 1;
  lel = 0;
  if (str[0] == '-')
    {
      neg = -neg;
      lel = -1;
    }
  while ((i - lel) <= my_strlen(str))
    {
      nbr += (str[my_strlen(str) - i] - 48) * c;
      i++;
      c *= 10;
    }
  nbr *= neg;
  return (nbr);
}
