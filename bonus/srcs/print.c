/*
** print.c for print in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Tue Dec 13 14:02:42 2016 Samuel
** Last update Tue Dec 20 21:38:24 2016 Samuel
*/

#include "my.h"
#include <ncurses.h>
#include <stdlib.h>
#include <time.h>

void	sokoloop(t_coordp s, char **map, t_list *lo, t_list *lx)
{
  while (1)
    {
      mvprintw(s.lines + 1, 0, "Moves: %d", s.a);
      mvprintw(s.lines + 2, 0, "                             ");
      mvprintw(s.lines + 2, 0, "Position: %dx%d", s.x, s.y);
      refresh();
      lx = get_X(s.cols, s.lines);
      check_O(lo);
      victory(lo);
      defeat(lx, lo);
      redim(s.cols, s.lines, lo, map);
      s.key = getch();
      if (s.key == 32)
	reset_game(map, s.cols, s.lines, lo);
      s = move_P(s, s.key);
      s.a++;
      refresh();
    }
}

void	reset_game(char **map, int column, int row, t_list *lo)
{
  t_coordp	s;
  t_list	*lx;

  clear();
  lx = 0;
  s = print_map(map, column, row);
  s.a = 0;
  s.cols = column;
  s.lines = row;
  sokoloop(s, map, lo, lx);
}

t_coordp	print_map(char **map, int column, int row)
{
  int		py;
  t_coordp	s;

  py = 0;
  s.x = 0;
  s.y = 0;
  s.O = 0;
  while (py != row)
    {
      mvprintw(py, 0, map[py]);
      refresh();
      py++;
    }
  while (mvinch(s.y, s.x) != 'P')
    {
      if (s.x == column)
	{
	  s.x = 0;
	  s.y++;
	}
      else
	s.x++;
    }
  return (s);
}

void    sokoban(char **map, int column, int row)
{
  t_coordp      s;
  t_list	*lo;
  t_list	*lx;

  initscr();
  keypad(stdscr, TRUE);
  s = print_map(map, column, row);
  noecho();
  curs_set(0);
  lo = get_O(column, row);
  s.a = 0;
  s.cols = column;
  s.lines = row;
  lx = 0;
  s.time = clock();
  sokoloop(s, map, lo, lx);
}
