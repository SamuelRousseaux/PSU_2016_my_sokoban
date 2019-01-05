/*
** my_strlen.c for my_strlen in /home/samuel.rousseaux/Lib
** 
** Made by Samuel Rousseaux
** Login   <samuel.rousseaux@epitech.net>
** 
** Started on  Tue Nov 15 00:39:03 2016 Samuel Rousseaux
** Last update Tue Nov 15 00:40:59 2016 Samuel Rousseaux
*/

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}
