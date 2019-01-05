/*
** move_left.c for move_left in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Wed Dec 14 11:49:30 2016 Samuel
** Last update Fri Dec 16 04:57:36 2016 Samuel
*/

#include "my.h"
#include <ncurses.h>

t_coordp	move_left(t_coordp s)
{
  if (mvinch(s.y, s.x - 1) == 'X')
    {
      if (mvinch(s.y, s.x - 2) != '#' && mvinch(s.y, s.x - 2) != 'X')
	{
	  mvprintw(s.y, s.x, " ");
	  s.x -= 1;
	  mvprintw(s.y, s.x, "P");
	  mvprintw(s.y, s.x - 1, "X");
	}
    }
  else if (mvinch(s.y, s.x - 1) != '#')
    {
      mvprintw(s.y, s.x, " ");
      s.x -= 1;
      mvprintw(s.y, s.x, "P");
    }
  return (s);
}
