/*
** move_right.c for move_right in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Wed Dec 14 11:43:27 2016 Samuel
** Last update Fri Dec 16 04:58:08 2016 Samuel
*/

#include "my.h"
#include <ncurses.h>

t_coordp	move_right(t_coordp s)
{
  if (mvinch(s.y, s.x + 1) == 'X')
    {
      if (mvinch(s.y, s.x + 2) != '#' && mvinch(s.y, s.x + 2) != 'X')
	{
	  mvprintw(s.y, s.x, " ");
	  s.x += 1;
	  mvprintw(s.y, s.x, "P");
	  mvprintw(s.y, s.x + 1, "X");
	}
    }
  else if (mvinch(s.y, s.x + 1) != '#')
    {
      mvprintw(s.y, s.x, " ");
      s.x += 1;
      mvprintw(s.y, s.x, "P");
    }
  return (s);
}
