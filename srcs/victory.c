/*
** victory.c for victory in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Wed Dec 14 19:29:09 2016 Samuel
** Last update Thu Dec 15 13:34:30 2016 Samuel
*/

#include "my.h"
#include <stdlib.h>
#include <ncurses.h>
#include <unistd.h>

char	*victory(t_list *lo)
{
  while (lo->next != NULL)
    {
      if (mvinch(lo->y, lo->x) != 'X')
	return (NULL);
      lo = lo->next;
    }
  if (mvinch(lo->y, lo->x) != 'X')
    return (NULL);
  endwin();
  exit(0);
}
