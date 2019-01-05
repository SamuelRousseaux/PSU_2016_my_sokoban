/*
** print.c for print in /home/samuel/Système Unix/My_Sokoban/PSU_2016_my_sokoban
** 
** Made by Samuel
** Login   <samuel.rousseaux@epitech.eu>
** 
** Started on  Tue Dec 13 14:02:42 2016 Samuel
** Last update Fri Dec 16 19:43:17 2016 Samuel
*/

#include "my.h"
#include <ncurses.h>
#include <stdlib.h>

void	check_O(t_list *lo)
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

t_coordp	move_P(t_coordp s, int key)
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

void	reset_game(char **map, int column, int row, t_list *lo)
{
  t_coordp	s;
  t_list	*lx;
  int		key;

  clear();
  s = print_map(map, column, row);
  while (1)
    {
      lx = get_X(column, row);
      lx = lx;
      check_O(lo);
      victory(lo);
      redim(column, row, lo, map);
      key = getch();
      if (key == 32)
	reset_game(map, column, row, lo);
      s = move_P(s, key);
    }
}

t_coordp	print_map(char **map, int column, int row)
{
  int		py;
  t_coordp	s;

  py = 0;
  s.x = 0;
  s.y = 0;
  s.O = 0;
  mvprintw(0,0, "%d", COLS);
  while (py != row)
    {
      mvprintw(py, 0, map[py]);
      refresh();
      py++;
    }
  while (mvinch(s.y, s.x) != 'P')
    {
      if (s.x == column+(COLS/2))
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
  int		key;

  initscr();
  keypad(stdscr, TRUE);
  s = print_map(map, column, row);
  noecho();
  curs_set(0);
  lo = get_O(column, row);
  while (1)
    {
      lx = get_X(column, row);
      lx = lx;
      check_O(lo);
      victory(lo);
      redim(column, row, lo, map);
      key = getch();
      if (key == 32)
	reset_game(map, column, row, lo);
      s = move_P(s, key);
    }
  endwin();
}
