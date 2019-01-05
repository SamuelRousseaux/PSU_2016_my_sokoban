/*
** my_putstr.c for my_putstr in /home/samuel.rousseaux/Lib
** 
** Made by Samuel Rousseaux
** Login   <samuel.rousseaux@epitech.net>
** 
** Started on  Tue Nov 15 00:41:19 2016 Samuel Rousseaux
** Last update Tue Nov 15 00:44:15 2016 Samuel Rousseaux
*/

#include <unistd.h>

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}
