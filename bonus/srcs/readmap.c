/*
** read.c for read in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Sun Dec 11 17:21:24 2016 Samuel
** Last update Fri Dec 16 05:01:12 2016 Samuel
*/

#include "my.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int	get_column(char *file)
{
  int	i;
  int	nb;

  i = 0;
  nb = 0;
  while (file[i] != '\n')
    {
      nb++;
      i++;
    }
  return (nb);
}

int	get_row(char *file)
{
  int   i;
  int   nb;

  i = 0;
  nb = 0;
  while (file[i] != '\0')
    {
      if (file[i] == '\n')
	 nb++;
      i++;
    }
  return (nb);
}

char	**putin_list(char *file)
{
  char	**map;
  int	i;
  int	x;
  int	y;

  i = 0;
  y = 0;
  x = 0;
  map = malloc(sizeof(char *) * 20);
  while (file[i + 2] != '\0')
    {
      x = 0;
      map[y] = malloc(sizeof(char) * 12);
      while (file[i] != '\n')
	{
	  map[y][x] = file[i];
	  i++;
	  x++;
	}
      i++;
      map[y][x] = '\0';
      y++;
    }
  return (map);
}

void    readmap(char *filename)
{
  int	opfile;
  char	*file;
  char	**map;

  file = malloc(sizeof(char) * 3000);
  opfile = open(filename, O_RDONLY);
  read(opfile, file, 3000);
  map = putin_list(file);
  close(opfile);
  sokoban(map, get_column(file), get_row(file));
}
