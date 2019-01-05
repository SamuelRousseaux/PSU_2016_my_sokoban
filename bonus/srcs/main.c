/*
** main.c for main in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Sun Dec 11 16:46:54 2016 Samuel
** Last update Tue Dec 20 04:01:02 2016 Samuel
*/

#include "my.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

void	help()
{
  my_putstr("\nUSAGE\n");
  my_putstr("           ./my_sokoban map\n\n");
  my_putstr("DESCRIPTION\n");
  my_putstr("           ");
  my_putstr("Sokoban is a game in which you need to but the boxes 'X'\n");
  my_putstr("           ");
  my_putstr("in the storage locations 'O' with the player 'P'\n");
  my_putstr("           ");
  my_putstr("Use arrow keys to move and 'space' to reset current game\n\n");
  exit(0);
}

void	exrror(char *error)
{
  write(2, error, my_strlen(error));
  exit(0);
}

int	check_file(char *file)
{
  int	check;
  check = open(file, O_RDONLY);
  return (check);
}

int	main(int ac, char **av)
{
  if (ac == 1)
    exrror("\nPro tip: ./my_sokoban -h (for help)\n\n");
  if ((av[1][0] == '-') && (av[1][1] == 'h'))
    help();
  if (check_file(av[1]) == -1)
    exrror("\nError while openning map. Please verify your map.\n\n");
  menu();
  readmap(av[1]);
  return (0);
}
