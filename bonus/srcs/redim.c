/*
** redim.c for redim in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Wed Dec 14 20:41:12 2016 Samuel
** Last update Tue Dec 20 21:40:25 2016 Samuel
*/

#include "my.h"
#include <ncurses.h>

void	redim(int column, int row, t_list *lo, char **map)
{
  if ((COLS < column) || (LINES < row))
    {
      while ((COLS < column) || (LINES < row))
	{
	  clear();
	  mvprintw(LINES / 2, (COLS / 2) - 12, "Resize the screen please");
	  refresh();
	}
      reset_game(map, column, row, lo);
    }
}
