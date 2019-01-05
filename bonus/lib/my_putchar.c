/*
** my_putchar.c for my_putchar in /home/samuel.rousseaux/Lib
** 
** Made by Samuel Rousseaux
** Login   <samuel.rousseaux@epitech.net>
** 
** Started on  Tue Nov 15 00:38:03 2016 Samuel Rousseaux
** Last update Tue Nov 15 00:44:48 2016 Samuel Rousseaux
*/

#include <unistd.h>

void	my_putchar(char str)
{
  write(1, &str, 1);
}
