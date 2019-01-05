/*
** move_down.c for move_down in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Wed Dec 14 11:56:19 2016 Samuel
** Last update Fri Dec 16 04:57:05 2016 Samuel
*/

#include "my.h"
#include <ncurses.h>

t_coordp	move_down(t_coordp s)
{
  if (mvinch(s.y + 1, s.x) == 'X')
    {
      if (mvinch(s.y + 2, s.x) != '#' && mvinch(s.y + 2, s.x) != 'X')
	{
	  mvprintw(s.y, s.x, " ");
	  s.y += 1;
	  mvprintw(s.y, s.x, "P");
	  mvprintw(s.y + 1, s.x, "X");
	}
    }
  else if (mvinch(s.y + 1, s.x) != '#')
    {
      mvprintw(s.y, s.x, " ");
      s.y += 1;
      mvprintw(s.y, s.x, "P");
    }
  return (s);
}
