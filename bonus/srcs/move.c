/*
** move.c for move in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban/bonus
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Mon Dec 19 14:04:07 2016 Samuel
** Last update Tue Dec 20 21:31:57 2016 Samuel
*/

#include "my.h"
#include <ncurses.h>
#include <stdlib.h>

t_coordp        move_P(t_coordp s, int key)
{
  if (key == KEY_RIGHT)
    s = move_right(s);
  else if (key == KEY_LEFT)
    s = move_left(s);
  else if (key == KEY_UP)
    s = move_up(s);
  else if (key == KEY_DOWN)
    s = move_down(s);
  return (s);
}

void    check_O(t_list *lo)
{
  while (lo->next != NULL)
    {
      if (mvinch(lo->y, lo->x) == ' ')
	mvprintw(lo->y, lo->x, "O");
      lo = lo->next;
    }
  if (mvinch(lo->y, lo->x) == ' ')
    mvprintw(lo->y, lo->x, "O");
}
